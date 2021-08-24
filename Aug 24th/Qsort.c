#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpint(const void* var1, const void* var2){
    return *(int*)var1 - *(int*)var2;
    //compare two variables, return 1 if var1 larger than var2, otherwise return 0
}

void printArray(int* arr, int sz){
    for(int i = 0; i < sz; i++){
        printf("%d ", *(arr + i));
    }
}

//qsort with integers
void test1(){
    int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("Array before qsort is: \n");
    printArray(arr, sz);

    qsort(arr, sz, sizeof(arr[0]), cmpint);
    printf("\nArray before qsort is: \n");
    printArray(arr, sz);
}

//qsort with struct

struct Student
{
    /* data */
    char name[20];
    int age;
};

int cmp_struct_age(const void* var1, const void* var2){
    return (*(struct Student*)var1).age - (*(struct Student*)var2).age;
    //or
    //return ((struct Student*)var1)->age - ((struct Student*)var2)->age;
}

//if we want sort in in the opposite wat
int cmp_struct_age(const void* var1, const void* var2){
    return (*(struct Student*)var2).age - (*(struct Student*)var1).age;
}


int cmp_struct_name(const void* var1, const void* var2){
    return strcmp((*(struct Student*)var1).name ,(*(struct Student*)var2).name);
    //strcmp is to compare each index of a string
    //abcd
    //adc
    //at position 2, d is larger than b so adc > abcd
}



void test2(){
    struct Student stu[] = { {"Jasper", 20}, {"Yang", 20}, {"Haorui", 25} };
    //sort the struct array
    //we have to desice how we want to sort the array eg: age or name
    //here we sort the structs by age from some to large
    int sz = sizeof(stu)/ sizeof(stu[0]);

    qsort(stu, sz, sizeof(stu[0]), cmp_struct_age);
    qsort(stu, sz, sizeof(stu[0]), cmp_struct_name);

    
}

int main () {
    



    return 0;
}