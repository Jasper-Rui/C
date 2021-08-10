#include <stdio.h>
//Advanced Pointers
//Date Aug 9th


int main() {

	char ch = 'w';
	char* pc = &ch;

	const char* p = "Hello Bit!"; 
	//Here "Hello Bit!" is constant string
	//Here we assign the address of "H",which is the 1st element of the string, to p


	//Test p
	//See if it's H
	printf("%c\n", *p);//H
	printf("%s\n", p);//Hello Bit


	//-------------------------------------------------------------------------------------
	printf("\n");
	char str1[] = "hello bit.";
	char str2[] = "hello bit.";
	const char* str3 = "hello bit.";
	const char* str4 = "hello bit.";
	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");

	//str1 and str2 are not same
	//str3 and str4 are same
	
	//str1 and str2 are the address of the string, and both of them are individual, and in different memory location
	// 	   so they are not same
	//str3 and str4 are const, which means they can not be changed, 
	// 	   since there is no need to use another part of memory to store the same content
	//	   so str3 and str4 points to the same address



	//-------------------------------------------------------------------------------------
	printf("\n");
	//array of pointers

	//char* arr[3]; //arr here is an array of char type pointers
	//int* arr2[4]; //arr here is an array of int type pointers

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	int* arr3[4] = { &a, &b, &c, &d };
	int i = 0;
	for (i = 0; i < 4; i++){
		printf("%d \n", *(arr3[i]));
	}


	printf("\n");
	int ar1[] = { 1,2,3,4,5 };
	int ar2[] = { 2,3,4,5,6 };
	int ar3[] = { 3,4,5,6,7 };

	int* parr[] = { ar1, ar2, ar3 };

	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d ", parr[i][j]);
			//p[i] == *(p + i)
			//parr[i][j] == *(parr[i] + j)
		}
		printf("\n");
	}


	//-------------------------------------------------------------------------------------
	printf("\n");

	const char* arrrr[5] = { "abcdef", "bcdefg", "haha", "Haorui", "Jasper" };//each of them has '\0' at the last


	for (i = 0; i < 5; i++)
	{
		printf("%s\n", arrrr[i]);
	}
	//if want Jasper only
	printf("%s\n", arrrr[4]);







	return 0;







}