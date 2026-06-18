#include <iostream>
using namespace std;

class student {
    public:
    string name;
    int age;
    float grade;
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << " Grade: " << grade << endl;
    }

string getLetterGrade() {
    if (grade >= 90) return "A";
    else if (grade >= 80) return "B";
    else if (grade >= 70) return "C";
    else if (grade >= 60) return "D";
    else return "F";
}
};

int main() {
    student s1;
    s1.name = "Sashah";
    s1.age = 20;
    s1.grade = 92.5;

    student s2;
    s2.name = "Seva";
    s2.age = 22;
    s2.grade = 85.0;

    cout << "=== Student 1 ===" << endl;
    s1.displayInfo();
    cout << "Letter Grade: " << s1.getLetterGrade() << endl;

    cout << "=== Student 2 ===" << endl;
    s2.displayInfo();
    cout << "Letter Grade: " << s2.getLetterGrade() << endl;
 return 0;
}
