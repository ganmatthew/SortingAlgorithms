// Selection Sort
// Based on https://www.geeksforgeeks.org/selection-sort/

void SelectionSort(int A[], int N) {
   int i, j, min, temp, ctr = 0;
   for (i = 0; i < N; i++) {
      
      min = i;
      for (j = i + 1; j < N; j++) {
         if (A[j] < A[min])
            min = j;
         ctr++;
      }

      temp = A[min];
      A[min] = A[i];
      A[i] = temp;
      ctr++;

   }

   count(ctr);
}