#include <stdio.h>

int main()
{
    int n = 1;
    int m = 2;
    switch (n){
        case 1:
            m++; // m = 3
        case 2:
            n++; // n = 2
        case 3:
            switch (n){
                case 1: 
                    n++;
                case 2:
                    m++; // here m = 3 + 1 = 4
                    n++; // n = 2 + 1 = 3
                    break; // this break only break the switch inside the case 3 and will go next to case 4
            }
        case 4:
            m++;
            break;
        default:
            break;
    }
    printf("m = %d, n = %d\n ", m, n);
    
    

    return 0;
}