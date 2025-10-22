#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mergedArr(int sensor1[], int size1, int sensor2[], int size2, int merged[])
{
    int k = 0;

    printf("\n----Copying %d elements from sensor1----\n", size1);
    for (int i = 0; i < size1; i++)
    {
        merged[k] = sensor1[i];
        k++;
    }

    printf("k after phase 1: %d\n", k);
    for (int i = 0; i < size2; i++)
    {
        merged[k] = sensor2[i];
        k++;
    }
    printf("Total elements in merged: %d\n", k);
}

int main()
{
    int sensor1[] = {6, 16, 26, 36, 55};
    int size1 = 5;

    int sensor2[] = {9, 18, 27, 36, 45, 54, 63};
    int size2 = 7;

    int total_size = size1 + size2;
    int merged_reading[total_size];

    printf("\n---Sensor 1 Array--\n");
    display(sensor1, size1);

    printf("\n---Sensor 2 Array--\n");
    display(sensor2, size2);

    printf("Total size required to merge: %d\n", total_size);
    mergedArr(sensor1, size1, sensor2, size2, merged_reading);

    printf("\n---Merged Array---\n");
    display(merged_reading, total_size);
}