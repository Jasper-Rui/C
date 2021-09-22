#include <stdio.h>
#include <assert.h>

void * my_memory(void * des, const void * src, size_t count){
    assert(des && src);
    //there are 3 different situations
    //des < src -> move from lower part
    //des > src -> move from hight part
    //des + count < src or scr + count < des, just do a normal memcpy
    void * temp = des;
    if(des < src){
        while(count--){
            *(char*)des = *(char*)src;
            src = (char*)src + 1;
            des = (char*)des + 1;
        }
    }
    else{
        while(count--){
            *((char*)des + count)= *((char*)src + count);
        }
    }
    return temp;
}


int main () {
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    //my_memory(arr1 + 2, arr1, 4 * sizeof(int));
    my_memory(arr1, arr1 + 2, 4 * sizeof(int));
    for(int i = 0; i < 10; i++){
        printf("%d ", arr1[i]);
    }
    return 0;
}