#include <stdio.h>
#include <string.h>

void * my_memmove (void * des, const void * src, size_t sz){
    void* temp = des;
    
    char arr[sz];
    size_t i = 0;
    printf("%d\n", sz);
    for(i = 0; i < sz; i++){
        arr[i] = *(char*)src;
        src = (char*)src + 1;
    }
    printf("%s\n", arr);
    return temp;
}


int main () {
    char arr1[10] = "abcdef";
    char arr2[10] = "123";
    char* ret = my_memmove(arr1, arr2, 3);
    //printf("%s\n", arr1);
    return 0;
}