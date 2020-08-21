// Insertion Sort
// Based on https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/tutorial/
// John Matthew Gan

void InsertionSort (int A[], sortResult * loc, int N) {
   int ctr = 0;
   int i, k, temp;

   for (i = 0; i < N; i++) {
      temp = A[i];
      k = i;

      while (k > 0 && temp < A[k - 1]) {
         A[k] = A[k - 1];
         --k;
         ctr++;
      }

      A[k] = temp;
      ctr++;
   }

   loc -> count = ctr;
   loc -> time = 0;
   printf("[InsertionSort] count = %d, time = %d\n", loc -> count, loc -> time);
}
