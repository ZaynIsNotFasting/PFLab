#include <stdio.h>

#define SECTIONS 2
#define SHELVES 3
#define ITEMS 4

int main()
{
    int s, h, i;

    int inventory[SECTIONS][SHELVES][ITEMS] = {

        {

            {10, 5, 8, 12},
            {15, 20, 0, 30},
            {22, 18, 10, 5}},
        {

            {40, 0, 15, 25},
            {10, 10, 50, 5},
            {30, 20, 10, 15}}};

    for (s = 0; s < SECTIONS; s++)
    {
        int totalInSection = 0;
        for (h = 0; h < SHELVES; h++)
        {
            for (i = 0; i < ITEMS; i++)
            {
                totalInSection += inventory[s][h][i];
            }
        }
        printf("Total items in Section %d: %d\n", s + 1, totalInSection);
    }

    printf("\n--- Shelf with Most Items ---\n");

    int maxShelfTotal = -1;
    int maxShelfIndex = -1;

    for (h = 0; h < SHELVES; h++)
    {
        int currentShelfTotal = 0;

        for (s = 0; s < SECTIONS; s++)
        {

            for (i = 0; i < ITEMS; i++)
            {
                currentShelfTotal += inventory[s][h][i];
            }
        }

        printf("Total quantity on Shelf %d (across all sections): %d\n", h + 1, currentShelfTotal);

        if (currentShelfTotal > maxShelfTotal)
        {
            maxShelfTotal = currentShelfTotal;
            maxShelfIndex = h;
        }

        printf("RESULT: The shelf with the highest total quantity is: Shelf %d (%d items)\n",
               maxShelfIndex + 1, maxShelfTotal);
        printf("\n");

        return 0;
    }
}