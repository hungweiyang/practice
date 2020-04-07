#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void bubblesort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (a[j] > a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }    
        }
    }
}

void quicksort(int a[], const int front, const int end)
{
    if (front >= end)
        return;
    
    int *pivot = &a[end];
    int i = front-1;
    int j = front;
    
    for (; j != end; j++)
    {
        if (a[j] < *pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    
    i++;
    swap(&a[i], pivot);
    
    quicksort(a, front, i-1);
    quicksort(a, i+1, end);
}

int main()
{
    int a[] = {77, 55, -44, 33, 11, 0, 2, 8, 10, -1, 30};
    int len = sizeof(a)/sizeof(a[0]);
    
    for (int i = 0; i < len; i++) printf("%d ", a[i]);
    printf("\n");
    
    //bubblesort(a, len);
    quicksort(a, 0, len-1);
    
    for (int i = 0; i < len; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
