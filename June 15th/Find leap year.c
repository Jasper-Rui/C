#include <stdio.h>
int main()
{
    int n = 1000;
    for(n = 1000; n <= 2000; n++ ){
        if((n%4 == 0 && n%100 != 0) || n %400 == 0){
            printf("%d ", n);
        }
    }
    
    return 0;
}

    