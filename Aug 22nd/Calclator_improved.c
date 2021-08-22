#include <stdio.h>


int add(int a, int b){ // int * (int, int)
    return a + b;
}

int sub(int a, int b){ // int * (int, int)
    return a - b;
}

int mul(int a, int b){
    return a * b;
}

int div(int a, int b){
    return a / b;
}

void menu(){
    printf("*************************************************\n");
    printf("************** 1. Add   2. Sub ******************\n");
    printf("************** 3. Mul   4. Div ******************\n");
    printf("**************     0. Exit     ******************\n");
    printf("*************************************************\n");

}


int main(){
    int input = 0;
    int result;
    int x, y;
    do
    {
        menu();
        printf("Please make a choice: \n");
        scanf("%d", &input);
        int (*parr[5])(int, int) = {0 ,add, sub, mul, div};
                                   // 0   1    2   3    4

        if(input == 0){
            printf("Thanks for using! \n");
        }
        else if(input >= 1 && input <= 4){
            printf("Please enter two integers: \n");
            scanf("%d %d", &x, &y);
            result = parr[input](x, y);
            printf("Result is %d\n", result);

        }
        else{
            printf("Invalid choice, please try it again.\n");
        }
    } while (input);

    return 0;
}