#include <stdio.h>
void rotateMatrix(int original[][3], int rotated[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            rotated[j][size - 1 - i] = original[i][j];
        }
    }
}

int main()
{

    int size = 3;

    int mat[3][3];
    int rotated[3][3];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("Enter mat numbers: \n");
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Original Matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%2d", mat[i][j]);
        }
        printf("\n");
    }

    printf("\nRotated Matrix:\n");
    rotateMatrix(mat, rotated, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%2d", rotated[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}