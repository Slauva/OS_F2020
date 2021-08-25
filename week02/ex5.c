#include <stdio.h>
// #include <stdlib.h>

void pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void right(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void cube(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void isosceles(int n)
{
    if (n % 2 == 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2 - i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = 0; i < n / 2 + 1; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2 - i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
}

int main()
{

    int n, p;
    char ch[100];

    printf("1. Cube \n");
    printf("2. Pyramid \n");
    printf("3. Right triangle \n");
    printf("4. Isosceles triangle \n");
    printf("Choose the figure to print: ");

    scanf("%s", ch);
    sscanf(ch, "%d", &n);

    printf("Write the size: ");
    scanf("%s", ch);
    sscanf(ch, "%d", &p);

    switch (n)
    {
    case 1:
        cube(p);
        break;
    case 2:
        pyramid(p);
        break;
    case 3:
        right(p);
        break;
    case 4:
        isosceles(p);
        break;
    default:
        printf("%d option does not exist\n", n);
        break;
    }

    return 0;
}
