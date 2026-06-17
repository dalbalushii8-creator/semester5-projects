#include <stdio.h>

int main() {
    int grades[5];
    int i;
    float Sum = 0;
    float average;
    int highest =0;
    int lowest = 100;

    printf("=== Student Grade Tracker ===\n");
    printf("Enter 5 student grades:\n\n");
    for (i = 0; i < 5; i++) {
        printf(" student %d grade: ", i + 1);
        scanf("%d", &grades[i]);
    }
    
    for (i = 0; i < 5; i++) {
        Sum = Sum + grades[i];
        if ( grades[i] > highest) {
            highest = grades[i];

        }
    if (grades[i] < lowest) {
        lowest = grades[i];
        
    }

}

average = Sum / 5;
printf("\n=== Results ===\n");
printf("Grades entered: ");
for (i = 0; i < 5; i++) {
    printf("%d ", grades[i]);

}
printf("\n");
printf("Highest grade: %d\n", highest);
printf("Lowest grade: %d\n", lowest);
printf("Average grade: %.2f\n", average);
return 0;
}
