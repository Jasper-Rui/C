#include <stdio.h>

int main()
{
    int a = 1;
    int b = 4;
    int c = (b = 5);
    printf("%d\n", c); // 5
    printf("%d\n", b); // 5
    //output here is 5 becuase b is 5 and the ( b = 5 ) is 5 so c = 5
    
    
    int ch = 0;
    //ch = getchar();
    //its similar to sacnf
    //scnaf("%c",ch);
    
    //putchar(ch);
    //its similar to printf
    //printf("%c", ch);
    
    
    //EOF == end of file
    // printf only numbers bewteen 0 to 9
    while( (ch = getchar()) != EOF ){
        if( ch < '0' || ch > '9'){
            continue;
        }
        putchar(ch);
    }

}