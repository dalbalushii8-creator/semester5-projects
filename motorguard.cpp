#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// ============================================================
//  MotorGuard - Embedded Motor Health Monitoring System
//  Day 11: Sensor layer using inheritance & polymorphism
// ============================================================

// ----- BASE CLASS -----
// Every sensor shares these traits. This is the "parent".
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

        // virtual = child classes can override this
        virtual string getType() {
            return "Generic";
        }

        // Each sensor decides its own danger level (0=OK, 1=warn, 2=fault)
        virtual int riskLevel() {
            return 0;
        }

        // Shared display logic, polymorphic via getType() & riskLevel()
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
};

// ----- CHILD 1: Temperature -----
class TemperatureSensor : public Sensor {
    public:
        TemperatureSensor(string loc, float val)
            : Sensor(loc, val, "C") {}

        string getType() override { return "Temperature"; }

        int riskLevel() override {
            if (value > 90) return 2;   // overheating fault
            if (value > 70) return 1;   // warming up
            return 0;
        }
};

// ----- CHILD 2: Vibration -----
class VibrationSensor : public Sensor {
    public:
        VibrationSensor(string loc, float val)
            : Sensor(loc, val, "mm/s") {}

        string getType() override { return "Vibration"; }

        int riskLevel() override {
            if (value > 7.0) return 2;  // bearing / imbalance fault
            if (value > 4.5) return 1;
            return 0;
        }
};

// ----- CHILD 3: Current -----
class CurrentSensor : public Sensor {
    public:
        CurrentSensor(string loc, float val)
            : Sensor(loc, val, "A") {}

        string getType() override { return "Current"; }

        int riskLevel() override {
            if (value > 12.0) return 2; // electrical overload
            if (value > 9.0) return 1;
            return 0;
        }
};

// ----- CHILD 4: Acoustic -----
class AcousticSensor : public Sensor {
    public:
        AcousticSensor(string loc, float val)
            : Sensor(loc, val, "dB") {}

        string getType() override { return "Acoustic"; }

        int riskLevel() override {
            if (value > 85) return 2;   // abnormal noise
            if (value > 75) return 1;
            return 0;
        }
};

// ============================================================
//  MAIN - demo of polymorphism
// ============================================================
int main() {
    cout << "==================================================\n";
    cout << "   MotorGuard - Motor Health Monitoring System\n";
    cout << "==================================================\n\n";

    // POLYMORPHISM: one vector holds many sensor TYPES
    // via base-class pointers. This is the powerful part!
    vector<Sensor*> sensors;
    sensors.push_back(new TemperatureSensor("Motor-A", 95.0));
    sensors.push_back(new VibrationSensor("Bearing-1", 8.2));
    sensors.push_back(new CurrentSensor("Line-3", 7.5));
    sensors.push_back(new AcousticSensor("Casing", 78.0));

    cout << left << setw(14) << "SENSOR"
         << setw(10) << "LOCATION"
         << right << setw(8) << "VALUE"
         << setw(5) << "UNIT"
         << "   STATUS" << endl;
    cout << "--------------------------------------------------\n";

    // The SAME loop works for every sensor type - polymorphism!
    for (int i = 0; i < sensors.size(); i++) {
        sensors[i]->report();
    }

    cout << "--------------------------------------------------\n";
    cout << "Sensor layer online. Diagnostic engine: Day 12.\n";

    // clean up memory (good embedded habit!)
    for (int i = 0; i < sensors.size(); i++) {
        delete sensors[i];
    }

    return 0;
}