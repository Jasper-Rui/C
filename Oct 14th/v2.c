/*
 * Author: 
 * Purpose: 
 * Language:  C
 * File: ASN5.c 
 * Solution to assignment 5, CECD 3401 Fall 2021
 */

#include "ASN5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

Node * make_Node(char * word){
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->word, word);
    node->next = NULL;
    node->prev = NULL;
    return node;
}


bool llist_add_node(LinkedList * linkedlist ,char * word){
    if(linkedlist == NULL){
        return false;
    }
    Node * node = make_Node(word);

    if(linkedlist->size == 0){
        linkedlist->first = node;
        linkedlist->last = node;
        linkedlist->size++;
        //printf("at add node, the added new node is %s\n", node->word);       
    }
    else if(!checkWord(linkedlist, word)){
        node->next = linkedlist->first;
        linkedlist->first = node;
        linkedlist->size++;
        //printf("at add node, the added new node is %s\n", node->word);
    }
    else{
        Node * node_copy = linkedlist->first;
        for(int i = 0; i < linkedlist->size - 1; i++){        
            if(strcmp(node_copy->next->word, word) == 0){

                if(node_copy->next == NULL){
                    node_copy = NULL;
                    
                }
                else{
                    node_copy->next = node_copy->next->next;
                }
                linkedlist->size--;
            }
            node_copy = node_copy->next;
        }
    }
    return true;
}


void llist_remove(LinkedList *linkedList, int index){
    Node *prev = linkedList->first;
    int i = 0;
    while(i < index - 1){
        prev = prev->next;
        i += 1;
    }
    prev->next = prev->next->next;
    linkedList->size--;
}



//check if the word is already exit in the list
//if it is there, then return the index, otherwise return -1
bool checkWord(LinkedList * linkedlist, char * word){
    if(linkedlist == 0){
        return false;
    }
    else{
        Node * node = linkedlist->first;
        for(int i = 0; i < linkedlist->size; i++){
            if(strcmp(node->word, word) == 0){
                return true;
            }
            node = node->next;
        }
    }
}




Node * SearchWord(LinkedList * linkedlist, int index){
    Node * node = linkedlist->first;
    for(int i = 1; i < index; i++){
        node = node->next;
    }
    printf("%s", node->word);
    return node;
}


int main () {
    FILE * fptr;
    LinkedList * linkedlist = llist_initialize();

    fptr = fopen("test2 comp.dat", "r");
    //fptr = fopen("test3.txt", "r");
    /* 
     * Open file in r (read) mode. 
     * input is complete path to read file
     */

    /* fopen() return NULL if last operation was unsuccessful */
    if(fptr == NULL)
    {
        /* File not read hence exit */
        printf("Unable to read file.\n");
        exit(EXIT_FAILURE);
    }

    char input;
    char word[100];
    int i = 0;

    int flag = 0;
    //flag 1 means it's a word
    //flag 2 means it's a number

    while (!feof(fptr)){
        input = fgetc(fptr);
        //printf("input is %c\n", input);
        //A to Z in ASCII is 65 to 90 and a to z is 97 to 122 
        if((input >= 65 && input <= 90) || (input >= 97 && input <= 122)){
            word[i] = input;
            i++;
            flag = 1;
        }
        //0 to 9 in ASNII is 48 to 57
        else if(input >= 48 && input <= 57){
            word[i] = input;
            i++;
            flag = 2;
        }
        //if the character read is one of the symbols then it means a word is read completely
        //10 represent for new line, others represent for symbols
        else if((input >= 32 && input <= 47) || (input >= 58 && input <= 64) || input == 10){
            if(flag == 1){
                llist_add_node(linkedlist, word);
                printf("%s", word);
                memset(word, 0 ,sizeof word);
                i = 0;
                flag = 0;
            }
            else if(flag == 2){
                int index = atoi(word);
                //SearchWord(linkedlist, index);
                Node * node = SearchWord(linkedlist, index);
                char word_copy[100];
                strcpy(word_copy, node->word);
                llist_add_node(linkedlist, word_copy);
                llist_add_node(linkedlist, word_copy);
                memset(word, 0 ,sizeof word);
                i = 0;
                flag = 0;
            }
            printf("%c", input);           
        }
    }
    /*
    printf("\n");
    Node * node = linkedlist->first;
    for(int i = 0; i < linkedlist->size; i++){
        printf("%s ", node->word);
        node = node->next;
    }
    */
    fclose(fptr);
    return 0;
}