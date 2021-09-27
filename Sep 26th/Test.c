#include <stdio.h>
#include <string.h>
#include <assert.h>

float Round(float input){
    //*100 for easy calculation
    //example: 20.05 -> 0.05 -> 5

    int result = input * 100; //20.05 -> 2005

    int remainder = result % 10; //2005 -> 5
    //case 1, round to 0
    if(remainder == 1 || remainder == 2){
        //2005 -> 2000
        //2005 - 5
        //result - remainder -> 2000
        //2000 / 100 -> 20
        //return float
        //(float) -> convert to float type
        return ((float)result - (float)remainder) / 100;
    }
    else if(remainder == 3 || remainder == 4 || remainder == 6 || remainder == 7){
        //2003 -> 2005
        //2003 - 3 + 5 -> 2005
        return ((float)result - (float)remainder + 5) / 100;
    }
    else if(remainder == 8 || remainder == 9){
        //20.08 -> 20.10
        //2008 - 8 + 10
        return ((float)result - (float)remainder + 10) / 100;
    }

    //0 or 5
    else{
        return input;
    }
}

int calculate(float input, float money){
    int count = 0;

    if(input >= money){
        while(input >= money){
            count++;
            input = input - money;
        }
    }
    return count;
}

void RefundMoney(float input){
    int count = 0;
    if(input >= 20){
        count = calculate(input, 20.00);
        printf("$20*%d ", count);
        input = input - count * 20.00;
    }

    if(input >= 10){
        count = calculate(input, 10.00);
        printf("$10*%d ", count);
        input = input - count * 10.00;
    }
    
    if(input >= 5.00){
        count = calculate(input, 5.00);
        printf("$5*%d ", count);
        input = input - count * 5.00;
    }
    
    if(input >= 2.00){
        count = calculate(input, 2.00);
        printf("$2*%d ", count);
        input = input - count * 2.00;
    }

    if(input >= 1.00){
        count = calculate(input, 1.00);
        printf("$1*%d ", count);
        input = input - count * 1.00;
    }

    if(input >= 0.25){
        count = calculate(input, 0.25);
        printf("25c*%d ", count);
        input = input - count * 0.25;
    }

    if(input >= 0.10){
        count = calculate(input, 0.10);
        printf("10c*%d ", count);
        input = input - count * 0.10;
    }

    if(input >= 0.05){
        count = calculate(input, 0.05);
        printf("5c*%d ", count);
        input = input - count * 0.05;
    }
    printf("\n");
}

float Test(float input1, float input2){

    //1st case, the purchase price equals to money offered by customer 
    //20.01 -> 20.00, 20.00
    if(input1 == input2){
        return 1;
    }

    //2nd case, money offered is not enough for the proce
    else if(input1 > input2){
        return 2;
    }

    //3rd case
    else{
        float refund = input2 - input1;
        RefundMoney(refund);
        return 0;
    }
}


int main () {
    //1 input type 'float'
    float input1, input2;  

    while(scanf("%f %f", &input1, &input2) != EOF){   // step 1 read input
        if(input1 == input2 && input1 == 0.00){
            return 0;
        }
        else{
            //step2 round the price
            input1 = (input1 * 100.0 + 1)/100.0;
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
