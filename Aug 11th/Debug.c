#include <stdio.h>


int main() {


	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int i = 0;
	printf("%p \n", &i); //004FFB88
	printf("%p \n", &arr[9]); //004FFB7C
	
		
	for (i = 0; i <= 12; i++) {		
		arr[i] = 0;
		printf("hehe\n");
	}
	//the result here will print infinity hehe
	//which means that i will never be larger than 12
	//why this is happening

	//when move to arr[9] == *(arr+9) then
	//arr[10] == *(arr + 10)
	//by monitoring the progress 
	//I find that when &arr[12] == &i
	//so when we assign arr[12] = 0
	//we also assign i = 0
	//thus -> infinity loop


	//but why they have the same address?
	//in stack, higher address will be used 1st
	//then lower address


	//but if we put int i = 0; after int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//it will not go into infinity loop but it will cuz a bug











	return 0;
}