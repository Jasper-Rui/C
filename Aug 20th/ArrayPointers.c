#include <stdio.h>


void print1(int arr[], int sz){
    int i = 0;
    for(i = 0; i < sz; i++){
        printf("%d ", arr[i]);
    }
}

void print2(int* arr, int sz){
    int i = 0;
    for(i = 0; i < sz; i++){
        printf("%d ", *(arr + i));
    }
}


void print3(int (*parr)[10], int sz){
    int i = 0;
    for(i = 0; i < sz; i++){
        printf("%d ", *((*parr) + i));
        //or
        //printf("%d ", (*parr)[i]);
        //both will work
        //cuz what we get here is the whole address of arr
    }
}

void print4(int (*parr)[10], int sz){
    int i = 0;
    for(i = 0; i < sz; i++){
        printf("%d ", (parr[0][i]));//here we treat parr[0] as the 1st row
        //printf("%d ", (*(parr + 0))[i]); //this will also work
        //printf("%d ", (*parr)[i]); //this will also work
    }
}

void print5(int arrr[3][5], int row, int col){
    int i = 0;
    for(i = 0; i < row; i++){
        int j = 0;
        for(j = 0; j < col; j++){
            printf("%d ", arrr[i][j]);
        }
        printf("\n");
    }
}


void print6(int (*arrr)[3][5], int row, int col){
    int i = 0;
    for(i = 0; i < row; i++){
        int j = 0;
        for(j = 0; j < col; j++){
            printf("%d ", (*(*arrr + i))[j]);
        }
        printf("\n");
    }
}


void print7(int (*arrr)[3][5], int row, int col){
    int i = 0;
    for(i = 0; i < row; i++){
        int j = 0;
        for(j = 0; j < col; j++){
            printf("%d ", (*arrr)[i][j]);
        }
        printf("\n");
    }
}


void print8(int (*arrr)[5], int row, int col){
    int i = 0;
    for(i = 0; i < row; i++){
        int j = 0;
        for(j = 0; j < col; j++){
            //printf("%d ", (*(*(arrr + i) + j));
            //printf("%d ", (arrr[i][j]);
            printf("%d ", (*(arrr + i))[j]);
            //explaination
            //arrr + i -> which row we want in address
            //*(arrr + i) -> represent row
            //*(arrr + i) + j -> represent j element in *(arrr + i) row in address
            //*(*(arrr + i) + j)) -> represent j element in *(arrr + i) row in value
        }
        printf("\n");
    }
}

int main(){


    //int* arr[10];
    //int* (*p)[10] = &arr;
    //they are equivalent

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int sz = sizeof(arr) / sizeof(arr[0]);

    print1(arr ,sz);//print each element of arr
    printf("\n");
    print2(arr ,sz);//print each element of arr
    printf("\n");
    print3(&arr, sz);
    printf("\n");
    print4(&arr, sz);
    printf("\n");

    printf("\n");
    int arrr[3][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    print5(arrr, 3, 5);

    printf("\n");
    print6(arrr, 3, 5);

    printf("\n");
    print7(arrr, 3, 5);

    printf("\n");
    print8(arrr, 3, 5);

    
    int arrrr[5]; // -> an array of 5 elements;
    int* parrr[5]; // -> an array of 5 pointers;
    int (*parrrr)[5]; // -> (*parrrr) here is an pointer, points to an array with 10 element
    int (*parrrrr[10])[5]; // -> (*parrrrr[10]) is an array of 10 pointers, each of them pointes to an array with 5 elements







    return 0;
}