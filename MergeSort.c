// Merge Sort 
// Based on https://www.geeksforgeeks.org/merge-sort/
// Jose Noel Noblefranca

#include <time.h>

void merge(int arr[], int l, int m, int r, int * ctr) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++;
            ++(*ctr);
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
            ++(*ctr);
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
        ++(*ctr);
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
        ++(*ctr);
    } 

} 

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r, int * ctr) 
{ 
   if (l < r) { 
      // Same as (l+r)/2, but avoids overflow for 
      // large l and h 
      int m = l + (r - l) / 2; 
      ++*ctr; 

      // Sort first and second halves 
      mergeSort(arr, l, m, ctr); 
      mergeSort(arr, m + 1, r, ctr); 

      merge(arr, l, m, r, ctr);
      
   } 
} 
  
void MergeSort (int A[],  sortResult * loc, int N) {
   int ctr = 0;
   int D[N];
   struct timespec begin, end; 

   clock_gettime(CLOCK_REALTIME, &begin);
   
   DuplicateData(D, A, N);
   mergeSort(D, 0, N, &ctr);
   
   clock_gettime(CLOCK_REALTIME, &end);

   long seconds = end.tv_sec - begin.tv_sec;
   long nanoseconds = end.tv_nsec - begin.tv_nsec;
   double elapsed = seconds + nanoseconds*1e-9;

   loc -> count = ctr;
   loc -> time = elapsed;
   printf("[MergeSort] \tcount = %9d, time = %f\n", loc -> count, loc -> time);
}