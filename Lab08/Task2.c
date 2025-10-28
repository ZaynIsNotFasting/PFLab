#include <stdio.h>

int main()
{
    char studentName[5][10];
    int n = 5;

    printf("Enter the marks of 5 students in 10 subjects:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Student id %d: \n", i + 1);

        scanf("%s", studentName[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Student id %d: %s\n", i + 1, studentName[i]);
    }
    return 0;
}