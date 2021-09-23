#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>


int main () {

    printf("Please Enter Your Sentence: ");
    char input[200];
    gets(input);

    //initialize a file pointer
    FILE * fptr = NULL;

    /* 
     * Open file in w (write) mode. 
     * "Output.txt" is complete path to create file
     */
    fptr = fopen("Output.txt", "w");
    /* fopen() return NULL if last operation was unsuccessful */
    if(fptr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    int length = strlen(input);
    for(int i = 0; i < length; i++){
        if(input[i] == ' '){

            /* Write data to file */
            fputs("\n", fptr);
            printf("\n");
        }
        else {
            /* Write data to file */
            fputs(&input[i], fptr);
            printf("%c", input[i]);
        }
    }

    /* Close file to save file data */
    fclose(fptr);



    return 0;
}