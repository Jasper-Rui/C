#include <stdio.h>

int count_one_bit_one(int n)
{
	int count = 0;
	while(n)
	{
		if(n%2==1)
			count++;
		n = n/2;
	}
	return count;
}

int count_one_bit_two(unsigned int n)
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

int count_one_bit_three(int n)
{
	int count = 0;
	while(n)
	{
		n = n&(n-1);
        //assume n = 5
        //1st time n & (n - 1)
        //5 -> 00000101
        //4 -> 00000100
        //now n is -> 4 -> 00000100
        //4 -> 00000100
        //3 -> 00000011
        //now n -> 00000000 -> 0




        //3 -> 00000011
        //2 -> 00000010
        //1 -> 00000001
		count++;
	}
	return count;
}


int main(){
    printf("Pleas enter 1 integer:\n");
    int a;
    scanf("%d", &a);
    int count = count_one_bit_three(a);
    printf("There are %d 1's in %d\n", count, a);

    return 0;
}
