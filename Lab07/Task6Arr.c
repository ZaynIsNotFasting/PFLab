#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shiftRight(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }
    int Last = arr[size - 1];

    for (int i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = Last;
}

int main()
{
    int arr[] = {2, 5, 14, 198, 23198};
    int size = 5;

    printf("\n ---Array before shifting--- \n");
    display(arr, size);

    shiftRight(arr, size);
    printf("\n---Array after shifting to right--- \n");
    display(arr, size);
}