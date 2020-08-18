// Quick Sort 
// Based on <LINK>
// Jose Noel Noblefranca

void swap (int * a, int * b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int partition(int * array, int low, int high)
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
    }

    swap (&array[i + 1], &array[high]);
    return (i + 1);
}

void quicksort (int * array, int low, int high)
{
   int p;

   if (low < high)
   {
      p = partition(array, low, high);
      
      quicksort(array, low, p - 1);
      quicksort(array, p + 1, high);
   }
}

void QuickSort (int A[], int N) {
   quicksort(A, 0, N - 1);
}