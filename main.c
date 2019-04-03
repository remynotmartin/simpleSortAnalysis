#include <stdio.h>
#include <time.h>

void bubbleSort(int* intArray, unsigned const size);
void printArray(int* intArray, unsigned const size);
void swap(int* A, int* B);

#define ARRAYSIZE = 15

int main (void)
{
    srand(time(0)); // Seeds the PRNG
    return 0;
}

/************************************************
   Function takes integer array and its size.
   Applies a bubble sort, and prints out number
   of swaps applied to the data set.
************************************************/
void bubbleSort(int* intArray, unsigned const size)
{
    unsigned swapCount = 0;
    for (
}

/******************************************************
   This function prints out an array in a single line.
******************************************************/
void printArray(int* intArray, unsigned const size)
{
    printf("Array: ");
    for (unsigned i = 0u; i < size; i++)
        printf("%d ", intArray[i]);
    putchar('\n');
}

/****************************************************
    This function is intended to be compatible with 
    various different sorts, not just a bubble sort.
****************************************************/
void swap(int* A, int* B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}
