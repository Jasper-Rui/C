#include <stdio.h>



struct s1
{
    /* data */
    int data[1000];
    int num;
};


void print1(struct s1 s){
    int i = 0;
    for(i = 0; i < s.num; i++){
        printf("%d ", s.data[i]);
    }

    printf("\nnum = %d\n", s.num);
}

void print2(const struct s1* s){
    int i = 0;
    for(i = 0; i < 10; i++){
        printf("%d ", s->data[i]);
    }

    printf("\nnum = %d\n", s->num);
}
//print2 is better, it will reduce the space complexity
int main () {

    struct s1 s = {{1,2,3,4,5,6,7,8,9,10}, 10};
    print1(s);

    print2(&s);


    return 0;
}