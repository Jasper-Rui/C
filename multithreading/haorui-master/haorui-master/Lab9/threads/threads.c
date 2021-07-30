#include "threads.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 10000000

void* fill(void* arguments){

    
    Args* args = arguments; 
    int* arr = args->arr;
    int start = args->start;
    int end = args->end;
  
    for(int i = start; i < end ; i++){
        arr[i] = arr[i] * arr[i];
    }
    return args;

}

void fill_memory(int* array, int number){

    
    
    pthread_t thread[number];
    Args args[number];
    int range = ARRAY_SIZE/number; 
    for(int i = 0; i < number; i++){
        args[i].arr = array;
        args[i].start = range*i;
        args[i].end = range*(i+1);
    }
    args[number-1].end = ARRAY_SIZE;
    
    for(int i = 0; i < number; i++){
        pthread_create(&thread[i], NULL, fill, &args[i]);
    }

    for(int i = 0; i < number; i++){
        pthread_join(thread[i],NULL);
    }
}