#include <stdio.h>
#include <string.h>


void reverse(char* arr){
    unsigned int len = strlen(arr);
    char* left = arr;
    char* right = arr + len - 1;
    
    while(left < right){
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }   
}




int main(){
    char arr[100] = {0};
    //if input contain " " then scanf is not the best idea since scanf will stop once it meet " "
    gets(arr);
    reverse(arr);
    printf("%s\n", arr);
    return 0;
}