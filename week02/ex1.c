#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

    int int_k = INT_MAX;
    float float_k = FLT_MAX;
    double double_k = DBL_MAX;

    printf("Value: %d with size: %ld\n", int_k, sizeof(int_k));
    printf("Value: %f with size: %ld\n", float_k, sizeof(float_k));
    printf("Value: %f with size: %ld\n", double_k, sizeof(double_k));

    return 0;
}
