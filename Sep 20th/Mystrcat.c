#include <stdio.h>
#include <assert.h>
#include <string.h>

char* my_strcat(char* des, const char* src){
    assert(des && src);
    char* temp = des;
    //1. find the end of des
    while(*des != '\0'){
        //'\0' in ascii -> 0
        //while(*des) is also working
        des++;
    }
    //2. add src to des
    while(*des++ = *src++){
        ;
    }

    return temp;


}

int main () {
    char arr[20] = "abc";
    my_strcat(arr, "def");
    //both work
    printf("%s\n", arr);
    printf("%s\n", my_strcat(arr, "def"));

    char arrr[5] = "\n";
    printf("%d\n", strlen(arrr));
    return 0;
}
