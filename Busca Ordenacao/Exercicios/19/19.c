#include <stdio.h>
#include <string.h>

void selection_sort_string_lentgh(char **array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (strlen(array[j]) < strlen(array[min]))
            {
                min = j;
            }
        }

        if (min != i)
        {
            char *swap = array[min];
            array[min] = array[i];
            array[i] = swap;
        }
    }
}
