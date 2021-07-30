#ifndef __UNSAFE_HEADER
#define __UNSAFE_HEADER


typedef struct _Count
{
    /* data */
    int counter;
} Count;

void* counting(void*);
void count_variable(int);
#endif