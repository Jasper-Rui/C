#include <stdio.h>



void find_k(int arr[3][3], int target, int col, int row){
    //start from top right or botton left

    int x = 0;
    int y = col - 1;
    while (x < col && y >= 0)
    {
        if(arr[x][y] < target) x++;
        else if(arr[x][y] > target) y--;
        else {
            printf("Find it ! Index is %d %d \n", x, y);
            break;
        }
    }
}

int main () {

    //1 2 3
    //4 5 6
    //7 8 9
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    int k = 7;

    find_k(arr, k, 3, 3);

    return 0;
}