#include <stdio.h>


int main(){
    
    //continueous 3 input, all integer
    //read input and compare if they fit the requiements are triangle
    
    //a + b > c && a + c > b && b + c > a
    
    
    //situations
    //1 all 3 numbers are same -> Equilateral triangle
    //2 of 3 numbers are same ->  Isosceles triangle
    //a^2 + b^2 = c^2 -> Right triangle
    //others are -> normal triangle
    
    
    int a = 0;
    int b = 0;
    int c = 0;
    
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        if(a + b > c && a + c > b && b + c > a){
            if(a == b && b == c){
            printf("Equilateral triangle!\n");
            }
            else if(a == b || a == c || b == c){
                printf("Isosceles triangle!\n");
            }
            else if(a^2 + b^2 == c^2 || a^2 + c^2 == b^2 || b^2 + c^2 == a^2){
                printf("Right triangle\n");
            }
            else{
                printf("Ordinary triangle!\n");
            }
        }
        else{
            printf("Not a triangle!\n");
        }

    }
    
    
    
        
    return 0;
}