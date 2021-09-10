#include <stdio.h>
#include <string.h>

int main () {
    char arr[] = "abcedfg";
    //size_t -> unsigned int
    size_t sz = strlen(arr);
    //to print unsigned int
    printf("%u\n", sz);

    char arr1[] = {'a', 'b'};
    //here strlen is not reconmmended, cuz strlen works by finding the '\0' in an array
    //and there is no '\0' in arr1

    if(strlen("abc") - strlen("abcedf") > 0){
        printf("haha\n");
    }
    else{
        printf("hehe\n");
    }

    //be careful, strlen return type is size_t -> unsigned int -> only positive

    //both sizeof / size_t -> unsigned int 

    return 0;
}