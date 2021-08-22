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
        if(input != 0){
            printf("Please enter two number: \n");         
            scanf("%d %d", &x, &y);
        }
    
        switch (input)
        {
        case 1:
            result = add(x, y);
            printf("Result is %d\n", result);
            break;
        case 2:
            result = sub(x, y);
            printf("Result is %d\n", result);
            break;
        case 3:
            result = mul(x, y);
            printf("Result is %d\n", result);
            break;
        case 4:
            result = div(x, y);
            printf("Result is %d\n", result);
            break;

        case 0:
            printf("Thank you for using! \n");
            break;
        default:
            printf("Invalie choice, please try it again!");
            break;
        }

    } while (input);

    return 0;
}