// Selection Sort
// Based on https://www.geeksforgeeks.org/selection-sort/
// John Matthew Gan, Angelo Remudaro

void SelectionSort (int A[], sortResult * loc, int N) {
   int i, j, min, temp, ctr = 0;
   int D[N];
   struct timespec begin, end; 

   clock_gettime(CLOCK_REALTIME, &begin);

   DuplicateData(D, A, N);
   for (i = 0; i < N; i++) {
      
      min = i;
      for (j = i + 1; j < N; j++) {
         if (D[j] < D[min]) {
            min = j;
         }
         ctr++;
      }

      temp = D[min];
      D[min] = D[i];
      D[i] = temp;
      ctr++;
   }

   clock_gettime(CLOCK_REALTIME, &end);
  
   long seconds = end.tv_sec - begin.tv_sec;
   long nanoseconds = end.tv_nsec - begin.tv_nsec;
   double elapsed = seconds + nanoseconds*1e-9;

   loc -> count = ctr;
   loc -> time = elapsed;
   printf("[SelectionSort] count = %9d, time = %f\n", loc -> count, loc -> time);
}