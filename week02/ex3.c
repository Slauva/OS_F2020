#include <stdio.h>
// #include <stdlib.h>

int main()
{

    int n;
    char ch[100];

    printf("Write the height: \n");
    scanf("%s", ch);
    sscanf(ch, "%d", &n);

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

    return 0;
}
