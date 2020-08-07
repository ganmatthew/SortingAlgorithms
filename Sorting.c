#include <stdio.h>

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

int main()
{
    int i;
    int test[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 4};
    int size = 10;

    printf("Before sorting: \n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", test[i]);
    }

    quicksort(test, 0, size - 1);
    
    printf("\nAfter sorting: \n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", test[i]);
    }

    
    return 0;
}