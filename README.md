# 🎓 Qasim Bilal — IoT & Embedded Systems Engineer in Progress

### 🚀 From LabVIEW & Mathcad → C/C++ → ESP32 Firmware → FFT Signal Analysis → TinyML | ETU "LETI" 2026–2028

> *"Building intelligent systems for smart infrastructure and a smarter future."*

![Status](https://img.shields.io/badge/Status-Actively%20Learning-brightgreen)
![University](https://img.shields.io/badge/University-ETU%20LETI-blue)
![Focus](https://img.shields.io/badge/Focus-IoT%20%7C%20Embedded%20%7C%20TinyML-orange)

---

## 👤 About Me

🎓 5th-semester student at SPbGETU "LETI" (Infocommunication Technologies & Communication Systems).  
⚙️ Self-driven learner building a strong foundation in embedded systems and IoT from the ground up — through daily practice, real projects, and hands-on hardware simulation.  
🔬 Current focus: ESP32 firmware, predictive maintenance, signal analysis, and future TinyML fault detection.

---

## 📚 Learning Journey

### 🧱 Phase 1 — C Foundations (Days 1–8)

| 🔢 Day | 📁 File | 🧠 Topic |
|-------|---------|----------|
| ✅ 1 | `hello.c` | Hello World, `printf` |
| ✅ 2 | `day2_input.c` | Variables, `scanf` |
| ✅ 3 | `day3_decisions.c` | If/else, switch |
| ✅ 4 | `day4_loops.c` | For loops |
| ✅ 5 | `day5_while.c` | While loops, grade calculator |
| ✅ 6 | `day6_functions.c` | Functions, scope |
| ✅ 7 | `day7_arrays.c` | Arrays, sorting |
| ✅ 8 | `day8_student_db.c` | Structs, pointers, file I/O |

### 🧩 Phase 2 — C++ & OOP (Days 9–12)

| 🔢 Day | 📁 File | 🧠 Topic |
|-------|---------|----------|
| ✅ 9 | `day9_classes.cpp` | Classes, encapsulation |
| ✅ 10 | `day10_fault_detector.cpp` | Constructors, TinyML-style logic |
| ✅ 11 | `motorguard.cpp` | Inheritance, polymorphism |
| ✅ 12 | `motorguard_v2.cpp` | Sensor fusion, DiagnosticEngine |

### 🔌 Phase 3 — Embedded IoT & Signal Analysis

| 🚦 Stage | 📁 File / Platform | 🧠 Topic | 📌 Status |
|---------|--------------------|----------|-----------|
| ✅ 1–4 | Wokwi ESP32 project | Multi-sensor IoT node, OLED display, Wi-Fi/HTTP | Complete |
| ✅ 5A | `motorguard_fft_analyzer.ino` | FFT vibration diagnosis, dominant-frequency fault detection | Complete |
| ⏳ 5B | Future integration | Merge FFT with full DiagnosticEngine + IoT system | Planned |

---

## ⭐ Flagship Project — MotorGuard

⚙️ **MotorGuard** is a multi-sensor motor health monitoring and fault diagnosis system, built progressively from C/C++ learning to ESP32 embedded firmware and FFT-based vibration analysis.

### 🧪 Version 1 — C++ Simulation (`motorguard.cpp`)

✅ Four sensor classes were implemented using object-oriented programming:

- 🌡️ Temperature sensor
- 📳 Vibration sensor
- ⚡ Current sensor
- 🔊 Acoustic sensor

🧠 This version demonstrates inheritance, polymorphism, and modular sensor-based architecture.

### 🧠 Version 2 — Full Diagnostic System (`motorguard_v2.cpp`)

A `DiagnosticEngine` fuses all four sensor signals to detect specific motor faults.

| 🚨 Fault | 🧾 Detection rule |
|----------|------------------|
| 🛞 Bearing defect | High vibration + abnormal acoustic |
| 🌀 Rotor imbalance | High vibration alone |
| ⚡ Electrical overload | High temperature + high current |
| 🔥 Overheating | High temperature alone |
| 📈 Abnormal current draw | High current alone |

📊 The system outputs a health score from **0–100%** and gives a maintenance recommendation.

---

## 🔌 Embedded IoT Node — ESP32 MotorGuard

**A complete IoT predictive-maintenance node — built in 5 stages from C++ simulation to a connected signal-analysis device.**

🧪 Built and tested on **Wokwi ESP32 simulator**.

### ✅ Stage 1 — Multi-Sensor Layer

- 🌡️ **DHT22** — live temperature sensor on pin 15
- 📳 **Potentiometer** — vibration channel on pin 34
- ⚡ **Potentiometer** — current channel on pin 35
- 🔊 **Potentiometer** — acoustic channel on pin 32

### ✅ Stage 2 — Diagnostic Engine

🧠 Full sensor-fusion fault detection running on the ESP32 microcontroller.

Detected conditions:

- 🛞 Bearing defect
- 🌀 Rotor imbalance
- ⚡ Electrical overload
- 🔥 Overheating
- 📉 Health degradation

📊 Multiple simultaneous faults can be diagnosed independently with live health scoring.

### ✅ Stage 3 — OLED Display

🖥️ Added **128×64 SSD1306 OLED display** using I2C communication.

| 🧩 OLED Detail | 📌 Value |
|---------------|----------|
| Display type | SSD1306 OLED |
| Communication | I2C |
| SDA pin | GPIO21 |
| SCL pin | GPIO22 |
| Output | Live readings, fault status, health score |

### ✅ Stage 4 — Wi-Fi / IoT Transmission

🌐 ESP32 connects to Wi-Fi and transmits sensor data and fault diagnosis over HTTP.

Confirmed output:

```text
Data sent! HTTP code: 200
```

✅ This confirms the node is not only reading and diagnosing faults, but also transmitting data as a real IoT device.

### ✅ Stage 5A — FFT Vibration Analyzer

🔬 A dedicated FFT-based vibration diagnosis layer was added using the `arduinoFFT` library.

⚙️ Working principle:

- 📳 Potentiometer on GPIO34 selects the vibration fault mode
- 🧮 ESP32 generates simulated vibration signals
- 📈 FFT extracts the dominant frequency
- 🧠 The system classifies the motor condition from the frequency peak
- 🖥️ OLED displays the diagnosis live

| 🧪 Test mode | 🎯 Injected frequency | 📈 FFT detected frequency | 🧠 Diagnosis | 📌 Result |
|-------------|----------------------|---------------------------|--------------|-----------|
| ✅ Normal running | 50.0 Hz | 49.9 Hz | Normal running | Passed |
| ✅ Rotor imbalance | 25.0 Hz | 24.8 Hz | Rotor imbalance | Passed |
| ✅ Bearing defect | 120.0 Hz | 120.4 Hz | Bearing defect | Passed |

🚀 This stage moves MotorGuard beyond simple threshold checking into **frequency-domain fault diagnosis**, which is a major step toward real predictive maintenance and TinyML-based fault classification.

---

## 🧭 System Architecture

```text
🌡️ Temperature Sensor
📳 Vibration Channel
⚡ Current Channel
🔊 Acoustic Channel
        ↓
🔌 ESP32 Firmware
        ↓
🧠 DiagnosticEngine
        ↓
📊 Health Score + Fault Classification
        ↓
🖥️ OLED Display + 🌐 Wi-Fi HTTP Transmission
        ↓
🔬 FFT Vibration Diagnosis
        ↓
🤖 Future TinyML Fault Classification
```

🔗 **[▶ Run the live simulation on Wokwi](https://wokwi.com/projects/467254523497153537)**

---

## 🛠️ Skills Developed

| 🧠 Area | 📌 Current level |
|--------|------------------|
| 💻 C programming | Structs, pointers, file I/O, functions |
| 🧩 C++ OOP | Classes, inheritance, polymorphism, virtual functions |
| 🔌 Embedded firmware | ESP32, `setup()`, `loop()`, I2C OLED, Wi-Fi/HTTP, multi-sensor logic |
| 📡 Sensor integration | DHT22, analog potentiometers, multi-sensor fusion |
| 🧠 Fault detection logic | Threshold-based rules, sensor fusion, health scoring |
| 🔬 Signal processing | FFT, dominant-frequency detection, vibration fault analysis |
| 🌐 IoT communication | Wi-Fi connection, HTTP data transmission, cloud-ready architecture |
| 🧰 Tools | VS Code, g++, Git, GitHub, Wokwi, arduinoFFT |

---

## 🚀 Research Roadmap

### 🔋 Phase 1 — ESP32 IoT Energy Monitor *(in progress)*

⚙️ Real hardware, real sensors, MQTT data transmission, and cloud dashboard development.

### 🏭 Phase 2 — STM32 Industrial Sensor Network

🔧 Industrial protocols, multi-node sensor systems, and real-time data pipelines.

### 🤖 Phase 3 — TinyML Edge Fault Detection

🧠 On-device ML models for motor fault classification.

Direct connection to current MotorGuard work:

```text
FFT signal analysis → feature extraction → TinyML inference → motor fault classification
```

> ⚡ MotorGuard is an early prototype of Phase 3 thinking: multi-sensor fusion, specific fault diagnosis, health scoring, OLED monitoring, Wi-Fi transmission, and FFT vibration analysis — the conceptual foundation before adding TinyML layers.

---

## 📊 Progress Tracker

| 🎓 Semester | 🎯 Focus | 📌 Status |
|------------|----------|-----------|
| 🔥 5th semester | C/C++ foundations + ESP32 firmware + FFT analysis | In progress |
| ⏳ 6th semester | ESP32 IoT + STM32 basics | Planned |
| ⏳ 7th–8th semester | TinyML + IEEE papers | Planned |

---

## 🏁 Project Milestones

| ✅ Milestone | 🧾 Description | 📌 Status |
|-------------|----------------|-----------|
| ✅ C foundations | Days 1–8 completed | Done |
| ✅ C++ OOP | Days 9–12 completed | Done |
| ✅ MotorGuard v1 | OOP sensor simulation | Done |
| ✅ MotorGuard v2 | DiagnosticEngine + sensor fusion | Done |
| ✅ ESP32 Stage 1 | All sensors reading live | Done |
| ✅ ESP32 Stage 2 | Fault diagnosis on microcontroller | Done |
| ✅ ESP32 Stage 3 | OLED display added | Done |
| ✅ ESP32 Stage 4 | Wi-Fi / HTTP IoT transmission | Done |
| ✅ ESP32 Stage 5A | FFT vibration diagnosis completed | Done |
| ⏳ ESP32 Stage 5B | Merge FFT with full IoT DiagnosticEngine | Planned |
| ⏳ Future Stage | TinyML model inference on microcontroller | Planned |

---

## 🎯 Vision

> **To design intelligent embedded systems that connect the world and protect smart energy infrastructure.**

🌍 My long-term goal is to contribute to intelligent embedded systems for smart energy infrastructure and predictive maintenance — where sensors, edge AI, and real-time diagnostics make industrial systems safer, smarter, and more efficient.

---

## ✍️ Signature

**Qasim Bilal**  
🎓 ETU "LETI" — Infocommunication Technologies & Communication Systems  
🔌 IoT & Embedded Systems Engineer in Progress  
🚀 Focus: ESP32, C/C++, Signal Analysis, TinyML, Predictive Maintenance  
📍 2026
