#include <stdio.h>

struct Student{
    char name[20];
    int age;
    char sex[5];
    char id[12];
};

struct Book{
    char name[20];
    int price;
    char author[20];
};



int main() {


    printf("Part1:\n");
    //lec4 note
    //pointer
    int a = 10;
    int* copya = &a;
    printf("%d\n%d\n%p\n",a, copya, &copya);

    *copya = 20;
    printf("%d\n%d\n%p",a, copya, &copya);

    printf("%d\n", sizeof(int*));
    printf("%d\n", sizeof(char*));
    printf("%d\n", sizeof(short*));
    printf("%d\n", sizeof(long*));
    printf("%d\n", sizeof(float*));
    printf("%d\n", sizeof(double*));

    printf("Part2:\n");
    struct Student s1 = { "Jasper", 20, "male", "12345678"};

    struct Book b1 = {"Name of the book", 99, "Donot know yet"};

    printf("Name: %s Age: %d Sex: %s Id: %s\n", s1.name, s1.age, s1.sex, s1.id);
    printf("%s %d %s\n", b1.name, b1.price, b1.author);

    struct Book * copyb = &b1;
    printf("%s %d %s\n", (*copyb).name, (*copyb).price, (*copyb).author);
    printf("%s %d %s\n", copyb->name, copyb->price, copyb->author);

    return 0;
}
