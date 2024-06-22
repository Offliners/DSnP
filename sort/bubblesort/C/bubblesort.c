#include <stdio.h>
#include "bubblesort.h"

void bubble_sort(int *data, int size, int flag)
{
    for(int i = 0; i < size - 1; ++i)
    {
        int swaped = 0;
        for(int j = 0; j < size - 1 - i; ++j)
        {
            if(flag)
            {
                if(data[j + 1] > data[j])
                {
                    swap(&data[j + 1], &data[j]);
                    swaped = 1;
                }
            }
            else
            {
                if(data[j + 1] < data[j])
                {
                    swap(&data[j + 1], &data[j]);
                    swaped = 1;
                }
            }
        }

        if(!swaped)
            break;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *data, int size)
{
    for(int i = 0; i < size; ++i)
        printf("%d\n", data[i]);
}