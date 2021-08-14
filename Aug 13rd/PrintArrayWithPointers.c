#include <stdio.h>

int main(){


    int arr[10] = {0};
    for(int i = 0; i < 10; i++){
        arr[i] = i;
    }

    int* parr = arr;
    
    printf("1st way to do that \n");

    for(int i = 0; i < 10; i++){
        printf("%d ",*(parr + i));
    }

    printf("\n");

    printf("2nd way to do that \n");

    for(int i = 0; i < 10; i++){
        printf("%d ", i[arr]);
    }

    printf("\n");

    printf("3rd way to do that \n");

    int (*p)[10] = &arr;
    for(int i = 0; i < 10; i++){
        printf("%d ", (*p)[i]);
    }

    
    printf("\n");
    printf("4th way to do that \n");
    int* pp = arr;  //here we give pp the arr[0] address to pp, all above code was giving the whold array arrdess
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
    {
        printf("%d ", *pp);   
        ++pp;                 
    }


    return 0;
}