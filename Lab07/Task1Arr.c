#include <stdio.h>
int main()
{
    int temp[] = {25, 28, 22, 31, 27, 30};
    int numRead = sizeof(temp) / sizeof(temp[0]);

    int maxTemp = temp[0];
    int miniTemp = temp[0];

    for (int i = 1; i < numRead; i++)
    {
        if (temp[i] > maxTemp)
        {
            maxTemp = temp[i];
        }

        if (temp[i] < miniTemp)
        {
            miniTemp = temp[i];
        }
    }

    printf("Hottest temperature: %d C\n", maxTemp);
    printf("Coldest temperature: %d C", miniTemp);
}