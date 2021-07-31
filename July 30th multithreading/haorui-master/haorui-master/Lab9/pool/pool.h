#ifndef __POOL_HEADER
#define __POOL_HEADER
#include <stdbool.h>
#include "../lib/queue.h"
#include "../lib/linked_list.h"
#include "../lib/array_list.h"
#include "../lib/heap.h"

typedef struct _Operation
{
    /* data */
    int (*op)(int,int);
    int a;
    int b;

} Operation;

typedef struct _Args
{
    /* data */
    Operation* operation;
    bool is_complete;
} Args;

void* compute(void*);
bool read_operations(char*,Queue*);
ArrayList* execute_thread_pool(char*,int);
void print_sorted(ArrayList*);
int add(int,int);
int sub(int,int);
int mul(int,int);
int compareInt(void*,void*);
void printInt(void*);
#endif