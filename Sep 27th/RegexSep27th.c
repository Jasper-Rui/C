#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int checksymbol1(char * buffer){
    regex_t regex;
    int value = regcomp(&regex, "[<.*>]", 0);
    //value = regexec(&regex, )
    if(value == 0){
        printf("yes\n");
    }
    //if value = 0 then it means there is a same pattern inside the string

    char open = '<';
    int count1 = 0;
    for(int i = 0; i < strlen(buffer); i++){
        if(buffer[i] == open)
            count1++;
    }

    char close = '>';
    int count2 = 0;
    for(int i = 0; i < strlen(buffer); i++){
        if(buffer[i] == close)
            count2++;
    }
    //compare the times it shows up, it will give a directly number
    int result = 0;

    printf("%d\n", count1);
    if(count1 == count2){
        return count1;
    }
    else{
        return result = count1 > count2 ? count2 : count1;
    }
}

int main () 
{
    FILE *fp;
    char buffer[10000];
    char c;
    fp = fopen("input.txt", "r");
    if(!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    //fgetc when end of  I/O or read failure, it will return EOF
    int i = 0;
    while ((c = fgetc(fp)) != EOF)
    {   
        buffer[i] = c;;
        i++;
    }
    //now all the content are stored into buffer array

    /*
    if (ferror(fp))
        printf("I/O error when reading");
    else if (feof(fp))
        printf("End of file reached successfully");
    */
    fclose(fp); 
    int a = checksymbol1(buffer);
    printf("%d\n", a);
    return 0;
}