#include <stdio.h>
#include <string.h>
#include <assert.h>


//strstr is to serach a specific string from a string
//return type is : return a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1
char * my_strstr(char * str1, char * str2){
    assert(str1 && str2);

    char * s1;
    char * s2;
    char * cp = str1;

    if(*str2 == '\0'){
        return str1;
    }

    while(*cp != '\0'){
        s1 = cp;
        s2 = str2;
        while((*s2 != '\0') && (*s1 != '\0') && (*s1 == *s2)){
            s1++;
            s2++;
        }
        if(*s2 == '\0'){
            return cp;
        }
        cp++;
    }
    return NULL;
}

int main () {

    char arr1[] = "I am the best, Jasper is me";
    char arr2[] = "Jasper";
    char arr3[] = "student";

    //char * result = strstr(arr1, arr2);
    char * result = my_strstr(arr1, arr2);
    //here result start with 'J'
    char * result1 = strstr(arr1, arr3);
    //here result1 is a null pointer
    printf("%s\n", result);



    return 0;
}