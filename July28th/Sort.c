#include <stdio.h>

//Bubble Sort
void Sort(int arr[]/* equal to int* arr*/, int sz)
{


    //here sizeof(arr) = 4
    // so sz = 4 / 4 = 1
    //cuz arr[] is the address of the 1st variable, not the whole array

    //int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;

    int flag = 1; // test if the arr is already sorted


    for(i = 0; i < sz - 1; i++)
    {
        int j = 0;
        for(j = 0; j < sz - 1 - i ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flag = 0;
            }
            else
            {
                flag = 1;
            }
        }
        if(flag == 1){
            break;
        }
    }
}


void Print(int* arr, int sz)
{
    int i = 0;
    for(i = 0; i < sz; i++)
    {
        printf("%d ", *arr++);
        //printf("%d ", *arr++);
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int arr1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int sz = sizeof(arr1) / sizeof(arr[0]); // 40 / 4 = 10
    //here sizeof(arr) is the whole list of array not the 1st element

    //when passing the name of arr, here is arr, to function, it will be the address of the 1st element (Pointer)
    Sort(arr1, sz);
    Print(arr1, sz);
    printf("\n");
    Sort(arr, sz);
    Print(arr, sz);



    return 0;
}