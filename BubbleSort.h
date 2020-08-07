// Bubble Sort
// Based on https://www.programmingsimplified.com/c/source-code/c-program-bubble-sort

void BubbleSort (int A[], int N) {
   int i, k, temp = A[0];

   for (k = 0 ; k < N - 1; k++) {

      for (i = 0 ; i < N - k - 1; i++) {
         if (A[i] > A[i + 1]) {
         temp = A[i];
         A[i] = A[i + 1];
         A[i + 1] = temp;
         }
      }
      
   }
}