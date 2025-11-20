#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAGS 50
#define MAX_LENGTH 100

char tags[MAX_TAGS][MAX_LENGTH];
int count = 0;

void loadTags()
{
    FILE *f = fopen("tags.txt", "r");
    if (f)
    {
        while (count < MAX_TAGS && fgets(tags[count], MAX_LENGTH, f))
        {
            tags[count][strlen(tags[count]) - 1] = '\0';
            count++;
        }
        fclose(f);
    }
}

void saveTags()
{
    FILE *f = fopen("tags.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(f, "%s\n", tags[i]);
    }
    fclose(f);
}

void displayTags()
{
    printf("\nPhoto Tags:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, tags[i]);
    }
}

int countWords(char *str)
{
    int words = 0;
    char *ptr = str;

    // Skip leading spaces
    while (*ptr && isspace(*ptr))
        ptr++;

    while (*ptr)
    {
        // Count when we find a word
        if (!isspace(*ptr))
        {
            words++;
            // Skip the word
            while (*ptr && !isspace(*ptr))
                ptr++;
        }
        else
        {
            ptr++;
        }
    }
    return words;
}

int isValidTag(char *tag)
{
    int words = countWords(tag);
    return (words >= 5 && words <= 7);
}

void addTag()
{
    if (count >= MAX_TAGS)
    {
        printf("Cannot add more tags! Storage full.\n");
        return;
    }

    printf("Enter photo tag (5-7 words): ");
    getchar();
    fgets(tags[count], MAX_LENGTH, stdin);
    tags[count][strlen(tags[count]) - 1] = '\0';

    if (!isValidTag(tags[count]))
    {
        printf("Error: Tag must be 5-7 words!\n");
        return;
    }

    count++;
    printf("Tag added successfully!\n");
}

void deleteTag()
{
    if (count == 0)
    {
        printf("No tags to delete!\n");
        return;
    }

    displayTags();
    int num;
    printf("Enter tag number to delete: ");
    scanf("%d", &num);

    if (num < 1 || num > count)
    {
        printf("Invalid tag number!\n");
        return;
    }

    // Shift tags using pointer arithmetic
    for (int i = num - 1; i < count - 1; i++)
    {
        char *dest = tags[i];
        char *src = tags[i + 1];
        while ((*dest++ = *src++))
            ;
    }

    count--;
    printf("Tag deleted successfully!\n");
}

void updateTag()
{
    if (count == 0)
    {
        printf("No tags to update!\n");
        return;
    }

    displayTags();
    int num;
    printf("Enter tag number to update: ");
    scanf("%d", &num);

    if (num < 1 || num > count)
    {
        printf("Invalid tag number!\n");
        return;
    }

    printf("Enter new tag (5-7 words): ");
    getchar();
    fgets(tags[num - 1], MAX_LENGTH, stdin);
    tags[num - 1][strlen(tags[num - 1]) - 1] = '\0';

    if (!isValidTag(tags[num - 1]))
    {
        printf("Error: Tag must be 5-7 words!\n");
        return;
    }

    printf("Tag updated successfully!\n");
}

int compareStrings(char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
        {
            return 0; // Not equal
        }
        str1++;
        str2++;
    }
    return (*str1 == *str2); // Both ended at same time
}

int containsWord(char *tag, char *search)
{
    char *tagPtr = tag;
    char searchLower[MAX_LENGTH];
    char tagLower[MAX_LENGTH];

    // Convert search to lowercase for case-insensitive search
    char *sPtr = search;
    char *dPtr = searchLower;
    while (*sPtr)
    {
        *dPtr++ = tolower(*sPtr++);
    }
    *dPtr = '\0';

    while (*tagPtr)
    {
        // Copy current tag to lowercase
        char *t = tag;
        char *dl = tagLower;
        while (*t)
        {
            *dl++ = tolower(*t++);
        }
        *dl = '\0';

        // Search in lowercase version
        if (strstr(tagLower, searchLower) != NULL)
        {
            return 1;
        }
        tagPtr++;
    }
    return 0;
}

void searchTags()
{
    if (count == 0)
    {
        printf("No tags to search!\n");
        return;
    }

    char search[MAX_LENGTH];
    printf("Enter search term: ");
    getchar();
    fgets(search, MAX_LENGTH, stdin);
    search[strlen(search) - 1] = '\0';

    printf("Matching tags:\n");
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (containsWord(tags[i], search))
        {
            printf("%d. %s\n", i + 1, tags[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No tags found with that term.\n");
    }
}

int main()
{
    int choice;

    loadTags();
    printf("Digital Camera Tag Manager\n");
    printf("Loaded %d tags from file.\n", count);

    do
    {
        printf("\nMenu:\n");
        printf("1. Display all tags\n");
        printf("2. Add new tag\n");
        printf("3. Delete tag\n");
        printf("4. Update tag\n");
        printf("5. Search tags\n");
        printf("-1. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayTags();
            break;
        case 2:
            addTag();
            break;
        case 3:
            deleteTag();
            break;
        case 4:
            updateTag();
            break;
        case 5:
            searchTags();
            break;
        case -1:
            printf("Saving tags and exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != -1);

    saveTags();
    printf("Tags saved to file. Goodbye!\n");

    return 0;
}