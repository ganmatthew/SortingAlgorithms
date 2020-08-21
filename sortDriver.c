#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "randomgenerator.c"

#define INT_MAX 2147483647

typedef struct sortresult { 
   int time;   // machine execution time
   int count;  // frequncy count
} sortResult;

typedef struct dataset {
   int N;            // value of N
   sortResult b[10]; // bubble sort
   sortResult i[10]; // insertion sort
   sortResult m[10]; // merge sort
   sortResult q[10]; // quick sort
   sortResult r[10]; // radix sort
   sortResult s[10]; // selection sort
} dataSet;

// Diagnostics for displaying the array
void DisplayData (int A[], int N) {
   int i;
   printf("\n---\n");
   for (i = 0; i < N; i++) {
      printf("%d\n", A[i]);
   }
   printf("---\n");
}

// Diagnostics for manually inputting data
void ManualInputData (int A[], int N) {
   int i;
   for (i = 0; i < N; i++) {
      printf("Enter item %d for a list of size %d: ", i + 1, N);
      scanf("%d", &A[i]);
   }
}

void getAverageData (float A[][2], int index, sortResult * loc) {
   int i, t;

   for (t = 0; t < 2; t++) {
      float sum = 0;
      for (i = 0; i < 10; i++) {
         switch (t) {
            case 0:
               sum += loc[i].count;
               break;
            case 1:
               sum += loc[i].time;
               break;
         }
      }
      A[index][t] = sum / 10;
   } 

   printf("[getAverageData] count = %f, time = %f\n", A[index][0], A[index][1]);
}

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

void recordData (dataSet * data, int N) {
   int i;
   float average[6][2];
   FILE *destFile;

   getAverageData(average, 0, data -> b);
   getAverageData(average, 1, data -> i);
   //getAverageData(average, 2, data -> m);
   //getAverageData(average, 3, data -> q);
   //getAverageData(average, 4, data -> r);
   getAverageData(average, 5, data -> s);

   if ( (destFile = fopen("output.txt", "a")) ) {
      for (i = 0; i < 6; i++) {
         fprintf(destFile, "%d %c ", data -> N, getLetterFromSortIndex(i));    // write N and type to file
         getLetterFromSortIndex(i);
         fprintf(destFile, "%0.2f %f\n", average[i][0], average[i][1]);  // write count and time to file
      }
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
   for (N = 2; N < INT_MAX; N *= 2) { // increments N by N^2
      printf("\n[main] N is %d of %d\n", N, INT_MAX);
      dataSet recordedData;
      recordedData.N = N;

      int numberList[N];
      //ManualInputData(numberList, N);
      GenerateData(numberList, N);

      for (M = 0; M < 10; M++) {
         printf("\n[main] M is %d of %d\n", M, 10);
         BubbleSort(numberList, &recordedData.b[M], N);
         InsertionSort(numberList, &recordedData.i[M], N);
         //MergeSort(numberList, &recordedData.m[M], N);
         //QuickSort(numberList, &recordedData.q[M], N);
         //RadixSort(numberList, &ecordedData.r[M], N);
         SelectionSort(numberList, &recordedData.s[M], N);

         recordData(&recordedData, N);
      }  
   }
   //DisplayData(data, N);
}