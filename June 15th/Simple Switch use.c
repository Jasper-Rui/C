#include <stdio.h>

int main()
{
    
    
    //switch( must be int, float or others won't work here )
    //case must be a constant variables, like 1 2 3 4 5 6, 1.1 is also restricted here
    // but something like 'a', 'b' is okay
    //break is not needed for every case, if depends on the requirements
    
    int day = 0;
    scanf("%d", &day);
    
    switch(day){
        /*case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;*/
    
    // if someone enter 1 to 5 and want to get weekday
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("Weekday\n");
            break;
        case 6:
        case 7:
            printf("Weekend\n");
            break;
        //in case of someone else adding new cases, add a break to avoid unexpected bugs
         default:
           printf("Error input, please try again with number between 1 to 7");
           break;
    	
    }

    return 0;
}
