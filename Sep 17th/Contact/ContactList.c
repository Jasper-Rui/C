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
    printf("%15s\t%5s\t%8s\t%15s\t%30s\n\n", "Name", "Age", "Sex", "Phone", "Address");
    for(int i = 0; i < pc->sz; i++){
        printf("%15s\t%5d\t%15s\t%15s\t%30s\n", pc -> data[i].name,
                pc -> data[i].age, pc -> data[i].sex, pc -> data[i].tel, pc -> data[i].address);
    }
}

int FindContactByName(struct Contact * pc, char name[]){
    int i = 0;
    for(i = 0; i < pc->sz; i++){
        if(strcmp(pc->data[i].name, name) == 0){
            return i;
        }
    }
    //the name does not exist
    return -1;
}





void DelContact(struct Contact * pc){
    if(pc -> sz == 0){
        printf("Contact list is empyt, cann't delete\n");
        return;
    }
    //1 get the target
    char name[NAME_MAX] = {0};
    printf("Please enter the name you want delete: ");
    scanf("%s", name);

    //2 find the target
    int pos = FindContactByName(pc, name);
    if(pos == -1){
        printf("The name is not exist on the contact list.\n");
    }
    else{
        //delete
        int i = 0;
        for(i = pos; i < pc->sz - 1; i++){
            pc->data[i] = pc->data[i + 1];
        }
        pc->sz--; 
        printf("Successfully deleted!\n");
    }

}




void SearchContact(const struct Contact * pc){
    char name[NAME_MAX];
    printf("Please enter a name to serach: ");
    scanf("%s", name);
    int pos = FindContactByName(pc, name);
    if(pos == -1){
        printf("The name is not exist on the contact list.\n");
    }
    else{
        printf("%15s\t%5s\t%8s\t%15s\t%30s\n\n", "Name", "Age", "Sex", "Phone", "Address");
        printf("%15s\t%5d\t%15s\t%15s\t%30s\n", pc -> data[pos].name,
                pc -> data[pos].age, pc -> data[pos].sex, pc -> data[pos].tel, pc -> data[pos].address);
    }
}

