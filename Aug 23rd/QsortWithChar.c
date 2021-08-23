#include <stdio.h>
#include <stdlib.h>

char ch[] = {"afsagafasdadasdads"};

int cmpfunc (const void * a, const void * b) {
   return ( *(char*)a - *(char*)b );
}

int main () {
   int n;

   int sz = sizeof(ch) / sizeof(ch[0]);
   printf("Before sorting the list is: \n");
   for( n = 0 ; n < sz; n++ ) {
      printf("%c ", ch[n]);
   }

   qsort(ch, sz, sizeof(char), cmpfunc);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < sz; n++ ) {   
      printf("%c ", ch[n]);
   }
  
   return(0);
}