#include <stdio.h>


int main(){


    char arr[] = "abc"; 
    // "a b c \0"

    char arr1[3] = {'a', 'b', 'c'}; 
    // "a ,b, c"

    int arr2[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    int arr3[3][5] = { {1,2}, {3,4}, {5,6}};

    int arr4[][5] = { {1,2}, {3,4}, {5,6}};

    char arr5[4][6] = {'a', 'b'};
    
    char arr6[4][6] = {{'a'}, {'b'}};

    char arr7[4][6] = { "abc", "def", "qwe"};
    //arr7:
    //  0  1  2   3   4
    //0 a, b, c, \0,
    //1 d, e, f, \0,
    //2 q, w, e, \0,
    // ,  ,  ,   , 
    // ASCII for '0' is 48
    // ASCII for '\0' is 0


    int arr8[3][5] = { {1,2,3}, {4,5}, {6,7,8,9,0}};
    int i = 0;

    for(i = 0; i < 3; i++){ 
        int j = 0;
        for (j = 0; j < 5; j++){
            printf("%d ", arr8[i][j]);            
        }
        printf("\n");   
    }

    for(i = 0; i < 3; i++){ 
        int j = 0;
        for (j = 0; j < 5; j++){
            printf("&arr[%d][%d] = %p\n", i, j, &arr8[i][j]);            
        }
        printf("\n");   
    }



    printf("\n"); 

    int arr9[5] = { 1,2,3,4,5 };
    int *p = arr9;
    for(int i = 0; i < 5; i++){
        printf("%d ", *p);
        p++;
    }

    printf("\n");

    for(int i = 0; i < 5; i++){
        printf("%d ", arr9[i]);
        p++;
    }
    
    printf("\n");

    

    int *pp = &arr8[0][0];
    for(int i = 0; i < 15; i++){
        printf("%d ", *pp);
        pp++;
    }



    return 0;
}