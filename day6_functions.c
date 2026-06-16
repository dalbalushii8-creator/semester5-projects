#include <stdio.h>

// Function declarations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(float a, float b);
void printResult(int result);

int main() {
    int num1, num2;

    printf("=== Simple Calculator ===\n");
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("\nResults:\n");
    printf("Addition: ");
    printResult(add(num1, num2));

    printf("Subtraction: ");
    printResult(subtract(num1, num2));

    printf("Multiplication: ");
    printResult(multiply(num1, num2));

    printf("Division: %.2f\n", divide(num1, num2));

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Error! Division by zero.\n");
        return 0;
    }
    return a / b;
}

void printResult(int result) {
    printf("%d\n", result);
}