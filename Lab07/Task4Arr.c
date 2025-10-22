#include <stdio.h>

void reverse(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int temp;

    while (start < end)
    {

        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void display(int arr[], int size)
{
    for (int k = 0; k < size; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

int main()
{
    int reading[] = {1, 10, 100, 1000, 10000};
    int size = 5;

    printf("\n---Original array---\n");
    display(reading, size);
    printf("               \n");

    reverse(reading, size);

    printf("\n----Chronologically reverserd array---- \n");
    display(reading, size);

    return 0;
}