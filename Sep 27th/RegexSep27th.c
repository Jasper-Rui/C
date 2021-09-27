#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <assert.h>


#define MAX_LINE_LENGTH 80

int main () 
{
    FILE *fptr;
    char content[10000];
    char line[MAX_LINE_LENGTH] = {0};
    unsigned int line_count = 0;
    fptr = fopen("input.txt", "r");
    if (!fptr)
    {
        perror("Error when opening the file");
        return 0;
    }
    /* Get each line until there are none left */
    while (fgets(line, MAX_LINE_LENGTH, fptr))
    {
        /* Print each line */
        printf("line[%06d]: %s", ++line_count, line);
        
        /* Add a trailing newline to lines that don't already have one */
        if (line[strlen(line) - 1] != '\n')
            printf("\n");
    }

    /*while (fscanf(line, "%s", content))
    {
        ;
    }*/


    fclose(fptr);
    return 0;
}