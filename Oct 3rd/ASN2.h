#ifndef __ASN2_HEADER
#define __ASN2_HEADER
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct _Node {
    void* data;
    struct _Node* next;
    struct _Node* prev;
} Node;

typedef struct _LList{
    Node* first;
    Node* last;
    int size;
    int itemSize;
    char* type;
} LinkedList;





#endif
