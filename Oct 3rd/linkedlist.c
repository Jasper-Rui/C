#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

//Helpful function
Node * make_Node(LinkedList * list ,void *item){
    Node *node = (Node *) malloc(sizeof(Node));
    int itemSize = list->itemSize;
    void *data = malloc(itemSize);
    memcpy(data, item, itemSize);
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

LinkedList* llist_initialize(int itemSize, char * type){
    LinkedList *list = malloc(sizeof(LinkedList));
    if(list == NULL){
        return NULL;
    }
    list->itemSize = itemSize;
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    list->type = malloc(strlen(type)+1);
    strcpy(list->type, type);
    return list;
}

void add_single_node(LinkedList *linkedList, Node * node){
    linkedList->first = node;
    linkedList->last = linkedList->first;
    linkedList->size = 1;
}

bool llist_add_first(LinkedList *linkedList, void *item){
    if(linkedList == NULL || item == NULL){
        return false;
    }
    Node *node = make_Node(linkedList, item);
    if(linkedList->size != 0){
        node->next = linkedList->first;
        linkedList->first = node;
        linkedList->size += 1;
    }else{
        add_single_node(linkedList, node);
    }
    return true;
}

bool llist_add_last(LinkedList *linkedList, void *item){
    if(linkedList == NULL || item == NULL){
        return false;
    }
    Node *node = make_Node(linkedList, item);
    if(linkedList->size != 0){
        linkedList->last->next = node;
        linkedList->last = node;
        linkedList->size += 1;
    }else{
        add_single_node(linkedList, node);
    }
    return true;
}


bool llist_add_at(LinkedList *linkedList, int index, void *item){
    if(linkedList == NULL || item== NULL){
        return false;
    } else if(index == 0){
        return llist_add_first(linkedList, item);
    }else if(index == linkedList->size){
        return llist_add_last(linkedList, item);
    }else{
        Node *prev = linkedList->first;
        int i = 0;
        while(i < index - 1){
            prev = prev->next;
            i += 1;
        }

        Node *node = make_Node(linkedList, item);
        node->next = prev->next;
        prev->next = node;
        return true;
    }
}


void* llist_get(LinkedList *linkedList, int index){
    void * res = NULL;
    if(linkedList != NULL){
        Node *node = linkedList->first;
        int i = 0;
        while(i < index){
            node = node->next;
            i += 1;
        }
        res = node->data;
    }
    return res;
}

int llist_index_of(LinkedList *linkedList, void *item){
    if(linkedList != NULL || item != NULL){
        Node * node = linkedList->first;
        int i = 0;
        while(i < linkedList->size){
            if(!memcmp(node->data, item,linkedList->itemSize)){
                return i;
            }
            i += 1;
            node = node->next;
        }
        
    }
    return -1;
}

void* llist_remove_first(LinkedList *linkedList){
    if(linkedList == NULL){
        return NULL;
    }
    void * data = linkedList->first->data;
    linkedList->first = linkedList->first->next;
    if(linkedList->first == NULL){
        linkedList->last = NULL;
    }
    linkedList->size--;
    return data;

}

void* llist_remove_last(LinkedList *linkedList){
    if(linkedList == NULL){
        return NULL;
    }
    if(linkedList->size == 1){
        return llist_remove_first(linkedList);
    }
    void * data = linkedList->last->data;
    Node * node = linkedList->first;
    while(node->next != linkedList->last){
        node = node->next;
    }
    node->next = NULL;
    linkedList->last = node;
    linkedList->size--;
    return data;
}

void* llist_remove(LinkedList *linkedList, int index){
    if(linkedList == NULL){
        return NULL;
    }
    if(index == 0){
        return llist_remove_first(linkedList);
    }else if(index == linkedList->size){
        return llist_remove_last(linkedList);
    }else{
        Node *prev = linkedList->first;
        int i = 0;
        while(i < index - 1){
            prev = prev->next;
            i += 1;
        }
        void * data = prev->next->data;
        prev->next = prev->next->next;
        linkedList->size--;
        return data;
    }


}

bool llist_destroy(LinkedList * list){
    if(list != NULL){
        Node * node = list->first;
        Node * next = node->next;
        while(node->next != NULL){
            free(node->data);
            free(node);
            node = next;
            next = node->next;
        }
        free(node->data);
        free(node);
        return true;
    }else{
        return false;
    }
}
