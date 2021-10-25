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

Node * make_Node(LinkedList * linkedlist ,char * word){
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
    Node * node = make_Node(linkedlist, word);
    if(linkedlist->size == 0){
        linkedlist->first = node;
        linkedlist->last = node;
        linkedlist->size = 1;
        
    }
    else{
        node->next = linkedlist->first;
        linkedlist->first = node;
        linkedlist->size += 1;
    }
    return true;
}



//check if the word is already exit in the list
//if it is there, then return the index, otherwise return -1
int checkWord(LinkedList * linkedlist, char * word){
    if(linkedlist != 0){
        Node * node = linkedlist->first;
        //printf("word is %s\n", word);
        //printf("node->word is %s\n", node->word);

        //int a = strcmp(node->word, word);
        //printf("a is %d", a);
        for(int i = 0; i < linkedlist->size; i++){
            if(strcmp(word, node->word) == 0){
                printf("%d\n", i);
                return i;
            }
            //printf("%d ", linkedlist->size);
            //printf("%s ", word);
            //printf("%s \n", node->word);
            node = node->next;
        }
    }
    return -1;
}

//first check is the word is exit, if not add it to the list
//otherwise put it in front
void addWord(LinkedList * linkedlist, char * word){
    int index = 0;
    int check = checkWord(linkedlist, word);
    if(linkedlist->size == 0 || check == -1){
        llist_add_node(linkedlist, word);
    }
    else {
        Node * node = linkedlist->first;
        for(int i = 0; i < check; i++){
            node = node->next;
        }
        //once we find the node
        //we readd the node to the front and remove this node
        //node here is a copy 
        //delete the node at index 
        Node * temp = node->next;
        node->prev->next = temp;
        temp->prev = node->prev;
        linkedlist->size--;
        llist_add_node(linkedlist, word);
    }
}


void SearchWord(LinkedList * linkedlist, int index){
    Node * node = linkedlist->first;
    for(int i = 0; i < index - 1; i++){
        node = node->next;
    }
    printf("%s", node->word);
}


int main () {
    FILE * fptr;
    LinkedList * linkedlist = llist_initialize();

    fptr = fopen("test2 comp.dat", "r");
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
                addWord(linkedlist, word);
                printf("%s", word);
                printf("%c", input);

                memset(word, 0 ,sizeof word);
                i = 0;
                flag = 0;
            }
            else if(flag == 2){
                int index = atoi(word);
                SearchWord(linkedlist, index);
                memset(word, 0 ,sizeof word);
                i = 0;
                flag = 0;
            } 
            printf("%c", input);           
        }
    }
    
    Node * node = linkedlist->first;
    for(int i = 0; i < linkedlist->size; i++){
        printf("%s ", node->word);
        node = node->next;
    }

    fclose(fptr);
    return 0;
}