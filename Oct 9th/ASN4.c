/*
 * Author: 
 * Purpose: Spell check
 * Language:  C
 * File: ASN4.c 
 * Solution to assignment 4, CECD 3401 Fall 2021
 */


/*
    Analyze
    1. read input file name and store into array, assumer each file is seperated by a space such as dictionary.txt input1.txt input2.txt
    2. the first file is dictionary, read it and store everything into an dictionary array
        There are a few details need to be taken care of
            1. since it is stored in a file, i have to read if from file and store into array
            2. since there are only one word each line, then there much be a '\n' after every word till the last one
            3. change the '\n' to '\0' which is the end of string            
    3. all other files are target files need to be checked
    4. similar to read dictionary, here just read and get each word, compare it with dictionary, and store the error word
    5. print out result
    6. there will be upper case and lower case
*/

//header file, all necessary libraries are added inside header file
#include "ASN4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Gloabl variable initializtion
char dictionary[100][32];
//[0]["hello"]
//[1]["jasper"]
int len = 0;
//char wrong_words[100][32];



void readDictionay(char * input){

    FILE * fptr = NULL;   
    fptr = fopen(input, "r");
     /* 
     * Open file in r (read) mode. 
     * input is complete path to read file
     */

    /* fopen() return NULL if last operation was unsuccessful */
    if(fptr == NULL)
    {   
        /* File not read hence exit */
        printf("Unable to read file.\n");
        //exit(EXIT_FAILURE);
    }

    if(fptr != NULL) { 
        //read words and store array
        while(!feof(fptr)){
            fscanf(fptr, "%s", dictionary[len]);
            len++;
        }
    }
    fclose(fptr); //close file
}


void checkSpell (char * input){

    char testword[32];
    char error_word[100][32];
    int error = 0;

    FILE * fptr = NULL;   
    fptr = fopen(input, "r");
     /* 
     * Open file in r (read) mode. 
     * input is complete path to read file
     */

    /* fopen() return NULL if last operation was unsuccessful */
    if(fptr == NULL)
    {
        /* File not read hence exit */
        printf("Unable to read file.\n");
        //exit(EXIT_FAILURE);
    }
    if(fptr) { 

        int flag = 1;

        //store everything into array
        while(!feof(fptr)){   
            fscanf(fptr, "%s", testword);
            char word_copy[32];
            int word_length = strlen(testword);
            strcpy(word_copy, testword);
            //convert the word to lower case

            //process words
            for(int i = 0; i < word_length; i++){
                //ASCII 33 -> ! 44 -> ,  46 -> .
                if(word_copy[i] == 33 || word_copy[i] == 44 || word_copy[i] == 46){
                    word_copy[i] = '\0';
                    //"abc" -> "abc\0" -> 
                }
            }   

            //compare the word with dictionary
            //if any one of the world matches the dictionay 
            //then it should be 0, otherwise it's an error   
            for(int i = 0; i < len; i++){
                if(strcmp(word_copy, dictionary[i]) == 0){
                    flag = 0;
                    break;        
                }
                flag = 1;
            }

            if(flag == 1){
                strcpy(error_word[error], word_copy);
                error++;
            } 
        }

        if(error == 0){
            printf("File \"%s\" has no spelling errors.\n", input);
        }
        else{
            printf("File \"%s\" has spelling errors.\n", input);
            //print errors
            for(int i = 0; i < error; i++){
                printf("%s\n", error_word[i]);
            }
        }
    }
}



int main () {

    //initialize variables
    char *file[20]; //a pointer array to store the file name
    char filename[1000];
    scanf("%[^\n]%*c", filename);
    //assume the input is seperated by 1 space, such as: dictionary.txt input1.txt input2.txt 
    //assume 1st file is dictionary.txt

    char * token = strtok(filename, " ");
    int index = 0;

    while(token){
        file[index] = token;
        //file[0] = dictionary.txt address
        token = strtok(NULL, " ");
        index++;   
    }

    
    readDictionay(file[0]);

    for(int i = 1; i < index; i++){
        checkSpell(file[i]);
    }

    printf("End of Output\n");

    return 0;
}
