/*
reference: Some code snippets in A3 are referred to Lecture9-2021-10-06-Part2 
and tutorial A3 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<assert.h>

// global arrays and other variables
int arr[1600] = { 0 };           // input unsorted array
int subArrLeft[800] = { 0 };     // left sub-list
int subArrRight[800] = { 0 };    // right sub-list
int sortedArr[1600] = { 0 };     // sorted array
int arrSize = 0;                 // array size
int leftSize = 0;                // size of left sub-list
int rightSize = 0;              // size of right sub-list
int sortedSize = 0;


/* struct for passing the indices to threads */
typedef struct{
    int first_index;
    int last_index;
    int * arradd;
} parameters;

/*the thread that performs basic sorting algorithm
Use qsort() function from C library*/
void *sorter(void *params);
/*the thread performs merging of results*/
void *merger(void *params);

int main(int argc, char* argv[]) {
    // read from the file IntegerList.txt
    FILE *filePtr = fopen("IntegerList.txt", "r");
    char str[1500] = { 0 };
    fgets(str, 1500, filePtr);

    assert(filePtr);
    
    // strtok breaks str by ",", covert pch to integer
    char* pch = strtok(str, ",");
    // size of the array
    int arrSize = 0;            
    while (pch != NULL) {
        arr[arrSize++] = atoi(pch);
        pch = strtok(NULL, ",");
    }

    sortedSize = arrSize;

    fclose(filePtr); // close the file
    filePtr = NULL; 
    
    // declare 3 thread variables
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;

    /* create the first sorting thread */
    parameters *arr1= (parameters *) malloc(sizeof(parameters));
    assert(arr1);
    arr1->first_index= 0;
    arr1->last_index = arrSize / 2;
    arr1->arradd = subArrLeft;
    // split to get the left sub-list 
    for (leftSize = 0; leftSize < arrSize/2; leftSize++) {
        subArrLeft[leftSize] = arr[leftSize];
    }
    

    pthread_create(&thread1, NULL, sorter, arr1);

    /* create the second sorting thread */
    parameters *arr2 = (parameters *) malloc(sizeof(parameters));
    assert(arr2);
    arr2->first_index= arrSize / 2;
    arr2->last_index = arrSize;
    arr2->arradd = subArrRight;

    // get the right sub-list using memcpy() function
    // reference URL: https://www.cplusplus.com/reference/cstring/memcpy/?kw=memcpy
    // arr+arrSize/2 is the address of arr[] for splitting the right sub-array
    memcpy(subArrRight, arr + arrSize/2, sizeof(int) * (arrSize-leftSize)); 

    pthread_create(&thread2, NULL, sorter, arr2);
    
    /* now wait for the 2 sorting threads to finish */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    /*free memory*/
    free(arr1);
    free(arr2);
    arr1 = NULL;
    arr2 = NULL;

    /* create the merger thread in the descending order*/
    parameters *arr3 = (parameters *) malloc(sizeof(parameters));
    assert(arr3);
    arr3->first_index= 0;
    arr3->last_index = arrSize;
    pthread_create(&thread3, NULL, merger, arr3);

    /* wait for the merge thread to finish */
    pthread_join(thread3, NULL);

    /*free memory*/
    free(arr3);
    arr3 = NULL;

    /* output the sorted array
     * write merged array to the file SortedIntegerList.txt*/
    FILE *pFile = fopen("SortedIntegerList.txt", "w"); 
    assert(pFile);
    int i = 0;
    for (i = 0; i < arrSize - 1; i++) {
        fprintf(pFile, "%d,", sortedArr[i]); 
    }
    fprintf(pFile, "%d\n", sortedArr[i]); 
    
    fclose(pFile);
    pFile = NULL;
    
    return 0;
}

// helper method used in sorter(): compare two integers
int compare(const void *a, const void *b) {
        return ( *(int*)a - *(int*)b );
}

// use qsort() function in C library 
// reference URL: https://www.cplusplus.com/reference/cstdlib/qsort/
void *sorter(void *params) {
/* sorting algorithm implementation */
    parameters *parameters = params;
    assert(params && parameters);
    int first = parameters->first_index;
    int last = parameters->last_index;

    qsort(parameters->arradd, last - first, sizeof(int), compare);
    
    pthread_exit(0);
}

void *merger(void *params) {
    parameters *parameters = params;
    assert(params && parameters);

    /* merging algorithm implementation */
    int first = parameters->first_index;
    int last = parameters->last_index;

    arrSize = sortedSize;
    int leftIndex = leftSize;
    int rightIndex = arrSize-leftSize;

    //printf("%d %d %d %d\n", subArrLeft[0], subArrLeft[4], subArrRight[0], subArrRight[4]); 
    //printf("%d %d\n", leftIndex, rightIndex);


    // referred to geeksforgeeks    
    int i = 0; // keep track of left subarray index
    int j = 0; // keep track of right subarray index
    int k = 0; // keep track of sorted array index
    // traverse both sub array to compare the each value
    while (leftIndex > i && rightIndex > j) {
        
        if (subArrLeft[i] < subArrRight[j]) {
            sortedArr[k++] = subArrLeft[i++];
        }
        else {
            sortedArr[k++] = subArrRight[j++];
        }
    }

    // left sub-list still has integers.
    while (i < leftIndex) {
        sortedArr[k++] = subArrLeft[i++];
    }

    // right sub-list still has integers.
    while (j < rightIndex) {
        sortedArr[k++] = subArrRight[j++];
    }
       
    pthread_exit(0);
}

