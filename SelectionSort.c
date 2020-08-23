// Selection Sort
// Based on https://www.geeksforgeeks.org/selection-sort/
// John Matthew Gan

void SelectionSort (int A[], sortResult * loc, int N) {
   int i, j, min, temp, ctr = 0;
   int D[N];
   
   DuplicateData(D, A, N);
   for (i = 0; i < N; i++) {
      
      min = i;
      for (j = i + 1; j < N; j++) {
         if (D[j] < D[min]) {
            min = j;
         }
         ctr += 2;
      }

      temp = D[min];
      D[min] = D[i];
      D[i] = temp;
   }

   loc -> count = ctr;
   loc -> time = 0;
   printf("[SelectionSort] count = %d, time = %d\n", loc -> count, loc -> time);
}