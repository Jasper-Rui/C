#include <stdio.h>

int main () {

    char * c[] = { "enter", "new", "point", "first"};

    //each element in c is a pinter
    // c[] -> char * c1 = "enter"; here c1 is the address for 'e'

    char ** cp [] = { c + 3, c + 2, c + 1, c};
    //                "first", "point", "new", "enter"

    // c[]                 cp[] 
    //char * enter       char ** c + 3 -> fisrt  -> cpp
    //char * new         char ** c + 2 -> point
    //char * point       char ** c + 1 -> new
    //char * fisrt       char ** c + 0 -> enter

    char *** cpp = cp;

    printf("%s\n",** ++cpp);
    //cpp store the address for cp
    //if ++cpp -> cpp + 1 -> cp[1] -> c + 2 address 
    //*(c + 2 -> "pointer" address) -> c + 2 -> "pointer" address 
    //*(*(c + 2 -> "pointer" address )) -> "pointer"


    //note, at this time cpp is points to cp + 1 -> c + 2  
    printf("%s\n",* -- * ++cpp + 3);
    //++ -- should be calculated before + 
    //1st thing to think about is the priviraty of operators
    //++cpp -> &cp + 1 -> what after { c + 3, c + 2, c + 1, c}; -> still an address
    //*(&cp + 1) -> what after { c + 3, c + 2, c + 1, c}; -> an element after c
    //*(&cp + 1) -- -> c
    //*c -> frist element address -> 'e'
    //*(c + 3) -> er

    //after detailed explaination from bite Peng ge
    //after line 21, cpp + 1, so cpp now points to c + 2
    //after cpp + 1 -> cpp now points to c + 1
    //then *(cpp) -> (c + 1)
    //(c + 1) - 1 -> c
    //*c -> enter / c is the address for 'e'
    //*c + 3 -> er


    //now cpp -> c + 1
    printf("%s\n",*cpp[-2] + 3);
    //cpp[-2] -> *(cpp - 2)
    //**(cpp - 2) + 3
    //cpp - 2 -> c + 3
    //*(cpp - 2) -> get the address for (c + 3)
    ///**(cpp - 2) -> get c + 3 -> "fisrt" address  -> the address start with 'f'
    // + 3 -> st

    //now cpp -> c + 1
    printf("%s\n",cpp[-1][-1] + 1);
    //cpp[-1] -> *(cpp - 1) -> (c + 2) address
    //(c + 2)[-1] -> *(c + 2 - 1) -> *(c + 1) -> "new"
    //ew


    return 0;
}