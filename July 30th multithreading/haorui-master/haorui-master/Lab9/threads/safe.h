#ifndef __SAFE_HEADER
#define __SAFE_HEADER
#include <stdbool.h>

typedef struct _Count
{
    /* data */
    int counter;
} Count;

void* counting(void*);
void count_variable(int);
#endif