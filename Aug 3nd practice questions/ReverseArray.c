#include <stdio.h>

void swap(int* a, int* b){
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

void Print(int arr[], int sz){
    for(int i = 0; i < sz; i++){
        printf("%d ", arr[i]);
    }
}
void Reverse(int arr[], int sz){
    int i = 0;
    int r = sz - 1;
    while(i < r){
        int tmp = arr[0];
        arr[i] = arr[sz - 1];
        arr[sz - 1] = tmp;
        i++;
        r--;
    }
    
}


int main(){

	int arr1[10] = {0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	//Init(arr, sz);
	Print(arr, sz);
	Reverse(arr, sz);
	return 0;

}