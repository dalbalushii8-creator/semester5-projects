# 🎓 Qasim Bilal — IoT & Embedded Systems Engineer in Progress

### From LabVIEW & Mathcad → C/C++ → ESP32 firmware → TinyML | ETU "LETI" 2026–2028

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

## 🔌 Embedded Prototype — ESP32 Sensor Node

**Taking MotorGuard from C++ simulation to real embedded firmware.**

Built and tested on Wokwi (ESP32 simulator):

- 🌡️ DHT22 — live temperature readings (pin 15)
- 📳 Potentiometer — vibration simulation (pin 34)
- ⚡ Potentiometer — current simulation (pin 35)
- 🔊 Potentiometer — acoustic simulation (pin 32)
- ⚙️ Full DiagnosticEngine running on the microcontroller
- 🔴 Real-time fault detection — bearing defect, rotor imbalance, electrical overload, overheating
- 📊 Health score calculated live from sensor fusion
- 🔁 Embedded `setup()` + `loop()` architecture (Arduino/ESP-IDF style)

**Verified output (Stage 2 complete):**
```
T:24.0C  V:8.6  C:15.0A  A:94.4dB
[FAULT] Bearing defect (high vib + acoustic)
[FAULT] Electrical overload (abnormal current)
Health: 20%
```

🔗 **[▶ Run the live simulation on Wokwi](https://wokwi.com/projects/467254523497153537)**

---

## 🛠️ Skills Developed

| Area | Current level |
|------|--------------|
| C programming | Structs, pointers, file I/O, functions |
| C++ OOP | Classes, inheritance, polymorphism, virtual functions |
| Embedded firmware | ESP32, setup/loop, analogRead, Serial, DHT22 |
| Sensor integration | DHT22, analog potentiometers, multi-sensor fusion |
| Fault detection logic | Threshold-based, multi-signal fusion rules |
| Tools | VS Code, g++, Git, GitHub, Wokwi |

---

## 🚀 Research Roadmap

### Phase 1 — ESP32 IoT Energy Monitor *(in progress)*
Real hardware, real sensors, MQTT data transmission, cloud dashboard.

### Phase 2 — STM32 Industrial Sensor Network
Industrial protocols, multi-node systems, real-time data pipelines.

### Phase 3 — TinyML Edge Fault Detection
On-device ML models for motor fault classification. Direct connection to current MotorGuard work — FFT signal analysis → neural network inference on the microcontroller.

> MotorGuard is an early prototype of Phase 3 thinking: multi-sensor fusion, specific fault diagnosis, health scoring — the conceptual foundation before adding FFT and ML layers.

---

## 📊 Progress Tracker

| Semester | Focus | Status |
|----------|-------|--------|
| 5th (current) | C/C++ foundations + ESP32 firmware | 🔥 In progress |
| 6th | ESP32 IoT + STM32 basics | ⏳ Planned |
| 7th–8th | TinyML + IEEE papers | ⏳ Planned |

---

## 🎯 Vision

To contribute to intelligent embedded systems for smart energy infrastructure and predictive maintenance — where sensors, edge AI, and real-time diagnostics make industrial systems safer and more efficient.
