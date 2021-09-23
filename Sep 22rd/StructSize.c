#include <stdio.h>
#include <string.h>
#include <assert.h>


struct S1 {
    char c1; // 1
    int a; // 4
    char c2; // 1
};

 
 struct S2 {
    int a; // 4
    char c1; // 1 
    char c2; // 1
};


int main () {

    struct S1 s = {'a', 100, 'b'};
    printf("%d\n", sizeof(struct S1)); // -> 12 now
    printf("%d\n", sizeof(s)); // -> 12 now
    printf("%d\n", sizeof(struct S2)); // -> 8 now
    //why there is a difference?
    //explaination
    // -> memory alignment

    return 0;
}