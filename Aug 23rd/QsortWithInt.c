#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25, 33, 99, 102};

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main () {
   int n;

   int sz = sizeof(values) / sizeof(values[0]);
   printf("Before sorting the list is: \n");
   for( n = 0 ; n < sz; n++ ) {
      printf("%d ", values[n]);
   }

   qsort(values, sz, sizeof(int), cmpfunc);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < sz; n++ ) {   
      printf("%d ", values[n]);
   }
  
   return(0);
}