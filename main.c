#include <stdio.h>
#include <stdlib.h> // for srand()
#include <time.h>

void callSorts(int* originalData);
void swap(int** A, int** B);
void printCopyArray(int** intArrayCopy, unsigned const size);


const unsigned ARRAYSIZE = 20;

int main (void)
{
    srand(time(0)); // Seeds the PRNG

    // Populate the coreData
    int coreData[ARRAYSIZE];
    for (unsigned i = 0u; i < ARRAYSIZE; i++)
        coreData[i] = rand() % 200;

    callSorts(coreData);
    
    return 0;
}

/************************************************
  Encapsulates calls to the sorts so that main
  remains relatively clean and short =)
************************************************/
void callSorts(int* originalData)
{    
    // Sorting Algorithms
    void bubbleSort(int**     intArray,
                    unsigned  size, 
                    unsigned* swaps);

    void selectionSort(int**     intArray, 
                       unsigned  size,
                       unsigned* swaps);
    
    void insertionSort(int**     intArray, 
                       unsigned  size,
                       unsigned* swaps);

    // Initialize a copy of the original data, 
    // to maintain its integrity.
    int* copyArray[ARRAYSIZE];
    for (unsigned i = 0u; i < ARRAYSIZE; i++)
        copyArray[i] = &originalData[i];
    
    unsigned swapCount = 0;

    printf("- ORIGINAL DATA -\n");
    printCopyArray(copyArray, ARRAYSIZE);
    putchar('\n');
    
    printf("- BUBBLE SORT -\n");
    bubbleSort(copyArray, ARRAYSIZE, &swapCount);
    printCopyArray(copyArray, ARRAYSIZE);
    printf("Swaps performed: %u\n", swapCount);
    putchar('\n');
    
    // reset the copyArray and the swapCount;
    swapCount = 0;
    for (unsigned i = 0u; i < ARRAYSIZE; i++)
        copyArray[i] = &originalData[i];
    
    printf("- SELECTION SORT -\n");
    selectionSort(copyArray, ARRAYSIZE, &swapCount);
    printCopyArray(copyArray, ARRAYSIZE);
    printf("Swaps performed: %u\n", swapCount);
    putchar('\n');
    
    // reset the copyArray and the swapCount;
    swapCount = 0;
    for (unsigned i = 0u; i < ARRAYSIZE; i++)
        copyArray[i] = &originalData[i];
    
    printf("- INSERTION SORT -\n");
    insertionSort(copyArray, ARRAYSIZE, &swapCount);
    printCopyArray(copyArray, ARRAYSIZE);
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
   The classic n00b sort~
************************************************/
void bubbleSort(int** intArray, unsigned size, unsigned* swaps)
{
    unsigned swapCount = 0u;
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
    *swaps = swapCount;
}

/*************************************************
  This function builds the sorted list one
  element at a time, starting from the beginning.
*************************************************/
void selectionSort(int** intArray, unsigned size, unsigned* swaps)
{
    unsigned mindex,
             swapCount = 0u;
    for (unsigned j = 0; j < size - 1; j++)
    {
        mindex = j;
        for (unsigned k = j + 1; k < size; k++)
        {
            if (*(intArray[k]) < *(intArray[mindex]))
                mindex = k;
        }
        if (mindex != j)
        {
            swap(&intArray[j], &intArray[mindex]);
            swapCount++;
        }
    }
    *swaps = swapCount;
}

/****************************************************
  Looks like this insertion sort will require more
  swaps, by virtue of all the shifting that has to
  occur. 
****************************************************/
void insertionSort(int** intArray, unsigned size, unsigned* swaps)
{
    unsigned swapCount = 0u;
    int* key; 
    for (unsigned i = 1; i < size; i++)
    {
        key = intArray[i];
        int j = i - 1;
        while (j >= 0 && *(intArray[j]) > *key)
        {
            swap(&intArray[j + 1], &intArray[j]);
            swapCount++;
            j--;
        }
        intArray[j + 1] = key;
    }
    *swaps = swapCount;
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
