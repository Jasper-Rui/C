#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {


    FILE * fptr;
    fptr = fopen("input.txt", "r");
    if(fptr == NULL)
    {
        /* File not read hence exit */
        printf("Unable to read file.\n");
        exit(EXIT_FAILURE);
    }
    int aim = 0;
    int horizontal = 0;
    int depth = 0;


    while (!feof(fptr)) {
        char array[2000] = { 0 };
        long int value = 0;
        fscanf(fptr, "%s %d", &array, &value);
        printf("%s %d\n", array, value);
        if(strcmp("down", array) == 0){
            aim += value;
        }
        else if(strcmp("up", array) == 0){
            aim -= value;
        }
        
        else if(strcmp("forward", array) == 0){
            horizontal += value;
            depth = depth + aim * value;
        }
        //printf("round %d %d\n", x, y);
    }
    printf("%d %d %d", aim, horizontal, depth);

    return 0;
}    
