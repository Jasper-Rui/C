#ifndef __ASN4_HEADER
#define __ASN4_HEADER
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _Node {
    char task_name[100];
    int arrtive_time;
    int run_time;
    struct _Node* next;
    struct _Node* prev;
} Node;

typedef struct _LList{
    Node* first;
    Node* last;
    int size;
} LinkedList;





Node * make_Node(LinkedList * list ,char * task_name, int arrive_time, int run_time);

LinkedList* llist_initialize();

bool llist_add_node(LinkedList * list ,char * task_name, int arrive_time, int run_time);

bool llist_remove_last(LinkedList *linkedList);

void * FCFS  (FILE* filename);

void * RR  (FILE* filename);

void * NPSJF  (FILE* filename);

void * PSJF  (FILE* filename);



#endif
