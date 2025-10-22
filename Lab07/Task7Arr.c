#include <stdio.h>
#include <ctype.h>

void vowels_consonents(const char arr[])
{
    int vowels = 0;
    int consonents = 0;

    for (int i = 0; arr[i] != '\0'; i++)
    {

        char ch = tolower(arr[i]);
        if (ch >= 'a' && ch <= 'z')
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowels++;
            }
            else
            {
                consonents++;
            }
        }
    }
    printf("\n -- Analysis Result -- \n");
    printf("Total Vowels: %d\n", vowels);
    printf("Total Consonents: %d\n", consonents);
    printf("Total letters processed: %d\n", vowels + consonents);
}

int main()
{
    char sensor_code[] = "A-b Cd_Efg h4I jKlM!";

    printf("\n---Sensor Code Analysis---\n");
    vowels_consonents(sensor_code);

    return 0;
}