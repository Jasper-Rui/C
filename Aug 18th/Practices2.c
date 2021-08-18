int main()
{
  char a[1000] = {0};
  int i=0;
  for(i=0; i<1000; i++)
  {
    a[i] = -1-i;
  }
  printf("%d",strlen(a));
  return 0;
}

//here strlen(a) is 255
//a[i] start with -1 till -127, cuz -127 is the limit of char(-128, 127)
//char -> 1 byte -> 01111111 max -> 127
//char -> 1 byte -> 10000000 min -> -128


//one's a[i] = -128, the next will be -129, but since it's a char array, only have 8 bits, here arr[i] -> 1
//so -129 will become -> 00000000 -> 0, when it goes to 127, it will be allways larger than 127,
//so the rest will be 0, here 0 will be '0'
//so it will be 127 + 128 = 255

