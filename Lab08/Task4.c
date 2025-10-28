#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0)
    {
        printf("Invalid size input. \n");
        return 1;
    }

    int hall[size][size];

    srand(time(NULL));

    int availableSeats = 0;
    int emptySeats = -1;
    int rowEmpty = -1;

    for (int i = 0; i < size; i++)
    {
        int emptyInRow = 0;
        printf("Row %d: ", i + 1);

        for (int j = 0; j < size; j++)
        {
            hall[i][j] = rand() % 2;
            printf("%2d", hall[i][j]);

            if (hall[i][j] == 0)
            {
                availableSeats++;
                emptyInRow++;
            }
        }
        printf("\n");
        if (emptyInRow > emptySeats)
        {
            emptySeats = emptyInRow;
            rowEmpty = i + 1;
        }
    }

    printf("Total available seats: %d\n", availableSeats);
    printf("Row with most empty seats: %d (%d empty seats)\n", rowEmpty, emptySeats);
    return 0;
}