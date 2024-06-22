#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"

int main(void)
{
    int n;
    scanf("%d", &n);

    int flag;
    scanf("%d", &flag);

    int *data = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i)
        scanf("%d", &data[i]);
    
    bubble_sort(data, n, flag);
    display(data, n);

    free(data);
    return 0;
}