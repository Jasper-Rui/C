#include <stdio.h>
#include <string.h>
#include <assert.h>

int convertToNumber(char* arr){
    assert(arr);
    int len = strlen(arr);
    //calculater the sum
    int sum1 = 0; 
    int sum2 = 0;  
    for(int j = 0; j < len; j++){
        //88 in ASCII represent character 'X'
        int a = *arr - '0';
        if((a != -3) && (*arr != 88)){
            sum1 += a;
            sum2 += sum1;
        }
        else if((*arr) == 88){
            //88 in ASCII represent character 'X'
            sum1 += 10;
            sum2 += sum1;
        }
        *arr++;
    }
    *arr--;
    //test if we find a valid sum2
    if(sum2 % 11 == 0) {
         return 1;
    }
    else {
        return 0;
    }
}

int main () {
    char arr[1000];
    while(scanf(" %[^\n]s", &arr) != EOF){  
        int result = convertToNumber(arr);
        if(result == 1){
            printf("%s is valid\n", arr);
            memset(arr, 0, sizeof arr);//reset arr[20] to null
        }
        else {
            printf("%s is invalid\n", arr);
            memset(arr, 0, sizeof arr);//reset arr[20] to null
        }
    }
    return 0;
}