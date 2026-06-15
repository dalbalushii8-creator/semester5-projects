#include <stdio.h>
int main() {
    int i;
    int number;
    printf("Enter a number for multiplication table: ");
    scanf("%d", &number);
    printf("\nMultiplication table for %d:\n", number);
    printf("=================\n");
    for (i= 1; i<=10; i++) {
    printf("%d x %d =%d\n", number, i, number * i);
    }
    return 0;
}

    
