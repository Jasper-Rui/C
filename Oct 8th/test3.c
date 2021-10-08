#include <stdio.h>
#define m 100
int main (){

#if m == 100
    printf("hehe\n");    
#elif m == 200
    printf("haha\n"); 
#else 
    printf("haha\n");
    printf("haha\n");
#endif

    return 0;
}
