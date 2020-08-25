// Insertion Sort
// Based on https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/tutorial/
// John Matthew Gan

void InsertionSort (int A[], sortResult * loc, int N) {
   int ctr = 0;
   int i, k, temp;
   int D[N];
   struct timespec begin, end;

   clock_gettime(CLOCK_REALTIME, &begin);
   
   DuplicateData(D, A, N);
   for (i = 0; i < N; i++) {
      temp = D[i];
      k = i;

      while (k > 0 && temp < D[k - 1]) {
         D[k] = D[k - 1];
         --k;
         ctr++;
      }

      D[k] = temp;
      ctr++;
   }

   clock_gettime(CLOCK_REALTIME, &end);

   long seconds = end.tv_sec - begin.tv_sec;
   long nanoseconds = end.tv_nsec - begin.tv_nsec;
   double elapsed = seconds + nanoseconds*1e-9;

   loc -> count = ctr;
   loc -> time = elapsed;
   printf("[InsertionSort] count = %9d, time = %f\n", loc -> count, loc -> time);
}
