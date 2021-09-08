#include <stdio.h>

void bubble_sort(int list[], int n) {
    for (int c = 0; c < n - 1; c++) {
        for (int d = 0; d < n - c - 1; d++) {
            if (list[d] > list[d + 1]) {
                int t = list[d];
                list[d] = list[d + 1];
                list[d + 1] = t;
            }
        }
    }
}

int main() {
    int array[100] = {5, 4, 3, 2, 1, 0}, n = 6;

    bubble_sort(array, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", array[i]);

    return 0;
}