#include <stdio.h>

int main()
{
  int aa[2][5] = {10,9,8,7,6,5,4,3,2,1};
  //here is a 2d array
  int *ptr1 = (int *)(&aa + 1);
  //(&aa + 1) -> aa[1]
  int *ptr2 = (int *)(*(aa + 1)); //
  printf( "%d,%d", *(ptr1 - 1), *(ptr2 - 1));
  //*(ptr1 - 1), ptr1 is the address of the end of array, by -1, it go backs to the last elemet of array -> 1
  //*(ptr2 - 1), is the end of 1st row, by -1, it go backs to the last element of 1st row which is 6
  return 0;
}
//result is 1 6