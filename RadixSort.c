// Radix Sort (base 10) with counting sort subroutine
// Based on https://www.geeksforgeeks.org/radix-sort/
// Jose Noel Noblefranca

// Uses a utility function to get maximum value in arr[] 

#include <time.h>

int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int arr[], int n, int exp, int * ctr) 
{ 
    int output[n]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) {
        count[ (arr[i]/exp)%10 ]++;
        ++(*ctr);
    } 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        ++(*ctr);
    } 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
        ++(*ctr);
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  
// The main function to that sorts arr[] of size n using  
// Radix Sort 
void RadixSort(int A[], sortResult * loc, int N) { 
    int D[N];
    struct timespec begin, end; 

    clock_gettime(CLOCK_REALTIME, &begin);

    DuplicateData(D, A, N);
    // Find the maximum number to know number of digits 
    int m = getMax(D, N); 
    int exp, ctr = 0;
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (exp = 1; m / exp > 0; exp *= 10) 
        countSort(D, N, exp, &ctr);

    clock_gettime(CLOCK_REALTIME, &end);
    
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;

    loc -> count = ctr;
    loc -> time = elapsed;
    printf("[RadixSort] \tcount = %9d, time = %f\n", loc -> count, loc -> time);
} 