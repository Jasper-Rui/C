#include <stdio.h>
#include <string.h>


struct Book
{
    char name[20];
    char author[20];
    int price;
}b1, b2;
//global variables

struct Book b3;
//global variable

struct
{
    int a;
    char c;
    double b;
}s1, s2;

struct
{
    int a;
    char c;
    double b;
}*p;

//even though both the anonymous struct have same declaration, but they are not same struct
//so p = &s1; is incorrect

//for linked list
struct Node
{
    int data;
    struct Node * next;   
};


//or
typedef struct Nodee {
    int data;
    struct Nodee * next;
}Nodee;

struct Point {
    int x;
    int y;
}p1 = {1,2}, p2 = {3,4};

struct Point p3 = {4,5};

//-------------------------

struct SS {
    double s;
    struct Point p1;
    char name[20];
    int arr[5];
};


int main (){

    struct Book b4; //local variable
    struct Point p4 = {7,5};
    //p = &s1; -> incorrect

    struct SS able = {3.1415, {1,2}, "Jasper name", {1,2,3,4,5}};

    printf("%lf\n", able.s);
    printf("%d\n", able.p1.x);
    printf("%d\n", able.p1.y);
    printf("%s\n", able.name);
    printf("%d\n", able.arr[0]);

    return 0;
}