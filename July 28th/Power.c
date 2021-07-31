#include <stdio.h>
#include <assert.h>


double Pow(int n, int k){

    if(k > 0){
        return n * Pow(n, k-1);
    }
    else if(k == 0){
        return 1.0;
    }
    else{
        return 1.0/Pow(n, -k);
    }

}


int main(){
    int n = 2;
    int k1 = 3;
    int k2 = -3;
    int k3 = 0;

    printf("Result is :  %lf\n", Pow(n, k1));
    printf("Result is :  %lf\n", Pow(n, k2));
    printf("Result is :  %lf\n", Pow(n, k3));
 
    return 0;
}