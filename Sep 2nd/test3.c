#include <stdio.h>
#include <string.h>

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

    //-------------------------------------------------------------------------------------------------------------------------
    printf("\n");
    printf("\n");
    printf("\n");
    char str[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    printf("%d\n", strlen(str)); // there is no '\0' in the str array, so for some compiler it will be an unexpected result
    //strlen is very stubborn, it will keep going until a '\0' is found 
    printf("%d\n", strlen(str + 0)); // same as last one
    //printf("%d\n", strlen(*str)); //segmentation falut
    //here (*str) is 'a' in ASCII is 97 -> a wild pointer
    //so strlen will assume user passed an wild poineter with 97

    //printf("%d\n", strlen(str[1])); //segmentation falut, here we passed str[1] -> 'b' -> 98
    //strlen() need an address, not an actual value

    
    printf("%d\n", strlen(&str)); //same as strlen(str)
    //size_t strlen(const char *);
    //but with &str -> char (*) []
    //however it is still the address of the array

    printf("%d\n", strlen(&str + 1)); //start with what after 'f', and everything after 'f' is unknown
    printf("%d\n", strlen(&str[0] + 1)); //same as strlen(str)


    
    //-------------------------------------------------------------------------------------------------------------------------
    printf("\n");
    printf("\n");
    printf("\n");

    char arrr[] = "abcdef"; // -> "ancdef\0"

    printf("%d\n", sizeof(arrr)); // 7
    printf("%d\n", sizeof(arrr + 0)); // -> arrr[0] -> 1]st var address -> 4
    printf("%d\n", sizeof(*arrr)); // 1
    printf("%d\n", sizeof(arrr[1])); // 1
    printf("%d\n", sizeof(&arrr)); //4 or 8
    printf("%d\n", sizeof(&arrr + 1)); // jump over the arrr, but it is still an address -> 4  / 8
    printf("%d\n", sizeof(&arrr[0] + 1)); // the address of arr[1] 4 / 8

    printf("\n");
    printf("\n");
    printf("\n");
    printf("%d\n", strlen(arrr)); // 6
    printf("%d\n", strlen(arrr + 0)); // 6
    //printf("%d\n", strlen(*arrr)); //error 
    //printf("%d\n", strlen(arrr[1])); //error
    printf("%d\n", strlen(&arrr)); // 6
    // printf("%d\n", strlen(&arrr + 1)); // error
    printf("%d\n", strlen(&arrr[0] + 1)); // 5 "bcde f"


    printf("\n");
    printf("\n");
    printf("\n");
    
    const char* p = "abcdef";
    printf("%d\n", sizeof(p)); // 4 / 8, p here is a pointer variable
    printf("%d\n", sizeof(p + 1)); // 4 / 8, p here is a pointer variable
    printf("%d\n", sizeof(*p)); // 1, *p here is the 1st element -> 'a' 
    printf("%d\n", sizeof(p[0])); // 1 same as above
    printf("%d\n", sizeof(&p)); // 4 or 8
    printf("%d\n", sizeof(&p + 1)); // 4 or 8
    printf("%d\n", sizeof(&p[0] + 1)); // 4 / 8












    return 0;
}