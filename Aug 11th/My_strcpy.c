#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

//des is the destination , pintes to the target memory
//src is the source , pointes to the target string
void my_strcpy(char* des, char* src) {
	if (des == NULL ||  src == NULL) {
		return;
	}
	while (*src != '\0') {
		*des = *src;
		des++;
		src++;
	}
	//we also need '\0' as part of the string
	*des = *src;
}

//to improve the code


void my_strcpy_improved(char* des, char* src) {

	assert(des != NULL);
	assert(src != NULL);
	//this will help for better understanding

	while (*src != '\0') {
		*des++ = *src++;
	}
	*des = *src; //for '\0'
}

void my_strcpy_improved_again(char* des, char* src) {
	assert(des && src);
	while (*des++ = *src++) {
		;
	}
	//when *src  = '\0', the ASCII for that is 0 -> false. so the loop will break
}


//to avoid someone put the des and src in the wrong postion

//after adding const
//Robustness

void my_strcpy_improved_again_second(char* des, const char* src) {
	assert(des && src);
	while (*des++ = *src++) {
		;
	}
	//when *src  = '\0', the ASCII for that is 0 -> false. so the loop will break
}

//How can we check the size of input, cuz we may not have enough space for des
//or we want return the des instead of using void function

char* my_strcpy_improved_again_third(char* des, const char* src) {
	assert(des && src);
	char* result = des;
	while (*des++ = *src++) {
		;
	}
	//when *src  = '\0', the ASCII for that is 0 -> false. so the loop will break

	return result;
}



int main() {

	//strcpy

	char arr1[] = "abcdef"; // length = 7 there is a '\0' after 'f'
	char arr2[20] = { 0 };


	strcpy(arr2, arr1); //copy arr1 and paste into arr2
	printf("%s\n", arr2);

	//create a strcpy
	char arr3[] = "abcdeff";
	my_strcpy(arr2, arr3);
	printf("%s\n", arr2);

	char arr4[] = "abcdefff";
	my_strcpy_improved(arr2, arr4);
	printf("%s\n", arr2);



	char arr5[] = "abcdeffff";
	my_strcpy_improved_again(arr2, arr5);
	printf("%s\n", arr2);



	printf("\n");

	const int num = 10;
	//num = 20; //error
	int n = 100;
	int* p = &num;
	*p = 20;
	//haha
	printf("%d \n", num); //num -> 20

	//how we make sure that will not happen?

	//we can use const for pointer

	const int* pp = &num; // equal to int const * pp
	//*pp = 30;//error
	//but
	pp = &n;

	printf("%d \n", num); //num -> 20
	//Summary
	//const int* pp -> here const is used for (*pp), and it can not changed by pointers
	//but pointer itself can be changes, here pp is pointed to num, it can be changed to n






	int* const ppp = &num;
	*ppp = 200;//work
	//ppp = &n; will not work


	printf("%d \n", num); //num -> 200
	//Summary
	//int* const ppp -> here const is used for ppp(pointer), what (*ppp) is can be changed
	//but pointer itself can not be changed, here ppp is pointed to num = 10(assume it is 10), it can change the 10 to 100 or 100000. etc
	//but it can not be other pointers

	//or
	const int* const pppp = &num;

	printf("\n");

	char arr6[] = "abcdefffff";
	char* result = my_strcpy_improved_again_third(arr2, arr6);
	printf("%s\n", result);


	printf("\n");
	char ar[] = "abcdefg";
	char ar1[3] = { 0 };
	//result = my_strcpy_improved_again_third(ar, ar1)l//will not work
	//we have to make sure the des has enough space for a copy

	//another wrong example
	char error1[] = "avcsads";
	char* error2 = "xxxxxxxxxxxx"; //here it's a constant string stored in constant area, it's unable to change

	//target space must be changable

	char arrrr[] = "abcdef";
	const char* arrrrrrrr = "qwer";
	//put 'q' address into arrrrrrrr

	printf("%s \n", arrrr);
	printf("%s \n", arrrrrrrr);
	//if we use &arrrr or *arrrrrrrr, it will be the 1st element of that string


	printf("%s \n", &arrrr);

	printf("%c \n", *arrrrrrrr);
	return 0;
}