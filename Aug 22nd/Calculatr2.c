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

void calu(int (*pf)(int, int)){
    int x, y;
    int result = 0;
    printf("Please enter two number: \n");         
    scanf("%d %d", &x, &y);
    result = pf(x, y);
    printf("Result is %d \n", result);
}

int main(){
    int input = 0;
    do
    {
        menu();
        printf("Please make a choice: \n");
        scanf("%d", &input);   
        switch (input)
        {
        case 1:
            calu(add);
            break;
        case 2:
            calu(sub);
            break;
        case 3:
            calu(mul);
            break;
        case 4:
            calu(div);
            break;

        case 0:
            printf("Thank you for using! \n");
            break;
        default:
            printf("Invalie choice, please try it again!\n");
            break;
        }

    } while (input);

    return 0;
}