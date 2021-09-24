#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int main () {
    //int arr[10] = {0}; -> 40 byte

    int * p = (int*) malloc(40);
    if(p == NULL){
        return -1;
    }
    //successfully malloc 40 bype space

    for (int i = 0; i < 10; i++)
    {
        *(p + i) = i;
    }
    
    //if we dont need those space anymore
    //free it
    free(p);
    
    p = NULL;
    return 0;
}