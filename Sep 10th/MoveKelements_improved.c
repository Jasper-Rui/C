#include <stdio.h>
#include <string.h>
#include <assert.h>



int is_left_move(char * arr, char * arr1){
    if(strlen(arr) != strlen(arr1)) return 0;

    //add arr1 to arr
    strncat(arr, arr1, strlen(arr));

    if(NULL == strstr(arr, arr1)){
        return 0;
    }
    return 1;

}


int main () {

    char arr[20] = "ABBCCDD";
    char arr1[10] = "BBCC";
    char arr2[] = "DDABBCC";

    int result = is_left_move(arr, arr1);
    int result1 = is_left_move(arr, arr2);
    if(result == 0) printf("arr1 is not able to get from reversing arr\n");
    if(result1 == 1) printf("arr2 is able to get from reversing arr\n");



    return 0;
}