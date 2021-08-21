//big endian vs little endian


#include <stdio.h>


int check_sys(){
    int i = 1;

    char* p = (char*) &i;
    return (*(char*) & i);
}

int main(){
    int ret = check_sys();

    if(ret == 1){
        printf("Little Endian \n");
    }
    else{
        printf("Big Endian");
    }
    //or
    int i = 1;
    char* p = (char*) &i;
    if(*p == 1){
        printf("Little Endian \n");
    }
    else{
        printf("Big Endian");
    }

    return 0;
}