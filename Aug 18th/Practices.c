#include <stdio.h>

int main()
{
  unsigned char a = 200;
  unsigned char b = 100;
  unsigned char c = 0;
  c = a + b;
  printf("%d %d", a+b,c);
  return 0;
}


//a + b is 300 as an int outut
//but for c, char is 1 byte so 
//300 in binary is
//300 -> 00000000 00000000 00000001 00101100
//since c can only take 00101100 -> 4 + 8 + 32 -> 44
//so resulat is 300 44
