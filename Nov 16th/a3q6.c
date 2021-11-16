/*
 * Author: Haorui Yang
 * Purpose: 
 * Language:  C
 * File: a3q6.c
 * Solution to Assignment 3 queston 6, CSCI 4152 Fall 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int main () {
    int should_run = 1;
    while (should_run) {
        char input1[100];
        char input2[100];
        int difference = 0;
        gets(input1);
        if (strcmp(input1, "END") == 0) {
            break;
        }
        else {
            gets(input2);
            int len1 = strlen(input1);
            int len2 = strlen(input2);

            input1[len1 - 1] = '\0';
            input2[len2 - 1] = '\0';
            
            if(len1 > len2) {
                for(int i = 0; i < len2; i++) {
                    if(input1[i] - input2[i] != 0) {
                        difference++;
                    }
                }
                difference += len1 - len2;
            }
            else if(len2 > len1) {
                for(int i = 0; i < len1; i++) {
                    if(input1[i] - input2[i] != 0) {
                        difference++;
                    }
                }
                difference += len2 - len1;
            }
            else {
                for(int i = 0; i < len1; i++) {
                    if(input1[i] - input2[i] != 0) {
                        difference++;
                    }
                }
            }
            printf("%d\n", difference);
            should_run = 1;
        }
    }
    return 0;
}