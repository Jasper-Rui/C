#include <stdio.h>
#include <string.h>
#include <assert.h>


int main () {
    char arr1[] = "JasperYang@dal.ca";
    char arr2[100] = {0};
    strcpy(arr2, arr1);

    char sep[] = "@.";
    //then we try strtok
    strtok(arr2, sep);

    return 0;
}