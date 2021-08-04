#include <stdio.h>

int fun(){
    static int count = 1;
    return ++count;
}



int main() {

    int a = 1;
    int d = (++a) + (++a) + (++a);
    printf("%d \n", d);
    //here my compiler resulting in 10 but different compilers will be different

    printf("\n");

    int answer;
    answer = fun() - fun()*fun();
    printf("%d \n", answer);
    //is that -10?
    //but actually the result is not matters, this code is non-usable and do not use it for work

    printf("\n");
    return 0;
}
