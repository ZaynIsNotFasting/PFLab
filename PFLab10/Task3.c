#include <stdio.h>
#include <string.h>

char recipes[40][100];
int count = 0;

void loadRecipes()
{
    FILE *f = fopen("recipes.txt", "r");
    if (f)
    {
        while (count < 40 && fgets(recipes[count], 100, f))
        {
            recipes[count][strlen(recipes[count]) - 1] = '\0';
            count++;
        }
        fclose(f);
    }
}

void saveRecipes()
{
    FILE *f = fopen("recipes.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(f, "%s\n", recipes[i]);
    }
    fclose(f);
}

void showRecipes()
{
    printf("\nRecipes:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, recipes[i]);
    }
}

void addRecipe()
{
    if (count >= 40)
    {
        printf("Max 40 recipes reached!\n");
        return;
    }
    printf("Enter recipe name: ");
    getchar();
    fgets(recipes[count], 100, stdin);
    recipes[count][strlen(recipes[count]) - 1] = '\0';
    count++;
    printf("Recipe added!\n");
}

void updateRecipe()
{
    showRecipes();
    int num;
    printf("Enter recipe number to update: ");
    scanf("%d", &num);
    if (num < 1 || num > count)
    {
        printf("Invalid number!\n");
        return;
    }
    printf("Enter new name: ");
    getchar();
    fgets(recipes[num - 1], 100, stdin);
    recipes[num - 1][strlen(recipes[num - 1]) - 1] = '\0';
    printf("Recipe updated!\n");
}

void deleteRecipe()
{
    showRecipes();
    int num;
    printf("Enter recipe number to delete: ");
    scanf("%d", &num);
    if (num < 1 || num > count)
    {
        printf("Invalid number!\n");
        return;
    }
    for (int i = num - 1; i < count - 1; i++)
    {
        strcpy(recipes[i], recipes[i + 1]);
    }
    count--;
    printf("Recipe deleted!\n");
}

void searchRecipe()
{
    char search[100];
    printf("Enter search term: ");
    getchar();
    fgets(search, 100, stdin);
    search[strlen(search) - 1] = '\0';

    printf("Matching recipes:\n");
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strstr(recipes[i], search))
        {
            printf("%d. %s\n", i + 1, recipes[i]);
            found = 1;
        }
    }
    if (!found)
        printf("No matches found.\n");
}

void sortRecipes()
{
    char temp[100];
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(recipes[i], recipes[j]) > 0)
            {
                strcpy(temp, recipes[i]);
                strcpy(recipes[i], recipes[j]);
                strcpy(recipes[j], temp);
            }
        }
    }
}

int main()
{
    int choice;

    loadRecipes();
    printf("Cooking Assistant - %d recipes loaded\n", count);

    do
    {
        printf("\n1.Show 2.Add 3.Update 4.Delete 5.Search -1.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            showRecipes();
            break;
        case 2:
            addRecipe();
            break;
        case 3:
            updateRecipe();
            break;
        case 4:
            deleteRecipe();
            break;
        case 5:
            searchRecipe();
            break;
        case -1:
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != -1);

    sortRecipes();
    saveRecipes();
    printf("\nFinal sorted recipes saved. Goodbye!\n");
    showRecipes();

    return 0;
}