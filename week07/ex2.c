#include <stdio.h>
#include <stdlib.h>

int main(int argc, char line[])
{

    int n;
    printf("N => ");
    scanf("%d", &n);

    int *arr = (int *)calloc(n, sizeof(int));
    printf("Inited array: ");
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}