#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

struct Student {
    int id;
    char name[50];
    float grade;
    char letter[2];
};

void assignLetter(struct Student *s) {
    if (s->grade >= 90) strcpy(s->letter, "A");
    else if (s->grade >= 80) strcpy(s->letter, "B");
    else if (s->grade >= 70) strcpy(s->letter, "C");
    else if (s->grade >= 60) strcpy(s->letter, "D");
    else strcpy(s->letter, "F");
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Database full!\n");
        return;
    }
    struct Student s;
    s.id = *count + 1;
    printf("Enter name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter grade: ");
    scanf("%f", &s.grade);
    assignLetter(&s);
    students[*count] = s;
    (*count)++;
    printf("Student added successfully!\n");
}

void displayAll(struct Student students[], int count) {
    if (count == 0) {
        printf("No students yet!\n");
        return;
    }
    printf("\n========================================\n");
    printf("         STUDENT DATABASE REPORT\n");
    printf("========================================\n");
    printf("%-5s %-20s %-8s %-6s\n", "No.", "Name", "Grade", "Letter");
    printf("----------------------------------------\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("%-5d %-20s %-8.2f %-6s\n",
            students[i].id,
            students[i].name,
            students[i].grade,
            students[i].letter);
    }
    printf("========================================\n");
}

void findHighest(struct Student students[], int count) {
    if (count == 0) { printf("No students!\n"); return; }
    int i, max = 0;
    for (i = 1; i < count; i++) {
        if (students[i].grade > students[max].grade)
            max = i;
    }
    printf("Highest: %s with %.2f (%s)\n",
        students[max].name,
        students[max].grade,
        students[max].letter);
}

void findLowest(struct Student students[], int count) {
    if (count == 0) { printf("No students!\n"); return; }
    int i, min = 0;
    for (i = 1; i < count; i++) {
        if (students[i].grade < students[min].grade)
            min = i;
    }
    printf("Lowest: %s with %.2f (%s)\n",
        students[min].name,
        students[min].grade,
        students[min].letter);
}

float calculateAverage(struct Student students[], int count) {
    if (count == 0) return 0;
    float sum = 0;
    int i;
    for (i = 0; i < count; i++)
        sum += students[i].grade;
    return sum / count;
}

void saveToFile(struct Student students[], int count) {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error saving file!\n");
        return;
    }
    int i;
    fprintf(file, "STUDENT DATABASE REPORT\n");
    fprintf(file, "========================\n");
    for (i = 0; i < count; i++) {
        fprintf(file, "ID: %d | Name: %s | Grade: %.2f | Letter: %s\n",
            students[i].id,
            students[i].name,
            students[i].grade,
            students[i].letter);
    }
    fprintf(file, "========================\n");
    fprintf(file, "Average: %.2f\n", calculateAverage(students, count));
    fclose(file);
    printf("Saved to students.txt successfully!\n");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    printf("================================\n");
    printf("    STUDENT DATABASE SYSTEM\n");
    printf("================================\n");

    while (1) {
        printf("\n1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Show Highest Grade\n");
        printf("4. Show Lowest Grade\n");
        printf("5. Show Class Average\n");
        printf("6. Save to File\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) addStudent(students, &count);
        else if (choice == 2) displayAll(students, count);
        else if (choice == 3) findHighest(students, count);
        else if (choice == 4) findLowest(students, count);
        else if (choice == 5) printf("Average: %.2f\n", calculateAverage(students, count));
        else if (choice == 6) saveToFile(students, count);
        else if (choice == 0) {
            printf("Goodbye, Mr. Gnook!\n");
            break;
        }
        else printf("Invalid choice!\n");
    }

    return 0;
}