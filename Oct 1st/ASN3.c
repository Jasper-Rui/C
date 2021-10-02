// File: ASN3.c Author: Yueming Zou
// Solution to assignment 3, ECED 3401 Fall 2021

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//include header file
#include "ASN3.h"


//print mazz function
void PrintMazz(char * input){
    int len = strlen(input);
    int times = 0;

    for(int i = 0; i < len; i++){
        if(*(input + i) - 48 >= 0 && *(input + i) - 48 <= 9){
            //from ASCII we know that 48 represent '0' as a char
            //any character from 48 to 57 minus 48 will become a number
            //and it can be represented by a int 
            times += *(input + i) - 48;
        }
        else if(*(input + i) >= 65 && *(input + i) <= 90){
            //in ASCII 65 to 90 represent character from 'A' to 'Z'
            while (times){
                printf("%c", *(input + i));
                times--;
                //finally times will becomes 0 again for next round
            } 
        }
        else if(*(input + i) == 33){
            //33 in ASCII represent '!'
            printf("\n");
        }
        else if(*(input + i) == 42){
            //33 in ASCII represent '*'
            while (times){
                printf("*");
                times--;
            }
        }
        else if(*(input + i) == 98){
            //33 in ASCII represent 'b'
            while (times){
                printf(" ");
                times--;
            }
        }
    }
    printf("\n");
}

int main () {

    //initialize the input char array to empty and maximum size is 132
    char input[132] = {0};
    //initialize a file pointer
    FILE * fptr = NULL;
    /* 
     * Open file in r (read) mode. 
     * "input.txt" is complete path to read file
     */
    fptr = fopen("input.txt", "r");
    /* fopen() return NULL if last operation was unsuccessful */
    if(fptr == NULL)
    {
        /* File not read hence exit */
        printf("Unable to read file.\n");
        exit(EXIT_FAILURE);
    }

    if(fptr) { 
         while(!feof(fptr)) { 
             fgets(input, sizeof(input), fptr); 
             //check index of each char
             //if it's a number from 0 - 9 check ascii
             //if it's a char from A to Z
             //if it's a ! or b or *
             //! means \n
             //b means a space
             //* for
             PrintMazz(input);
             //printf("%s", input);
         } 
         fclose(fptr); 
         //close file
   } 
    return 0;
}