#include <stdio.h>
int main()
{
    int arr[] = {1,2,(3,4),5};
    printf("%d\n", sizeof(arr));
    //here result is 16, becasue in (3,4)
    //it's a Comma expression
    //and it will pick 4 as a result of (3,4)
    //so there are acutally 4 elements in arr 1 2 4 5
    return 0;
}