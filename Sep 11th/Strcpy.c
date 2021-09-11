#include <stdio.h>
#include <assert.h>


char* my_strcpy(char * des, const char * scr){
    assert(des);
    assert(scr);
    char * result = des;
    while (*scr)
    //or while(*scr++ = *des++){ ; }
    {
        *des = *scr;
        *des++;
        *scr++;
    }
    *des = *scr;

    return result;
    
}



int main () {
    char arr1[] = "xxxxxxxxxx";
    char arr2[] = "abc";
    char* result = my_strcpy(arr1, arr2);
    printf("%s\n", result);
    printf("%s\n", arr1);
    return 0;
}