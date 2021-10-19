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

// top - 20:38:31 up 39 min,  1 user,  load average: 0,60, 0,95, 0,96
// Tasks: 319 total,   1 running, 248 sleeping,   0 stopped,   0 zombietop - 20:38:32 up 39 min,  1 user,  load average: 0,60, 0,95, 0,96
// Tasks: 315 total,   1 running, 244 sleeping,   0 stopped,   0 zombie%Cpu(s):  8,8 us,  7,0 sy,  0,1 ni, 83,8 id,  0,1 wa,  0,0 hi,  0,1 si,  0,0 st
//   PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
//  1410 slavako+   9 -11 2384208  19816  15808 S   5,9  0,1   1:57.25 pulseaudio
//  3410 slavako+  20   0  645700 171944  97688 S 127,5  1,1   3:08.87 code
//  1410 slavako+   9 -11 2384208  19816  15808 S   6,9  0,1   1:57.32 pulseaudio
//  3372 slavako+  20   0 50,723g 343828 155172 S   4,9  2,1   3:48.05 code
// 15952 slavako+  20   0   45580   4352   3620 R   2,9  0,0   0:00.21 top
//  1142 slavako+  20   0 1871328 159644 120844 S   1,0  1,0   1:48.03 Xorg
//  1357 slavako+  20   0 4200732 276956 134764 S   1,0  1,7   1:29.17 gnome-shell
//  2720 slavako+  20   0 2661644 145768  95432 S   1,0  0,9   0:16.21 Web Content
//  3326 slavako+  20   0 36,669g 153964 104840 S   1,0  0,9   0:30.99 code
//  3450 slavako+  20   0 36,538g 130452  91720 S   1,0  0,8   0:15.83 code
//  3483 slavako+  20   0 36,439g  80820  53852 S   1,0  0,5   0:06.04 code