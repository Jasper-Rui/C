// File: A4.c Author: Haorui Yang
// Solution to Assignment 4, CSCI 3120 Fall 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//initialize a 2d array to store the task and a global variable i start with 0
char task[100][100];
int task_number = 0;

char info[100][100];
int info_count = 0;

void * FCFS (FILE * file_pointer) {
    //detect if the file_pointer is NULL or not
    assert(file_pointer);
    
    fputs("FCFS:\n", file_pointer);
    for(int i = 0; i < info_count; i++){
        if(i % 3 == 0) {
            fputs(info[i], file_pointer);
            fputs("\t", file_pointer);
        }
        else if(i % 3 == 1) {
            fputs(info[i], file_pointer);
            fputs("\t", file_pointer);
        }
        else {
            fputs(info[i], file_pointer);
            fputs("\n", file_pointer);
        }
    }

    int task_total = 0;
    int total_time = 0;
    int arrive_time = 0;
    int arrive_time_difference = 0;
    double time = 0;

    for(int i = 0; i < info_count - 1; i += 3){
        if(i == 0){
            fprintf(file_pointer, "Waiting time %s: 0\n", info[i]);
            arrive_time = atoi(info[i + 1]);
            total_time += atoi(info[i + 2]);
            task_total++;
        }
        else{
            arrive_time_difference = atoi(info[i + 1]) - arrive_time; // calculate the differene of arriving time
            arrive_time = atoi(info[i + 1]); // update arrive time
            total_time -= arrive_time_difference; // total time is the run time from last task minus the arrive time
            time += total_time;
            fprintf(file_pointer, "Waiting time %s: %d\n", info[i], total_time);
            total_time += atoi(info[i + 2]);
            task_total++;     
        }       
    }
    double average_time = time/task_total;
    fprintf(file_pointer, "Average Waiting Time: %.2f\n", average_time);
    return file_pointer;
}


void * RR (FILE * file_pointer) {
    assert(file_pointer);
    int time_quantum = 4;
    return file_pointer;
}

void * NPSJF (FILE * file_pointer) {
    assert(file_pointer);
    int run_time = 0;
    char runned_task[100][100];
    int runned_count = 0;
    //for the first job, it will run without interrupt
    //just add it to the file
    int i = 0;

    fputs("\nNPSJF\n", file_pointer);
    fprintf(file_pointer, "%s\t%s\t%s\n", info[i], info[i + 1], info[i + 2]);
    i += 3;
    strcpy(runned_task[i], info[i]);
    runned_count = 1;
    //run time is the total time needed to run previous tasks
    //now the rum time is just the first job running time
    run_time = atoi(info[i + 2]);

    //search for the shortest job
    int should_run = 1;

    //copy all other unrunned jobs into an array
    //stop it here at 08/11/2021 need a little rest

    return file_pointer;
}

void  * PSJG (FILE * file_pointer) {
    assert(file_pointer);
    return file_pointer;
    
}





int main () {

    /* following lines before flose(fp) is the read the TaskSpec file*/
    FILE * fp = NULL;
    fp = fopen("TaskSpec.txt", "r"); 

    if(fp == NULL) {
        perror("Error opening file");
        return(-1);
    }
    while (fgets(task[task_number], 100, fp) != NULL) {
        /* code */
        task_number++;
    }
    fclose(fp);

    //read all the infomation and store them into a 2d array
    int i = 0;
    while (i < task_number) {
        char * token = strtok(task[i], ",");
        while (token)
        {   
            char temp[100];
            strcpy(temp, token);
            int length = strlen(temp);
            //remove new line character 
            if(temp[length - 1] == '\n'){
                temp[length - 1] = '\0';
            }
            strcpy(info[info_count], temp);
            token = strtok(NULL, ",");
            info_count++;
        }
        i++;
    }
    //after this step, all the information are splited into name, arrive time and run time

    FILE * output_fp = NULL;
    output_fp = fopen("Output.txt", "w+"); 
    if(output_fp == NULL) {
        perror("Error creating file");
        return(-1);
    }
    //start with FCFS
    //passing a file pointer
    FCFS(output_fp);
    NPSJF(output_fp);
    fclose(output_fp);

    return 0;
}