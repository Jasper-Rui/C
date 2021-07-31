#include "safe.h"
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>
#define COUNT_SIZE 1000
sem_t wait_here;

void* counting(void* countinput){
  Count* count = countinput;
  

  while(count->counter < COUNT_SIZE){
      count->counter++;
      printf("%d\n",count->counter);
  }
  return count;

}
void count_variable(int number){
    
    Count count;
    pthread_t thread[number];
    sem_init(&wait_here,0,1);
    
    sem_wait(&wait_here);
    for(int i = 0; i < number; i++){
        pthread_create(&thread[i], NULL, counting, &count);
        sleep(4);
        sem_post(&wait_here);
    }
    
    for(int i = 0; i < number; i++){
        pthread_join(thread[i],NULL);
    }

    
}