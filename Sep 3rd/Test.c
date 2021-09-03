#include <stdio.h>
#include <string.h>

int main(){

    const char* p = "abcdef";

    printf("%d\n", strlen(p)); //p is the address for a so it's 6
    printf("%d\n", strlen(p + 1)); // 5
    //printf("%d\n", strlen(*p)); //error
    //printf("%d\n", strlen(p[0])); //error p[0] -> equals(*(p + 0)) -> *p -> error
    printf("%d\n", strlen(&p)); // random value 
    printf("%d\n", strlen(&p + 1)); // random value
    printf("%d\n", strlen(&p[0] + 1)); // 5 &p[0] -> &a + 1 -> start with b -> 5

    printf("\n");
    printf("\n");
    printf("\n");

    int a[3][4] = {0};
    //only sizeof(a) or &a -> here a is the whole array
    //all others are -> the 1st var in the array
    //here is a[0] the 1st row

    printf("%d\n", sizeof(a));// 3 * 4 * 4 = 48; 3 rol 4 col, each of them is 4 byte
    printf("%d\n", sizeof(a[0][0])); // 4 
    printf("%d\n", sizeof(a[0])); // 4 * 4 = 16
    printf("%d\n", sizeof(a[0] + 1)); // -> a[1] = 4 * 4 = 16 this is actually wrong
    //as we mention above, if and only if sizeof(a[0]) or & a[0] will represent the whole array
    //so here we can say that
    //a[0] is the name for the first row of a[3][4]
    //and a[0] represent the address for 1st element int 1st row -> here a[0][0]
    //so after we + 1, we move to a[0][1], it is still an address
    //so it's 4/8 (depends on compiler)
    printf("%p\n", &a[0][0]);
    printf("%p\n", a[0] + 1);

    printf("%d\n", sizeof(*(a[0] + 1)));// an integer -> 4
    printf("%d\n", sizeof(a + 1)); //a[1] -> it's an address -> 4 / 8

    printf("%d\n", sizeof(*(a + 1))); // *(a+1) -> a[1] -> 4 element -> 4 * 4 -> 16 -> it's sizeof(a[1])
    //here a[1] is the name of an 1 d array
    //so here it's the address of whole array in the second row

    printf("%d\n", sizeof(&a[0] + 1));
    //a[0] -> 1st row name
    //&a[0] -> 1st row address
    //&a[0] + 1 -> get the address of 1st row and add the same size of &a[0]
    //-> &a[1]
    //-> 4/8 (it's an address)

    printf("%d\n", sizeof(*(&a[0] + 1)));
    //*(&a[1]) -> a[1] -> 16
    printf("%d\n", sizeof(*a)); // -> 16 -> 1st row
    printf("%d\n", sizeof(a[3])); // out of boundary, but in c it will go to the address and check it for u
    //if the a[4] exist, then it will print 16 as well, it will not access directly to that part
    //but it will check if it exists
    








    return 0;
}