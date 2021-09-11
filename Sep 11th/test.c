#include <stdio.h>
#include <string.h>

int main () {

    char a[10] = "hello";
    //here actually is "hello\0" -> length is 6
    char b[10] = "abc"; 
    //here actually is "abc\0" -> length is 4
    char c[10] = "xxxxxxxxxx";
    char d[10] = "hello\0abc";
    //if we do
    strcpy(c, d);
    //what will happen is
    //c now is "hello\0xxxx"

    //explaniation
    //strcyp will start copy with the target address, here is 'h', until it matches '\0' and it will stop

    //now, what if we try

    char e[10] = {'a', 'b', 'c'};

    //what will happen ?
    //since we know that strcpy will keep looking for '\0'
    //and there is not '\0' in e, so it will access the address after 'c'
    //so it will keep copy things until there is a'\0'

    //kep points here
    //e do not have '\0'
    //strcpy stop by '\0'




    return 0;
}