#include <stdio.h>
void swap(int* a, int* b);
void BubbleSort(int* arr, int size);


void swap(int* a, int* b){
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

void BubbleSort(int* arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i; j++){
            if(arr[j] > arr[j + 1]){
            swap(&arr[j], &arr[j + 1]);
            }
        }       
    }    
}
 

int main()
{
    int arr[10] = {999, 20, 389, 25, -52, 64, 22, -1, 30, 66};
    int sz = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, sz);
    printf("new arr is ");
    for(int i=0; i < sz; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
