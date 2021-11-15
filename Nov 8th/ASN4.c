/*
 * Author: Haorui Yang
 * Purpose: To simulate CPU Scheduling
 * Language:  C
 * File: ASN4.c & ASN4.h
 * Solution to Assignment 4, CSCI 3120 Fall 2021
 */

//header file, all necessary libraries are added inside header file
#include "A4.h"

//initialize a 2d array to store the task and a global variable i start with 0
char task[150][150];
int task_number = 0;

char info[150][150];
int info_count = 0;
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
 * Function:  llist_add_frond
 * --------------------
 *  linkedlist: linked list pointer
 *  command: command string to be added
 *  pid: integer pid to be added
 * 
 *  returns: if the new node add successfully
 */
bool llist_add_front(LinkedList * linkedlist, char * task_name, int arrive_time, int run_time){
    assert(linkedlist);
    assert(task_name);
    Node *node = make_Node(task_name, arrive_time, run_time);
    node->next = linkedlist->first;
    node->prev = NULL;
    linkedlist->first->prev = node;
    linkedlist->first = node;
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
        //this part is a little buggy, but this part is never used in my code
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
    //find shortest job
    //use task name is better, since there may exist task coming in with the same run time
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


/*
 * Function:  FCFS
 * --------------------
 *  file_pointer: file which will store the prograss
 * 
 *  returns: file poitner
 */

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

    for(int i = 0; i < info_count; i += 3){
        if(i == 0){
            fprintf(file_pointer, "Waiting Time %s: 0\n", info[i]);
            arrive_time = atoi(info[i + 1]);
            total_time += atoi(info[i + 2]);
            task_total++;
        }
        else{
            arrive_time_difference = atoi(info[i + 1]) - arrive_time; // calculate the differene of arriving time
            arrive_time = atoi(info[i + 1]); // update arrive time
            total_time -= arrive_time_difference; // total time is the run time from last task minus the arrive time
            time += total_time;
            fprintf(file_pointer, "Waiting Time %s: %d\n", info[i], total_time);
            total_time += atoi(info[i + 2]);
            task_total++;     
        }       
    }
    double average_time = time/task_total;
    fprintf(file_pointer, "Average Waiting Time: %.2f\n", average_time);
    return file_pointer;
}

/*
 * Function:  RR
 * --------------------
 *  file_pointer: file which will store the prograss
 *  returns: file poitner
 */

void * RR (FILE * file_pointer) {
    //if there is only 1 task, rr will keep running this task
    assert(file_pointer);
    int time_quantum = 4;

    //since we already know there are how many task
    //read 1 task, process with time_quantum, then current run time is 4
    //add all the task arrive time under 4, then process second task
    //read all test arrive under 8
    //if two or more task arrive at the same time, new task should be placed to linkedlist first

    fputs("\nRR:\n", file_pointer);
    LinkedList * linkedlist = llist_initialize();
    
    int task_run_time = 0;
    int task_wait_time = 0;
    int task_read_count = 0;
    int current_time = 0;
    //now we read the first task and add it to the linkedlist
    //assume the run_time is 4, now add task with run_time under 4

    int wait_time_for_task[(info_count/3) + 1];
    int last_arrive_time[(info_count/3) + 1];
    for(int i = 0; i <= info_count/3; i++){
        wait_time_for_task[i] = 0;
        last_arrive_time[i] = 0;
    }
    while(1){   
        if(task_read_count == 0){
            llist_add_node(linkedlist, info[0], atoi(info[1]), atoi(info[2]));
            if(linkedlist->first->run_time > time_quantum) task_run_time = time_quantum;
            else task_run_time = linkedlist->first->run_time;
            fprintf(file_pointer, "%s\t%d\t%d\n", linkedlist->first->task_name, linkedlist->first->arrtive_time, task_run_time);
            wait_time_for_task[1] = linkedlist->first->arrtive_time;
            last_arrive_time[1] = linkedlist->first->arrtive_time;
            task_wait_time = task_run_time;
            task_read_count += 3;
            current_time = task_run_time;
            //The reason why it is 3, is the info_count/3 is the amount of task
            //if the task is not finished, add to the end
            //and read task
            //info[task_read_count + 1] is the arrive time for each task
            while(1){
                if(atoi(info[task_read_count + 1]) <= current_time && task_read_count <= info_count - 3){
                    llist_add_node(linkedlist, info[task_read_count], atoi(info[task_read_count + 1]), atoi(info[task_read_count + 2]));
                    task_read_count += 3;
                }
                else{
                    break;
                }
            }
            if(linkedlist->first->run_time - task_run_time > 0){
                llist_add_node(linkedlist, linkedlist->first->task_name, linkedlist->first->arrtive_time, linkedlist->first->run_time - task_run_time);
                llist_remove(linkedlist, linkedlist->first->task_name);
            }
            else{
                llist_remove(linkedlist, linkedlist->first->task_name);
            } 
        }
        else{
            //second stage process next task
            Node * node = linkedlist->first;
            int index = 0;
            if(strlen(node->task_name) == 2){
                index = *(node->task_name + 1) - '0';
            }
            else if (strlen(node->task_name) == 3) {
                index = (*(node->task_name + 1) - '0') * 10 + *(node->task_name + 2) - '0';
            } 
            //update run time
            if(linkedlist->first->run_time > time_quantum && linkedlist->size > 1) task_run_time = time_quantum;
            else task_run_time = linkedlist->first->run_time;

            if(linkedlist->size == 1 && task_read_count == info_count){
                task_run_time = linkedlist->first->run_time;
            } 

            fprintf(file_pointer, "%s\t%d\t%d\n", linkedlist->first->task_name, task_wait_time, task_wait_time + task_run_time);
            
            //if wait_time_for_task[index] != 0, means it already run once, so we need -4 
            if(wait_time_for_task[index] == 0 && index != 1){
                wait_time_for_task[index] = task_wait_time - linkedlist->first->arrtive_time;
            }
            else{
                //printf("%d\n", last_arrive_time[index]);
                //printf("%d\n", task_wait_time);
                wait_time_for_task[index] = task_wait_time - last_arrive_time[index] - time_quantum + wait_time_for_task[index];
            }

            last_arrive_time[index] = task_wait_time;
            task_wait_time += task_run_time;
            current_time += task_run_time;

            while(1){
                if(atoi(info[task_read_count + 1]) <= current_time && task_read_count <= info_count - 3){
                    llist_add_node(linkedlist, info[task_read_count], atoi(info[task_read_count + 1]), atoi(info[task_read_count + 2]));
                    task_read_count += 3;
                }
                else{
                    break;
                }
            }

            if(linkedlist->first->run_time - task_run_time != 0 && linkedlist->first->run_time - task_run_time > 0){
                llist_add_node(linkedlist, linkedlist->first->task_name, linkedlist->first->arrtive_time, linkedlist->first->run_time - task_run_time);
                llist_remove(linkedlist, linkedlist->first->task_name);
            }
            else{
                llist_remove(linkedlist, linkedlist->first->task_name);
            }
        }
        
        //condition to stop the while loop
        if(linkedlist->size == 0){
            break;
        }
    }
    double total_time = 0.00;
    for(int i = 0; i < info_count/3; i++){
        total_time += wait_time_for_task[i + 1];
        fprintf(file_pointer, "Waiting Time %s: %d\n", info[i * 3], wait_time_for_task[i + 1]);
    }
    fprintf(file_pointer, "Average Waiting Time: %.2f\n", total_time / (info_count/3));

    free(linkedlist);
    linkedlist = NULL;
    return file_pointer;
}

void * NSJF (FILE * file_pointer) {
    assert(file_pointer);
    fputs("\nNSJF:\n", file_pointer);
    int count = 0;
    LinkedList * linkedlist = llist_initialize();

    while(count < info_count){
        llist_add_node(linkedlist, info[count], atoi(info[count + 1]), atoi(info[count + 2]));
        count += 3;
    }

    //create a 2d array to store the info
    char task_order[150][150];

    int time[50];
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
    int wait[100];
    int wait_times = 0;

    wait[wait_times] = wait_time;
    wait_times++;

    //remaining task
    while(linkedlist->size){
        Node * node = searchSJ(linkedlist, wait_time);
        fprintf(file_pointer, "%s\t%d\t%d\n", node->task_name, wait_time, wait_time + node->run_time);
        //update wait_time;
        //check which task we are running 
        int index = 0;
        if(strlen(node->task_name) == 2){
            index = *(node->task_name + 1) - '0';
        }
        else if (strlen(node->task_name) == 3) {
            index = (*(node->task_name + 1) - '0') * 10 + *(node->task_name + 2) - '0';
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
        fprintf(file_pointer, "Waiting Time %s: %d\n", task_order[i], time[i]);
    }
    fprintf(file_pointer, "Average Waiting Time: %.2f\n", average_time/time_count);

    free(linkedlist);
    linkedlist = NULL;
    return file_pointer;
}

void  * PSJF (FILE * file_pointer) {
    assert(file_pointer);
    fputs("\nPSJF\n", file_pointer);
    int count = 0;
    LinkedList * linkedlist = llist_initialize();
    llist_add_node(linkedlist, info[count], atoi(info[count + 1]), atoi(info[count + 2]));
    count += 3;

    int current_time = 0;
    int next_task_arrive_time = 0;
    int prev_task_arrive_time = linkedlist->first->arrtive_time;
    while (count < info_count) {
        //time difference between new task and previous task
        next_task_arrive_time = atoi(info[count + 1]) - prev_task_arrive_time;
        if(linkedlist->first->run_time - next_task_arrive_time > atoi(info[count + 2])) {
            fprintf(file_pointer, "%s\t%d\t%d\n", linkedlist->first->task_name, current_time, current_time + next_task_arrive_time);
            current_time += next_task_arrive_time;
            prev_task_arrive_time = atoi(info[count + 1]);
            llist_add_front(linkedlist, info[count], atoi(info[count + 1]), atoi(info[count + 2]));
            count += 3;
        }
        else {
            ;
        }

        break;
    }



    free(linkedlist);
    linkedlist = NULL;
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

    while (fgets(task[task_number++], 100, fp) != NULL) { 
        ; 
    }
    fclose(fp);
    fp = NULL;
    //close file pointer and set variable to NULL

    //read all the infomation and store them into a 2d array
    int i = 0;
    while (i < task_number) {
        char * token = strtok(task[i], ",");
        while (token) {   
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
    RR(output_fp);
    NSJF(output_fp);
    PSJF(output_fp);

    fclose(output_fp);
    output_fp = NULL;
    //close file pointer and set variable to NULL
    return 0;
}