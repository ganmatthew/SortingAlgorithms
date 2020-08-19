#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define LIST_MIN 1
#define LIST_MAX 10

// Random Number Generator
// Based on https://www.geeksforgeeks.org/generating-random-number-range-c/
int Random (int floor, int ceiling, int cycles) { 
	int i, num;
	for (i = 0; i < cycles; i++) {
		num = (rand() % (ceiling - floor + 1)) + floor;
	}

	return num;
}

// Generates an array of numbers given the defined limits
void GenerateData (int A[], int N) {
   int i;
   for (i = 0; i < N; i++) {
      A[i] = Random(LIST_MIN, LIST_MAX, 1);
   }
}

// Displays the array
void DisplayData (int A[], int N) {
   int i;
   printf("\n---\n");
   for (i = 0; i < N; i++) {
      printf("%d\n", A[i]);
   }
   printf("---\n");
}

void count (int counter) {
   printf("counter: %d\n", counter);
}

// Main driver code
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "RadixSort.h"

int main () {
   srand(time(NULL));
   int list[ARRAY_SIZE];

   GenerateData(list, ARRAY_SIZE);
   DisplayData(list, ARRAY_SIZE);

   //BubbleSort(list, ARRAY_SIZE);
   //InsertionSort(list, ARRAY_SIZE);
   //SelectionSort(list, ARRAY_SIZE);
   QuickSort(list, ARRAY_SIZE);
   //MergeSort(list, ARRAY_SIZE);
   //RadixSort(list, ARRAY_SIZE);

   DisplayData(list, ARRAY_SIZE);
}