#include <stdio.h>

void check(int* arr){
    int a = (arr[1] == 2) + (arr[0] == 3);
    int b = (arr[1] == 2) + (arr[4] == 4);
    int c = (arr[2] == 1) + (arr[3] == 2);
    int d = (arr[2] == 5) + (arr[3] == 3);
    int e = (arr[4] == 4) + (arr[0] == 1);
  
    if((arr[0] + arr[1] + arr[2] + arr[3] + arr[4] == 15) && ((a + b + c + d + e) == 5)){
        printf("A is %d, B is %d, C is %d, D is %d, E is %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    }
}

int main(){
    int arr[5] = {0};
    for(int i = 0; i < 2; i++){
        if(i == 0) {
            arr[0] = 3;
        }
        else {
            arr[1] = 2;
        }
        for(int j = 0; j < 2; j++){
            if(j == 0) {
                arr[1] = 2;
            }
            else{
                arr[4] = 4;
            }
            for(int k = 0; k < 2; k++){
                if(k == 0){
                    arr[2] = 1;
                } 
                else {
                    arr[3] = 2;
                }
                for(int l = 0; l < 2; l++){
                    if(l == 0) arr[2] = 5;
                    else {
                        arr[3] = 3;
                    }
                    for(int n = 0; n < 2; n++){
                        if(n == 0) arr[4] = 4;
                        else {
                            arr[0] = 1;
                        }
                        check(arr);
                    }
                }
            }

        }
    }


    



    return 0;
}