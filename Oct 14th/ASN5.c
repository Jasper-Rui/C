/*
 * Author: 
 * Purpose: Spell check
 * Language:  C
 * File: ASN4.c 
 * Solution to assignment 4, CECD 3401 Fall 2021
 */

#include "ASN4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int wait_status;
int nth_command;
char copyofcommand[100];
char nth_commands[100];


/*
 * Function:  make_Node
 * --------------------
 *  linkedlist: a linked list 
 *  command: a pointer that points to the location stores the string
 *  pid: children process identifier
 * 
 *  returns: the node with the commands and the pid
 */
Node * make_Node(LinkedList * linkedlist ,char * command){
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->command, command);
    node->next = NULL;
    node->prev = NULL;
    return node;
}
/*
 * Function:  llist_initialize
 * --------------------
 *  no input parameter
 * 
 *  returns: the initialized linked_list
 */
LinkedList* llist_initialize(){
    LinkedList *linkedlist = malloc(sizeof(LinkedList));
    if(linkedlist == NULL){
        return NULL;
    }
    linkedlist->size = 0;
    linkedlist->first = NULL;
    linkedlist->last = NULL;
    return linkedlist;
}

/*
 * Function:  llist_add_node
 * --------------------
 *  linkedlist: linked list pointer
 *  command: command string to be added
 *  pid: integer pid to be added
 * 
 *  returns: if the new node add successfully
 */
bool llist_add_node(LinkedList * linkedlist ,char *command){
    if(linkedlist == NULL){
        return false;
    }
    Node *node = make_Node(linkedlist, command);
    if(linkedlist->size != 0){
        node->next = linkedlist->first;
        linkedlist->first = node;
        linkedlist->size += 1;
    }
    else{
        linkedlist->first = node;
        linkedlist->last = linkedlist->first;
        linkedlist->size = 1;
    }
    return true;
}

/*
 * Function:  llist_remove_last
 * --------------------
 *  linkedlist: linked list pointer
 * 
 *  returns: false if the linked_list is NULL, otherwise 
 *           the linked_list pointer that has already removed the last node
 */
bool llist_remove_last(LinkedList *linkedlist){
    if(linkedlist == NULL){
        return false;
    }
    if(linkedlist->size == 1){
        linkedlist->first = NULL;
        linkedlist->last = NULL;
        linkedlist->size--;
    }
    else{
        Node * node = linkedlist->first;
        while(node->next != linkedlist->last){
            node = node->next;
        }
        node->next = NULL;
        linkedlist->last = node;
        linkedlist->size--;
    }
    return true;
}



int main () {
    FILE * fptr;
    char input_file_name[100];
    LinkedList * linkedlist = llist_initialize();
    while (scanf("%s", input_file_name) != NULL){


    }

    



    return 0;
}