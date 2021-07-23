#include <stdio.h>



int is_leap_year(int year){
    return (year % 4 == 0  && year % 100 != 0) || year % 400 == 0;
}

int main() {
    int year;
    for( year = 1000; year <= 2000; year++){
        if(is_leap_year(year) == 1){
            printf(("%d "), year);
        }
    }

    return 0;
}
