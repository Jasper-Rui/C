#program once

#define NAME_MAX 20;
#define SEX_MAX 10;
#define TEL_MAX 20;
#define ADDRESS_MAX 30;

#define MAX 1000;
#include <stdio.h>
#include <string.h>

//MAX number of people
struct PerInfo
{
    char name[NAME_MAX];
    int age;
    char sex[SEX_MAX];
    int tel[TEL_MAX];
    char address[ADDRESS_MAX];
};

struct Contact
{
    struct Person data[MAX];
    int sz; // currnt active amount of people
};

void InitContact(struct Contact * con);


