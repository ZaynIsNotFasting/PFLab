#include <stdio.h>
#include <string.h>

void longestWord(const char str[])
{
    int maxLen = 0;
    int currentLen = 0;
    int max_start_index = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            if (currentLen > maxLen)
            {
                maxLen = currentLen;
                max_start_index = i - maxLen;
            }
            currentLen = 0;
        }
        else
        {
            currentLen++;
        }
    }
    if (currentLen > maxLen)
    {
        maxLen = currentLen;
        max_start_index = strlen(str) - maxLen;
    }

    if (maxLen == 0)
    {
        printf("String is empty or only spaces\n");
        return;
    }
    printf("\n-- Analysis Result --\n");
    printf("Longest word length: %d\n", maxLen);
    printf("Longest word: \"");
    for (int i = 0; i < maxLen; i++)
    {
        printf("%c", str[max_start_index + i]);
    }
    printf("\"\n");
}

int main()
{
    char str[] = "To Love is to delusion, to delusion is to live outside of reality";
    char str1[] = "Data";
    char str2[] = "  ";

    printf("\n---Analyzing sentence 1---\n");
    printf("Input String: \"%s\"\n", str);
    longestWord(str);

    printf("\n---Analyzing sentence 2---\n");
    printf("Input String: \"%s\"\n", str1);
    longestWord(str1);

    return 0;
}