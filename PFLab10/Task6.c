#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOTES 50
#define MAX_LENGTH 100

char notes[MAX_NOTES][MAX_LENGTH];
int count = 0;

void loadNotes()
{
    FILE *f = fopen("episodes.txt", "r");
    if (f)
    {
        while (count < MAX_NOTES && fgets(notes[count], MAX_LENGTH, f))
        {
            char *ptr = notes[count];
            while (*ptr != '\n' && *ptr != '\0')
                ptr++;
            *ptr = '\0';
            count++;
        }
        fclose(f);
    }
}

void saveNotes()
{
    FILE *f = fopen("episodes.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(f, "%s\n", notes[i]);
    }
    fclose(f);
}

void displayNotes()
{
    printf("\nPodcast Notes:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, notes[i]);
    }
}

int stringLength(char *str)
{
    char *ptr = str;
    while (*ptr != '\0')
        ptr++;
    return ptr - str;
}

void stringCopy(char *dest, char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int stringCompare(char *str1, char *str2)
{
    while (*str1 && *str2 && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int containsWord(char *note, char *word)
{
    char *notePtr = note;
    char *wordPtr = word;

    while (*notePtr)
    {
        char *current = notePtr;
        wordPtr = word;

        while (*current && *wordPtr && *current == *wordPtr)
        {
            current++;
            wordPtr++;
        }
        if (*wordPtr == '\0' &&
            (notePtr == note || isspace(*(notePtr - 1))) &&
            (*current == '\0' || isspace(*current)))
        {
            return 1;
        }
        notePtr++;
    }
    return 0;
}

int countWordOccurrences(char *word)
{
    int total = 0;
    for (int i = 0; i < count; i++)
    {
        char *notePtr = notes[i];
        char *wordPtr = word;

        while (*notePtr)
        {
            char *current = notePtr;
            wordPtr = word;

            while (*current && *wordPtr && *current == *wordPtr)
            {
                current++;
                wordPtr++;
            }

            if (*wordPtr == '\0' &&
                (notePtr == notes[i] || isspace(*(notePtr - 1))) &&
                (*current == '\0' || isspace(*current)))
            {
                total++;
            }
            notePtr++;
        }
    }
    return total;
}

void addNote()
{
    if (count >= MAX_NOTES)
    {
        printf("Cannot add more notes! Storage full.\n");
        return;
    }

    printf("Enter podcast note: ");
    getchar();
    fgets(notes[count], MAX_LENGTH, stdin);

    char *ptr = notes[count];
    while (*ptr != '\n' && *ptr != '\0')
        ptr++;
    *ptr = '\0';

    count++;
    printf("Note added successfully!\n");
}

void removeNote()
{
    if (count == 0)
    {
        printf("No notes to remove!\n");
        return;
    }

    displayNotes();
    int num;
    printf("Enter note number to remove: ");
    scanf("%d", &num);

    if (num < 1 || num > count)
    {
        printf("Invalid note number!\n");
        return;
    }

    for (int i = num - 1; i < count - 1; i++)
    {
        stringCopy(notes[i], notes[i + 1]);
    }

    count--;
    printf("Note removed successfully!\n");
}

void editNote()
{
    if (count == 0)
    {
        printf("No notes to edit!\n");
        return;
    }

    displayNotes();
    int num;
    printf("Enter note number to edit: ");
    scanf("%d", &num);

    if (num < 1 || num > count)
    {
        printf("Invalid note number!\n");
        return;
    }

    printf("Enter new note: ");
    getchar();
    fgets(notes[num - 1], MAX_LENGTH, stdin);

    char *ptr = notes[num - 1];
    while (*ptr != '\n' && *ptr != '\0')
        ptr++;
    *ptr = '\0';

    printf("Note updated successfully!\n");
}

void searchNote()
{
    if (count == 0)
    {
        printf("No notes to search!\n");
        return;
    }

    char search[MAX_LENGTH];
    printf("Enter search term: ");
    getchar();
    fgets(search, MAX_LENGTH, stdin);

    char *ptr = search;
    while (*ptr != '\n' && *ptr != '\0')
        ptr++;
    *ptr = '\0';

    printf("Matching notes:\n");
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (containsWord(notes[i], search))
        {
            printf("%d. %s\n", i + 1, notes[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No notes found with that term.\n");
    }
}

void countWords()
{
    if (count == 0)
    {
        printf("No notes to count words from!\n");
        return;
    }

    char word[MAX_LENGTH];
    printf("Enter word to count: ");
    getchar();
    fgets(word, MAX_LENGTH, stdin);

    char *ptr = word;
    while (*ptr != '\n' && *ptr != '\0')
        ptr++;
    *ptr = '\0';

    int occurrences = countWordOccurrences(word);
    printf("The word '%s' appears %d times in all notes.\n", word, occurrences);
}

int main()
{
    int choice;

    loadNotes();
    printf("Podcast Note Manager\n");
    printf("Loaded %d notes from file.\n", count);

    do
    {
        printf("\nMenu:\n");
        printf("1. Display all notes\n");
        printf("2. Add new note\n");
        printf("3. Remove note\n");
        printf("4. Edit note\n");
        printf("5. Search notes\n");
        printf("6. Count word occurrences\n");
        printf("-1. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayNotes();
            break;
        case 2:
            addNote();
            break;
        case 3:
            removeNote();
            break;
        case 4:
            editNote();
            break;
        case 5:
            searchNote();
            break;
        case 6:
            countWords();
            break;
        case -1:
            printf("Saving notes and exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != -1);

    saveNotes();
    printf("Notes saved to file. Goodbye!\n");

    return 0;
}