#include <stdio.h>
#include <string.h>
//strcpy is to copy a string

//what does strcat do?
//connect two strings or add more strings to a string
int main () {
    char arr[20] = "abc";
    //we want put "def" after abc
    strcat(arr, "def");
    //arr should have enough space for the add-on string
    char arrr[] = "abc";
    //arrr -> a b c \0 there is no more space left
    printf("%s\n", arr);
    //now arr is "abcdef"

    //or what if 
    char arr2 [] = { 'a', 'b', 'c'};
    //strcat(arr, arr2);
    //arr2 -> a b c what after c is unknown and there is no \0 for strcat to stop
    //so this is a bug

    char arr3 [] = { 'a', 'b', 'c', '\0'};
    //this one will work

    //as as summary
    //1. source string must end with '\0'
    //2. destination string must be able to change and have enough space

    //what if we try strcat(arr,arr);
    //what will happen?
    char test[10] = "test";
    strcat(test, test);
    printf("%d\n", test);





    return 0;
}