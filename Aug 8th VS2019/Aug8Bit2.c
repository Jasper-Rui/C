#include <stdio.h>
#include <Windows.h>


int main() {



	int a = -20;
	unsigned int b = 10;
	int result = a + b;
	printf("%d  \n", result);
	//-10

	printf("%u  \n", result);
	//4294967286

	//but if a + b
	//for example
	if ((a + b) > 0) {
		printf("hahah  \n");
	}
	//cuz sign int + unsign int -> unsign int


	
	//unsigned int i;
	//for (i = 9; i >= 0; i--) {
	//	printf("%u \n", i);
	//	Sleep(1000);
	//}
	//
	//this is a dead loop it will never end


	char a[1000];
	int i;
	for (i = 0; i < 1000; i++) {
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
	//255








	
	return 0;
}