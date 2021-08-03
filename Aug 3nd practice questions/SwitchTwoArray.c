#include <stdio.h>

void swap(int* a, int* b){
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

int main(){

	int arr1[10] = {0};
	int arr2[10] = {0};
	int i = 0;
	printf("Please enter 10 numbers:");
	for(i=0; i<10; i++){
		scanf("%d", &arr1[i]);
	}

	printf("Please enter 10 numbers for arr2:");
	for(i=0; i<10; i++){
		scanf("%d", &arr2[i]);
	}
	for(i=0; i<10; i++)
	{
        swap(&arr1[i], &arr2[i]);
	}
	
	for(i=0; i<10; i++)
	{
        printf("%d ", arr1[i]);
        
	}
    printf("\n");
    for(i=0; i<10; i++)
	{
        
        printf("%d ", arr2[i]);
	}
	return 0;

}