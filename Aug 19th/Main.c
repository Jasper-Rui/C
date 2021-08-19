#include <stdio.h>

int check(int* arr){
    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum += *(arr + i);
    }
    for(int i = 0; i < 5; i++){
        for(int j = 1; j < 5; j++){
            if( (*(arr + i)) == (*(arr + j))){
                return 0;
            }
        }
    }
    if(sum == 15){
        return 1;
    }
    return 0;
}

int main(){

    int arr[5] = {0};
    for(int i = 0; i < 2; i++){
        if(i == 0){
            arr[1] = 2;
        }
        else{
            arr[0] = 3;
        }
        for(int j = 0; j < 2; j++){
            if(j == 0){
                arr[1] = 2;
            }
            else{
                arr[4] = 4;
            }
            for(int k = 0; k < 2; k++){
                if(k == 0){
                    arr[2] = 1;
                }
                else{
                    arr[3] = 2;
                }
                for(int h = 0; h < 2; h++){
                    if(h == 0){
                        arr[2] = 5;
                    }
                    else{
                        arr[3] = 3;
                    }
                    for(int f = 0; f < 2; f++){
                        if(f == 0){
                            arr[4] = 4;
                        }
                        else{
                            arr[0] = 1;
                        }
                        int result = check(arr);
                        if(result == 1){
                            for(int n = 0; n < 5; n++){
                                printf("%d ", arr[n]);
                            }
                            break;
                        }

                    }
                }
            }
        }
    }

    return 0;
}