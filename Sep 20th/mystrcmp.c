#include <stdio.h>
#include <string.h>


void set (int * arr, int sz){
    int i = 0;
    for(i = 0; i < sz; i++){
        *(arr + 1) = 0;
    }
}

int my_strcmp (const char * arr1, const char * arr2){
    while(*arr1 == *arr2){
        if(*arr1 == '\0'){
            return 0;
        }
        arr1++;
        arr2++;
    }
    return *arr1 - *arr2;
}

int main () {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};


    //strcmp is to compare the content, not the length of the array
    char arr1[] = "abcdef";
    char arr2[] = "abq";
    char arr3[] = "abc";
    char arr4[] = "abc";
    // a == a, b == b, q > c , so arr2 > arr1 in strcmp
    int ret1 = strcmp(arr1, arr2);
    int ret2 = strcmp(arr1, arr3);
    int ret3 = strcmp(arr3, arr4);
    printf("%d\n", ret1);
    printf("%d\n", ret2);
    printf("%d\n", ret3);

    //use my_strcmp

    int ret4 = my_strcmp(arr1, arr4);
    if(ret4 > 0){
        printf(">\n");
    }
    else if (ret4 < 0){
        printf("<\n");
    }
    else{
        printf("=\n");
    }
    return 0;
}