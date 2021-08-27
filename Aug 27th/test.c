#include <stdio.h>
#include <assert.h>
#include <string.h>

//this is a error for move k elemets example
void exchange(char* arr, int num){
    assert(arr != NULL);
    assert(num != NULL);
    assert(strlen(arr) > num);
    while (num)
    {
        *(arr + num - 1) = (*(arr)) ^ (*(arr + num - 1));
        *arr = (*(arr)) ^ (*(arr + num - 1));
        *(arr + num - 1) = (*(arr)) ^ (*(arr + num - 1));
        //after above step
        //one significant error
        //we want abcd -> bcda
        //1sr round it indeed becomes bcda when num = 1
        //but the things is, it actually becomes
        //abcd ->bacd
        //we want 1st goes to the last each time
        //so
        //
        arr++;
        num--;
    }
    

}

int main(){


    char arr[] = "abcdef";
    printf(arr);
    exchange(arr, 2);
    printf(arr);

    return 0;
}

/*
#include <stdio.h>

int main()
{
    char a = 'a';
    char b = 'b';
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("%c\n",a);
    printf("%c",b);

    return 0;
}
*/