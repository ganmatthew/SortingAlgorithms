#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <randomgenerator.c>

#define ARRAY_SIZE 1024
#define LIST_MIN 1
#define LIST_MAX 10


// Displays the array
void DisplayData (int A[], int N) {
   int i;
   printf("\n---\n");
   for (i = 0; i < N; i++) {
      printf("%d\n", A[i]);
   }
   printf("---\n");
}

void ManualInputData (int A[], int N) {
   int i;
   for (i = 0; i < N; i++) {
      printf("Enter item %d for a list of size %d: ", i + 1, N);
      scanf("%d", &A[i]);
   }
}

void count (int counter) {
   printf("counter: %d\n", counter);
}

// Main driver code
#include "BubbleSort.c"
#include "InsertionSort.c"
#include "SelectionSort.c"
#include "QuickSort.c"
#include "MergeSort.c"
#include "RadixSort.c"

int main () {
   srand((unsigned) time(0)); // get seed from current time
   int list[ARRAY_SIZE];

   GenerateData(list, ARRAY_SIZE);
   //ManualInputData(list, ARRAY_SIZE);
   DisplayData(list, ARRAY_SIZE);

   //BubbleSort(list, ARRAY_SIZE);
   InsertionSort(list, ARRAY_SIZE);
   //SelectionSort(list, ARRAY_SIZE);
   //QuickSort(list, ARRAY_SIZE);
   //MergeSort(list, ARRAY_SIZE);
   //RadixSort(list, ARRAY_SIZE);

   DisplayData(list, ARRAY_SIZE);
}