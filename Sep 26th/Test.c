#include <stdio.h>
#include <string.h>
#include <assert.h>

float Round(float input){
    int result = input * 100;
    int remainder = result % 10;
    //case 1, round to 0
    if(remainder == 1 || remainder == 2){
        return ((float)result - (float)remainder) / 100;
    }
    else if(remainder == 3 || remainder == 4 || remainder == 6 || remainder == 7){
        return ((float)result - (float)remainder + 5) / 100;
    }
    else if(remainder == 8 || remainder == 9){
        return ((float)result - (float)remainder + 10) / 100;
    }
    else{
        return input;
    }
}


void RefundMoney(float input){
    int count = 0;
    if(input >= 20.00){
        while(input >= 20.00){
            count++;
            input = input - 20.00;
        }
        printf("$20*%d ", count);
    }

    if(input >= 10.00){
        count = 0;
        while(input >= 10.00){
            count++;
            input = input - 10.00;
        }
        printf("$10*%d ", count);
    }

    if(input >= 5.00){
        count = 0;
        while(input >= 5.00){
            count++;
            input = input - 5.00;
        }
        printf("$5*%d ", count);
    }

    if(input >= 2.00){
        count = 0;
        while(input >= 2.00){
            count++;
            input = input - 2.00;
        }
        printf("$2*%d ", count);
    }

    if(input >= 1.00){
        count = 0;
        while(input >= 1.00){
            count++;
            input = input - 1.00;
        }
        printf("$1*%d ", count);
    }

    if(input >= 0.25){
        count = 0;
        while(input >= 0.25){
            count++;
            input = input - 0.25;
        }
        printf("25c*%d ", count);
    }

    if(input >= 0.10){
        count = 0;
        while(input >= 0.10){
            count++;
            input = input - 0.10;
        }
        printf("10c*%d ", count);
    }

    if(input >= 0.05){
        count = 0;
        while(input >= 0.05){
            count++;
            input = input - 0.05;
        }
        printf("5c*%d ", count);
    }
    printf("\n");
}

float Test(float input1, float input2){

    float a = input1 - (int)input1;
    float b = input2 - (int)input2;

    //1st case, the purchase price equals to money offered by customer 
    if((input1 - (int)input1) == (input2 - (int)input2) && (input1 == input2)){
        return 1;
    }
    //2nd case, money offered is not enough for the proce
    else if(input1 > input2){
        return 2;
    }
    else{
        float refund = input2 - input1;
        RefundMoney(refund);
        return 0;
    }
}


int main () {
    float input1, input2;

    
    while(scanf("%f %f", &input1, &input2) != EOF){   // step 1 read input
        if(input1 == input2 && input1 == 0.00){
            return 0;
        }
        else{
            //step2 round the price
            input1 = Round(input1);
            int result = Test(input1, input2);
            if(result == 1){
                printf("Exact amount.\n");
            }
            else if(result == 2){
                printf("Not enough money offered.\n");
            }
            else if(result == 3){
                printf("Error\n");
            }
        }
    }
    return 0;
}