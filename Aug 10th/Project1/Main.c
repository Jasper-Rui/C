#include <stdio.h>
#include <assert.h>
int my_strlen(char* input) {
	assert(input);
	int count = 0;
	while (*input != '\0') {
		input++;
		count++;		
	}
	return count;
}


char* my_strcpy(char* dest, const char* src) {





}


int main() {
	char arr[] = "abcdef";
	printf("%d \n", my_strlen(arr));

	printf("\n");
	int n = 100;
	const int num = 10;
	const int* p = &num;
	//here const is for *
	//so we cant change *p, but p

	//we can do 
	p = &n;
	//but not
	//*p = 20;


	
	





	return 0;
}