// Insertion Sort
// Based on https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/tutorial/
// John Matthew Gan

void InsertionSort (int A[], sortResult * loc, int N) {
   int ctr = 0;
   int i, k, temp;
   int D[N];
   
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

   loc -> count = ctr;
   loc -> time = 0;
   printf("[InsertionSort] count = %d, time = %d\n", loc -> count, loc -> time);
}
