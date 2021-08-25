#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a, b;
    printf("Enter Value of first number 'a': ");
    scanf("%d", &a);
    printf("Enter Value of second number 'b': ");
    scanf("%d", &b);
    swap(&a, &b);
    printf("After Swapping: a = %d, b = %d\n", a, b);
    return 0;
}
