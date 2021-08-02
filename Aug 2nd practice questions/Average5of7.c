#include <stdio.h>


int main() {
    
    int arr[7];
    
    
    scanf("%d %d %d %d %d %d %d", &arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6]);
    int max = arr[0];
    int min = arr[0];
    double sum = 0;
    
    
    for(int i = 0; i < 7; i++){
        max = arr[i] > max ? arr[i] : max;
        min = arr[i] < min ? arr[i] : min;
    }

    for(int i = 0; i < 7; i++){
        sum += arr[i];
    }
    sum = (sum - min - max)/5;
    printf("%.2f", sum);

    
    
    return 0;
}