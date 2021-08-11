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

int main() {
	char arr[] = "abcdef";
	printf("%d \n", my_strlen(arr));


	





	return 0;
}