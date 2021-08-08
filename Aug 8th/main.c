#include <stdio.h>

void test2(){
    printf("Test2\n");
}

void test1(){
    test2();
}

void test(){
    test1();
}


int main() {



    int arr[10] = { 0 };
    int i = 0;
    for(i = 0; i < 10; i++){
        arr[i] = i + 1;
        printf("%d \n", arr[i]);
    }


    printf("\n");

    test();
    printf("\n");


    //find the factorial
    printf("\n");
    int n = 0;
    scanf("%d", &n);
    //n! = 1*2*3......*n
    int result = 1;
    for(i = 1; i <= n; i++){
        result = result * i;
    }
    printf("%d is the result\n", result);

    return 0;
}
