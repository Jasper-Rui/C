#include <stdio.h>
int main()
{
    char str[] = "hello bit";
    printf("%d %d\n", sizeof(str), strlen(str));
    //sizeof str is 10 since there is \0 as the last element in str
    //strlen(str) is 9
	return 0;
}