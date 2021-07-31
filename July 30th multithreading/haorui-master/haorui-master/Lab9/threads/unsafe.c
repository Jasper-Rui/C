#include "unsafe.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>


#define COUNT_SIZE 1000

void* counting(void* counternumber){
   Count* count = counternumber;
   while(count->counter < COUNT_SIZE){
       count->counter++;
       printf("%d\n",count->counter);
   }
   return count;
}
void count_variable(int number){
    pthread_t thread[number];
    Count count;

    for(int i = 0; i < number; i++){
        pthread_create(&thread[i], NULL, counting, &count);
    }

    for(int i = 0; i < number; i ++){
        pthread_join(thread[i], NULL);
    }

}