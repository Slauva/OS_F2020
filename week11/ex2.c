#include "stdio.h"
#include "sys/dir.h"

int main()
{
    struct dirent *root = opendir("/");
    struct dirent *dp;

    while ((dp = readdir(root)) != NULL)
    {
        printf("%s\n", dp->d_name);
    }

    closedir(root);
    return 0;
}