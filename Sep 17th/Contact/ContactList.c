#include "Contact.h"

void InitContact(struct Contact * con){
    con->sz = 0; //default value is 0
    
    memset(con->data, 0, MAX * sizeof(struct PerInfo));
    //or
    //memset(con->data, 0, sizeof(con->data));
}

void AddContact(struct Contact * pc){
    if(pc -> sz == MAX){
        printf("Contact is full now.\n");
    }
    else{
        printf("Print enter a name: ");
        scanf("%s", pc -> data[pc -> sz].name);
        printf("Print enter the age: ");
        scanf("%d", &(pc -> data[pc -> sz].age)); 
        printf("Print enter the gender: ");
        scanf("%s", pc -> data[pc -> sz].sex);
        printf("Print enter the telephone number: ");
        scanf("%d", pc -> data[pc -> sz].tel);
        printf("Print enter the address: ");
        scanf("%s", pc -> data[pc -> sz].address);
        printf("Successfully added\n");
        pc->sz++;
    }
}


void ShowContact(struct Contact * pc){
    printf("%15s\t %5s\t %15s\t %15s\t %15s\n ", "Name", "Age", "Sex", "Phone", "Address");
    for(int i = 0; i < pc->sz; i++){
        printf("%15s\t %5d\t %15s\t %15s\t %30s\n ", pc -> data[i].name,
                pc -> data[i].age, pc -> data[i].sex, pc -> data[i].tel, pc -> data[i].address);
    }
}
