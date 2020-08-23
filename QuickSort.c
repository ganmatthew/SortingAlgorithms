// Quick Sort 
// Based on https://www.geeksforgeeks.org/quick-sort/
// Jose Noel Noblefranca

#include <time.h>

void swap (int * a, int * b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int partition(int * array, int low, int high, int * ctr)
{
    int j;
    int pivot = array[high];
    int i = low - 1;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap (&array[i], &array[j]);
        }
        ++(*ctr);
    }

    swap (&array[i + 1], &array[high]);
    ++(*ctr);
    return (i + 1);
}

void quicksort (int * array, int low, int high, int * ctr)
{
   int p;

   if (low < high)
   {
      p = partition(array, low, high, ctr);
      
      quicksort(array, low, p - 1, ctr);
      quicksort(array, p + 1, high, ctr);
   }
}

void QuickSort (int A[],  sortResult * loc, int N) {
    int ctr = 0;
    int D[N];

    struct timespec begin, end; 

    clock_gettime(CLOCK_REALTIME, &begin);
   
    DuplicateData(D, A, N);
    quicksort(D, 0, N - 1, &ctr);

    clock_gettime(CLOCK_REALTIME, &end);
    
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;

    loc -> count = ctr;
    loc -> time = elapsed;
    printf("[QuickSort] \tcount = %9d, time = %f\n", loc -> count, loc -> time);
}