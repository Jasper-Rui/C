#include <stdio.h>

int main () {

    //initialize an array
    int arr[10][10] = { 0 };

    //base case row 1 -> 1
    //base case row 2 -> 1 1
    //first element of the n row and the nth element in row n is 1
    //all others are the sub of arr[i - 1][j - 1] + arr[i - 1][j]

    int i = 0;
    for(i = 0; i < 10; i++){
        int j = 0;
        for(j = 0; j <= i; j++){
            if(j == 0) arr[i][j] = 1; //every 1st element in row i (every row start with 1)
            if(j == i) arr[i][j] = 1; //every j element row i (every row end with 1)
            if(i >= 2 && j >= 1){
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }



    for(i = 0; i < 10; i++){
        int j = 0;
        for(j = 0; j <= i; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }



    return 0;
}