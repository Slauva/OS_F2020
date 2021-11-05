#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    unsigned short id;
    unsigned short age;
} page;

int getMinAgePage(page pages[], int n)
{
    int min_age = 65536;
    int empty_page = -1;
    int page_index = 0;

    for (int i = 0; i < n; i++)
    {
        if (pages[i].age <= min_age)
        {
            min_age = pages[i].age;

            if (pages[i].id != -1)
                page_index = i;
            else
                empty_page = i;
        }
    }

    return empty_page != -1 ? empty_page : page_index;
}

void ageing(page pages[], int n)
{
    FILE *inp = fopen("input.txt", "r");

    int page_number;
    float hit = 0.0;
    float miss = 0.0;

    while (fscanf(inp, "%d", &page_number) != -1)
    {
        int temp = 0;

        for (int i = 0; i < n; i++)
        {
            pages[i].age >>= 1;
            if (page_number == pages[i].age)
            {
                pages[i].age |= 32768;
                temp++;
            }
        }

        if (temp != 1)
        {
            int minPageNum = getMinAgePage(pages, n);
            pages[minPageNum].id = page_number;
            pages[minPageNum].age = 32768;
            miss++;
        }
        else
            hit++;
    }

    printf("Hit/Miss Ratio: %f\t Hit: %f\t Miss: %f\n", hit, miss, hit / miss);
    fclose(inp);
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Write the number of pages: ");
    scanf("%d", &n);

    page *pages = malloc(sizeof(page) * n);

    for (int i = 0; i < n; i++)
        pages[i].id = -1;

    ageing(pages, n);

    return 0;
}
