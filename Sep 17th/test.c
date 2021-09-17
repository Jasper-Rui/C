#include <stdio.h>
#include <stddef.h>


#pragma (8) // normally default value is (8)
struct s1
{
    char c1;
    int i1;
    char c2;
};
//12 byte
#pragma pack() //reset to default


#pragma (1) // if we set it to 1
struct s2
{
    char c1;//1 1 1
    int i1; //4 1 1
    char c2;//1 1 1
};
//12 byte -> 6 byte
#pragma pack() //reset to default

struct s3
{
    char c1;
    char c2;
    int i1;
};
//8 byte
//try to put char before int





int main () {
    printf("%d\n", sizeof(struct s1));
    printf("%d\n", sizeof(struct s2));
    printf("%u\n", offsetof(struct s1, c1));
    printf("%u\n", offsetof(struct s1, i1));
    printf("%u\n", offsetof(struct s1, c2));
    return 0;
}