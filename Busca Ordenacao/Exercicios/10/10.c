#include <stdio.h>

#include "./10.h"

int _partitionate(int *array, int begin, int end)
{
    int left = begin;
    int right = end;
    int pivot = array[begin];

    while (left < right)
    {
        while (left <= end && array[left] <= pivot)
        {
            left++;
        }

        while (right >= begin && array[right] > pivot)
        {
            right--;
        }

        if (left < right)
        {
            int swap = array[left];
            array[left] = array[right];
            array[right] = swap;
        }
    }

    array[begin] = array[right];
    array[right] = pivot;

    return right;
}

void _quick_sort(int *array, int begin, int end)
{
    if (end > begin)
    {
        int pivot = _partitionate(array, begin, end);
        _quick_sort(array, begin, pivot - 1);
        _quick_sort(array, pivot + 1, end);
    }
}

void quick_sort(int *array, int size)
{
    _quick_sort(array, 0, size - 1);
}

void main()
{
    int size = 12;
    int array[] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};

    printf("\n[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]\n");

    quick_sort(array, size);

    printf("\n[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]\n");
}