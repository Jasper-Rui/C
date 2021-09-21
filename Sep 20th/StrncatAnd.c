#include <stdio.h>
#include <string.h>
#include <assert.h>


int main () {

    char arr1[20] = "asdfghjkl";
    char arr2[] = "xxxxx";

    strncpy(arr1, arr2, 2);
    printf("%s\n", arr1);
    //now arr1 becomes xxdfghjkl

    //what if we try
    strncpy(arr1, arr2, 6);
    //be careful with the size
    printf("%s\n", arr1);


    char arr3[20] = "abc\0xxxxxx";
    char arr4[] = "defgyh";

    strncat(arr3, arr4, 3);
    printf("%s\n", arr3);
    //arr3 will be "abcdef\0xxxxx"
    //strncat will add a \0 after adding the content

    //evenif
    //strncat(arr3, arr4, 6);
    //it will check if there is actually 6 char to add, or it will end when there is no char and will add \0



    char arr5[10] = "abcdef";
    char arr6[] = "abcqw";
    int n = strncmp(arr5, arr6, 3);
    printf("%d\n", n);

    n = strncmp(arr5, arr6, 4);
    printf("%d\n", n);

    int nn = strncmp(arr5, arr6, 6);
    printf("%d\n", nn);
    



    return 0;
}