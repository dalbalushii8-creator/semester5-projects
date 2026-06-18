#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// ============================================================
//  MotorGuard v2 - Complete Motor Fault Diagnostic System
//  Day 12: Final Project - Multi-sensor fusion & diagnosis
// ============================================================

// ----- BASE SENSOR CLASS -----
class Sensor {
    protected:
        string location;
        float value;
        string unit;

    public:
        Sensor(string loc, float val, string u) {
            location = loc;
            value = val;
            unit = u;
        }

        virtual string getType() { return "Generic"; }

        virtual int riskLevel() { return 0; }

        void report() {
            string status;
            int r = riskLevel();
            if (r == 0) status = "OK";
            else if (r == 1) status = "WARNING";
            else status = "CRITICAL";

            cout << left << setw(14) << getType()
                 << setw(10) << location
                 << right << setw(8) << fixed << setprecision(1) << value
                 << " " << setw(4) << unit
                 << "   [" << status << "]" << endl;
        }

        float getValue() { return value; }
        void setValue(float v) { value = v; }
};

// ----- CHILD 1: Temperature -----
class TemperatureSensor : public Sensor {
    public:
        TemperatureSensor(string loc, float val) : Sensor(loc, val, "C") {}
        string getType() override { return "Temperature"; }
        int riskLevel() override {
            if (value > 90) return 2;
            if (value > 70) return 1;
            return 0;
        }
};

// ----- CHILD 2: Vibration -----
class VibrationSensor : public Sensor {
    public:
        VibrationSensor(string loc, float val) : Sensor(loc, val, "mm/s") {}
        string getType() override { return "Vibration"; }
        int riskLevel() override {
            if (value > 7.0) return 2;
            if (value > 4.5) return 1;
            return 0;
        }
};

// ----- CHILD 3: Current -----
class CurrentSensor : public Sensor {
    public:
        CurrentSensor(string loc, float val) : Sensor(loc, val, "A") {}
        string getType() override { return "Current"; }
        int riskLevel() override {
            if (value > 12.0) return 2;
            if (value > 9.0) return 1;
            return 0;
        }
};

// ----- CHILD 4: Acoustic -----
class AcousticSensor : public Sensor {
    public:
        AcousticSensor(string loc, float val) : Sensor(loc, val, "dB") {}
        string getType() override { return "Acoustic"; }
        int riskLevel() override {
            if (value > 85) return 2;
            if (value > 75) return 1;
            return 0;
        }
};

// ============================================================
//  DIAGNOSTIC ENGINE - fuses all sensors to find faults
// ============================================================
class DiagnosticEngine {
    private:
        TemperatureSensor* temp;
        VibrationSensor* vib;
        CurrentSensor* curr;
        AcousticSensor* acou;

    public:
        DiagnosticEngine(TemperatureSensor* t, VibrationSensor* v,
                         CurrentSensor* c, AcousticSensor* a) {
            temp = t;
            vib = v;
            curr = c;
            acou = a;
        }

        int healthScore() {
            int score = 100;
            score -= temp->riskLevel() * 15;
            score -= vib->riskLevel()  * 15;
            score -= curr->riskLevel() * 15;
            score -= acou->riskLevel() * 10;
            if (score < 0) score = 0;
            return score;
        }

        void diagnose() {
            cout << "\n=== DIAGNOSTIC ANALYSIS ===\n";
            bool faultFound = false;

            if (vib->riskLevel() >= 2 && acou->riskLevel() >= 1) {
                cout << "[FAULT] Bearing defect suspected ";
                cout << "(high vibration + abnormal noise)\n";
                faultFound = true;
            }
            else if (vib->riskLevel() >= 2) {
                cout << "[FAULT] Rotor imbalance suspected ";
                cout << "(high vibration)\n";
                faultFound = true;
            }

            if (temp->riskLevel() >= 2 && curr->riskLevel() >= 1) {
                cout << "[FAULT] Electrical overload / winding stress ";
                cout << "(high temp + high current)\n";
                faultFound = true;
            }
            else if (temp->riskLevel() >= 2) {
                cout << "[FAULT] Overheating detected ";
                cout << "(cooling or load issue)\n";
                faultFound = true;
            }

            if (curr->riskLevel() >= 2 && temp->riskLevel() < 2) {
                cout << "[FAULT] Electrical overload ";
                cout << "(abnormal current draw)\n";
                faultFound = true;
            }

            if (!faultFound) {
                cout << "[OK] No specific fault detected.\n";
            }
        }

        void recommend() {
            int h = healthScore();
            cout << "\n=== HEALTH & RECOMMENDATION ===\n";
            cout << "Motor health score: " << h << "%\n";

            if (h >= 85)
                cout << "Status: HEALTHY - continue normal operation.\n";
            else if (h >= 60)
                cout << "Status: MONITOR - schedule inspection soon.\n";
            else if (h >= 35)
                cout << "Status: DEGRADED - maintenance required.\n";
            else
                cout << "Status: CRITICAL - STOP motor, urgent repair!\n";
        }
};

// ============================================================
//  HELPER - run one full diagnostic cycle
// ============================================================
void runDiagnostics(TemperatureSensor* t, VibrationSensor* v,
                    CurrentSensor* c, AcousticSensor* a) {
    vector<Sensor*> sensors;
    sensors.push_back(t);
    sensors.push_back(v);
    sensors.push_back(c);
    sensors.push_back(a);

    cout << "\n" << left << setw(14) << "SENSOR"
         << setw(10) << "LOCATION"
         << right << setw(8) << "VALUE"
         << setw(5) << "UNIT" << "   STATUS" << endl;
    cout << "--------------------------------------------------\n";
    for (int i = 0; i < sensors.size(); i++)
        sensors[i]->report();
    cout << "--------------------------------------------------\n";

    DiagnosticEngine engine(t, v, c, a);
    engine.diagnose();
    engine.recommend();
}

// ============================================================
//  MAIN - menu with auto demo + manual mode
// ============================================================
int main() {
    cout << "==================================================\n";
    cout << "   MotorGuard v2 - Motor Fault Diagnostic System\n";
    cout << "==================================================\n";

    int choice;
    while (true) {
        cout << "\n1. Run auto demo (faulty motor)\n";
        cout << "2. Enter sensor readings manually\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            TemperatureSensor t("Motor-A", 95.0);
            VibrationSensor   v("Bearing-1", 8.2);
            CurrentSensor     c("Line-3", 7.5);
            AcousticSensor    a("Casing", 82.0);
            runDiagnostics(&t, &v, &c, &a);
        }
        else if (choice == 2) {
            float tv, vv, cv, av;
            cout << "Temperature (C): ";  cin >> tv;
            cout << "Vibration (mm/s): "; cin >> vv;
            cout << "Current (A): ";      cin >> cv;
            cout << "Acoustic (dB): ";    cin >> av;

            TemperatureSensor t("Motor-X", tv);
            VibrationSensor   v("Bearing-X", vv);
            CurrentSensor     c("Line-X", cv);
            AcousticSensor    a("Casing-X", av);
            runDiagnostics(&t, &v, &c, &a);
        }
        else if (choice == 0) {
            cout << "MotorGuard shutting down. Stay safe!\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}