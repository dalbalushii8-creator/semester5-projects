# 🎓 Qasim Bilal — IoT & Embedded Systems Engineer in Progress
### From LabVIEW & Mathcad → ESP32 → STM32 → TinyML | ETU "LETI" 2026–2028

> *"Building intelligent systems for smart infrastructure and a smarter future."*

![Status](https://img.shields.io/badge/Status-Actively%20Learning-brightgreen)
![University](https://img.shields.io/badge/University-ETU%20LETI-blue)
![Program](https://img.shields.io/badge/Program-ICTS%2011.03.02-orange)
![Language](https://img.shields.io/badge/Russian%20Level-C1-red)
![Portfolio](https://img.shields.io/badge/Portfolio-Growing%20Daily-yellow)

---

## 👤 About Me

I am **Qasim Bilal** — an international student at ETU "LETI" studying Information and Communication Technologies (ICTS 11.03.02) entirely in **Russian (C1 proficiency)**.

I am passionate about embedded systems, IoT, and intelligent energy infrastructure. I am building a research career from the ground up — one program, one paper, one project at a time.

📧 dalbalushii8@gmail.com
🏛️ Saint Petersburg Electrotechnical University "LETI"
📅 2026 → 2028

---

## 📚 What I Did in Previous Semesters

| Semester | Project | Tool | Result |
|---|---|---|---|
| 2nd | Software Development Coursework | Visual Studio Code | ✅ Completed |
| 3rd | Phone Book Application | C / OOP | ✅ Completed |
| 3rd | Oscilloscope Simulation | LabVIEW | ✅ Completed |
| 3rd | Mathematical Modeling & Analysis | Mathcad | ✅ Completed |
| All | Internship Project | — | ✅ Grade: Good |

---

## 💻 Current — 5th Semester (2026)

**Learning C & C++ foundations — one program per day, building toward embedded systems.**

### Phase 1 — C Programming Foundations ✅

| Day | Program | Concept Learned | Status |
|---|---|---|---|
| Day 1 | `hello.c` | Basic output, printf, main function | ✅ Done |
| Day 2 | `day2_input.c` | Variables, user input, scanf | ✅ Done |
| Day 3 | `day3_decisions.c` | If/Else decisions | ✅ Done |
| Day 4 | `day4_loops.c` | For loops — multiplication table | ✅ Done |
| Day 5 | `day5_while.c` | While loops — grade average calculator | ✅ Done |
| Day 6 | `day6_functions.c` | Functions — simple calculator | ✅ Done |
| Day 7 | `day7_arrays.c` | Arrays — student grade tracker | ✅ Done |
| Day 8 | `day8_student_db.c` | Structs, Pointers, File I/O — Student Database | ✅ Done |

### Phase 2 — C++ & Object-Oriented Programming ✅

| Day | Program | Concept Learned | Status |
|---|---|---|---|
| Day 9 | `day9_classes.cpp` | Classes, objects, methods | ✅ Done |
| Day 10 | `day10_fault_detector.cpp` | Constructors — TinyML-style fault detector | ✅ Done |
| Day 11 | `motorguard.cpp` | Inheritance & polymorphism — multi-sensor system | ✅ Done |
| Day 12 | `motorguard_v2.cpp` | **Final Project — MotorGuard diagnostic engine** | ✅ Done |

### 🏆 12-Day C & C++ Journey Complete!

---

## ⭐ Flagship Project — MotorGuard

**An Embedded Motor Fault Diagnostic System** (`motorguard_v2.cpp`)

A C++ system that simulates a real predictive-maintenance node — exactly the kind used in industrial motor health monitoring.

**How it works:**
- 📡 Reads four sensors: **temperature, vibration, current, and acoustic**
- 🧠 A `DiagnosticEngine` **fuses** all signals to detect *specific* faults:
  - Bearing defect (vibration + abnormal noise)
  - Rotor imbalance (high vibration)
  - Overheating (cooling / load issue)
  - Electrical overload / winding stress (temperature + current)
- 📊 Computes a **health score (0–100%)** and a **maintenance recommendation**
- 🎛️ Runs in **auto-demo** and **manual input** modes

**Built using everything from the 12-day journey:**

| Concept | Where it's used |
|---|---|
| Variables & I/O | Sensor data, user input |
| If/Else logic | Fault diagnosis rules |
| Loops | Menu system, sensor scanning |
| Functions | `runDiagnostics()` |
| Arrays / Vectors | `vector<Sensor*>` |
| Structs → Classes | Sensor & engine classes |
| Pointers | Base-class pointers, memory management |
| Constructors | Sensor initialization |
| **Inheritance** | 4 sensor types from 1 base class |
| **Polymorphism** | One loop handles all sensor types |

---

## 🛠️ Skills Learned

| Concept | Description |
|---|---|
| `printf` / `scanf` / `cout` / `cin` | Input & output operations |
| Variables & Data Types | int, float, char, string |
| Control Flow | If/Else, for, while loops |
| Functions | Code organization & reuse |
| Arrays & Vectors | Storing multiple values |
| Structs | Custom data types |
| Pointers | Memory management |
| File I/O | Saving data to files |
| Classes & Objects | Object-oriented design |
| Constructors | Object initialization |
| Inheritance | Code reuse across classes |
| Polymorphism | Flexible, scalable design |

---

## 🚀 What I Am Building Next (2026–2028)

### 🌐 Phase 1 — 6th Semester (2027)
**IoT-Based Smart Energy Monitoring System**
- ESP32 microcontroller + PZEM-004T energy sensors
- MQTT communication protocol over Wi-Fi
- Python Dash real-time dashboard + InfluxDB storage
- 📄 **Research Paper #1** → IEEE Conference 2027

### 🏭 Phase 2 — 7th Semester (2027–2028)
**Industrial Sensor Network — MQTT Performance Analysis**
- STM32F407 industrial nodes
- Modbus RTU + CAN Bus protocols
- 50-node MQTT performance testbed
- 📄 **Research Paper #2** → IEEE Journal 2028

### 🤖 Phase 3 — 8th Semester (2028)
**Edge-Based Fault Detection Using TinyML**
- Raspberry Pi 4 edge gateway
- TensorFlow Lite neural network
- Real-time motor fault classification — no cloud needed
- 📄 **Research Paper #3** → IEEE Conference + Final Thesis 2028

> 💡 *MotorGuard is an early prototype of the thinking behind Phase 3 — multi-sensor fusion for motor fault detection.*

---

## 🏗️ Target System Architecture

```
SENSORS ──→ MCU ──→ COMMUNICATION ──→ GATEWAY ──→ AI/ML ──→ DASHBOARD
PZEM-004T   ESP32   MQTT / Wi-Fi      RPi 4       TinyML    Python Dash
DHT22       STM32   Modbus / CAN                  TFLite    Grafana
```

---

## 🧰 Technology Stack

| Category | Current | Future |
|---|---|---|
| Programming | C, C++ | Python, ESP-IDF |
| Embedded | Learning | ESP32, STM32, Raspberry Pi |
| Communication | — | MQTT, Modbus, CAN Bus, Wi-Fi |
| AI / ML | — | TinyML, TensorFlow Lite |
| Tools | VS Code, Git, GCC, g++, LabVIEW, Mathcad | Linux, FreeRTOS |
| OS | Windows | Embedded Linux |

---

## 📊 Research Goals by Graduation 2028

- 📄 3 IEEE Research Papers Published
- 🔧 3 Major Hardware Projects Deployed
- 🎓 Final Year Thesis Defended
- 💼 Industry-Ready Embedded Engineer
- 🌍 Strong International GitHub Portfolio

---

## 📈 Progress Tracker

```
5th Semester  ████████████  C & C++ Foundations ✅ COMPLETE
6th Semester  ░░░░░░░░░░░░  ESP32 + IoT + Paper #1
7th Semester  ░░░░░░░░░░░░  STM32 + Industrial + Paper #2
8th Semester  ░░░░░░░░░░░░  TinyML + Edge AI + Paper #3
```

---

## 🌟 Vision

> *"To design intelligent, reliable and sustainable systems that*
> *connect the world and improve lives — starting with*
> *smart energy infrastructure."*
> — Qasim Bilal, ETU "LETI", 2026

---

*⭐ Follow this repository to watch the journey from first C program to published IoT researcher!*
