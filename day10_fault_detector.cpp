#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Represents a single sensor reading - like data from ESP32/STM32
class SensorReading {
    private:
        float temperature;
        float vibration;
        float current;

    public:
        // CONSTRUCTOR - one reading from the sensors
        SensorReading(float temp, float vib, float curr) {
            temperature = temp;
            vibration = vib;
            current = curr;
        }

        float getTemp()    { return temperature; }
        float getVib()     { return vibration; }
        float getCurrent() { return current; }
};

// A simple "model" that classifies machine health
// This mimics how a TinyML model takes features and outputs a class
class FaultDetector {
    private:
        string modelName;
        // simple thresholds (in real TinyML these are learned weights)
        float tempLimit;
        float vibLimit;
        float currentLimit;

    public:
        // CONSTRUCTOR - set up the detector with thresholds
        FaultDetector(string name, float tLimit, float vLimit, float cLimit) {
            modelName = name;
            tempLimit = tLimit;
            vibLimit = vLimit;
            currentLimit = cLimit;
            cout << "Model '" << modelName << "' loaded.\n";
        }

        // The "inference" function - classify a reading
        string predict(SensorReading r) {
            int faultScore = 0;

            if (r.getTemp() > tempLimit)       faultScore++;
            if (r.getVib() > vibLimit)         faultScore++;
            if (r.getCurrent() > currentLimit) faultScore++;

            // Classification based on how many limits exceeded
            if (faultScore == 0) return "NORMAL";
            else if (faultScore == 1) return "WARNING";
            else return "FAULT";
        }
};

int main() {
    cout << "=== Edge Fault Detection (TinyML-style) ===\n\n";

    // Create the detector model with thresholds
    FaultDetector detector("FaultNet-v1", 70.0, 5.0, 10.0);

    // Simulated sensor readings (like data coming from a machine)
    vector<SensorReading> readings = {
        SensorReading(45.0, 2.1, 6.5),   // healthy
        SensorReading(72.0, 3.0, 7.0),   // one warning
        SensorReading(85.0, 6.5, 12.0)   // multiple faults
    };

    cout << "\n";
    cout << left << setw(8) << "Sample"
         << setw(8) << "Temp" << setw(8) << "Vib"
         << setw(10) << "Current" << setw(10) << "Status" << endl;
    cout << "------------------------------------------------\n";

    for (int i = 0; i < readings.size(); i++) {
        string result = detector.predict(readings[i]);
        cout << left << setw(8) << (i + 1)
             << setw(8) << readings[i].getTemp()
             << setw(8) << readings[i].getVib()
             << setw(10) << readings[i].getCurrent()
             << setw(10) << result << endl;
    }

    cout << "------------------------------------------------\n";
    cout << "\nInference complete. This is how an edge device\n";
    cout << "classifies machine health in real time!\n";

    return 0;
}