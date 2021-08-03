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
//void Init(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		*(arr + i) = i;
//	}
//}
//
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void Reverse(int arr[], int sz)
//{
//	int l = 0;
//	int r = sz - 1;
//
//	while (l<r)
//	{
//		int tmp = arr[l];
//		arr[l] = arr[r];
//		arr[r] = tmp;
//		l++;
//		r--;
//	}
//}
//
//int main()
//{
//	int arr[10];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Init(arr, sz);
//	Print(arr, sz);
//	Reverse(arr, sz);
//	Print(arr, sz);
//
//	return 0;
//}

//
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int i = 0;
//	printf("%d\n", arr[4]);
//	printf("%d\n", 4[arr]);
//
//
//	//a + b;
//	//b + a;
//	//arr[4] -- > *(arr+4) --> *(4+arr) --> 4[arr]
//	//arr[4];  *(arr+4)
//
//	//for (i = 0; i < 5; i++)
//	//{
//	//	printf("%p --- %p\n", &arr[i], arr+i);
//	//}
//
//	return 0;
//}
