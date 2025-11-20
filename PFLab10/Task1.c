#include <stdio.h>
#include <string.h>

char songs[10][100];
int count = 0;

void loadSongs()
{
    FILE *f = fopen("playlist.txt", "r");
    if (f)
    {
        while (count < 10 && fgets(songs[count], 100, f))
        {
            songs[count][strlen(songs[count]) - 1] = '\0';
            count++;
        }
        fclose(f);
    }
}

void saveSongs()
{
    FILE *f = fopen("playlist.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(f, "%s\n", songs[i]);
    fclose(f);
}

void showSongs()
{
    printf("\nPlaylist:\n");
    for (int i = 0; i < count; i++)
        printf("%d. %s\n", i + 1, songs[i]);
}

void addSong()
{
    if (count >= 10)
    {
        printf("Full! Max 10 songs.\n");
        return;
    }
    printf("Song title: ");
    getchar();
    fgets(songs[count], 100, stdin);
    songs[count][strlen(songs[count]) - 1] = '\0';
    count++;
    printf("Added!\n");
}

void deleteSong()
{
    showSongs();
    int num;
    printf("Delete song #: ");
    scanf("%d", &num);
    if (num < 1 || num > count)
    {
        printf("Invalid!\n");
        return;
    }
    for (int i = num - 1; i < count - 1; i++)
        strcpy(songs[i], songs[i + 1]);
    count--;
    printf("Deleted!\n");
}

void updateSong()
{
    showSongs();
    int num;
    printf("Update song #: ");
    scanf("%d", &num);
    if (num < 1 || num > count)
    {
        printf("Invalid!\n");
        return;
    }
    printf("New title: ");
    getchar();
    fgets(songs[num - 1], 100, stdin);
    songs[num - 1][strlen(songs[num - 1]) - 1] = '\0';
    printf("Updated!\n");
}

void searchSong()
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
        if (strstr(songs[i], search))
        {
            printf("%d. %s\n", i + 1, songs[i]);
            found = 1;
        }
    }
    if (!found)
        printf("No matches.\n");
}

void sortSongs()
{
    char temp[100];
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(songs[i], songs[j]) > 0)
            {
                strcpy(temp, songs[i]);
                strcpy(songs[i], songs[j]);
                strcpy(songs[j], temp);
            }
        }
    }
}

int main()
{
    int choice;
    loadSongs();

    do
    {
        printf("1.Show\n 2.Add\n 3.Delete\n 4.Update\n 5.Search\n -1.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            showSongs();
            break;
        case 2:
            addSong();
            break;
        case 3:
            deleteSong();
            break;
        case 4:
            updateSong();
            break;
        case 5:
            searchSong();
            break;
        }
        if (choice != -1)
            saveSongs();
    } while (choice != -1);

    sortSongs();
    printf("\nFinal Playlist:\n");
    showSongs();
    saveSongs();
    return 0;
}