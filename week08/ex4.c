#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

#define t_size 10 * 1024 * 1024 * 8 // 10 MB

int main(int argc, char const *argv[])
{
    struct rusage usage;
    for (int i = 0; i < 10; i++)
    {
        void *buff = malloc(t_size);
        memset(buff, 0, t_size);
        getrusage(RUSAGE_SELF, &usage);
        printf("maximum resident set size: %ld\n", usage.ru_maxrss);
        printf("integral shared memory size: %ld\n", usage.ru_ixrss);
        printf("integral unshared data size: %ld\n", usage.ru_idrss);
        printf("integral unshared stack size: %ld\n", usage.ru_isrss);
        printf("\n");
        sleep(1);
    }
    printf("Finish simulation\n");
    return 0;
}