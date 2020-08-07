// Insertion Sort
// Based on https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/tutorial/

void InsertionSort(int A[], int N) {
   int i, k, temp;

   for (i = 0; i < N; i++) {
      temp = A[i];
      k = i;

      while (k > 0 && temp < A[k - 1]) {
         A[k] = A[k - 1];
         --k;
      }

      A[k] = temp;
   }
}