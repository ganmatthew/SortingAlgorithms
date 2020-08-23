// Quick Sort 
// Based on https://www.geeksforgeeks.org/quick-sort/
// Jose Noel Noblefranca

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
   
   DuplicateData(D, A, N);
    quicksort(D, 0, N - 1, &ctr);

    loc -> count = ctr;
    loc -> time = 0;
    printf("[QuickSort] count = %d, time = %d\n", loc -> count, loc -> time);
}