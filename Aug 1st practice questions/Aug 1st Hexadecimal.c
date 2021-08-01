#include <stdio.h>


//tranfser a number to Radix
int main(){
    int num = 0;
    int arr[50] = {0};

    scanf("%d", &num);
    int i = 0;
    while(num){
        arr[i] = num % 6;
        i++;
        num = num / 6;
    }

    for(i--; i >=0; i--){

        printf("%d ", arr[i]);
    }

    return 0;
}