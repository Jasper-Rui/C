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
    char command[100];
    int pid;
    struct _Node* next;
    struct _Node* prev;
} Node;

typedef struct _LList{
    Node* first;
    Node* last;
    int size;
} LinkedList;





void addhistory(LinkedList * linkedlist, char *command, int pid);

void printHistory(LinkedList * linkedlist);

Node * make_Node(LinkedList * list ,char *command, int pid);

LinkedList* llist_initialize();

bool llist_add_node(LinkedList * list ,char *command, int pid);

bool llist_remove_last(LinkedList *linkedList);
#endif
