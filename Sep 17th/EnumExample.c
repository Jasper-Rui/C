#include <stdio.h>

enum Color
{
    Red = 5,
    Green = 8,
    Blue = 9
};




int main () {

    printf("%d\n", Red);
    printf("%d\n", Green);
    printf("%d\n", Blue);

    enum Color c = Green;
    if(c == Green){
        printf("Green\n");
    }

    return 0;
}