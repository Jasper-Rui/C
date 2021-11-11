/*
 * Author: Haorui Yang
 * Purpose: To simulate CPU Scheduling
 * Language:  C
 * File: ASN4.c & ASN4.h
 * Solution to Assignment 4, CSCI 3120 Fall 2021
 */

//header file, all necessary libraries are added inside header file
#include "A4.h"

/*
 * Function:  make_Node
 * --------------------
 *  linkedlist: a linked list 
 *  command: a pointer that points to the location stores the string
 *  pid: children process identifier
 * 
 *  returns: the node with the commands and the pid
 */

Node * make_Node(char * task_name, int arrive_time, int run_time){
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->task_name, task_name);
    node->arrtive_time = arrive_time;
    node->run_time = run_time;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

/*
 * Function:  llist_initialize
 * --------------------
 *  no input parameter
 * 
 *  returns: the initialized linked_list
 */
LinkedList* llist_initialize(){
    LinkedList *linkedlist = malloc(sizeof(LinkedList));
    if(linkedlist == NULL){
        return NULL;
    }
    linkedlist->size = 0;
    linkedlist->first = NULL;
    linkedlist->last = NULL;
    return linkedlist;
}

/*
 * Function:  llist_add_node
 * --------------------
 *  linkedlist: linked list pointer
 *  command: command string to be added
 *  pid: integer pid to be added
 * 
 *  returns: if the new node add successfully
 */
bool llist_add_node(LinkedList * linkedlist, char * task_name, int arrive_time, int run_time){
    assert(linkedlist);
    assert(task_name);

    Node *node = make_Node(task_name, arrive_time, run_time);

    if(linkedlist->size != 0){
        node->prev = linkedlist->last;
        node->next = NULL;
        linkedlist->last->next = node;
        linkedlist->last = node;
        linkedlist->size += 1;
    }
    else if(linkedlist->size == 1){
        linkedlist->first->next = node;
        node->prev = linkedlist->first;
        node->next = NULL;
        linkedlist->last = node;
        linkedlist->size += 1;
    }
    else{
        linkedlist->first = node;
        linkedlist->last = linkedlist->first;
        linkedlist->size = 1;
    }
    return true;
}

/*
 * Function:  llist_remove_last
 * --------------------
 *  linkedlist: linked list pointer
 * 
 *  returns: false if the linked_list is NULL, otherwise 
 *           the linked_list pointer that has already removed the last node
 */

bool llist_remove(LinkedList *linkedlist, char * task_name){
    assert(linkedlist);
    assert(task_name);

    if(linkedlist->size == 1){
        linkedlist->first = NULL;
        linkedlist->last = NULL;
        linkedlist->size--;
    }
    else if(strcmp(task_name, linkedlist->first->task_name) == 0){
        linkedlist->first = linkedlist->first->next;
        linkedlist->size--;
        linkedlist->first->prev = NULL;
    }
    else if(strcmp(task_name, linkedlist->last->task_name) == 0){
        linkedlist->last = linkedlist->last->prev;
        linkedlist->size--;
        linkedlist->last->next = NULL;
    }
    else{
        Node * node = linkedlist->last;
        while(strcmp(task_name, node->prev->task_name) != 0){
            node = node->prev;
        }
        node->prev = node->prev->prev;
        linkedlist->size--;   
    }
    return true;
}

Node * searchSJ (LinkedList * linkedlist, int previous_run_time){
    Node * node = linkedlist->first;
    int shortest_time = linkedlist->first->run_time;
    for(int i = 0; i < linkedlist->size; i++){
        if(node->arrtive_time < previous_run_time){
            int temp = node->run_time;
            if(temp < shortest_time){
                shortest_time = temp;
            }
        }
        node = node->next;
    }
    Node * node_copy = linkedlist->first;
    for(int i = 0; i < linkedlist->size; i++){
        if(shortest_time == node_copy->run_time){
            break;
        }
        node_copy = node_copy->next;
    }
    return node_copy;
}

//initialize a 2d array to store the task and a global variable i start with 0
char task[100][100];
int task_number = 0;

char info[100][100];
int info_count = 0;

void * FCFS (FILE * file_pointer) {
    //detect if the file_pointer is NULL or not
    assert(file_pointer);
    
    int timer = 0;
    fputs("FCFS:\n", file_pointer);
    for(int i = 0; i < info_count; i++){
        if(i % 3 == 0) {
            fprintf(file_pointer, "%s\t", info[i]);
        }
        else if(i % 3 == 1) {
            fprintf(file_pointer, "%d\t", timer);
        }
        else {
            fprintf(file_pointer, "%d\n", atoi(info[i]) + timer);
            timer += atoi(info[i]);
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

void * NSJF (FILE * file_pointer) {
    assert(file_pointer);
    fputs("\nNSJF\n", file_pointer);
    int count = 0;
    LinkedList * linkedlist = llist_initialize();

    while(count < info_count){
        llist_add_node(linkedlist, info[count], atoi(info[count + 1]), atoi(info[count + 2]));
        count += 3;
    }

    //create a 2d array to store the info
    char task_order[100][100];
    int task_order_count = 1;

    int time[10];
    int time_count = 1;

    //first task
    int wait_time = 0;
    fprintf(file_pointer, "%s\t%d\t%d\n", linkedlist->first->task_name, wait_time, wait_time + linkedlist->first->run_time);
    wait_time += linkedlist->first->run_time;
    //fprintf(file_pointer, "Waiting time %s: %d\n", linkedlist->first->task_name, linkedlist->first->arrtive_time);

    strcpy(task_order[1], linkedlist->first->task_name);
    time[1] = linkedlist->first->arrtive_time;

    llist_remove(linkedlist, linkedlist->first->task_name);

    double average_time = 0;
    int wait[10];
    int wait_times = 0;

    wait[wait_times] = wait_time;
    wait_times++;

    //remaining task
    while(linkedlist->size){
        Node * node = searchSJ(linkedlist, wait_time);
        fprintf(file_pointer, "%s\t%d\t%d\n", node->task_name, wait_time, wait_time + node->run_time);
        //update wait_time;
        int index = 0;
        if(strlen(node->task_name) == 2){
            index = *(node->task_name + 1) - '0';
        }
         
        strcpy(task_order[index], node->task_name);
        time[index] = wait_time - node->arrtive_time;
        //fprintf(file_pointer, "Waiting time %s: %d\n", node->task_name, wait_time - node->arrtive_time);
        average_time += wait_time - node->arrtive_time;
        wait_time += node->run_time;
        wait[wait_times++] = wait_time;
        llist_remove(linkedlist, node->task_name);
        time_count++;
    }

    for(int i = 1; i <= time_count; i++){
        fprintf(file_pointer, "Waiting time %s: %d\n", task_order[i], time[i]);
    }

    fprintf(file_pointer, "Average Waiting Time: %.2f\n", average_time/time_count);
    return file_pointer;
}

void  * PSJF (FILE * file_pointer) {
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
    //close file pointer

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
    NSJF(output_fp);
    fclose(output_fp);
    //close file pointer

    return 0;
}