#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char* XOR(char * gx, char * mx){
    if(*mx == '0'){
        return mx + 1;
    }
    else{
        for(int i = 0; i < strlen(gx); i++){
            if(*(gx + i) == *(mx + 1)){
                *(mx + i) = '0';
            }
            else{
                *(mx + i) = '1';
            }
        }
    }
    return mx + 1;
}


int main () {

    char gx[100];
    char mx[100];

    printf("Please enter G(x) and the separate by a space: ");
    scanf("%s %s", gx, mx);

    int gx_len = strlen(gx);
    int mx_len = strlen(mx);
    int i = 0;

    //adding gx - 1 '0' to mx
    for(i = 0; i < gx_len - 1; i++){
        mx[mx_len + i] = '0';
    }
    mx[mx_len + i] = '\0';

    //CRCreminder(gx, mx);

    char * temp = XOR(gx, mx);
    int len = strlen(mx);
    
    while(len > strlen(gx)){
        printf("%s\n", temp);
        temp = XOR(gx, temp);
        len--;
    }
    printf("%s\n", temp);
    

    return 0;
}