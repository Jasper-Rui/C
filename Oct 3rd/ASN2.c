/*
 * Author: Haorui Yang
 * Purpose: To simulate a simple shell
 * Language:  C
 * File: ASN2.c 
 * Solution to assignment 2, CSCI 3120 Fall 2021
 */

//header file, all necessary libraries are added inside header file
#include "ASN2.h"
#define MAX_LINE 80 /* The maximum length command */

//initializa 4 global variables
int wait_status;
int nth_command;
char copyofcommand[100];
char nth_commands[100];


/*
 * Function:  make_Node
 * --------------------
 *  linkedlist: a linked list 
 *  command: a pointer that points to the location stores the string
 *  pid: children process identifier
 * 
 *  returns: the node with the commands and the pid
 */
Node * make_Node(LinkedList * linkedlist ,char * command, int pid){
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->command, command);
    node->pid = pid;
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
bool llist_add_node(LinkedList * linkedlist ,char *command, int pid){
    if(linkedlist == NULL){
        return false;
    }
    Node *node = make_Node(linkedlist, command, pid);
    if(linkedlist->size != 0){
        node->next = linkedlist->first;
        linkedlist->first = node;
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
bool llist_remove_last(LinkedList *linkedlist){
    if(linkedlist == NULL){
        return false;
    }
    if(linkedlist->size == 1){
        linkedlist->first = NULL;
        linkedlist->last = NULL;
        linkedlist->size--;
    }
    else{
        Node * node = linkedlist->first;
        while(node->next != linkedlist->last){
            node = node->next;
        }
        node->next = NULL;
        linkedlist->last = node;
        linkedlist->size--;
    }
    return true;
}


/*
 * Function:  addhistory
 * --------------------
 *  linkedlist: linked list pointer
 *  command: command string to be added
 *  pid: integer pid to be added
 * 
 *  The purpose of this fuction is to the add the command history as a node
 *              at the meantime, check if the size of nodes is less than 10 
 *              or large than 10, if large than 10, add the newest one and 
 *              delete the last node
 *              
 */
void addhistory(LinkedList * linkedlist, char * command, int pid){

    Node *node = make_Node(linkedlist, command, pid);
    //here node add unsuccessful
    if(linkedlist->size == 0){
        linkedlist->first = node;
        linkedlist->last = node;
        linkedlist->size++;
    }
    else if(linkedlist->size > 0 && linkedlist->size < 10){
        llist_add_node(linkedlist, command, pid);
    }
    else{
        llist_add_node(linkedlist, command, pid);
        llist_remove_last(linkedlist);
    }
}

/*
 * Function:  printHistory
 * --------------------
 *  linkedlist: linked list pointer contains the commands history
 * 
 *  The purpose of this fuction is print the history with a specific format
 */
void printHistory(LinkedList * linkedlist){
    Node *node = (Node *) malloc(sizeof(Node)); 
    printf("%s\t\t%s\t\t\t%s\t\t\t\t\n", "ID","PID","Command");
    for(int i = 0; i < linkedlist->size; i++){
        node = linkedlist->first;
        for(int j = 0; j < linkedlist->size; j++){
            if(i == j){
                printf("%d\t\t%d\t\t\t%s\t\t\t\t\n", i + 1, node->pid, node->command);
                break;
            }
            else{
                node = node->next;
            }
        }   
    }    
}


/*
 * Function:  execute
 * --------------------
 *  args: level 2 pointers
 *  command: command string to be added
 * 
 *  The purpose of this fuction is to execute the command and it has 
 *              several conditions, it has to check if the commend is
 *              one of (!!, or !1 to !10), for those command, execute 
 *              the required command and add the executed command not
 *              the (!!, or !1 to !10)         
 */
int execute(char ** args, LinkedList * linkedlist){
    pid_t pid = fork();           
    if(pid < 0){
        perror("Forked failed");
        return 1;
    }
    else if(pid == 0){
        int execvp_status = execvp(args[0], args); 
        if(execvp_status == -1){
            printf("Invalid command!\n");
            exit(1);
        }
    }
    else{
        if(strcmp(copyofcommand, "!!" ) == 0){
            addhistory(linkedlist, linkedlist->first->command, pid);
        }
        else if(nth_command){
            addhistory(linkedlist, nth_commands, pid);
        }
        else{
            addhistory(linkedlist, copyofcommand, pid);
        }
        wait(&wait_status);
        //printf("Child complete successfully\n");
    }
    return 1;
}


/*
 * Function:  testNth
 * --------------------
 *  input: a pointer that stores the input command
 * 
 *  The purpose of this fuction is to find the specifice command to be executed again        
 */
int testNth(char * input){
    char *test[10] = {"!1", "!2", "!3", "!4", "!5", "!6", "!7", "!8", "!9", "!10"};
    for(int i = 0; i < 10; i++){
        if(strcmp(input, test[i]) == 0){
            return i + 1;
        }
    }
    return 0;
}


int main (){
    int should_run = 1; /* flag to determine when to exit program */
    //initialize an linkedlist
    LinkedList * linkedlist = llist_initialize();
    while(should_run){
        char executeRecentCommand[100] = {0};
        char * args[MAX_LINE/2 + 1]; /* an array of character strings */
        char user_input[100];
        printf("CSCI3120>");
        fflush(stdout);    
        scanf("%[^\n]%*c", user_input);//read user input
        strcpy(copyofcommand, user_input);//make a copy for later use
        char * token = strtok(user_input, " ");
        int index = 0;
        while(token){
            args[index++] = token;
            token = strtok(NULL, " ");  
        }
        //tokenlize the input
        args[index] = NULL;
        nth_command = testNth(user_input);
        //if it's one of(!!, !1 to !10)
        //we need to know which index it want

        //check if user want to exit
        if(strcmp(args[0], "exit") == 0){
            should_run = 0;
        }   
        //check if user want to list the history
        //if 0 commands then print No command is in history!
        //else list the commands
        else if(strcmp(args[0], "history") == 0){
            if(linkedlist->size == 0){
                printf("No command is in history!\n");
            }
            else{
                printHistory(linkedlist);
            }
        }
        //if the user input is "!!", execute the recent command 
        //if the command history is 0, then print No command is in history!
        else if(strcmp(args[0], "!!") == 0){
            if(linkedlist->size == 0){
                printf("No command is in history!\n");
            }
            else{
                //execute the command
                strcpy(executeRecentCommand, linkedlist->first->command);
                printf("%s\n", executeRecentCommand);
                token = strtok(executeRecentCommand, " ");
                index = 0;
                while(token){
                    args[index++] = token;
                    token = strtok(NULL, " ");  
                }
                args[index] = NULL;
                execute(args, linkedlist);
                //after using the executeRecentCommand string
                //reset it to null
                memset(executeRecentCommand, 0, sizeof executeRecentCommand);
            }
        }
        
        else if(nth_command){
            Node *node = (Node *) malloc(sizeof(Node)); 
            node = linkedlist->first;
            for(int nth = 0; nth < 10; nth++){
                if((nth_command - 1) == nth){
                    strcpy(executeRecentCommand, node->command);
                    strcpy(nth_commands, node->command);
                    printf("%s\n", executeRecentCommand);
                    token = strtok(executeRecentCommand, " ");
                    index = 0;
                    while(token){
                        args[index++] = token;
                        token = strtok(NULL, " ");  
                    }
                    args[index] = NULL;
                    execute(args, linkedlist);
                    memset(executeRecentCommand, 0, sizeof executeRecentCommand);
                    break;
                }
                else{
                    node = node->next;
                }
            }
        }
        else{    
            //execute normal command
            execute(args, linkedlist);
        }
    }
    return 0;
}
//Done!




