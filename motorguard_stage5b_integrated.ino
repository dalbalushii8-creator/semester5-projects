#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "arduinoFFT.h"

// =======================================================
// MotorGuard Stage 5B
// Full Integrated IoT + DiagnosticEngine + FFT Analyzer
// =======================================================

// ------------------- Sensor Pins -------------------
#define DHT_PIN   15
#define DHT_TYPE  DHT22

#define VIB_PIN   34   // vibration potentiometer + FFT mode selector
#define CURR_PIN  35   // current potentiometer
#define ACOU_PIN  32   // acoustic potentiometer

// ------------------- OLED Settings -------------------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// ------------------- FFT Settings -------------------
const uint16_t SAMPLES = 128;
const double SAMPLING_FREQ = 1000.0;
const double PI2 = 6.283185307179586;

double vReal[SAMPLES];
double vImag[SAMPLES];

ArduinoFFT<double> FFT = ArduinoFFT<double>(vReal, vImag, SAMPLES, SAMPLING_FREQ);

// ------------------- Objects -------------------
DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ------------------- Wi-Fi -------------------
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ------------------- Global Results -------------------
String fftMode = "";
String fftDiagnosis = "";
double injectedFreq = 0.0;
double peakHz = 0.0;

String finalDiagnosis = "";
int health = 100;

// =======================================================
// Setup
// =======================================================
void setup() {
  Serial.begin(115200);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("MotorGuard 5B");
  display.println("IoT + FFT");
  display.println("Starting...");
  display.display();

  delay(1000);

  connectWiFi();

  Serial.println("===========================================");
  Serial.println("MotorGuard Stage 5B Integrated System");
  Serial.println("Sensors + DiagnosticEngine + OLED + WiFi + FFT");
  Serial.println("===========================================");
}

// =======================================================
// Main Loop
// =======================================================
void loop() {
  // ------------------- Read Sensors -------------------
  float temp = dht.readTemperature();

  int vibRaw = analogRead(VIB_PIN);
  int currRaw = analogRead(CURR_PIN);
  int acouRaw = analogRead(ACOU_PIN);

  float vibration = vibRaw / 4095.0 * 10.0;   // mm/s
  float current   = currRaw / 4095.0 * 15.0;  // A
  float acoustic  = acouRaw / 4095.0 * 100.0; // dB

  if (isnan(temp)) {
    temp = 24.0;
  }

  // ------------------- Run FFT -------------------
  int fftModeNumber = selectFFTMode(vibRaw);
  buildVibrationSignal(fftModeNumber);

  FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);
  FFT.compute(FFTDirection::Forward);
  FFT.complexToMagnitude();

  peakHz = FFT.majorPeak();

  classifyFFT(peakHz);

  // ------------------- Diagnostic Engine -------------------
  runDiagnosticEngine(temp, vibration, current, acoustic);

  // ------------------- OLED Output -------------------
  updateOLED(temp, vibration, current, acoustic);

  // ------------------- Serial Output -------------------
  printSerial(temp, vibration, current, acoustic, vibRaw);

  // ------------------- IoT Transmission -------------------
  sendIoTData(temp, vibration, current, acoustic);

  delay(3000);
}

// =======================================================
// Wi-Fi Connection
// =======================================================
void connectWiFi() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("MotorGuard 5B");
  display.println("Connecting WiFi...");
  display.display();

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  int tries = 0;

  while (WiFi.status() != WL_CONNECTED && tries < 20) {
    delay(500);
    Serial.print(".");
    tries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println();
    Serial.println("WiFi connected!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("WiFi connected");
    display.println(WiFi.localIP());
    display.display();
  } 
  else {
    Serial.println();
    Serial.println("WiFi failed");

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("WiFi failed");
    display.display();
  }

  delay(1000);
}

// =======================================================
// FFT Mode Selection
// =======================================================
int selectFFTMode(int knob) {
  if (knob < 1365) {
    return 0;   // Normal
  } 
  else if (knob < 2730) {
    return 1;   // Rotor imbalance
  } 
  else {
    return 2;   // Bearing defect
  }
}

// =======================================================
// Build Simulated Vibration Signal
// =======================================================
void buildVibrationSignal(int mode) {
  double mainFreq;
  double harmonicFreq;
  double amplitudeMain;
  double amplitudeHarmonic;

  if (mode == 0) {
    fftMode = "NORMAL";
    injectedFreq = 50.0;

    mainFreq = 50.0;
    harmonicFreq = 100.0;
    amplitudeMain = 1.0;
    amplitudeHarmonic = 0.15;
  } 
  else if (mode == 1) {
    fftMode = "ROTOR IMBAL";
    injectedFreq = 25.0;

    mainFreq = 25.0;
    harmonicFreq = 50.0;
    amplitudeMain = 1.6;
    amplitudeHarmonic = 0.30;
  } 
  else {
    fftMode = "BEARING";
    injectedFreq = 120.0;

    mainFreq = 120.0;
    harmonicFreq = 240.0;
    amplitudeMain = 1.8;
    amplitudeHarmonic = 0.45;
  }

  for (uint16_t i = 0; i < SAMPLES; i++) {
    double t = (double)i / SAMPLING_FREQ;

    double signal =
      amplitudeMain * sin(PI2 * mainFreq * t) +
      amplitudeHarmonic * sin(PI2 * harmonicFreq * t) +
      0.08 * sin(PI2 * 330.0 * t);

    vReal[i] = signal;
    vImag[i] = 0.0;
  }
}

// =======================================================
// FFT Fault Classification
// =======================================================
void classifyFFT(double peak) {
  if (peak >= 105.0 && peak <= 135.0) {
    fftDiagnosis = "Bearing defect";
  } 
  else if (peak >= 18.0 && peak <= 35.0) {
    fftDiagnosis = "Rotor imbalance";
  } 
  else if (peak >= 40.0 && peak <= 60.0) {
    fftDiagnosis = "Normal running";
  } 
  else {
    fftDiagnosis = "Unknown vibration";
  }
}

// =======================================================
// Full Diagnostic Engine
// =======================================================
void runDiagnosticEngine(float temp, float vibration, float current, float acoustic) {
  int rTemp = (temp > 75.0) ? 2 : (temp > 60.0) ? 1 : 0;
  int rVib  = (vibration > 7.0) ? 2 : (vibration > 4.0) ? 1 : 0;
  int rCurr = (current > 12.0) ? 2 : (current > 9.0) ? 1 : 0;
  int rAcou = (acoustic > 85.0) ? 2 : (acoustic > 75.0) ? 1 : 0;

  finalDiagnosis = "";

  bool fftBearing = (fftDiagnosis == "Bearing defect");
  bool fftImbalance = (fftDiagnosis == "Rotor imbalance");

  // Bearing fault from FFT OR vibration + acoustic fusion
  if (fftBearing || (rVib >= 2 && rAcou >= 1)) {
    addFault("Bearing");
  }

  // Rotor imbalance from FFT OR high vibration
  if (fftImbalance || (rVib >= 2 && !fftBearing)) {
    addFault("Imbalance");
  }

  // Electrical / thermal faults
  if (rTemp >= 2 && rCurr >= 1) {
    addFault("Overload");
  } 
  else if (rTemp >= 2) {
    addFault("Overheat");
  }

  if (rCurr >= 2 && rTemp < 2) {
    addFault("High current");
  }

  if (finalDiagnosis == "") {
    finalDiagnosis = "OK";
  }

  // Health score
  health = 100;
  health -= rTemp * 15;
  health -= rVib * 15;
  health -= rCurr * 15;
  health -= rAcou * 10;

  if (fftBearing) {
    health -= 25;
  }

  if (fftImbalance) {
    health -= 15;
  }

  if (health < 0) {
    health = 0;
  }
}

// =======================================================
// Add Fault
// =======================================================
void addFault(String fault) {
  if (finalDiagnosis == "") {
    finalDiagnosis = fault;
  } 
  else {
    finalDiagnosis += "+";
    finalDiagnosis += fault;
  }
}

// =======================================================
// OLED Display
// =======================================================
void updateOLED(float temp, float vibration, float current, float acoustic) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);

  display.println("MotorGuard 5B");

  display.print("T:");
  display.print(temp, 0);
  display.print(" V:");
  display.println(vibration, 1);

  display.print("I:");
  display.print(current, 1);
  display.print(" A:");
  display.println(acoustic, 0);

  display.print("FFT:");
  display.print(peakHz, 1);
  display.println("Hz");

  if (finalDiagnosis == "OK") {
    display.println("[OK]");
  } 
  else {
    display.println("[FAULT]");
  }

  display.println(finalDiagnosis);

  display.print("H:");
  display.print(health);
  display.print("% ");

  if (WiFi.status() == WL_CONNECTED) {
    display.println("WiFi");
  } 
  else {
    display.println("NoWiFi");
  }

  display.display();
}

// =======================================================
// Serial Monitor Output
// =======================================================
void printSerial(float temp, float vibration, float current, float acoustic, int vibRaw) {
  Serial.println("-------------------------------------------");

  Serial.print("Temperature: ");
  Serial.print(temp, 1);
  Serial.println(" C");

  Serial.print("Vibration: ");
  Serial.print(vibration, 1);
  Serial.println(" mm/s");

  Serial.print("Current: ");
  Serial.print(current, 1);
  Serial.println(" A");

  Serial.print("Acoustic: ");
  Serial.print(acoustic, 1);
  Serial.println(" dB");

  Serial.print("Vibration knob value: ");
  Serial.println(vibRaw);

  Serial.print("FFT mode: ");
  Serial.println(fftMode);

  Serial.print("Injected FFT frequency: ");
  Serial.print(injectedFreq, 1);
  Serial.println(" Hz");

  Serial.print("FFT dominant frequency: ");
  Serial.print(peakHz, 1);
  Serial.println(" Hz");

  Serial.print("FFT diagnosis: ");
  Serial.println(fftDiagnosis);

  Serial.print("Final diagnosis: ");
  Serial.println(finalDiagnosis);

  Serial.print("Health: ");
  Serial.print(health);
  Serial.println("%");

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi: CONNECTED");
  } 
  else {
    Serial.println("WiFi: DISCONNECTED");
  }
}

// =======================================================
// IoT Data Transmission
// =======================================================
void sendIoTData(float temp, float vibration, float current, float acoustic) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("IoT: WiFi not connected, data not sent");
    return;
  }

  HTTPClient http;

  String diagnosisURL = finalDiagnosis;
  diagnosisURL.replace(" ", "%20");
  diagnosisURL.replace("+", "%2B");

  String fftURL = fftDiagnosis;
  fftURL.replace(" ", "%20");

  String url = "http://httpbin.org/get?temp=" + String(temp, 1) +
               "&vib=" + String(vibration, 1) +
               "&curr=" + String(current, 1) +
               "&acoustic=" + String(acoustic, 1) +
               "&fft_peak=" + String(peakHz, 1) +
               "&fft_diag=" + fftURL +
               "&health=" + String(health) +
               "&status=" + diagnosisURL;

  http.begin(url);

  int httpCode = http.GET();

  Serial.print("IoT data sent. HTTP code: ");
  Serial.println(httpCode);

  http.end();
}
