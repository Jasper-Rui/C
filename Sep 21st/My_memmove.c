#include <stdio.h>
#include <string.h>
#include <assert.h>


void * my_memmove (void * des, const void * src, size_t sz){
    assert(des && src);
    assert(des >= src + sz);
    void* temp = des;
    
    char arr[sz];
    size_t i = 0;
    for(i = 0; i < sz; i++){
        arr[i] = *(char*)src;
        src = (char*)src + 1;
    }
    for(i = 0; i < sz; i++){
        *(char*)des = arr[i];
        des = (char*)des + 1;
    }
    return temp;
}


int main () {
    char arr1[10] = "abcdef";
    char arr2[10] = "123";
    char* ret = my_memmove(arr1, arr2, 3 * sizeof(char));
    printf("%s\n", ret);
    return 0;
}