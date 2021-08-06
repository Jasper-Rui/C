#include <stdio.h>

struct Book {

    char name[20];
    char author[20];
    float price;

}b1, b2;

struct point{
    int x;
    int y;
}p1, p2;

//or

struct  point p3;

//here b1 b2 or p1 p2 are global variables

typedef struct Student{
    char name[20];
    int age;
    char id[20];

}Student;
//here we rename the whole struct into Student

//here Student is a type, but the p1, p2 are variables


//struct in struct

struct S{
    int a;
    char c;
    double b;
};

struct T{
    struct S s;
    char name[20];
    int num;
};

//to build a house
//blueprint -> house
//struct declaration -> struct variables

struct P{
    int arr[100];
    int num;
    char ch;
    double b;
};

void print1(struct P p){
    printf("%d %d %d %d %c %lf \n", p.arr[0], p.arr[1], p.arr[2], p.num, p.ch, p.b);
}

void print2(struct P* p){
    printf("%d %d %d %d %c %lf \n", p->arr[0], p->arr[1], p->arr[2], p->num, p->ch, p->b);
}

int main() {
    struct Book b; //local variables, stack
    struct Book bb = {"C programming", "Jasper Rui", 25.0000};
    struct Student s1 = {"Jasper", 23, "2020203"};
    //or
    Student s2;
    //both will work
    printf("\n");

    struct T t = {{100, 'c', 3.14}, "list", 30};

    printf("\n");


    struct T tt = { {100, 'w', 3.14}, "Haorui", 200};
    printf("%d %c %f %s %d \n", tt.s.a, tt.s.c, tt.s.b, tt.name, tt.num);

    struct T* pt = &tt;

    printf("%d %c %f %s %d \n", pt->s.a, pt->s.c, pt->s.b, pt->name, pt->num);
    //or
    printf("%d %c %f %s %d \n", (*pt).s.a, (*pt).s.c, (*pt).s.b, (*pt).name, (*pt).num);

    printf("\n");

    struct P p = { {1,2,3,4,5}, 100, 'w', 3.14};
    //here we already have a block for p
    //but when we pass the p to print1(p)
    //print1(p) has to create a new block for the same memory for p
    //so that will be a waste of memory
    print1(p);


    //so we have print2

    print2(&p); // here we only pass 4 byte && the address of the struct
    //we pass the pointer to print2
    //this is better that print1(p)
    return 0;
}
