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

    int array[2000] = { 0 };
    int i = 0;
    while (!feof(fptr)) {
        char input[10] = { 0 };
        fgets(input, 10, fptr);
        int len = strlen(input);
        if(input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        array[i++] = atoi(input);
    }

    //printf("%d", array[1999]);

    int count = 0;
    int sum = array[0] + array[1] + array[2];

    for(int j = 1; j < 1998; j++){
        if((array[j] + array[j + 1] + array[j + 2]) > sum) {
            count++;
        }
        sum = array[j] + array[j + 1] + array[j + 2];
    }

    printf("%d\n", count);



    return 0;
}