#include <stdio.h>
#include <stdlib.h>

int cmp_small_big(const void *a, const void*b)
{
    return *(int*)a - *(int*)b;
}

int cmp_big_small(const void *a, const void*b)
{
    return *(int*)b - *(int*)a;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int flag;
    scanf("%d", &flag);

    int *data = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i)
        scanf("%d", &data[i]);
    
    if(!flag)
        qsort(data, n, sizeof(int), cmp_small_big);
    else
        qsort(data, n, sizeof(int), cmp_big_small);

    for(int i = 0; i < n; ++i)
        printf("%d\n", data[i]);

    free(data);
    return 0;
}