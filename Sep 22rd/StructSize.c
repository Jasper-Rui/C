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

struct S3 {
    char c1; // 1 
    char c2; // 1
    int a; // 4
};


struct S4 {
    double d1; // 8 8 8 
    char c2; // 1 8 1
    int a; // 4 8 4
};
// -> 16


struct S5 {
    char c1; // 1 8 1 -> 8
    struct S4 s;// 16 16 16 -> 24
    double a; // 8 16 8 -> 32
};

// -> 32

int main () {

    struct S1 s = {'a', 100, 'b'};
    printf("%d\n", sizeof(struct S1)); // -> 12 now
    printf("%d\n", sizeof(s)); // -> 12 now
    printf("%d\n", sizeof(struct S2)); // -> 8 now
    printf("%d\n", sizeof(struct S3)); // -> 8 now
    printf("%d\n", sizeof(struct S4)); // -> 16 now
    printf("%d\n", sizeof(struct S5)); // -> 16 now
    //why there is a difference?
    //explaination
    // -> memory alignment

    //rules:
    //1. 1st member always been put at the 0 index
    //2. from the 2nd member, it will always been put at n times (a specific number)
    //a specific number -> default + data type size
    //3. the overall size for a struct must be n times (max data type size)
    //

    return 0;
}