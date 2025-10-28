#include <stdio.h>

int main()
{
    int students = 5, subject = 4;
    int marks[students][subject];

    for (int i = 0; i < students; i++)
    {
        printf("\nEnter student %d marks: \n", i + 1);
        for (int j = 0; j < subject; j++)
        {
            printf("Subject %d: ", j + 1);
            if (scanf("%d", &marks[i][j]) != 1)
            {
                printf("Invalid input!");
            }
        }
    }

    printf("\nStudent Marks:\n");
    for (int i = 0; i < students; i++)
    {
        int sum = 0;
        for (int j = 0; j < subject; j++)
        {
            sum += marks[i][j];

            double average = sum / subject;

            printf("%.2lf\n", average);

            if (i < students - 1)
            {
                printf(", ");
            }
        }
    }
    printf("\n");

    int highest[subject];
    for (int j = 0; j < subject; j++)
    {
        int max = -1;
        for (int i = 0; i < students; i++)
        {
            if (marks[i][j] > max)
            {
                max = marks[i][j];
            }
        }
        highest[j] = max;
    }
    printf("Highest marks in each subject: \n");

    for (int j = 0; j < subject; j++)
    {
        printf("Subject %d: %d\n", j + 1, highest[j]);
        if (j < subject - 1)
        {

            printf(",");
        }
    }

    printf("\n");
    return 0;
}