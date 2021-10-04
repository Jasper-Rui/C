#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define MAX_LINE 80 /* The maximum length command */

//analyze
//1 read input
//2 sort input with strsok
//3 fork process
//4 execute process
//linkedlist to store history
int WAIT_TIME  = 10;

int main (){


    char * args[MAX_LINE/2 + 1]; /* an array of character strings */
    int should_run = 1; /* flag to determine when to exit program */
    int i = 0;
    int j = 0;
    char user_input[100] = {0};
    char * history_list[10];
    char history[100];
    pid_t pid;
    int execvp_status;
    int wait_status;


    while(should_run){
        printf("CSCI3120>");
        fflush(stdout);
        scanf("%[^\n]s", user_input);
        //history_list[i] = user_input;
        //i++;
        //printf("%s\n", history_list[i]);
        char * token = strtok(user_input, " ");
        while(token){
            args[j] = token;
            token = strtok(NULL, " ");
            //printf("%s\n", args[j]);
            j++;       
        }
        args[j] = NULL;

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
                printf("Child complete successfully");
            }
        }
    }

    
    return 0;
}