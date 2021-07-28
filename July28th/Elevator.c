#include <stdio.h>


int elevator(int people){
    int minute = 0;

    if(people <= 12){
        return minute = minute + 4;
    }
    else{
        return 4 + elevator(people - 12);
    }
}



int main(){

    int people;
    printf("Please enter a valie number: ");
    scanf("%d", &people);

    printf("%d is needed.", elevator(people));


    return 0;
}