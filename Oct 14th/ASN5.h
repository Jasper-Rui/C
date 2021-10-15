#ifndef __ASN5_HEADER
#define __ASN5_HEADER
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node {
    char word[100];
    struct _Node* next;
    struct _Node* prev;
} Node;

typedef struct _LList{
    Node* first;
    Node* last;
    int size;
} LinkedList;


Node * make_Node(LinkedList * list ,char *command);

LinkedList* llist_initialize();

bool llist_add_node(LinkedList * list ,char *command);

bool llist_remove_last(LinkedList *linkedList);
#endif
