#include <stdio.h>

int main (){

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'}; // 6 variables so arr size is 6
    printf("%d\n", sizeof(arr)); //here is the size of whole array so it's 6 * 1 byte -> 6

    printf("%d\n", sizeof(arr + 0)); //here arr is the 1st var address, by plus 0, it means arr[0] -> size is 1

    //only sizeof(arr) or sizeof(&arr) is the whole address of array -> 6, 4 or 8 (depends on compiler) x32/x64

    printf("%d\n", sizeof(*arr)); //*arr -> arr[0] -> 1 
    //why?
    //so, since its not either sizeof(arr) or sizeof(&arr), so here arr is the 1st var address, by adding *arr
    //we get the value of arr[0] -> a char -> 'a' -> sizeof(char) -> 1

    printf("%d\n", sizeof(arr[1]));
    //same as sizeof(char) -> 1

    printf("%d\n", sizeof(&arr)); // 4 or 8 (depends on compiler) x32/x64

    printf("%d\n", sizeof(&arr + 1)); // &arr is the address of array, by plus 1, it add the same sizeof(&arr), so here 
    // originally -> a b c d e f
    // &arr starts at a, by add 1
    // &arr + 1 -> a b c d e f arr is here now
    //but it is still an address
    printf("%d\n", sizeof(&arr[0] + 1)); //address of arr[1]






    return 0;
}