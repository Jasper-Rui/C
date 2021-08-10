#include <stdio.h>


int main() {

	int a = 10;
	int* pa = &a;
	char c = 'w';
	char* pw = &c;

	int arr[10] = { 0 };

	int* p = arr;//here p is the 1st element of arr[10];

	int (*parr)[10] = &arr; 
	//here &arr is the address of the whole array 
	//and it should be stored at array pointer

	// int* parr[10] is incorrect/
	// cuz it is an array of pointers
	// but we need  array pointer



	int ar[10] = { 0 };
	ar;//name arr is the 1st element address
	&ar[0];//the 1st element address
	&ar;//the whole array address

	printf("%p\n", ar); //00CFF98C
	printf("%p\n", &ar[0]); //00CFF98C
	printf("%p\n", &ar); //00CFF98C


	printf("%p\n", ar + 1); //012FF764
	printf("%p\n", &ar[0] + 1); //012FF764
	printf("%p\n", &ar + 1); //012FF788
		
	//the +1 has different meaning here, based on the type before + 1



	int* aaarrr[10];

	int* (*ppp)[10] = &arr;








	return 0;
}