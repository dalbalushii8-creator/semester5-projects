#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "arduinoFFT.h"

// =======================================================
// MotorGuard Stage 5A
// Standalone FFT Vibration Analyzer
// =======================================================
// Potentiometer on GPIO34 selects simulated vibration fault mode.
// LOW  = Normal running
// MID  = Rotor imbalance
// HIGH = Bearing defect

#define VIB_PIN 34

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

const uint16_t SAMPLES = 128;
const double SAMPLING_FREQ = 1000.0;
const double PI2 = 6.283185307179586;

double vReal[SAMPLES];
double vImag[SAMPLES];

ArduinoFFT<double> FFT = ArduinoFFT<double>(vReal, vImag, SAMPLES, SAMPLING_FREQ);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String modeName = "";
String diagnosis = "";
double injectedFreq = 0.0;

// =======================================================
// Setup
// =======================================================
void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("MotorGuard FFT");
  display.println("Stage 5A");
  display.println("Starting...");
  display.display();

  delay(1500);

  Serial.println("======================================");
  Serial.println("MotorGuard Stage 5A - FFT Analyzer");
  Serial.println("LOW knob  = Normal running vibration");
  Serial.println("MID knob  = Rotor imbalance");
  Serial.println("HIGH knob = Bearing defect");
  Serial.println("======================================");
}

// =======================================================
// Main Loop
// =======================================================
void loop() {
  int knob = analogRead(VIB_PIN);

  int mode;

  if (knob < 1365) {
    mode = 0;
  } 
  else if (knob < 2730) {
    mode = 1;
  } 
  else {
    mode = 2;
  }

  buildVibrationSignal(mode);

  FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);
  FFT.compute(FFTDirection::Forward);
  FFT.complexToMagnitude();

  double peakHz = FFT.majorPeak();

  classifyFault(peakHz);

  Serial.println("--------------------------------------");

  Serial.print("Knob value: ");
  Serial.println(knob);

  Serial.print("Mode selected: ");
  Serial.println(modeName);

  Serial.print("Injected vibration frequency: ");
  Serial.print(injectedFreq, 1);
  Serial.println(" Hz");

  Serial.print("FFT dominant frequency: ");
  Serial.print(peakHz, 1);
  Serial.println(" Hz");

  Serial.print("Diagnosis: ");
  Serial.println(diagnosis);

  updateOLED(peakHz);

  delay(2500);
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
    modeName = "NORMAL";
    injectedFreq = 50.0;

    mainFreq = 50.0;
    harmonicFreq = 100.0;
    amplitudeMain = 1.0;
    amplitudeHarmonic = 0.15;
  } 
  else if (mode == 1) {
    modeName = "ROTOR IMBALANCE";
    injectedFreq = 25.0;

    mainFreq = 25.0;
    harmonicFreq = 50.0;
    amplitudeMain = 1.6;
    amplitudeHarmonic = 0.30;
  } 
  else {
    modeName = "BEARING DEFECT";
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
void classifyFault(double peakHz) {
  if (peakHz >= 105.0 && peakHz <= 135.0) {
    diagnosis = "Bearing defect";
  } 
  else if (peakHz >= 18.0 && peakHz <= 35.0) {
    diagnosis = "Rotor imbalance";
  } 
  else if (peakHz >= 40.0 && peakHz <= 60.0) {
    diagnosis = "Normal running";
  } 
  else {
    diagnosis = "Unknown vibration";
  }
}

// =======================================================
// OLED Display
// =======================================================
void updateOLED(double peakHz) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);

  display.println("MotorGuard FFT");

  display.print("Mode:");
  display.println(modeName);

  display.print("Peak:");
  display.print(peakHz, 1);
  display.println("Hz");

  display.println("----------------");

  if (diagnosis == "Normal running") {
    display.println("[OK]");
  } 
  else {
    display.println("[FAULT]");
  }

  display.println(diagnosis);

  display.display();
}
