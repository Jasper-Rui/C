#include <stdio.h>
int calculate(int row, int index){
    if(row == 1 || row == 2 || index == 1 || index == row){
        return 1;
    }
    else{
        return calculate(row - 1, index - 1) + calculate(row - 1, index);
    }
}

int main()
{
    //1
    //1 1
    //1 2 1
    //1 3 3 1 
    //1 4 6 4 1 
    //1 5 10 10 5 1
    int input = 0;
    scanf("%d", &input);
    
    for(int i = 1; i <= input; i++){
        for(int j = 1; j <= i; j++){
            int result =  calculate(i, j);
            printf("%d ", result);
        }
        printf("\n");
        
    }
    return 0;
}