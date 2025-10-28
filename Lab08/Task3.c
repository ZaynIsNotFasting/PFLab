#include <stdio.h>
#include <ctype.h>

int main()
{
    char arr[3][20] =
        {
            "Minecraft",
            "Light Novels",
            "Astronomy"};
    char current_char;
    int vowels = 0;

    printf("The words to check are:\n %s\n %s\n %s\n", arr[0], arr[1], arr[2]);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            current_char = arr[i][j];
            if (current_char == '\0')
            {
                break;
            }
            current_char = tolower(current_char);

            switch (current_char)
            {
            case 'a':
            case 'i':
            case 'e':
            case 'o':
            case 'u':
                vowels++;
                break;
            }
        }
    }

    printf("Total vowels in the array are: %d\n", vowels);
    return 0;
}