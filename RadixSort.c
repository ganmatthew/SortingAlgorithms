// Radix Sort (base 10)
// Uses Counting Sort ass subroutine
// Based on https://www.geeksforgeeks.org/radix-sort/
// Jose Noel Noblefranca

// A utility function to get maximum value in arr[] 
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
void RadixSort(int A[], sortResult loc, int N) { 
    // Find the maximum number to know number of digits 
    int m = getMax(A[], N); 
    
    int ctr = 0;
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp, &ctr); 

    loc.count = ctr;
    loc.time = 0;
    printf("[BubbleSort] count = %d, time = %d\n", loc.count, loc.time);
} 