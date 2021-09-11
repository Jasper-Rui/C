#include <stdio.h>
#include <assert.h>

int is_sorted_in_ascend_order(int* arr, int sz){
    assert(arr);
    assert(sz);
    int i = 0;
    int flag = 0;
    for(i = 0; i < sz - 1; i++){
        if(arr[i] < arr[i + 1]){
            flag = 0;
        }
        else{
            flag = 1;
            break;
        }
    }
    return flag;
}

int is_sorted_in_reverse_order(int* arr, int sz){
    assert(arr);
    assert(sz);
    int i = 0;
    int flag = 0;
    for(i = 0; i < sz - 1; i++){
        if(arr[i] > arr[i + 1]){
            flag = 1;
        }
        else if(arr[i] == arr[i+1]){
            flag = 2;
        }
        else{
            flag = 0;
            break;
        }
    }
    return flag;
}

int main () {
    
    int input = 0;
    scanf("%d", &input);
    int arr[input];
    int i = 0;
    while(scanf("%d", &arr[i]) != EOF){
        i++;
    }
    int result1 = is_sorted_in_ascend_order(arr, input);
    int result2 = is_sorted_in_reverse_order(arr, input);
    if((result1 == 0 && result2 == 0) || (result2 == 2)){
        printf("sorted");
    }
    else if(result1 == 1 && result2 == 1){
        printf("sorted");
    }
    else{
        printf("unsorted");
    }
    return 0;
}


//beat 100% in c, run time 1ms
//memory cost 308kb, beat 96%