// simulation of log in

#include <stdio.h>
#include <string.h>
int main() {
    int count;
    char password[20] = {0};
    //assume password is aws123
    int i = 0;

    for(i = 0; i < 3; i++){
        printf("Please enter passowrd: \n");
        scanf("%s", password);
        //if(password == "aws123"){
            //here we have a problem
            //wwe cant use == to compare 2 char[]
            //instead
        if(strcmp(password,"aws123") == 0){
            //return 0 if they are equal
            //return 1 if not
            printf("Sucessfully logged in!\n");
            break;
        }
        else{
            printf("The password in incorrect, please retry!\n");
        }
    }
    if(i == 3){
        printf("gg\n");
    }
    return 0;
}
