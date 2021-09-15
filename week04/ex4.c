#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "string.h"

int main()
{
    while (1)
    {
        char line[256];
        printf("> ");
        fgets(line, sizeof line, stdin);

        int pid = fork();
        if (pid == 0)
        {
            system(line);
        }
        waitpid(pid, NULL, 0);
    }
    return 0;
}