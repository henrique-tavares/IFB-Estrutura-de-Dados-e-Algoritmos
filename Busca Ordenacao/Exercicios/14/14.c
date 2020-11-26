#include <stdio.h>
#include <stdlib.h>

#include "./14.h"

void print_array(int *array, int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]");
}

int *less_counting_sort(int *array, int size)
{
    int *count = (int *)malloc(size * sizeof(int));
    int *result = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        int less_than = 0;

        for (int j = 0; j < size; j++)
        {
            if (array[j] < array[i])
            {
                less_than++;
            }
        }

        count[i] = less_than;

        int offset = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (count[j] == count[i])
            {
                offset++;
            }
        }

        result[count[i] + offset] = array[i];
    }

    free(count);

    return result;
}

int main()
{
    int size = 12;
    int array[] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};

    putchar('\n');
    print_array(array, size);
    putchar('\n');

    int *sorted_array = less_counting_sort(array, size);

    putchar('\n');
    print_array(sorted_array, size);
    putchar('\n');

    return 0;
}