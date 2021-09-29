#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//&& *(input + i + 1) != '!'
//&& *(input + i - 1) != '-'

//there are 3 situations
//1 is just < and >
//2 is <!-- <> -->
//3 is <  <!-- --> >

char* checkforstarttags(char * input){
    assert(input);
    int len = strlen(input);
    printf("start tages now %d\n", len);
    char* start = input;
    for(int i = 0; i < len; i++){
        if(*(start + i) == '<' ){
            return start + i;
        }
    }
}

char* checkforstoptags(char * input){
    assert(input);
    int len = strlen(input);
    printf("stop tages now %d\n", len);
    char* end = input;
    for(int i = 0; i < len; i++){
        if(*(end + i) == '>'){
            return end + i;
        }
    }
}

int checkEOF(char* input){
    //go through the end of string and see if there is tags left
    //time complexity is an issue
    //but it is not the top priority
    assert(input);
    int len = strlen(input);
    printf("len is %d\n", len);
    for(int i = 0; i < len; i++){
        if(*(input + i) == '>'){
            return 1;
        }
    }
    return 0;
}

void validation (char* input){
    assert(input);
    char* storelocation = input;
    int len = strlen(input);

    printf("%d\n", len);

    int tagcount = 0;
    int lengthsum = 0;
    int minlength ;
    int maxlength = 0;
    char* start = input;
    char* end = NULL;
    int flag = 1;
    int length = 0;
    while(flag){
        start = checkforstarttags(start);
        end = checkforstoptags(start);
        flag = checkEOF(end);
        if(flag){
            length = end - start + 1;
            lengthsum += length;
            if(minlength > length) minlength = length;
            //minlength = minlength > length ? length : minlength;
            if(maxlength < length) maxlength = length;
            //maxlength = maxlength > length ? maxlength : length;
            //move start to end            
            
        }
        tagcount++;
        start = end;        
        printf("length is %d\n", length);
        printf("maxlength is %d\n", maxlength);
        printf("minlength is %d\n", minlength);
        printf("total length is %d\n", lengthsum);
        printf("total tags is %d\n", tagcount);
        
        printf("flag now is %d\n", flag); 
        printf("\n"); 
        //break;
    }
}




int main () 
{
    char buffer[10000] = "No tags here. This is a tag: <html> We allow empty tags <>, or <multiline tags>. <!-- a comment <ignored> -->";
    //fgets(buffer, 10000, stdin);
    printf("initial lenght is %d\n", strlen(buffer));
    //scanf("%[^\r]s", buffer); 
    validation(buffer);
    
    return 0;
}