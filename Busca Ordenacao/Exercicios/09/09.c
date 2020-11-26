#include <stdio.h>

#include "./09.h"

int insertion_sort(int *array, int size)
{
    int copies = 0;

    for (int i = 0; i < size; i++)
    {
        int actual = array[i];
        int j;
        for (j = i; (j > 0) && (actual < array[j - 1]); j--)
        {
            array[j] = array[j - 1];
            copies++;
        }
        array[j] = actual;
        copies++;
    }

    return copies;
}

void main()
{
    int size = 10;
    int array[] = {72, 12, 62, 69, 27, 67, 41, 56, 33, 74};

    printf("\n[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]\n");

    printf("\nNúmero de cópias feito pelo insertion sort: %d\n", insertion_sort(array, size));

    printf("\n[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]\n");
}