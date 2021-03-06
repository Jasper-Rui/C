#include <stdio.h>
#include <assert.h>
//Question:
//move k elements to the end of the string
//example: ABCD -> 2 -> CDAB


//1: Get inpunt and store into an array
//2: Get the k numbers that user want to move
//3: 
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
    
    //assume input is ABCD
    //K = 2
    //1st round:
    //BCDA
    //2nd round:
    //tmp = B; CDAA;
    //right-- -> 0 -> false
}


int main(){
    char arr[10] = {0};
    int k = 0;
    gets(arr);
    scanf("%d" ,&k);
    reverse_string(arr, k);
    printf("%s", arr);
    return 0;
}