#include <stdio.h>

int main()
{
    int i = 0;
    while(i <= 10){
        if(5 == i){
           break; 
        }
        printf("%d\n", i);
        i++;
    }
    
    //output is 0 1 2 3 4
    printf("\n");
    
    
    /*int j = 0;
    while(j <= 10){
        if(5 == j){
           continue; 
        }
        printf("%d ", j);
        j++;
    }*/
    //output is a death cycle
    //cause it will keep looping as j = 5 and continue and won't stop
    
    // but if we add something like
    int j = 0;
    while(j <= 10){
        if(5 == j){
            j++;
            continue; 
        }
        printf("%d ", j);
        j++;
    }
    //output is 0 1 2 3 4 6 7 8 9 10 and it will skip printf 5 
    return 0;
}
