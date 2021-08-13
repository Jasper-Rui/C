#include <stdio.h>


int count_one_bit(unsigned int n)
{
	int count = 0;
	int i = 0;
	for(i=0; i<32; i++)
	{
		if(((n>>i)&1) == 1)//compare n with 1 by using &, if and only if both of them have 1, then count will + 1, go 32 times
			count++;
	}
	return count;
}

int main(){

    int a, b;
    scanf("%d%d", &a, &b);
    //example a = 3 b = 5
    //a -> 00000000 00000000 00000000 00000011
    //b -> 00000000 00000000 00000000 00000101
    //go a ^ b

    int c = a ^ b;
    int result = count_one_bit(c);
    printf("%d\n", result);
    return 0;
}