#include <stdio.h>


//A : not me
//B : it's C
//C : it's D
//D : C is wrong
int main () {

    int killer = 0;
    for(killer ='A'; killer <= 'D'; killer++){
        if((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3){
            break;
        }
    }

    printf("%c", killer);
    return 0;
}