#include <stdio.h>

void six(int input)
{
    int m;
    if(input == 0);
    else{
        m = input % 6;
        six(input / 6);
        printf("%d",m);
    }
}

int main(){
    
    int input;
    scanf("%d",&input);
    six(input);

    return 0;
}