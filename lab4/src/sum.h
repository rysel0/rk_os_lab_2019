
#ifndef SUM_H
#define SUM_H

struct SumArgs {
    int *array;
    int begin;
    int end;
};

void *ThreadSum(void *args);

#endif // SUM_H