#include <stdio.h>

int manual_strcmp(const char str1[], const char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
    {
        i++;
    }

    if (str1[i] == str2[i])
    {
        return 0;
    }
    else
    {

        return (str1[i] - str2[i]);
    }
}

void comp_result(const char s1[], const char s2[])
{
    int result = manual_strcmp(s1, s2);

    printf("Comparing \"%s\" and \"%s\": ", s1, s2);

    if (result == 0)
    {
        printf("MATCH (Identical)\n");
    }
    else
    {
        printf("MISMATCH (Difference Code: %d)\n", result);
    }
}

int main()
{
    char sensorA_code[] = "XJ-2024_A1";
    char sensorB_code[] = "XJ-2024_A2";

    printf("\n---Sensor Code Comparison---\n");
    printf("Comparing Sensor A and Sensor B codes:\n");
    comp_result(sensorA_code, sensorB_code);

    char sensorC_code[] = "LM-9000_B3";
    char sensorD_code[] = "LM-9000_B3";

    printf("\nComparing Sensor C and Sensor D codes:\n");
    comp_result(sensorC_code, sensorD_code);

    return 0;
}