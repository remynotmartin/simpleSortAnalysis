#include <stdio.h>
#include <stdlib.h> // for srand()
#include <time.h>


// Utilities
void callSorts(int* originalData);
void swap(int** A, int** B);

// Sorting Algorithms
unsigned bubbleSort(int** intArray, unsigned size);

const unsigned ARRAYSIZE = 10;

int main (void)
{
    srand(time(0)); // Seeds the PRNG

    // Initialize the array with data
    int coreData[ARRAYSIZE];
    for (unsigned i = 0u; i < ARRAYSIZE; i++)
        coreData[i] = rand() % 50;

    callSorts(coreData);
    
    return 0;
}

/************************************************
  Encapsulates calls to the sorts so that main
  remains relatively clean and short =)
************************************************/
void callSorts(int* originalData)
{    
    void printCopyArray(int** intArrayCopy, unsigned const size);

    // Initialize a copy of the original data, 
    // to maintain its integrity.
    int* copyA[ARRAYSIZE];
    unsigned swapCount = 0;
    for (unsigned i = 0u; i < ARRAYSIZE; i++)
        copyA[i] = &originalData[i];


    printf("- ORIGINAL DATA-\n");
    printCopyArray(copyA, ARRAYSIZE);
    putchar('\n');

    swapCount = bubbleSort(copyA, ARRAYSIZE);
    
    printf("- Bubble SORTED -\n");
    printCopyArray(copyA, ARRAYSIZE);
    printf("Swaps performed: %u\n", swapCount);
    putchar('\n');
}

/******************************************************
  This function is designed to print an array of
  pointers to int, rather than a raw array of ints
  themselves. This is needed to print my copy arrays
  which get sorted.
******************************************************/
void printCopyArray(int** intArrayCopy, unsigned const size)
{
    for (unsigned i = 0u; i < size; i++)
        printf("%d ", **(intArrayCopy + i));
    putchar('\n');
}

/************************************************
   Function takes integer array and its size.
   Applies a bubble sort, and prints out number
   of swaps applied to the data set.
************************************************/
unsigned bubbleSort(int** intArray, unsigned size)
{
    unsigned swapCount = 0;
    for (unsigned j = 0; j < size - 1; j++)
    {
        for (unsigned k = 0 ; k < size - (j + 1); k++)
        {
            if (*(intArray[k]) > *(intArray[k + 1]))
            {
                swap(&intArray[k], &intArray[k + 1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}

/****************************************************
    This function is intended to be compatible with 
    various different sorts, not just a bubble sort.
****************************************************/
void swap(int** A, int** B)
{
    int* temp = *A;
    *A = *B;
    *B = temp;
}
