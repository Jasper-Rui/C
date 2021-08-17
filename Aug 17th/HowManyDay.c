#include <stdio.h>

int main(){
    int year, month;
    int result;
    while(scanf("%d %d", &year, &month) != EOF){
        if(month == 1 || month == 3 || month == 5 || month == 7 
           || month == 8 || month == 10 || month == 12){
            result = 31;
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11){
            result = 30;
        }
        else{
            if(year % 4 == 0 && year % 100 != 0){
                result = 29;
            }
            else if(year % 400 == 0) result = 29;
            else result = 28;
        }
        printf("%d \n", result);
    }

    return 0;
}