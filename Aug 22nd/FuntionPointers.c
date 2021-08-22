#include <stdio.h>

int add(int a, int b){
    return a + b;
}


int main(){
    printf("%p \n", &add); //here we get the address of function add
    printf("%p \n", add);
    //they are totally same here

    //Q: how we store the address for function?

    int (*padd)(int, int) = &add;


    //similar idea with
    int arr[10];
    int (*parr)[10] = &arr;

    //more examples
    int a; //type is int
    int arrrrr[10]; //type is int [10]
    int (*parrrrr)[10]; //type is int(*)[10]
    int (*paddd)(int, int); //type is int (*)(int, int)

    //normally
    int ret = add(2,3);
    printf("%d \n", ret);
    //or
    ret = (*padd)(3,5);
    printf("%d \n", ret);

    //or

    int (*pf)(int, int) = add;
    int ret1 = (*pf)(3,66);
    //or
    int ret2 = pf(3, 77);
    printf("%d\n", ret1);
    printf("%d\n", ret2);

    //two interesting method

    (*(void (*)())0)();
    //( void (*) () ); is an void type function 
    //it's original can be written as void (*func) ()
    //then we force 0 to convert to the address for the same type of func as void (*) () 
    //then *(void (*)()) 0 is to call the function store at 0 (  is an address here), the func is none para and it's a void fumc
    

    //void (*signal(int, void(*)(int)))(int);

    //function name is signal
    //there are 2 variables
    //one is int, one is from void(*)(int)
    

    //return type is void(*)(int)


    //summary
    //for a function
    //3 params
    //1 function name
    //2 function input variables
    //3 function return type







    return 0;
}