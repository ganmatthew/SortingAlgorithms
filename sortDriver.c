#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 7
#define LIST_MIN 1
#define LIST_MAX 20

int Random (int floor, int ceiling, int cycles) { 
	int i, num;
	for (i = 0; i < cycles; i++) {
		num = (rand() % (ceiling - floor + 1)) + floor;
	}

	return num;
}

void GenerateData (int A[], int N) {
   int i;
   for (i = 0; i < N; i++) {
      A[i] = Random(LIST_MIN, LIST_MAX, i + 2);
   }
}

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

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

int main () {
   srand(time(NULL));
   int list[ARRAY_SIZE];

   GenerateData(list, ARRAY_SIZE);
   DisplayData(list, ARRAY_SIZE);

   BubbleSort(list, ARRAY_SIZE);
   //InsertionSort(list, ARRAY_SIZE);
   //SequentialnSort(list, ARRAY_SIZE);

   DisplayData(list, ARRAY_SIZE);
}