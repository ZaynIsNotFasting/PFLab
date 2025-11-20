#include <stdio.h>
#include <string.h>

char affirmations[50][100];
int count = 0;

void loadAffirmations()
{
    FILE *f = fopen("affirm.txt", "r");
    if (f)
    {
        while (count < 50 && fgets(affirmations[count], 100, f))
        {
            affirmations[count][strlen(affirmations[count]) - 1] = '\0';
            count++;
        }
        fclose(f);
    }
}

void saveAffirmations()
{
    FILE *f = fopen("affirm.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(f, "%s\n", affirmations[i]);
    fclose(f);
}

void showAffirmations()
{
    printf("\nYour Affirmations:\n");
    for (int i = 0; i < count; i++)
        printf("%d. %s\n", i + 1, affirmations[i]);
}

int checkWords(char text[])
{
    int words = 0, i = 0;
    while (text[i] == ' ')
        i++;
    while (text[i] != '\0')
    {
        if (text[i] == ' ' && text[i + 1] != ' ' && text[i + 1] != '\0')
            words++;
        i++;
    }
    if (strlen(text) > 0)
        words++;
    return words <= 7;
}

void addAffirmation()
{
    if (count >= 50)
    {
        printf("Max 50 affirmations reached!\n");
        return;
    }
    printf("Enter affirmation (max 7 words): ");
    getchar();
    fgets(affirmations[count], 100, stdin);
    affirmations[count][strlen(affirmations[count]) - 1] = '\0';
    if (!checkWords(affirmations[count]))
    {
        printf("Too many words! Max is 7.\n");
        return;
    }
    count++;
    printf("Affirmation added!\n");
}

void updateAffirmation()
{
    showAffirmations();
    int num;
    printf("Update affirmation #: ");
    scanf("%d", &num);
    if (num < 1 || num > count)
    {
        printf("Invalid number!\n");
        return;
    }
    printf("New affirmation: ");
    getchar();
    fgets(affirmations[num - 1], 100, stdin);
    affirmations[num - 1][strlen(affirmations[num - 1]) - 1] = '\0';
    if (!checkWords(affirmations[num - 1]))
    {
        printf("Too many words! Max is 7.\n");
        return;
    }
    printf("Updated!\n");
}

void deleteAffirmation()
{
    showAffirmations();
    int num;
    printf("Delete affirmation #: ");
    scanf("%d", &num);
    if (num < 1 || num > count)
    {
        printf("Invalid number!\n");
        return;
    }
    for (int i = num - 1; i < count - 1; i++)
        strcpy(affirmations[i], affirmations[i + 1]);
    count--;
    printf("Deleted!\n");
}

void searchAffirmation()
{
    char search[100];
    printf("Search phrase: ");
    getchar();
    fgets(search, 100, stdin);
    search[strlen(search) - 1] = '\0';
    printf("Results:\n");
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strstr(affirmations[i], search))
        {
            printf("%d. %s\n", i + 1, affirmations[i]);
            found = 1;
        }
    }
    if (!found)
        printf("No matches found.\n");
}

int main()
{
    int choice;

    loadAffirmations();
    printf("Wellness App - %d affirmations loaded\n", count);

    do
    {
        printf("\n1.Show\n 2.Add\n 3.Update\n 4.Delete\n 5.Search\n -1.Exit\nChoice:\n ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            showAffirmations();
            break;
        case 2:
            addAffirmation();
            break;
        case 3:
            updateAffirmation();
            break;
        case 4:
            deleteAffirmation();
            break;
        case 5:
            searchAffirmation();
            break;
        case -1:
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != -1);

    saveAffirmations();
    printf("\nAffirmations saved to file. Stay positive!\n");
    return 0;
}