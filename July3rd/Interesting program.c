#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

//shut down program

//count 60s before shut down the system
//if the expected input is entered
//the stop the program

//shutdown -s -t 60
//this command is for shutting down the system after 60s
//shutdown -a
//cancel the plan for shutting down

//int main() {
//    char input[20] = {0};
//    //system("shutdown -s -t 60");
//again:
//    printf("Warning, your system will shut donw in 60s, if enter : 'I am stupid' then this program will stop\n");
//    scanf("%s", input);
//    if(strcmp(input, "I am stupid") == 0){
//        system("shutdown -a");
//    }
//    else{
//        goto again;
//    }
//    //now this will lead to an infinite loop
//    return 0;
//}
//
// now we have a better way
int main() {
    char input[20] = {0};
    system("shutdown -s -t 60");
    while (1) {
        printf("Warning, your system will shut down in 60s, if enter : 'I am stupid' then this program will stop\n");
        scanf("%s", input);
        if (strcmp(input, "I am stupid") == 0) {
            system("shutdown -a");
            break;
        }
    }
    return 0;
}