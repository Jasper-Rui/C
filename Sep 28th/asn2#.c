#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

double Round(double input) {
    //case 1, round to 0
    double remainder = fmod(input, 1.00);
    //get the decimal part of the input
    //then round up or round down to get new cost of purchase 
    if (remainder > 0.00 && remainder < 0.03) {
        return input - remainder;
    }
    else if ((remainder >= 0.03 && remainder < 0.05) || (remainder > 0.05 && remainder < 0.08)) {
        return input - remainder + 0.05;
    }
    else if (remainder == 0.08 || remainder == 0.09) {
        return input - remainder + 0.10;
    }
    else {
        return input;
    }
}

int calculate(double input, double money) {
    int count = 0;

    if (input >= money) {
        while (input >= money) {
            count++;
            input = input - money;
        }
    }
    return count;
}
//set the fuction calculate to calculate the number of each kind of money

void RefundMoney(double input) {
    int count = 0;
    if (input >= 20) {
        count = calculate(input, 20.00);
        printf("$20*%d ", count);
        input = input - count * 20.00;
    }

    if (input >= 10) {
        count = calculate(input, 10.00);
        printf("$10*%d ", count);
        input = input - count * 10.00;
    }

    if (input >= 5.00) {
        count = calculate(input, 5.00);
        printf("$5*%d ", count);
        input = input - count * 5.00;
    }

    if (input >= 2.00) {
        count = calculate(input, 2.00);
        printf("$2*%d ", count);
        input = input - count * 2.00;
    }

    if (input >= 1.00) {
        count = calculate(input, 1.00);
        printf("$1*%d ", count);
        input = input - count * 1.00;
    }

    if (input >= 0.25) {
        count = calculate(input, 0.25);
        printf("25c*%d ", count);
        input = input - count * 0.25;
    }

    if (input >= 0.10) {
        count = calculate(input, 0.10);
        printf("10c*%d ", count);
        input = input - count * 0.10;
    }

    if (input >= 0.05) {
        count = calculate(input, 0.05);
        printf("5c*%d ", count);
        input = input - count * 0.05;
    }
    printf("\n");
}

double Test(double input1, double input2) {

    //1st case, the purchase price equals to money offered by customer 
    //20.01 -> 20.00, 20.00
    if (input1 == input2) {
        return 1;
    }

    //2nd case, money offered is not enough for the price
    else if (input1 > input2) {
        return 2;
    }

    //3rd case,Refundmoney
    else {
        double refund = input2 - input1;
        RefundMoney(refund);
        return 0;
    }
}


int main() {
    //1 input type 'float'
    double input1, input2;

    while (scanf("%lf %lf", &input1, &input2) != EOF) {   // step 1 read input
        if (input1 == input2 && input1 == 0.00) {
            return 0;
        }
        else {
            //step2 round the price
            input1 = Round(input1);
            double result = Test(input1, input2);
            result = (int)result;
            if (result == 1) {
                printf("Exact amount.\n");
            }
            else if (result == 2) {
                printf("Not enough money offered.\n");
            }
            else if (result == 3) {
                printf("Error\n");
            }
        }
    }
    return 0;
}
