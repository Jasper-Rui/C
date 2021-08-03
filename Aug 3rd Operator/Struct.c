#include <stdio.h>
#include <string.h>

struct Book{
    char name[20];
    float price;
    char id[10];

};

void Print(struct Book b){
    printf("Name: %s\n", b.name);
    printf("Price: %f\n", b.price);
    printf("ID: %s\n", b.id);
}


void Print2(struct Book *pb){
    printf("Name: %s\n", pb->name);// (*pb).name is also working
    printf("Price: %f\n", pb->price);
    printf("ID: %s\n", pb->id);


    //here pb is the pointer of the struct
    //what -> aim for is the variable of the struct

}



int main() {


    struct Book b = {"C language", 55.5f, "C20190201"};
    Print(b);
    printf("\n");
    //strcpy

    b.price = 100.0f;

    Print(b);
    printf("\n");


    strcpy(b.name, "Data Structure");
    Print(b);
    printf("\n");


    Print2(&b);

    return 0;
}
