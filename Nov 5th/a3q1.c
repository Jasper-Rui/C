// File: a3q1.c Author: Haorui Yang
// Solution to question 1 of assignment 3, CSCI4171 Fall 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//store the info from txt file to array
char source[1000][1000];

int main () {

    /* following lines before flose(fp) is the read the BridgeFDB file and store all the info to a 2d array*/
    FILE * fp = NULL;
    //fp = fopen("BridgeFDB.txt", "r"); 
    fp = fopen("input1.txt", "r");
    int len = 0;
    if(fp == NULL) {
        perror("Error opening file");
        return(-1);
    }

    char copy[100];
    while(fgets(copy, 100, fp) != NULL) {
        /* writing content to array */
        int length = strlen(copy);

        if(copy[length - 1] == '\n'){
            copy[length - 1] = '\0';
        }

        strcpy(source[len], copy);
        len++;
        memset(copy, 0, 100);     
    }
    fclose(fp);


    FILE * fptr2 = NULL;
    //fptr2 = fopen("RandomFramesNew.txt", "r");
    fptr2 = fopen("input2.txt", "r");

    //there are 3 main processes when a new frame coming in
    //1. check if the source is already exits, if exits, then continue to next step, if not update it
    //2. check if the destion is exits, if exits, check which port
    //   if they are at same port, discard, if not, forward to destination port
    //   if the destination is not exit, then broadcast

    char target_src[100];
    char target_des[100];
    char port[10];

    

    while(!feof(fptr2)){
        int flag = 0; //status
        fgets(target_src, 100, fp);
        fgets(target_des, 100, fp);
        fgets(port, 10, fp);

        //remove \n
        int length = strlen(target_des);
        if(target_des[length - 1] == '\n'){
            target_des[length - 1] = '\0';
        }

        length = strlen(target_src);
        if(target_src[length - 1] == '\n'){
            target_src[length - 1] = '\0';
        }

        length = strlen(port);
        if(port[length - 1] == '\n'){
            port[length - 1] = '\0';
        }

        
        //step1
        int status = 0;
        for(int i = 0; i < len - 1; i++){
            if(strcmp(target_src, source[i]) == 0){
                //if the ports are not same, update it
                if(strcmp(source[i + 1], port) != 0){
                    strcpy(source[i + 1], port);
                }
            }
            else if(strcmp(target_src, source[i]) != 0){
                status = 1;
            }
        }

        if(status == 1){
            strcpy(source[len], target_src);
            strcpy(source[len + 1], port);
            len += 2;
        }
        //now the src can be found in file, the port are updated

        //step2
        for(int i = 0; i < len; i++){
            if(strcmp(target_des, source[i]) == 0){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            printf("%s\t%s\t%s\tBroadcast\n", target_src, target_des, port);
        }

        //step3
        //if we can find the des, then check the port
        else if(flag == 1){
            for(int i = 0; i < len - 1; i++){
                if(strcmp(source[i], target_des) == 0 && strcmp(port, source[i + 1]) == 0){
                    printf("%s\t%s\t%s\tDiscard\n", target_src, target_des, port);
                }
                else if(strcmp(source[i], target_des) == 0 && strcmp(port, source[i + 1]) != 0){
                    printf("%s\t%s\t%s\tForward on port %s\n", target_src, target_des, port, source[i + 1]);
                }
            }
        }

    }
    fclose(fptr2);
    return 0;
}