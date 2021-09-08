#include <stdio.h>

int main () {

    char * c[] = { "enter", "new", "pointer", "fisrt"};

    //each element in c is a pinter
    // c[] -> char * c1 = "enter"; here c1 is the address for 'e'

    char ** cp [] = { c + 3, c + 2, c + 1, c};

    //c is the address for "enter"
    //c + 3 -> "first" address
    //c + 2 -> "pointer" address 
    //c + 1 -> "new" address
    //c -> "enter" address

    char *** cpp = cp;

    printf("%s\n",** ++cpp);
    //cpp store the address for cp
    //if ++cp -> cp + 1 -> cp[1] -> c + 2 -> "pointer" address 
    //*(c + 2 -> "pointer" address) -> c + 2 -> "pointer" address 
    //*(*(c + 2 -> "pointer" address )) -> "pointer"

    printf("%s\n",* -- * ++cpp + 3);

    //1st thing to think about is the priviraty of operators
    printf("%s\n",*cpp[-2] + 3);
    printf("%s\n",cpp[-1][-1] + 1);


    return 0;
}