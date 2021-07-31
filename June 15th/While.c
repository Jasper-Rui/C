#include <stdio.h>

// a small program to find the number we want
int main()
{
    int input = 0;
    while(input < 100){
        if(input % 2 == 1){
            printf("%d ", input);
        }
        input++;
    }
    
    //a second way to write it
    
    while(input < 100){
        printf("%d ", input);
        input += 2;
    }
    	 
    return 0;
}
