#include <stdio.h>
#include <assert.h>
#include <string.h>

//Question:
//is abcde the same after bcdea with reverse k times?

unsigned int my_strlen_improve(const char* input) {//or size_t my_strlen_improve(const char* input)
	assert(input != NULL);
	int count = 0;
	while (*input++){
		count++;
	}
	return count;
}

void reverse_string(char* string, int k){
    assert(string != NULL);
    int left = 0;// 1st element
    int right = k;// last element
    int len = my_strlen_improve(string);
    
    while (right)
    {
        char tmp = string[0];
        for(int i = 0; i < len - 1; i++){
            string[left + i] = string[left + i + 1] ; //move (ABCD) TO (BCDD) 
        }
        string[len - 1] = tmp;//Change BCDD to BCDA
        right--;
    }
}


int main(){


    char input1[100];
    char input2[100];
    gets(input1);
    gets(input2);
    int times1 = my_strlen_improve(input1);
    int times2 = my_strlen_improve(input2);
    int n;
    if(times1 != times2){
        printf("0\n");
    }
    else{
        for(n = 0; n < times1; n++){
            if(strcmp(input1, input2) != 0){
                reverse_string(input2, 1);
            }
            else if(strcmp(input1, input2) == 0){
                break;
            }
        }
        printf("%d \n", n);
    }


}