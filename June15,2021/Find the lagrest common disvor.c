#include <stdio.h>
int main()
{
    int input1, input2;
    int limit;
    scanf("%d %d", &input1, &input2);
    
    if(input1 > input2){
        limit = input2;
    }
    else{
        limit = input1;
    }
    
    
    for (int i = limit; i > 0; i--){
        
        if(input1 % i ==0 && input2 % i ==0){
            printf("%d ", i);
            break;
        }
    }
    return 0;
}

    
