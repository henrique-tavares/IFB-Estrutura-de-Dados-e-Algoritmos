#include <stdio.h>
#include <string.h>

#include "./18.h"

void bubble_sort_string(char *string)
{
    int length = strlen(string);

    for (int i = 1; i < length; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (string[j] < string[j - 1])
            {
                char swap = string[j];
                string[j] = string[j - 1];
                string[j - 1] = swap;
            }
        }
    }
}
