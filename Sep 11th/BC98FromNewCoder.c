#include <stdio.h>


int main () {
    
    int inputsize = 0;
    scanf("%d", &inputsize);
    int arr[inputsize];
    int i = 0;
    
    for(i = 0; i < inputsize; i++){
        scanf("%d", &arr[i]);
    }
    
    int target = 0;
    scanf("%d", &target);
    
    for(i = 0; i < inputsize; i++){
        if(arr[i] == target){
            arr[i] = NULL;
            continue;
        }
        printf("%d ", arr[i]);
    }

    return 0;
}