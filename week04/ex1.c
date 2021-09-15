#include <stdio.h>
#include <unistd.h>

int main() {
    int pid_f = fork();
    int pid = getpid();

    if (pid_f == 0) {
        printf("Hello from child [%d - %d]\n", pid_f, pid);
    } else {
        printf("Hello from parent [%d - %d]\n", pid_f, pid);
    }

    return 0;
}