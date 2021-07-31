#include <stdio.h>
#include <assert.h>
#include <string.h>

//input "abcde"
//expected output "edcba"

//without recursion
void reverse_string(char* string){
    assert(string != NULL);
    int len = strlen(string);
    int left = 0;// 1st element
    int right = len - 1;// last element
    
    while(left < right){
        char tmp = string[left];
        string[left] = string[right];
        string[right] = tmp;
        left++;
        right--;
    }
    
}

int my_strlen(char* string){
    int count = 0;
    while(*string != "\0"){
        string++;
        count++;
    }
    return count;
}


//with recursion
void reverse_string_recursion(char* string){
    int len = my_strlen(string);
    char tmp = string[0];
    string[0] = string[len - 1]; // now it becomes "f bcde f"
                                 // then we need to make it "f bcde \0"   
    string[len - 1] = "\0";

    if(my_strlen(string + 1) >= 2){
        reverse_string_recursion(string + 1);
    }
    

    string[len - 1] = tmp; //then we bring " a " back
}

int main(){

    char arr[10] = "abcdef";
    reverse_string(arr);
    printf("%s\n", arr);

    reverse_string_recursion(arr);
    printf("%s\n", arr);

    return 0;

}