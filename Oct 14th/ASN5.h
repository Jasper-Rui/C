#ifndef __ASN5_HEADER
#define __ASN5_HEADER

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node {
    struct _Node * next;
    struct _Node * prev;
    char word[50];
} Node;



typedef struct _LList{
    Node * first;
    Node * last;
    int size;
} LinkedList;


Node * make_Node(char * word);

LinkedList* llist_initialize();

bool llist_add_node(LinkedList * list ,char * word);

bool checkWord(LinkedList * linkedlist, char * word);

Node * SearchWord(LinkedList * linkedlist, int index);

#endif
