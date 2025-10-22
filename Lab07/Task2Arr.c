#include <stdio.h>

int main()
{
    float powerUsage[] = {135.5, 120.6, 145.2, 177.9, 299.4, 154.3, 123.2, 321.2};

    int num = sizeof(powerUsage) / sizeof(powerUsage[0]);

    float totalUsage = 0.0f;

    for (int i = 1; i < num; i++)
    {
        totalUsage = powerUsage[i];
    }
    float averageUsage = totalUsage / num;

    printf("Average power usage per hour: %.2f watts\n", averageUsage);
    printf("Total power usage per hourr: %.2f watts\n", totalUsage);
    return 0;
}