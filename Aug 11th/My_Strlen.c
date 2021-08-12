#include <stdio.h>
#include <assert.h>


int my_strlen(char* input) {
	assert(input != NULL);
	int count = 0;
	while (*input != '\0') {
		count++;
		input++;
	}
	return count;
}

unsigned int my_strlen_improve(const char* input) {//or size_t my_strlen_improve(const char* input)
	assert(input != NULL);
	int count = 0;
	while (*input++){
		count++;
	}
	return count;
}


int main() {

	char arr[] = "abcedf";
	printf("%d \n", my_strlen(arr));
	printf("%d \n", my_strlen_improve(arr));



	return 0;
}