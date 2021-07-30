#include "pool.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void* compute(void* arguments){
    if(arguments == NULL){
        return NULL;
    }

    Args* args = arguments;
    
    if(args->operation == NULL){
        return NULL;
    }
    Operation* operation = args->operation;

    int a = operation->a;
    int b = operation->b;

    int* result = malloc(sizeof(int));
    *result = operation->op(a, b);
    args->is_complete = true;

    return result;

}

bool read_operations(char* ptr,Queue* queue){
    if (ptr == NULL || queue == NULL){
        return NULL;
    }
    Operation* operation = malloc(sizeof(*operation));
    FILE* fileptr = fopen(ptr,"r");
    if(fileptr == NULL){
        return false;
    }
    int op,a,b;
    while(fscanf(fileptr, "%d %d %d", &op, &a, &b) == 3){
        if(op == 0){
            operation->op = &add;
        }
        else if(op == 1){
            operation->op = &sub;
        }
        else{
            operation->op = &mul;
        }
        operation->a = a;
        operation->b = b;
        queue_enqueue(queue, operation);
    }
    return true;
}

ArrayList* execute_thread_pool(char* name,int poolsize){
    if(name == NULL || poolsize <= 0){
        return NULL;
    }
    //initialize variables
    ArrayList* array = alist_initialize(10, sizeof(int), "int");
    Queue* queue = queue_initialize(sizeof(Operation), "Opreation");
    Args args[poolsize];
    pthread_t threads[poolsize];

    bool read = read_operations(name,queue);
    if(!read){
        return NULL;
    }


    //create threads based on the poolsize
    for(int i = 0; i < poolsize; i++){
        args[i].operation = queue_dequeue(queue);
        args[i].is_complete = false;
        pthread_create(&threads[i], NULL, compute, &args[i]);
    }
    //after we created threads now we have to manage them one by one
    //since we already have poolsize threads, we have to check if they are executed
    // go through the queue, we check the threads from 0
    // if there exits some threads completed, we join them and store the value to array
    //and at the same index, we extract new opreations and execute it with same index args
    // then we have to set is_complete to false and go through entire queue
    int index = 0;
    int* result = NULL;
    while(queue_size(queue) > 0){
        if(args[index].is_complete){
            pthread_join(threads[index], (void**) &result);
            alist_add(array,(int*)result);
            args[index].operation = queue_dequeue(queue);
            args[index].is_complete = false;
            pthread_create(&threads[index], NULL, compute, &args[index]);
        }
        index = (index + 1) % poolsize;
    }

    for(int i = 0; i < poolsize; i++ ){
        pthread_join(threads[i], (void**) &result);
        alist_add(array,(int*)result);
    }
    return array;
}

void print_sorted(ArrayList* array){
    Heap* heap = heap_initialize(sizeof(int), "int", &compareInt, &printInt);
    for(int i = 0; i <10000; i++){
        void* ptr = alist_get(array, i);
        heap_insert(heap, ptr);
    }

    for(int i = 0; i <10000; i++){
        printInt(heap_remove(heap));
    }
 }

int add(int a, int b){
	return a + b;
}

int sub(int a, int b){
	return a - b;
}

int mul(int a, int b){
	return a * b;
}
int compareInt(void* a, void* b){
    return *((int *) b) - *((int *) a);
}

void printInt(void* a){
    printf("%d\n",*((int*) a));
}
