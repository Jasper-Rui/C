#include <stdio.h>
#include <string.h>
#include <errno.h>

//strerror will return the error message, not just the error code

int main () {
    //for example, if we are missing a ';' -> error code will be c2143 in vs2019
    printf("%s\n", strerror(0));
    printf("%s\n", strerror(1));
    printf("%s\n", strerror(2));
    printf("%s\n", strerror(3));

    //Undefined error: 0
    //Operation not permitted
    //No such file or directory
    //No such process

    //when an error happen, the error code will save as "errno"
    //errno is a varable we can use directly

    FILE* pf = fopen("test.txt", "r");
    if(pf == NULL){
        //printf("%s\n", strerror(errno)); // -> No such file or directory
        //or
        perror("jASPER HIHI"); // -> jASPER HIHI: No such file or directory
        //It's like printf + strerror
    }
    else{

    }


    return 0;
}