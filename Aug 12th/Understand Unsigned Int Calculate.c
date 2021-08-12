#include <stdio.h>

#include <string.h>


int main() {

	//3 - 6 = -3
	//10000000 00000000 00000000 00000011
	//11111111 11111111 11111111 11111100
	//11111111 11111111 11111111 11111101

	//strlen -> return unsign number
	//unsign - unsign = unsign
	//so for a unsign number, ones == twos == original == 11111111 11111111 11111111 11111101 -> larger than 0

	if (strlen("abc") - strlen("abcdef") > 0) {
		printf("hehe \n");
	}
	else {
		printf("haha \n");
	}


	int a = strlen("abc");
	printf("%d\n", a);
	printf("%d\n", strlen("abc"));
	int aa;
	printf("%d\n", aa = strlen("abc") > strlen("abcdfe"));







	return 0;
}