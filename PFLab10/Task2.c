#include <stdio.h>
#include <string.h>

char levels[50][100];
int count = 0;

void loadLevels()
{
    FILE *f = fopen("levels.txt", "r");
    if (f)
    {
        while (count < 50 && fgets(levels[count], 100, f))
        {
            levels[count][strlen(levels[count]) - 1] = '\0';
            count++;
        }
        fclose(f);
    }
}

void saveLevels()
{
    FILE *f = fopen("levels.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(f, "%s\n", levels[i]);
    fclose(f);
}

void showLevels()
{
    printf("\nLevels:\n");
    for (int i = 0; i < count; i++)
        printf("%d. %s\n", i + 1, levels[i]);
}

int checkWords(char desc[])
{
    int words = 0, i = 0;
    while (desc[i] == ' ')
        i++;
    while (desc[i] != '\0')
    {
        if (desc[i] == ' ' && desc[i + 1] != ' ' && desc[i + 1] != '\0')
            words++;
        i++;
    }
    if (strlen(desc) > 0)
        words++;
    return words <= 7;
}

void addLevel()
{
    if (count >= 50)
    {
        printf("Full! Max 50 levels.\n");
        return;
    }
    printf("Level desc (max 7 words): ");
    getchar();
    fgets(levels[count], 100, stdin);
    levels[count][strlen(levels[count]) - 1] = '\0';
    if (!checkWords(levels[count]))
    {
        printf("Too many words!\n");
        return;
    }
    count++;
    printf("Added!\n");
}

void updateLevel()
{
    showLevels();
    int num;
    printf("Update level #: ");
    scanf("%d", &num);
    if (num < 1 || num > count)
    {
        printf("Invalid!\n");
        return;
    }
    printf("New desc: ");
    getchar();
    fgets(levels[num - 1], 100, stdin);
    levels[num - 1][strlen(levels[num - 1]) - 1] = '\0';
    if (!checkWords(levels[num - 1]))
    {
        printf("Too many words!\n");
        return;
    }
    printf("Updated!\n");
}

void deleteLevel()
{
    showLevels();
    int num;
    printf("Delete level #: ");
    scanf("%d", &num);
    if (num < 1 || num > count)
    {
        printf("Invalid!\n");
        return;
    }
    for (int i = num - 1; i < count - 1; i++)
        strcpy(levels[i], levels[i + 1]);
    count--;
    printf("Deleted!\n");
}

void searchLevel()
{
    char search[100];
    printf("Search: ");
    getchar();
    fgets(search, 100, stdin);
    search[strlen(search) - 1] = '\0';
    printf("Results:\n");
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strstr(levels[i], search))
        {
            printf("%d. %s\n", i + 1, levels[i]);
            found = 1;
        }
    }
    if (!found)
        printf("No matches.\n");
}

int main()
{
    int choice;
    loadLevels();
    printf("Level Tracker - %d levels loaded\n", count);

    do
    {
        printf("\n1.Show\n 2.Add\n 3.Update\n 4.Delete\n 5.Search\n -1.Exit\nChoice:\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            showLevels();
            break;
        case 2:
            addLevel();
            break;
        case 3:
            updateLevel();
            break;
        case 4:
            deleteLevel();
            break;
        case 5:
            searchLevel();
            break;
        }
    } while (choice != -1);

    saveLevels();
    printf("Levels saved. Goodbye!\n");
    return 0;
}