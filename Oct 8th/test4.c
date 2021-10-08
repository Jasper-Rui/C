#include <stdio.h>
#define MAX 0
int main () {

//based on if the variable inside ( ) is defined
#if defined(MAX)
    printf("MAX is defined %d\n", MAX);
#endif

#ifdef MAX
    printf("MAX is defined %d\n", MAX);
#endif

    return 0;
}