#include <stdio.h>
#include <stdlib.h>

#include "./12.h"

void print_array(int *array, int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]");
}

void _merge(int *array, int begin, int middle, int end)
{
    int size = end - begin + 1;

    int *array_temp = (int *)malloc(size * sizeof(int));

    for (int i = 0, i_aux1 = begin, i_aux2 = middle + 1; i < size; i++)
    {
        if (i_aux1 <= middle && i_aux2 <= end)
        {
            array_temp[i] = (array[i_aux1] < array[i_aux2]) ? array[i_aux1++] : array[i_aux2++];
        }
        else if (i_aux1 <= middle)
        {
            array_temp[i] = array[i_aux1++];
        }
        else
        {
            array_temp[i] = array[i_aux2++];
        }
    }

    for (int i = 0, j = begin; i < size; i++, j++)
    {
        array[j] = array_temp[i];
    }

    free(array_temp);
}

void _merge_sort(int *array, int begin, int end, int size)
{
    if (begin < end)
    {
        int middle = (begin + end) / 2;
        _merge_sort(array, begin, middle, size);
        _merge_sort(array, middle + 1, end, size);
        _merge(array, begin, middle, end);

        print_array(array, size);
        putchar('\n');
    }
}

void merge_sort(int *array, int size)
{
    _merge_sort(array, 0, size - 1, size);
}

int _partitionate(int *array, int begin, int end, int size)
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

        print_array(array, size);
        putchar('\n');
    }

    array[begin] = array[right];
    array[right] = pivot;

    return right;
}

void _quick_sort(int *array, int begin, int end, int size)
{
    if (end > begin)
    {
        int pivot = _partitionate(array, begin, end, size);

        _quick_sort(array, begin, pivot - 1, size);
        _quick_sort(array, pivot + 1, end, size);
    }
}

void quick_sort(int *array, int size)
{
    _quick_sort(array, 0, size - 1, size);
}

void _heapify(int *array, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && array[left] > array[largest])
    {
        largest = left;
    }

    if (right < size && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        int swap = array[index];
        array[index] = array[largest];
        array[largest] = swap;

        _heapify(array, size, largest);
    }
}

void heap_sort(int *array, int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        _heapify(array, size, i);
        print_array(array, size);
        putchar('\n');
    }

    for (int i = size - 1; i > 0; i--)
    {
        int swap = array[0];
        array[0] = array[i];
        array[i] = swap;

        _heapify(array, i, 0);
        print_array(array, size);
        putchar('\n');
    }
}

int main()
{
    int size = 16;

    int array_merge[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};

    printf("\na) Merge Sort:\n");
    merge_sort(array_merge, size);
    putchar('\n');

    int array_quick[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};

    printf("\nb) Quick Sort:\n");
    quick_sort(array_quick, size);
    putchar('\n');

    int array_heap[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};

    printf("\nc) Heap Sort:\n");
    heap_sort(array_heap, size);
    putchar('\n');

    return 0;
}