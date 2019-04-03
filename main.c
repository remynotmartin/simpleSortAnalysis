#include <stdio.h>
#include <string.h> // for memcpy()
#include <stdlib.h> // for srand()
#include <time.h>


// Utilities
void callSorts(int* originalData);
void printArray(int* intArray, unsigned const size);
void swap(int* A, int* B);

// Sorting Algorithms
unsigned bubbleSort(int* intArray, unsigned size);

const unsigned ARRAYSIZE = 10;

int main (void)
{
    srand(time(0)); // Seeds the PRNG

    // Initialize the array with data
    int myArray[ARRAYSIZE];
    for (unsigned i = 0u; i < ARRAYSIZE; i++)
        myArray[i] = rand() % 50;

    callSorts(myArray);
    
    return 0;
}

/************************************************
  Encapsulates calls to the sorts so that main
  remains relatively clean and short =)
************************************************/
void callSorts(int* originalData)
{    
    // Initialize a copy of the original data, to maintain data integrity.
    int copyA[ARRAYSIZE];
    memcpy(copyA, originalData, ARRAYSIZE * sizeof(int));

    unsigned swapCount = 0;

    printf("- ORIGINAL ARRAY -\n");
    printArray(originalData, ARRAYSIZE);
    putchar('\n');

    swapCount = bubbleSort(copyA, ARRAYSIZE);
    
    printf("- Bubble SORTED -\n");
    printArray(copyA, ARRAYSIZE);
    printf("Swaps performed: %u\n", swapCount);
    putchar('\n');
}

/************************************************
   Function takes integer array and its size.
   Applies a bubble sort, and prints out number
   of swaps applied to the data set.
************************************************/
unsigned bubbleSort(int* intArray, unsigned size)
{
    unsigned swapCount = 0;
    for (unsigned j = 0; j < size - 1; j++)
    {
        for (unsigned k = 0 ; k < size - (j + 1); k++)
        {
            if (intArray[k] > intArray[k + 1])
            {
                swap(&intArray[k], &intArray[k + 1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}

/******************************************************
   This function prints out an array in a single line.
******************************************************/
void printArray(int* intArray, unsigned const size)
{
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
