// File: ASN3.c Author: 
// Solution to assignment 3, ECED 3401 Fall 2021
#include "ASN2.h"


#define MAX_LINE 80 /* The maximum length command */

int main (){

    char * args[MAX_LINE/2 + 1]; /* an array of character strings */
    int should_run = 1; /* flag to determine when to exit program */
    char user_input[100] = {0};
    int i = 0;
    pid_t pid;
    int execvp_status;
    int wait_status;


    while(should_run){
   
        printf("CSCI3120>");
        fflush(stdout);

        scanf("%[^\n]s", user_input);
        char * token = strtok(user_input, " ");
        int index = 0;
        while(token){
            args[index++] = token;
            token = strtok(NULL, " ");
                 
        }
        args[index] = NULL;

        if(strcmp(args[0], "exit") == 0){
            should_run = 0;
        }    
        else{
            pid = fork();

            if(pid < 0){
                perror("Forked failed");
                return 1;
            }
            else if(pid == 0){
                execvp_status = execvp(args[0], args);  
                if(execvp_status == -1){
                    printf("execvp error\n");
                    exit(1);
                }
            }
            else{
                wait(&wait_status);
                printf("Child complete successfully\n");
            }
        }
        break;
    }

    return 0;
}