// Sorting Algorithms Test Driver File
// John Matthew Gan, Angelo Remudaro

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "randomgenerator.c" // random number generator

#define N_MIN 1024   // log base 2 (32768) = 10
#define N_MAX 32768  // log base 2 (32768) = 15
#define M_MAX 10     // number of cycles per N run

// Contains the execution time and frequency count of each M run
typedef struct sortresult { 
   double time;      // machine execution time
   int count;        // frequncy count
} sortResult;

// Contains the all testing data of each N run
typedef struct dataset {
   int N;            // value of N
   sortResult b[M_MAX]; // bubble sort
   sortResult i[M_MAX]; // insertion sort
   sortResult m[M_MAX]; // merge sort
   sortResult q[M_MAX]; // quick sort
   sortResult r[M_MAX]; // radix sort
   sortResult s[M_MAX]; // selection sort
} dataSet;

// Diagnostics for displaying the array
void DisplayData (int A[], int N) {
   int i;
   printf("\n---\n");
   for (i = 0; i < N; i++) {
      printf("%d", A[i]);
      if (i != N - 1)
         printf(", ");
   }
   printf("---\n");
}

// Duplicates the data of one array to another of same size
void DuplicateData (int D[], int S[], int N) {
   int i, temp[N];
   for (i = 0; i < N; i++) {
      temp[i] = S[i];
   }

   for (i = 0; i < N; i++) {
      D[i] = temp[i];
   }
}

// Diagnostics for manually inputting data
void ManualInputData (int A[], int N) {
   int i;
   for (i = 0; i < N; i++) {
      printf("Enter item %d for a list of size %d: ", i + 1, N);
      scanf("%d", &A[i]);
   }
}

// Retrieves data from sortResult and places the average of its contents into an array
void getAverageData (float A[][2], int index, sortResult * loc) {
   int i, t;
   char algorithm[15];

   for (t = 0; t < 2; t++) {
      float sum = 0;
      for (i = 0; i < M_MAX; i++) {
         switch (t) {
            case 0:
               sum += loc[i].count;
               break;
            case 1:
               sum += loc[i].time;
               break;
         }
      }
      A[index][t] = sum / M_MAX;
   } 

   switch(index) {
      case 0:
         strcpy(algorithm, "Bubble Sort");
         break;
      case 1:
         strcpy(algorithm, "Insertion Sort");
         break;
      case 2:
         strcpy(algorithm, "Merge Sort");
         break;
      case 3:
         strcpy(algorithm, "Quick Sort");
         break;
      case 4:
         strcpy(algorithm, "Radix Sort");
         break;
      case 5:
         strcpy(algorithm, "Selection Sort");
         break;
   }
   
   printf("[getAverageData] %-12s\t%-8s%10.0f, time = %f\n", algorithm, "count = ", A[index][0], A[index][1]);
}

// Returns a letter corresponding to a sorting algorithm (for text file display purposes)
char getLetterFromSortIndex (int index) {
   switch (index) {
      case 0:
         return 'b';
         break;
      case 1:
         return 'i';
         break;
      case 2:
         return 'm';
         break;
      case 3:
         return 'q';
         break;
      case 4:
         return 'r';
         break;
      case 5:
         return 's';
         break;
      default:
         return '0';
         break;
   }
}

// Saves the data of each run into a text file
void recordData (dataSet * data, int N) {
   int i;
   float average[6][2];
   FILE *destFile;

   printf("\n");
   getAverageData(average, 0, data -> b);
   getAverageData(average, 1, data -> i);
   getAverageData(average, 2, data -> m);
   getAverageData(average, 3, data -> q);
   getAverageData(average, 4, data -> r);
   getAverageData(average, 5, data -> s);

   if ( (destFile = fopen("output.txt", "a+")) ) {
      for (i = 0; i < 6; i++) {
         fprintf(destFile, "%5d %c ", data -> N, getLetterFromSortIndex(i));      // write N and type to file
         fprintf(destFile, "%13.0f %f\n", average[i][0], average[i][1]);         // write count and time to file
      }
   }
   else {
      destFile = fopen("output.txt", "r");
   }
   
   fclose(destFile);
}

// References the sorting algorithms
#include "BubbleSort.c"
#include "InsertionSort.c"
#include "SelectionSort.c"
#include "QuickSort.c"
#include "MergeSort.c"
#include "RadixSort.c"

// Main driver
int main () {
   srand((unsigned) time(0)); // get seed from current time

   int M, N;
   for (N = N_MIN; N <= N_MAX; N *= 2) { // increments N by N^2
      printf("\n[main] N is %d of %d\n", N, N_MAX);
      dataSet recordedData;
      recordedData.N = N;

      int unsortedList[N];
      //ManualInputData(numberList, N);
      GenerateData(unsortedList, N);

      for (M = 0; M < M_MAX; M++) {
         printf("\n[main] M is index %d of %d\n", M, M_MAX);
         BubbleSort(unsortedList, &recordedData.b[M], N);
         InsertionSort(unsortedList, &recordedData.i[M], N);
         MergeSort(unsortedList, &recordedData.m[M], N);
         QuickSort(unsortedList, &recordedData.q[M], N);
         RadixSort(unsortedList, &recordedData.r[M], N);
         SelectionSort(unsortedList, &recordedData.s[M], N);

         if (M == M_MAX - 1) {
            recordData(&recordedData, N); // saves the data at the end of each N run
         }

      }  
   }

   printf("\n[main] End of program!\n");
}