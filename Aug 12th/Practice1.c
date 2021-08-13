#include <stdio.h>


void print_odd_even_bit_seperate(unsigned int n)
{
	int count = 0;
	int i = 0;
    int bit[32] = {0};
    int tmp;
	for(i = 0; i < 32; i++)
	{
        if(i % 2 == 0){
            if(((n>>i)&1) == 1){
                tmp = 1;
            }
			else{
                tmp = 0;
            }
        }
        else{
            if(((n>>i)&1) == 1){
                tmp = 1;
            }
			else{
                tmp = 0;
            }
        }
        bit[i] = tmp;
	}
    printf("Even bits are \n");
    for(i = 0; i < 32 ; i = i + 2){
        printf("%d ", bit[i]);
    }
    printf("\n ");
    printf("Odd bits are \n");
    for(i = 1; i < 32 ; i = i + 2){
        printf("%d ", bit[i]);
    }

}

int main(){

    int a;
    scanf("%d", &a);
    print_odd_even_bit_seperate(a);
    return 0;
}