// Insertion Sort
// Based on https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/tutorial/
// John Matthew Gan

void InsertionSort(int A[], int N) {
   int ctr = 0;
   int i, k, temp;
   //ctr += 2;

   for (i = 0; i < N; i++) {
      ctr+= 1;
      temp = A[i];
      k = i;
      ctr += 2;

      while (k > 0 && temp < A[k - 1]) {
         ctr += 1;
         A[k] = A[k - 1];
         --k;
         ctr += 2;
      }
      ctr += 1;

      A[k] = temp;
      ctr += 1;
   }
   ctr += 1;

   count(ctr);
}
