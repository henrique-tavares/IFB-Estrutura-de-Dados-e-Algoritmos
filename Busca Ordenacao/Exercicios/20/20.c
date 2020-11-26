#include <stdio.h>
#include <string.h>

#include "./20.h"

int _partitionate(char *string, int begin, int end)
{
    int length = strlen(string);
    int left = begin;
    int right = end;
    int pivot = string[begin];

    while (left < right)
    {
        while (left <= end && string[left] >= pivot)
        {
            left++;
        }

        while (right >= begin && string[right] < pivot)
        {
            right--;
        }

        if (left < right)
        {
            char swap = string[left];
            string[left] = string[right];
            string[right] = swap;
        }
    }

    string[begin] = string[right];
    string[right] = pivot;

    return right;
}

void _quick_sort_string_descendent(char *string, int begin, int end)
{
    if (begin < end)
    {
        int pivot = _partitionate(string, begin, end);

        _quick_sort_string_descendent(string, begin, pivot - 1);
        _quick_sort_string_descendent(string, pivot + 1, end);
    }
}

void quick_sort_string_descendent(char *string)
{
    _quick_sort_string_descendent(string, 0, strlen(string) - 1);
}
