#include <stdio.h>
#include <math.h>

int test(int input) {
    int tmp = input;
    double sum = 0.0;
    int arr[10] = { 0 };
    int n = 0;
    while (input) {
        int reminder = input % 10;
        arr[n] = reminder;
        input /= 10;
        n++;
    }
    //now we put every number into an array and we know how many numbers are there
    for (int i = 0; i < n ; i++) {
        sum += pow(arr[i], n);
    }
    return sum;
}


int main() {

    //brute force
    int i = 10000;
    while (i) {
        int result = test(i);
        if (i == result) {
            printf("%d ", i);
        }
        i--;
    }

    return 0;
}