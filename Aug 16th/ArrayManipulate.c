#include <stdio.h>
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//method 1 bubble sort
//simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
int ArrayManipulate(int* arr, int sz) {
    for (int i = 0; i < sz - 1; i++) {
        for (int j = i ; j < sz - 1; j++) {
            if ((*(arr + j)) % 2 == 0) {
                swap(arr + j, arr + j + 1);
            }
        }    
    }

    for (int i = 0; i < sz - 1; i++) {
        for (int j = i; j < sz - 1; j++) {
            if ((*(arr + j)) % 2 == 0 && (*(arr + j)) > (*(arr + j + 1))) {
                swap(arr + j, arr + j + 1);
            }
        }
    }


    return *arr;
}


//method 2






int ArrayManipulate_two(int* arr, int sz) {
    
    int left = 0;
    int right = sz - 1;

    while (left < right){
        if ((*(arr + left)) % 2 == 0 && (*(arr + right)) % 2 != 0) {
            swap(arr + left, arr + right);
        }
        left++;
        right--;
    }

    //for (int i = 0; i < sz / 2; i++) {
    //    for (int j = i; j < sz - 1; j++) {
    //        if ((*(arr + j)) % 2 != 0 && (*(arr + j)) > (*(arr + j + 1))) {
    //            swap(arr + j, arr + j + 1);
    //        }
    //    }
    //}

    //for (int i = (sz/2) - 1; i < sz; i++) {
    //    for (int j = i; j < sz - 1; j++) {
    //        if ((*(arr + j)) % 2 == 0 && (*(arr + j)) > (*(arr + j + 1))) {
    //            swap(arr + j, arr + j + 1);
    //        }
    //    }
    //}

    
    
    return *arr;
}




int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", sz);

    *arr = ArrayManipulate_two(arr, sz);
    //printf("%d", *(arr + 9));
    for (int i = 0; i < sz; i++) {
        printf("%d ", *(arr + i));
    }
    return 0;
}