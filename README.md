# 🎓 Qasim Bilal — IoT & Embedded Systems Engineer in Progress

### From C/C++ Foundations → ESP32 Firmware → IoT Diagnostics → FFT Signal Analysis → TinyML Roadmap

> *Building intelligent embedded systems for smart infrastructure, predictive maintenance, and edge AI.*

![Status](https://img.shields.io/badge/Status-Actively%20Building-brightgreen)
![University](https://img.shields.io/badge/University-ETU%20LETI-blue)
![Focus](https://img.shields.io/badge/Focus-IoT%20%7C%20Embedded%20Systems%20%7C%20FFT%20%7C%20TinyML-orange)
![Platform](https://img.shields.io/badge/Platform-ESP32%20%7C%20Wokwi-lightgrey)

---

## 👤 About Me

I am a 5th-semester student at **SPbGETU "LETI"**, studying **Infocommunication Technologies and Communication Systems**.

My current technical focus is building a strong foundation in **C/C++ programming, embedded firmware, ESP32-based IoT systems, sensor integration, signal analysis, and TinyML-oriented predictive maintenance**.

This repository documents my step-by-step engineering journey: from basic programming fundamentals to a working embedded IoT motor fault-diagnosis prototype.

---

## 🧭 Learning Roadmap

| Phase | Focus Area | Status |
|------:|------------|:------:|
| ✅ Phase 1 | C programming foundations | Completed |
| ✅ Phase 2 | C++ OOP and sensor-fusion logic | Completed |
| ✅ Phase 3 | ESP32 embedded firmware simulation | Completed |
| ✅ Phase 4 | IoT node with OLED + Wi-Fi transmission | Completed |
| ✅ Phase 5A | FFT vibration analyzer | Completed |
| ✅ Phase 5B | FFT merged with DiagnosticEngine + IoT system | Completed |
| ⏳ Phase 6 | TinyML motor fault classification | Planned |

---

## 📚 Phase 1 — C Foundations

| Day | File | Topic |
|----:|------|-------|
| 1 | `hello.c` | Hello World, `printf()` |
| 2 | `day2_input.c` | Variables, input, `scanf()` |
| 3 | `day3_decisions.c` | `if/else`, `switch` |
| 4 | `day4_loops.c` | `for` loops |
| 5 | `day5_while.c` | `while` loops, grade calculator |
| 6 | `day6_functions.c` | Functions and scope |
| 7 | `day7_arrays.c` | Arrays and sorting |
| 8 | `day8_student_db.c` | Structs, pointers, file I/O |

---

## 🧱 Phase 2 — C++ and OOP

| Day | File | Concept |
|----:|------|---------|
| 9 | `day9_classes.cpp` | Classes and encapsulation |
| 10 | `day10_fault_detector.cpp` | Constructors and fault logic |
| 11 | `motorguard.cpp` | Inheritance and polymorphism |
| 12 | `motorguard_v2.cpp` | Sensor fusion and DiagnosticEngine |

---

# ⭐ Flagship Project — MotorGuard

**MotorGuard** is a progressive embedded systems project for **motor health monitoring and predictive maintenance**.

It began as a C++ simulation and evolved into a full ESP32-based IoT diagnostic node with:

- 🌡️ Temperature monitoring
- 📳 Vibration monitoring
- ⚡ Current monitoring
- 🔊 Acoustic monitoring
- 🧠 Rule-based DiagnosticEngine
- 🖥️ OLED display output
- 📡 Wi-Fi / HTTP IoT transmission
- 🔬 FFT-based vibration fault diagnosis
- 📊 Health score calculation
- 🚨 Multi-fault detection

🔗 **Live Wokwi Simulation:** [Run MotorGuard ESP32 Sensor Node](https://wokwi.com/projects/467254523497153537)

## 📁 Firmware Files

The ESP32 firmware developed for MotorGuard is organized inside the `firmware/` folder.

| File | Purpose |
|------|---------|
| `firmware/motorguard_fft_analyzer_stage5a.ino` | Standalone FFT vibration analyzer used to classify normal running, rotor imbalance, and bearing defect through dominant frequency detection. |
| `firmware/motorguard_stage5b_integrated.ino` | Full integrated MotorGuard firmware combining sensors, DiagnosticEngine, FFT analysis, OLED display, Wi-Fi connection, HTTP IoT transmission, health score, and multi-fault diagnosis. |

---

## 🧠 MotorGuard v1 — C++ Sensor Model

`motorguard.cpp` introduces the first object-oriented structure of the project.

### Key features

- Sensor classes for temperature, vibration, current, and acoustic channels
- Inheritance and polymorphism
- Clean OOP architecture for sensor-based systems
- Early fault-status output logic

---

## 🧠 MotorGuard v2 — DiagnosticEngine

`motorguard_v2.cpp` adds sensor-fusion logic through a dedicated **DiagnosticEngine**.

| Fault Type | Detection Rule |
|-----------|----------------|
| 🔩 Bearing defect | High vibration + abnormal acoustic signal |
| 🌀 Rotor imbalance | High vibration condition |
| ⚡ Electrical overload | High current and/or high temperature |
| 🌡️ Overheating | High temperature condition |
| 🚨 Abnormal current draw | Critical current level |

### Diagnostic output

- Specific fault name
- Health score from **0–100%**
- Maintenance recommendation
- Support for simultaneous faults

---

# 🔌 ESP32 MotorGuard IoT Node

A complete embedded IoT prototype built and tested in **Wokwi** using an **ESP32 DevKit**.

## Hardware / Simulation Components

| Component | Purpose | Pin / Interface |
|----------|---------|-----------------|
| ESP32 DevKit | Main microcontroller | — |
| DHT22 | Temperature sensor | GPIO 15 |
| Potentiometer | Vibration channel | GPIO 34 |
| Potentiometer | Current channel | GPIO 35 |
| Potentiometer | Acoustic channel | GPIO 32 |
| SSD1306 OLED | Live display | I2C: SDA 21, SCL 22 |
| Wi-Fi | IoT data transmission | `Wokwi-GUEST` |

---

## ⚙️ Embedded System Architecture

```text
Sensor Layer
   │
   ├── DHT22 temperature
   ├── Vibration channel
   ├── Current channel
   └── Acoustic channel

Processing Layer
   │
   ├── ESP32 firmware
   ├── DiagnosticEngine
   ├── FFT vibration analyzer
   └── Health score calculation

Output Layer
   │
   ├── OLED display
   ├── Serial Monitor
   └── HTTP IoT transmission
```

---

# ✅ Development Stages

## ✅ Stage 1 — Multi-Sensor Layer

The ESP32 reads all sensor channels in real time:

- 🌡️ Temperature from DHT22
- 📳 Vibration from analog input
- ⚡ Current from analog input
- 🔊 Acoustic level from analog input

**Result:** All four channels successfully produced live values in the Serial Monitor.

---

## ✅ Stage 2 — DiagnosticEngine on ESP32

The C++ DiagnosticEngine logic was transferred from desktop simulation to embedded firmware.

### Implemented diagnostic rules

| Condition | Diagnosis |
|----------|-----------|
| High vibration + acoustic signal | Bearing defect |
| High vibration only | Rotor imbalance |
| High temperature + high current | Electrical overload / winding stress |
| High temperature only | Overheating |
| High current only | Abnormal current draw |

**Verified result:** Multiple simultaneous faults were detected successfully.

Example output:

```text
[FAULT] Bearing defect
[FAULT] Electrical overload
Health: 20%
```

---

## ✅ Stage 3 — OLED Display Integration

An **SSD1306 128×64 OLED display** was added through I2C.

The display shows:

- Live sensor values
- Fault status
- Diagnostic result
- Health score

Example OLED output:

```text
MotorGuard v2
T:24C V:8.6
C:15.0A A:94
[FAULT] Bearing
Health: 20%
```

---

## ✅ Stage 4 — Wi-Fi / IoT Transmission

The ESP32 was connected to Wi-Fi using the Wokwi simulated network.

### Implemented features

- Wi-Fi connection through `Wokwi-GUEST`
- HTTP request generation
- Sensor data transmission
- Fault status transmission
- Health score transmission

**Verified IoT result:**

```text
WiFi: CONNECTED
IoT data sent. HTTP code: 200
```

---

# 🔬 Stage 5A — FFT Vibration Analyzer

Stage 5A introduced **frequency-domain vibration analysis** using FFT.

Instead of relying only on simple threshold values, the system now identifies vibration faults by detecting the dominant frequency component.

### FFT concept

```text
Time-domain vibration signal → FFT → Dominant frequency → Fault classification
```

### FFT test modes

| Mode | Injected Frequency | FFT Detected Frequency | Diagnosis | Status |
|------|-------------------:|-----------------------:|-----------|:------:|
| Normal running | 50.0 Hz | 49.9 Hz | Normal running | ✅ Verified |
| Rotor imbalance | 25.0 Hz | 24.8 Hz | Rotor imbalance | ✅ Verified |
| Bearing defect | 120.0 Hz | 120.4 Hz | Bearing defect | ✅ Verified |

**Result:** FFT analysis successfully classified all three vibration conditions.

---

# 🚀 Stage 5B — Full Integration

Stage 5B merged the FFT vibration analyzer with the complete MotorGuard IoT system.

## Integrated system includes

- 🌡️ DHT22 temperature sensing
- 📳 Vibration monitoring
- ⚡ Current monitoring
- 🔊 Acoustic monitoring
- 🧠 DiagnosticEngine
- 🔬 FFT vibration analysis
- 🖥️ OLED display
- 📡 Wi-Fi connection
- 🌐 HTTP IoT transmission
- 📊 Health score calculation
- 🚨 Multi-fault diagnosis

---

## ✅ Stage 5B Verified Results

### Normal condition

```text
FFT mode: NORMAL
Injected FFT frequency: 50.0 Hz
FFT dominant frequency: 49.9 Hz
FFT diagnosis: Normal running
Final diagnosis: OK
Health: 100%
WiFi: CONNECTED
IoT data sent. HTTP code: 200
```

### Rotor imbalance condition

```text
Vibration knob value: 2017
FFT mode: ROTOR IMBAL
Injected FFT frequency: 25.0 Hz
FFT dominant frequency: 24.8 Hz
FFT diagnosis: Rotor imbalance
Final diagnosis: Imbalance
Health: 70%
WiFi: CONNECTED
```

### Bearing defect condition

```text
FFT mode: BEARING
Injected FFT frequency: 120.0 Hz
FFT dominant frequency: 120.4 Hz
FFT diagnosis: Bearing defect
Final diagnosis: Bearing
Health: 45%
WiFi: CONNECTED
IoT data sent. HTTP code: 200
```

### Combined fault condition

```text
FFT dominant frequency: 120.4 Hz
FFT diagnosis: Bearing defect
Final diagnosis: Bearing+High current
Health: 0%
WiFi: CONNECTED
IoT data sent. HTTP code: 200
```

**Result:** Stage 5B successfully demonstrated a complete IoT predictive-maintenance node with FFT-based vibration diagnosis and multi-fault reporting.

---

# 🛠️ Skills Developed

| Area | Skills Practiced |
|------|------------------|
| C programming | Variables, loops, functions, arrays, structs, pointers, file I/O |
| C++ programming | Classes, constructors, inheritance, polymorphism, object-oriented design |
| Embedded firmware | ESP32, Arduino-style firmware, `setup()`, `loop()`, GPIO, ADC |
| Sensor systems | DHT22, analog channels, simulated vibration/current/acoustic signals |
| Display systems | SSD1306 OLED, I2C communication, embedded UI output |
| IoT communication | Wi-Fi connection, HTTP GET requests, sensor data transmission |
| Signal processing | FFT, frequency-domain diagnosis, dominant-frequency detection |
| Fault diagnosis | Threshold logic, sensor fusion, multi-fault classification |
| Tools | VS Code, g++, Git, GitHub, Wokwi, Serial Monitor |

---

# 🧪 Technical Highlights

- Built a complete ESP32 predictive-maintenance prototype in simulation
- Developed progressive C/C++ code from basics to embedded diagnostics
- Implemented multi-sensor fault detection logic
- Added live OLED monitoring
- Added Wi-Fi-based IoT transmission
- Added FFT-based vibration fault diagnosis
- Verified multi-fault condition: **Bearing defect + High current**
- Prepared foundation for future TinyML classification

---

# 🧭 Research Roadmap

## ✅ Current Focus — Embedded IoT Fault Diagnosis

MotorGuard now demonstrates a full embedded diagnostic workflow:

```text
Sensors → ESP32 → DiagnosticEngine → FFT → OLED → Wi-Fi → IoT reporting
```

## ⏳ Next Step — TinyML Edge Fault Classification

The next technical direction is to move from rule-based diagnosis toward machine-learning-based classification.

### Planned direction

- Collect vibration/fault data
- Extract FFT features
- Train a small ML model
- Convert model to TensorFlow Lite Micro
- Deploy inference on ESP32 or STM32
- Compare rule-based vs TinyML diagnosis

---

# 📊 Progress Tracker

| Semester | Focus | Status |
|---------:|-------|:------:|
| 5th semester | C/C++, ESP32 firmware, IoT, FFT analysis | ✅ Active / Completed milestones |
| 6th semester | Real ESP32 hardware, MQTT, cloud dashboard, STM32 basics | ⏳ Planned |
| 7th semester | TinyML fault classification and research paper preparation | ⏳ Planned |
| 8th semester | Final-year embedded AI / smart infrastructure project | ⏳ Planned |

---

# 🎯 Vision

My long-term goal is to contribute to **intelligent embedded systems for smart energy infrastructure and predictive maintenance**, where sensors, real-time diagnostics, signal processing, and edge AI make industrial systems safer, smarter, and more reliable.

> *MotorGuard is my foundation project toward embedded AI, smart infrastructure, and industrial predictive maintenance.*

— **Qasim Bilal**  
ETU "LETI" | Infocommunication Technologies and Communication Systems | 2026
