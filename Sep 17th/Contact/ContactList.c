#include "Contact.h"

void InitContact(struct Contact * con){
    con->sz = 0; //default value is 0
    
    memset(con->data, 0, MAX * sizeof(struct PerInfo));
    //or
    //memset(con->data, 0, sizeof(con->data));
}