#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

//initialize variables and functions
int merged_list[2000];

typedef struct Parameters{
    int * starting_index;
    int * ending_index; 
} parameters;

typedef struct Merge{
    int * list1_starting_index;
    int * list2_starting_index;
    int list1_size; 
    int list2_size;
} merge;

int ConvertCharToInt(char * input);
int cmp_int(const void* var1, const void* var2);
void * sorter(void * input);
void * merger(void * input);


int main () {

    parameters * data1 = (parameters *) malloc (sizeof (parameters));
    parameters * data2 = (parameters *) malloc (sizeof (parameters));
    merge * data3 = (merge *) malloc (sizeof (merge));

    char integer_list[10000];
    int list[2000];

    FILE * fptr = NULL;
    fptr = fopen("input1.txt", "r");
    fgets(integer_list, 2000, fptr);

    //1. input is a char array, each integer is separated by a ','
    //2. change char type to int type
    //3. below code is read input from a file, convert the char array to integer list


    int index = 0;
    char * token = strtok(integer_list, ",");

    while(token){
        //two ways to convert char array to integer
        /*
        if(strlen(token) == 1){
            list[index] = (*token) - 48;
            index++;
            token = strtok(NULL, ",");
        }
        else{
            list[index] = ConvertCharToInt(token);
            index++;
            token = strtok(NULL, ",");
        }
        */
       list[index] = atoi(token);
       index++;
       token = strtok(NULL, ",");
    }

    //divide the list into two sub list
    //if the size is odd, then the fisrt list will have one element than the other list
    int sub_list1[1000];
    int sub_list2[1000];
    //copy the list into two sub list

    if(index % 2 == 0){
        memcpy(sub_list1, list, (index / 2) * sizeof(int));
        memcpy(sub_list2, list + (index / 2), (index / 2) * sizeof(int));
        data1->starting_index = list;
        data1->ending_index = &list[index / 2];
        data2->starting_index = &list[index / 2];
        data2->ending_index = &list[index];
        data3->list1_starting_index = data1->starting_index;
        data3->list2_starting_index = data2->starting_index;
        data3->list1_size = index / 2;
        data3->list2_size = index / 2;
    }
    else{
        memcpy(sub_list1, list, ((index + 1)/ 2) * sizeof(int));
        memcpy(sub_list2, list + ((index + 1)/ 2), (index / 2) * sizeof(int));
        data1->starting_index = list;
        data1->ending_index = &list[(index + 1) / 2];
        data2->starting_index = &list[(index + 1) / 2];
        data2->ending_index = &list[index];
        data3->list1_starting_index = data1->starting_index;
        data3->list2_starting_index = data2->starting_index;
        data3->list1_size = (index + 1) / 2;
        data3->list2_size = (index + 1) / 2 - 1;
    }

    pthread_t thread1; //sort first part list
    pthread_t thread2; //sort second part list
    pthread_t thread3; //merge the sort to a new list

    pthread_create(&thread1, NULL, sorter, data1);
    pthread_create(&thread2, NULL, sorter, data2);
    pthread_create(&thread3, NULL, merger, data3);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    
    fclose(fptr);

    FILE * fptr2 = NULL;
    /* 
     * Open file in w (write) mode. 
     * "SortedIntegerList.txt" is complete path to create file
     */
    fptr2 = fopen("SortedIntegerList.txt", "w");
    int i = 0;
    for(i = 0; i < index - 1; i++){
        /* Write data to file */
        fprintf(fptr2, "%d,", merged_list[i]);
        //fputs(merged_list[i], )
    }
    fprintf(fptr2, "%d", merged_list[i]);

    //free memeory
    free(data1);
    free(data2);
    free(data3);

    fclose(fptr2);
    return 0;

}


int ConvertCharToInt(char * input){
    int result = 0;
    int len = strlen(input);
    for(int i = 0; i < len; i++){
        result *= 10;
        result += (*(input + i) - 48);
    }
    return result;
}

/*
 * Function:  make_Node
 * --------------------
 *  linkedlist: a linked list 
 *  command: a pointer that points to the location stores the string
 *  pid: children process identifier
 * 
 *  returns: the node with the commands and the pid
 */
int cmp_int(const void* var1, const void* var2){
    return *(int*)var1 - *(int*)var2;
    //compare two variables, return 1 if var1 larger than var2, otherwise return 0
}


void * sorter(void * input){
    parameters * para = input;
    qsort(para->starting_index, para->ending_index - para->starting_index, sizeof(int), cmp_int);
    return 0;
}

void * merger(void * input){
    merge * input_struct = input;
    int size1 = input_struct->list1_size;
    int size2 = input_struct->list2_size;
    
    
    int i, j = 0;
    int index = 0;

    
    while(i < size1 && j < size2){
        if(*(input_struct->list1_starting_index + i) > *(input_struct->list2_starting_index + j)){
            merged_list[index] = *(input_struct->list2_starting_index + j);
            j++;
        }
        else if (*(input_struct->list1_starting_index + i) < *(input_struct->list2_starting_index + j)) {
            merged_list[index] = *(input_struct->list1_starting_index + i);
            i++;
        }
        index++;
    }

    while(i < size1){
        merged_list[index] = *(input_struct->list1_starting_index + i);
        i++;
        index++;
    }

    while(j < size2){
        merged_list[index] = *(input_struct->list2_starting_index + j);
        j++;
        index++;
    }
    pthread_exit(0);
    return 0;
}