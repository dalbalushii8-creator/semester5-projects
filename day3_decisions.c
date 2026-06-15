#include <stdio.h>

int main() {
    int grade;
    printf("Enter your grade (0-100): ");
    scanf("%d",&grade);
    if (grade >= 90) {
        printf("Excellent! You are a top student!\n");
    } else if (grade>= 75) {
        printf("Good! Keep pushing higher!\n");
    } else if (grade >=60) {
        printf("Satisfactory. You can do better!\n");
    } else if (grade >=0){
        printf("Keep studying.You will improve!\n");
    } else {
        printf("Invalid grade entered!\n");
    }
    return 0;
}


