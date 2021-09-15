#include "stdio.h"
#include "stdlib.h"

int main() {
    while (1) {
        char line[256];
        printf("> ");
        scanf("%s", line);
        printf("> ");
        system(line);
    }
}