#include <stdio.h>

//void swap(int* a, int* b){
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//
//int main() {
//
//    int a, b;
//
//    scanf("%d %d", &a, &b);
//
//    printf("Before swap they are: %d %d \n", a, b);
//
//    swap(&a,&b);
//
//    printf("After swap they are: %d %d", a, b);
//    return 0;
//}



//void print_multiplication_table(int input){
//
//    for(int i = 1; i <= input; i++){
//        for (int j = 1; j <= i; ++j) {
//            printf("%d x %d = %d ", i, j, i*j);
//        }
//        printf("\n");
//    }
//
//}
//
//int main(){
//    int input;
//    printf("Please enter a number\n");
//    scanf("%d", &input);
//    print_multiplication_table(input);
//
//    return 0;
//}


//print each single number
//void print(unsigned int input){
//    //must have 1 condition to stop it
//    if(input > 9){
//        print(input / 10);
//    }
//    printf("%d ", input % 10);
//
//}
//
//int main(){
//
//    unsigned int num = 0;
//    scanf("%u", &num);
//    print(num);
//    //assume the input is 1234
//    return 0;
//}


//calculate the length of an array
//int my_arrlen(char* input){
//    int count = 0;
//    while(*input != '\0'){
//        count++;
//        input++;
//    }
//    return count;
//}
//

#include <string.h>
//another way
//int my_strlen(char* input){
//    if(*input != '\0'){
//        return 1 + my_strlen(input + 1);
//    }
//    else{
//        return 0;
//    }
//}
//int main(){
//    // find the length of the char without creating new variables
//    //normally
//    char arr[10] = "length";
//    int len = strlen(arr);
//    printf("Len is %d \n", len);
//    printf("%d",my_strlen(arr));
//    //now lets creat a new function
//    return 0;
//}

//int Fac(int a){
//    //normal for loop to multiply one by one
//    return a;
//}
//int Fac1(int a){
//    if(a <= 1){
//        return 1;
//    }
//    else {
//        return a * Fac1(a - 1);
//    }
//}
//
//int main(){
//
//    int n = 0;
//    scanf("%d", &n);
//    int result = Fac1(n);
//    printf("%d\n", result);
//
//    return 0;
//}

//this is not efficiency
int Fib(int n){
    if(n <= 2){
        return 1;
    }
    else{
        return Fib(n-1)+ Fib(n-2);
    }
}

int Fib1(int n){
    int a = 1;
    int b = 1;
    int c = 0;
    while(n > 2){
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;

}

int main(){

    int n = 0;
    scanf("%d", &n);
    //int result = Fib(n);
    int result1 = Fib1(n);
    //printf("%d\n", result);
    printf("%d\n", result1);

   return 0;
}
