#include <stdio.h>
#include <float.h>



int main() {




	int n = 9;
	float* pFloat = (float*)&n;
	//here we create a float pointer points to n

	printf("n is£º%d\n", n);
	//here n is 9

	printf("*pFloat is£º%f\n", *pFloat);
	//here pFloat is 9.00000
	//looks like float has different store methond


	*pFloat = 9.0;
	printf("num is£º%d\n", n);
	//here n is 9.0
	printf("*pFloat is£º%f\n", *pFloat);
	//here pFloat = 9.0

	//but actually
	//n is£º9
	//* pFloat is£º0.000000
	//num is£º1091567616
	//* pFloat is£º9.000000


	//Based on IEEE 754
	//every float can be represented by
	//(-1)^S * M * 2 ^ E
	//(-1)^S -> positive or negative
	//M is valid number, if S = 0, V is position
	//					 if S = 1, V is negative
	//2^E -> Exponent bit
	//number 5.5
	//in binary
	//101.1
	// .1 means -> 2^(-1)


	//(-1)^0 * 1.011 * 2^2
	//S = 0
	//M = 1.011
	//E = 2

	//SEEEEEEEEMMMMMMMMMMMMMMMMMMMMMMM
	//1S 8E 23M
	//S is the sign bit
	// EEEEEEEE is the the number for E

	//double
	//S 11E and 52M

	// 1 <= M <= 2
	//M will only store what after 1.


	//another example
	float f = 5.5f;
	//101.1
	//(-1)^0 * 1.011 * 2^2
	//S = 0
	//M = 1.011
	//E = 2 +127
	//01000000 10110000 00000000 00000000
	//40 B0 00 00






	return 0;
}