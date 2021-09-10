#include <stdio.h>
#include <string.h>
#include <assert.h>

//original -> "ABCDEF"
//if we move 2 -> we can do -> "BAFEDC"
//then reverse it all -> "CDEFBA"

void reverse (char* left, char* right){
    assert(left && right);
    while (left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

void left_move(char* arr, int k){
    assert(arr);
    assert(k);
    int len = strlen(arr);
    k %= len;
    //reverst left
    reverse(arr, arr + k - 1);
    //reverse right
    reverse(arr + k, arr + len - 1);
    //reverse it 
    reverse(arr, arr + len - 1);
}


int main () {

    char arr[] = "abcdefgh";
    left_move(arr, 2);
    printf(arr);
    printf("\n");
    //or
    printf("%s\n", arr);


    return 0;
}