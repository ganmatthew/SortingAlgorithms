// Selection Sort
// Based on https://www.geeksforgeeks.org/selection-sort/
// John Matthew Gan

void SelectionSort (int A[], sortResult loc, int N) {
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

   loc.count = ctr;
   loc.time = 0;
   printf("[SelectionSort] count = %d, time = %d\n", loc.count, loc.time);
}