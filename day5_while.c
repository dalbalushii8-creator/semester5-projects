#include <stdio.h>
int main() {
    int number;
    int sum = 0;
    int count = 0;

    printf("=== Grade Average calculator ===\n");
    printf("Enter grade one by one.\n");
    printf("Enter -1 to stop and see your average.\n\n");
    while (number != -1) {
        printf("Enter grade: ");
        scanf("%d" , &number);
            
            if(number !=-1) {
            sum =sum + number;
            count++;
        }
        }
        
        
if (count >0) {
printf("\nTotal grades entered: %d\n", count);
printf("Sum: %d\n", sum);
printf("Average: %.2f\n", (float)sum / count);
        } else {
         printf("No grades entered!\n");
        }

        return 0;
        }

        