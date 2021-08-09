#include <stdio.h>

int main() {

	char a = -1;
	//-1 -> 10000000 00000000 00000000 00000001
	//  -> 11111111 11111111 11111111 11111110
	//  -> 11111111 11111111 11111111 11111111
	//11111111 -> in a

	signed char b = -1;
	//11111111 -> in b

	unsigned char c = -1;
	//11111111 -> in c 
	//but


	//%d is to print integer with sign bit
	//since char is 1 byte = 8 bit, but int has 4 byte then we need integral promotion 
	//for a  11111111, 1st 1 is the sign bit
	//fill a with 11111111 11111111 11111111 11111111(twos' complemnt)
	//then 11111111 11111111 11111111 11111110 (-1) (ones' complement)
	//then 10000000 00000000 00000000 00000001 (True form)
	//same for b

	//but for c
	//since its an unsign char
	//11111111 -> in c fill with 00000000 00000000 00000000 11111111
	//1st number is 0 so it's a positive numebr
	//and it's  True form, ones' twos' are the same
	//so c will be 00000000 00000000 00000000 11111111 -> 255

	printf("a = %d b = %d c = %d\n", a, b, c);
	//here result is -1 -1 255



	//another example
	printf("\n");
	char aa = -128;
	//aa is 10000000
	//do integral promotion
	//when fill 0 \ 1, it depends on the signbit
	// 
	//11111111 11111111 11111111 10000000
	//and it's and signed variable
	//but %u print it without sign bit
	//so it will be a positive number
	//thus True form == twos'
	printf("%u\n", aa);
	//here result is 4294967168

	char aaa = 128;
	//128 -> 00000000 00000000 00000000 10000000
	//aaa -> 10000000
	// 	     1 here is the sign bit
	//11111111 11111111 11111111 10000000
	// 	   since it's %u
	//11111111 11111111 11111111 10000000

	//char is -128 ~ 127
	//even tho store 10000 here, the only thing char can have is 127
	//
	printf("%u\n", aaa);
	//here result is 4294967168 as well

	//-------------------------------------------------------------------------------------

	int i = -20;
	unsigned int j = 10;
	//i ->10000000 00000000 00000000 00010100
	//  ->11111111 11111111 11111111 11101011 do +1
	//  ->11111111 11111111 11111111 11101100

	//j ->00000000 00000000 00000000 00001010
	//j ->00000000 00000000 00000000 00001010
	//j ->00000000 00000000 00000000 00001010

	//we do
	//i ->11111111 11111111 11111111 11101100
	//					+
	//j ->00000000 00000000 00000000 00001010
	//  ->11111111 11111111 11111111 11110110

	//do -1 and turn aroung
	//after -1 -> 11111111 11111111 11111111 11110101
	//after turn ->10000000 00000000 00000000 00001010 -> -10
	printf("%d\n", i + j);

	return 0;
}