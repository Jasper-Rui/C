// File: a2q5.pc Author: Haorui Yang
// Solution to question 5 of assignment 2, CSCI4152/6509 Fall 2021


/*assume input file is "input.txt" with content:

true label:A result:A
true label:A result:A
true label:A result:A
true label:B result:B
true label:B result:B
true label:C result:C
true label:A result:B
true label:B result:C
true label:A result:B
end

compile the program by
gcc -o a2q5 a2q5.c

run the program by
./a2q5 < input1.txt

then result will show on the screen
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main () {

    char input[100];;

    char class[100] = {0};
    int true_table[100] = {0};
    int result_table[100] = {0};
    int precision[100] = {0};
    

    int should_run = 1;

    while (should_run)
    {
        scanf("%[^\n]%*c", input);
        if(strcmp(input, "end") == 0){
            for(int i = 0; i < strlen(class); i++){
                //printf("class is %c, true times is %d, result is %d precision is %d\n", class[i], true_table[i], result_table[i], precision[i]);          
            }
            exit(0);
            should_run = 0;
        }
        else{
            //printf("%c %c\n", input[11], input[20]);
            int len = strlen(class);
            if(len == 0){
                class[0] = input[11];
                true_table[0] = 1;
                result_table[0] = 1;
                precision[0] = 1;
            }
            else{
                int flag = 1;
                for(int i = 0; i < strlen(class); i++){
                    if(class[i] == input[11]){
                        flag = 0;
                        break;
                    }
                }

                if(flag == 1) {
                    int length = strlen(class);
                    class[length] = input[11];
                    //printf("%c\n", class[length]);
                }

                for(int i = 0; i < strlen(class); i++){
                    if(input[11] == input[20] && input[11] == class[i]){
                        precision[i]++;
                    }

                    if(input[11] == class[i]){
                        true_table[i] += 1;
                    }
                    if(input[20] == class[i]){
                        result_table[i] += 1;
                    }
                }

            }
        }
    }

    float precision_score[100] = {0};
    float recall[100] = {0};
    float f1[100] = {0};
    for(int i = 0; i < strlen(class); i++){
        if(result_table[i] == 0){
            precision_score[i] = 0;
        } 
        else if(true_table[i] == 0){
            recall[i] = 0;
        } 
        else if(recall[i] + precision_score[i] == 0){
            f1[i] = 0;
        }
        if(result_table[i] != 0){
            precision_score[i] = (float) precision[i] / result_table[i];
        }
        if(true_table[i] != 0){
                recall[i] = (float) precision[i] / true_table[i];
        }
        if((recall[i] + precision_score[i]) != 0){
            f1[i] = (2 * precision_score[i] * recall[i]) / (recall[i] + precision_score[i]);
        }
        printf("P(%c)=%.5f ", class[i], precision_score[i]);
        printf("R(%c)=%.5f ", class[i], recall[i]);
        printf("F1(%c)=%.5f ", class[i], f1[i]);
        printf("\n");
    }
    float ave_precision_score = 0;
    float ave_recall = 0;
    int i = 0;
    for(i = 0; i < strlen(class); i++){
        ave_precision_score += precision_score[i];
        ave_recall += recall[i];
    }

    printf("P=%.5f R=%.5f F1=%.5f\n",ave_precision_score/i, ave_recall/i, (2 * (ave_precision_score/i) * (ave_recall/i))/((ave_precision_score/i) + (ave_recall/i)));
    return 0;
}