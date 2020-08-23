// Bubble Sort
// Based on https://www.programmingsimplified.com/c/source-code/c-program-bubble-sort
// John Matthew Gan

#include <time.h>

void BubbleSort (int A[], sortResult * loc, int N) {
   int ctr = 0;
   int i, k, temp = A[0];
   int D[N];
   struct timespec begin, end; 
   
   clock_gettime(CLOCK_REALTIME, &begin);

   DuplicateData(D, A, N);
   for (k = 0 ; k < N - 1; k++) {

      for (i = 0 ; i < N - k - 1; i++) {
         if (D[i] > D[i + 1]) {
            temp = D[i];
            D[i] = D[i + 1];
            D[i + 1] = temp;
         }
         ctr++;
      }
      ctr++;
   }

   clock_gettime(CLOCK_REALTIME, &end);

   long seconds = end.tv_sec - begin.tv_sec;
   long nanoseconds = end.tv_nsec - begin.tv_nsec;
   double elapsed = seconds + nanoseconds*1e-9;

   loc -> count = ctr;
   loc -> time = elapsed;
   printf("[BubbleSort] \tcount = %9d, time = %f\n", loc -> count, loc -> time);
}