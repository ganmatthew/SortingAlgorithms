// Bubble Sort
// Based on https://www.programmingsimplified.com/c/source-code/c-program-bubble-sort
// John Matthew Gan

void BubbleSort (int A[], sortResult * loc, int N) {
   int ctr = 0;
   int i, k, temp = A[0];
   int D[N];
   
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

   loc -> count = ctr;
   loc -> time = 0;
   printf("[BubbleSort] count = %d, time = %d\n", loc -> count, loc -> time);
}