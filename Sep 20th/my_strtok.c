#include <stdio.h>
#include <string.h>
#include <assert.h>

//here is how strtok works
//it will first look for the tag we want, and end it will '\0'
//return a pointer 
//if the 1st para is not null, then it will find the mark that shows up in str for the 1st time
//if the 1st para is null, then it will keep finding the next mark in the same str
int main () {
    char arr1[] = "JasperYang@dal.ca";
    char arr2[100] = {0};
    strcpy(arr2, arr1);

    char sep[] = "@.";
    //then we try strtok
    char * result1 = strtok(arr2, sep);
    //here in arr2 -> JasperYang\0dal.ca
    printf("%s\n", result1);
    char * result2 = strtok(NULL, sep);
    //here in arr2 -> JasperYang\0dal\0ca
    printf("%s\n", result2);

    char * result3 = strtok(NULL, sep);
    //here in arr2 -> JasperYang\0dal\0ca the only thing left is ca
    printf("%s\n", result3);

    char * ret = NULL;
    char arr3[200] = {0};
    strcpy(arr3, arr1);
    for(ret = strtok(arr3, sep); ret != NULL; ret = strtok(NULL, sep)){
        printf("%s\n", ret);
    }

    return 0;
}