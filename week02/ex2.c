#include <stdio.h>
#include <string.h>

void reverse(char line[])
{
    int n = strlen(line);

    for (int i = 0; i < n / 2; i++)
    {
        char ch = line[i];
        line[i] = line[n - i - 1];
        line[n - i - 1] = ch;
    }
}

int main()
{
    char line[1000];
    printf("Write your text for reversing.\n");
    gets(line);
    reverse(line);
    printf("String After Reverse: %s\n", line);
    return 0;
}
