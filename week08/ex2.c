#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define t_size 10 * 1024 * 1024 * 8 // 10 MB

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        void *buff = malloc(t_size);
        memset(buff, 0, t_size);
        sleep(1);
    }
    printf("Finish simulation\n");
    return 0;
}

// procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
//  r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
// 18  0      0 8627408 498752 4122176    0    0   387   332  220 1595  6  2 91  0  0
//  1  0      0 8560960 498752 4128992    0    0     0     0 1650 63288  7  3 91  0  0
//  0  0      0 8480468 498752 4128992    0    0     0     0  508 2199  2  1 97  0  0
//  0  0      0 8398584 498752 4128992    0    0     0     0  815 2734  2  1 97  0  0
//  0  0      0 8315164 498764 4126276    0    0     0   116  591 2802  2  2 96  0  0
//  0  0      0 8241156 498772 4126300    0    0    32   148  665 2496  2  2 97  0  0
//  0  0      0 8160980 498772 4123236    0    0     0    32  475 2018  1  1 98  0  0
//  0  0      0 8079836 498772 4123236    0    0     0   132  333 1916  1  1 98  0  0
//  0  0      0 8000532 498772 4122980    0    0     0     0  868 2797  4  2 94  0  0
//  0  0      0 7919420 498772 4122468    0    0     0     0  348 1849  1  1 99  0  0
//  0  0      0 7837268 498780 4122468    0    0     0    80  365 1925  1  1 98  0  0

//               total        used        free      shared  buff/cache   available
// Mem:            15G        2,9G        8,2G        549M        4,4G         11G
// Swap:          2,0G          0B        2,0G
// Total:          17G        2,9G         10G
