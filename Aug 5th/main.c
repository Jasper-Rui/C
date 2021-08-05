#include <stdio.h>
#include <string.h>


//pointers calculation

//pointers + integer number
//pointers with pointers\


//what if pointers + pointers?
//what if address + address?

int my_strlen(char* s){
    int count = 0;
    char* start = s;

    while(*s != '\0'){
        count++;
        s++;
    }

    //return count;
    return s - start;
    //by using pointers to get the amount of variables in an arr
}

int main() {

    //pointers with integer number
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* p = &arr[9];

    printf("%p \n", p);
    printf("%p \n", p - 1);
    printf("%d \n", *p);
    printf("\n");


    //pointers with pointers
    printf("%d \n", &arr[9] - &arr[0]); // -> 9
    printf("%d \n", &arr[0] - &arr[9]); // -> 9
    //the result of pointers - pointers is the number of variables between those two address (abs value)
    //for CLion compiler. &arr[0] - &arr[9] returns -9

    printf("\n");

    //what if

    char ch[5] = {0};

    //printf("%d\n", &arr[9] - &ch[4]);//this is wrong
    //the only thing that can using pointers - pointers is they are targeting the same memory address block

    printf("\n");

    char arrr[] = "abcdef";
    int len = strlen(arrr);

    int lenn = my_strlen(arrr);

    printf("%d\n", len);
    printf("%d\n", lenn);

    //most cases, pointers can compare with what after it but not what before it
    //like arr[3] can compare with arr[5] but not arr[1].


    // arr -> a continuous block of memory with the same type of element
    // pointers -> is a variable for address 4 byte (32bit) / 8 byte (64bit)
    //


    printf("\n");
    int arrrr[10] = {0};

    int sz = sizeof(arrrr);
    printf("%d\n", sz); // here is 40
    //normally arrrr is the address of the 1st element in its array
    //but there are two exception
    //1st is sizeof(arrrr)
    //2nd is &arrrr here is the address of the whole array
    //all others are the address of the 1st element in its array
    




    return 0;
}
