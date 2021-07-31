#include <stdio.h>
#include <time.h>
#include "stdlib.h"

// June 27, 2021
// Haorui Yang

// guess the number
// larger, smaller or bingo!

void menu(){
    printf("*************************************\n");
    printf("********      1. play       *********\n");
    printf("********      0. exit       *********\n");
    printf("*************************************\n");
}

void game(){
    // the core of this game
    // 1 generate a random number in a range
    // assume it's bwtween 1 to 100
    // 2 guess the number
    // rand will generate a number between 0 and 32767

    //srand(100);
    //srand(200);

    int number = rand() % 100 + 1;
    int guess;
    //printf("%d\n", number);
    // rand in the range of 1 to 100 after + 1, was 0 to 99

    while (1){
        printf("Please guess the number: \n");
        scanf("%d", &guess);
        if(guess < number){
            printf("Small \n");
        }
        else if(guess > number){
            printf("Large \n");
        }
        else{
            printf("Bingo! \n");
            break;
        }
    }

}

int main() {
    int input;
    srand((unsigned int) time(NULL));
    do {
        //print the menu for the game
        menu();
        printf("Please make a choice: \n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("Game start!\n");
                game();
                break;
            case 0:
                printf("Exit the game!\n");
                break;
            default:
                printf("Invalid choice, please chose a valid number!\n");
                break;
        }
    } while (input);

    // 0 == false;
    // 1 == true;
    return 0;
}
