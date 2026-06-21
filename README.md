# 🎓 Qasim Bilal — IoT & Embedded Systems Engineer in Progress

### From LabVIEW & Mathcad → C/C++ → ESP32 firmware → FFT signal analysis → TinyML | ETU "LETI" 2026–2028

> *"Building intelligent systems for smart infrastructure and a smarter future."*

![Status](https://img.shields.io/badge/Status-Actively%20Learning-brightgreen)
![University](https://img.shields.io/badge/University-ETU%20LETI-blue)
![Focus](https://img.shields.io/badge/Focus-IoT%20%7C%20Embedded%20%7C%20TinyML-orange)

---

## 👤 About Me

5th-semester student at SPbGETU "LETI" (Infocommunication Technologies & Communication Systems).
Self-driven learner building a foundation in embedded systems and IoT from the ground up — through daily practice, real projects, and hands-on hardware simulation.

---

## 📚 Learning Journey

### Phase 1 — C Foundations (Days 1–8)

| Day | File | Topic |
|-----|------|-------|
| 1 | `hello.c` | Hello World, printf |
| 2 | `day2_input.c` | Variables, scanf |
| 3 | `day3_decisions.c` | If/else, switch |
| 4 | `day4_loops.c` | For loops |
| 5 | `day5_while.c` | While loops, grade calculator |
| 6 | `day6_functions.c` | Functions, scope |
| 7 | `day7_arrays.c` | Arrays, sorting |
| 8 | `day8_student_db.c` | Structs, pointers, file I/O |

### Phase 2 — C++ & OOP (Days 9–12)

| Day | File | Topic |
|-----|------|-------|
| 9 | `day9_classes.cpp` | Classes, encapsulation |
| 10 | `day10_fault_detector.cpp` | Constructors, TinyML-style logic |
| 11 | `motorguard.cpp` | Inheritance, polymorphism |
| 12 | `motorguard_v2.cpp` | Sensor fusion, DiagnosticEngine |

### Phase 3 — Embedded IoT & Signal Analysis

| Stage | File / Platform | Topic |
|-------|-----------------|-------|
| 1–4 | Wokwi ESP32 project | Multi-sensor IoT node, OLED, Wi-Fi/HTTP |
| 5A | `motorguard_fft_analyzer.ino` | FFT vibration diagnosis, dominant-frequency fault detection |

---

## ⭐ Flagship Project — MotorGuard

A multi-sensor motor health monitoring and fault diagnosis system, built progressively from C++ simulation to real ESP32 embedded firmware.

### Version 1 — C++ Simulation (`motorguard.cpp`)
Four sensor classes (Temperature, Vibration, Current, Acoustic) built with inheritance and polymorphism. Demonstrates OOP architecture for sensor-based systems.

### Version 2 — Full Diagnostic System (`motorguard_v2.cpp`)
A `DiagnosticEngine` that fuses all four sensor signals to detect specific faults:

| Fault | Detection rule |
|-------|---------------|
| Bearing defect | High vibration + abnormal acoustic |
| Rotor imbalance | High vibration alone |
| Electrical overload | High temperature + high current |
| Overheating | High temperature alone |
| Abnormal current draw | High current alone |

Outputs a health score (0–100%) and maintenance recommendation.

---

## 🔌 Embedded IoT Node — ESP32 MotorGuard

**A complete IoT predictive-maintenance node — built in 4 stages from C++ simulation to a connected device.**

Built and tested on Wokwi (ESP32 simulator):

### Stage 1 — Multi-sensor layer
- 🌡️ DHT22 — live temperature (pin 15)
- 📳 Potentiometer — vibration (pin 34)
- ⚡ Potentiometer — current (pin 35)
- 🔊 Potentiometer — acoustic (pin 32)

### Stage 2 — Diagnostic Engine
Full sensor-fusion fault detection running on the microcontroller — detects bearing defect, rotor imbalance, electrical overload, and overheating, with a live health score (0–100%). Multiple simultaneous faults are diagnosed independently.

### Stage 3 — OLED Display
128×64 SSD1306 OLED (I2C, pins 21/22) showing live readings, fault status, and health score — a real industrial-style monitor.

### Stage 4 — Wi-Fi / IoT
ESP32 connects to Wi-Fi and transmits sensor data and diagnosis over HTTP — turning the node into a true connected IoT device (HTTP 200 confirmed).

### Stage 5A — FFT Vibration Analyzer
A dedicated FFT-based vibration diagnosis layer was added using the `arduinoFFT` library.  
The potentiometer on GPIO34 is used as a fault-mode selector, while the ESP32 generates simulated vibration signals and applies FFT to detect the dominant frequency.

| Test mode | Injected frequency | FFT detected frequency | Diagnosis |
|-----------|--------------------|------------------------|-----------|
| Normal running | 50.0 Hz | 49.9 Hz | Normal running |
| Rotor imbalance | 25.0 Hz | 24.8 Hz | Rotor imbalance |
| Bearing defect | 120.0 Hz | 120.4 Hz | Bearing defect |

This stage moves MotorGuard beyond simple threshold checking into real signal-processing-based fault diagnosis.

**Architecture:** 4 sensors → ESP32 (`setup()`/`loop()`) → DiagnosticEngine → OLED + Wi-Fi cloud transmission → FFT vibration diagnosis.

This mirrors real sensor-based predictive-maintenance systems for electrical machines — the foundation for adding TinyML inference (Phase 3).

🔗 **[▶ Run the live simulation on Wokwi](https://wokwi.com/projects/467254523497153537)**

---

## 🛠️ Skills Developed

| Area | Current level |
|------|--------------|
| C programming | Structs, pointers, file I/O, functions |
| C++ OOP | Classes, inheritance, polymorphism, virtual functions |
| Embedded firmware | ESP32, setup/loop, I2C OLED, Wi-Fi/HTTP, multi-sensor, FFT analyzer |
| Sensor integration | DHT22, analog potentiometers, multi-sensor fusion |
| Fault detection logic | Threshold-based, multi-signal fusion rules, FFT dominant-frequency diagnosis |
| Tools | VS Code, g++, Git, GitHub, Wokwi, arduinoFFT |

---

## 🚀 Research Roadmap

### Phase 1 — ESP32 IoT Energy Monitor *(in progress)*
Real hardware, real sensors, MQTT data transmission, cloud dashboard.

### Phase 2 — STM32 Industrial Sensor Network
Industrial protocols, multi-node systems, real-time data pipelines.

### Phase 3 — TinyML Edge Fault Detection
On-device ML models for motor fault classification. Direct connection to current MotorGuard work — FFT signal analysis is now implemented as Stage 5A, preparing the project for neural network inference on the microcontroller.

> MotorGuard is an early prototype of Phase 3 thinking: multi-sensor fusion, specific fault diagnosis, health scoring, Wi-Fi transmission, OLED monitoring, and FFT vibration analysis — the conceptual foundation before adding TinyML layers.

---

## 📊 Progress Tracker

| Semester | Focus | Status |
|----------|-------|--------|
| 5th (current) | C/C++ foundations + ESP32 firmware + FFT analysis | 🔥 In progress |
| 6th | ESP32 IoT + STM32 basics | ⏳ Planned |
| 7th–8th | TinyML + IEEE papers | ⏳ Planned |

---

## 🎯 Vision

To contribute to intelligent embedded systems for smart energy infrastructure and predictive maintenance — where sensors, edge AI, and real-time diagnostics make industrial systems safer and more efficient.
