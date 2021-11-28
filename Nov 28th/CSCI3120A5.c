/*
 * Author: Haorui Yang
 * Purpose: To simulate CPU Scheduling
 * Language:  C
 * File: ASN5.c 
 * Solution to Assignment 5, CSCI 3120 Fall 2021
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define  BUFFER_SIZE  5 
typedef  int  buffer_item; 
buffer_item buffer[BUFFER_SIZE];


int main (int argc, char *argv[]) {
    int sleep_time = 0;
    int number_of_producer = 0;
    int number_of_consumer = 0;
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);
    printf("%s\n", argv[3]);
    //before producer and consumer threads are created, the buffer is empty


    //we assume that when a buffer slot is empty, “-1” should be placed into the corresponding buffer slot
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = -1;
    }
    int array[3] = { 0 };
    int i = 0;

    char * token = strtok(argv[1], " ");
    array[i++] = atoi(token);
    while (token)
    {
        array[i++] = atoi(token);
    }
    

    int sleep_time = array[0];
    int number_of_producer = array[1];
    int number_of_consumer = array[2];

    //scanf("%d %d %d", &sleep_time, &number_of_producer, &number_of_consumer);
    //printf("%d %d %d\n", sleep_time, number_of_producer, number_of_consumer);
    


    return 0;
}