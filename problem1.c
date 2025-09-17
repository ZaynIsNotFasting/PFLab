#include <stdio.h>

int main (){
    int marks1, marks2, marks3;
    int total;
    float percentage; 

    printf("Enter marks of subject 1: ");
    scanf("%d", &marks1);

    printf("Enter marks of subject 2: ");
    scanf("%d", &marks2);

    printf("Enter marks of subject 3: ");
    scanf("%d",  &marks3);

    total = marks1 + marks2 + marks3;
    
    percentage = (total / 300.00) * 100;

    printf("Total marks = %d\n", total);
    printf("Percentage = %.2f\n", percentage);

    return 0;
}