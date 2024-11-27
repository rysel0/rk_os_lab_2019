#include "sum.h"
#include <stdlib.h>

void *ThreadSum(void *args) {
    struct SumArgs *sum_args = (struct SumArgs *)args;

    int *result = malloc(sizeof(int));
    *result = 0;

    for (int i = sum_args->begin; i < sum_args->end; i++) {
        *result += sum_args->array[i];
    }

    return (void *)result;
}