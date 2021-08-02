#include <stdio.h>



int main(){
    
    int ch = 0;
    
    while((ch = getchar()) != EOF){
        if(ch >= 'a' && ch <= 'z' ||ch >= 'A' && ch <= 'Z'){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        getchar();
    }
    
    
    return 0;
}