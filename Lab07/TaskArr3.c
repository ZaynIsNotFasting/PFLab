#include <stdio.h>

int deleteArr(int arr[], int size, int target)
{

    int k = 0;
    for (int i = 0; i < size; i++)
    {

        if (arr[i] != target)
        {
            arr[k] = arr[i];
            k++;
        }
    }
    return k;
}

void showArr(int arr[], int size)
{

    if (size == 0)
    {
        printf("Empty array\n");
        return;
    }
    printf("Elements of Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int SensorData[] = {50, 4, 30, 25, 4, 44, 6, 4, 12};
    int ogSize = 9;
    int targetValue = 4;
    int newSize;

    printf("Original ");
    showArr(SensorData, ogSize);
    printf("Targeted value to delete: %d\n", targetValue);

    newSize = deleteArr(SensorData, ogSize, targetValue);

    printf("\n---After Deletion---\n");
    printf("Size of the array now: %d\n", newSize);

    printf("Array after deletion: %d\n", targetValue);
    showArr(SensorData, newSize);
    return 0;
}