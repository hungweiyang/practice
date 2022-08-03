#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void mergesort(int a[], int len)
{
    if (len <= 1)
        return;

    int b[len];
    mergesort(a, len/2);
    mergesort(a + len/2, len/2 + len%2);

    int i = 0;
    int j = len/2;
    int k = 0;
    for (; i < len/2 && j < len; ++k) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
    }

    if (i == len/2) {
        for (; j < len; ++k) {
            b[k] = a[j];
            ++j;
        }
    } else {
        for (; i < len/2; ++k) {
            b[k] = a[i];
            ++i;
        }
    }

    for (i = 0; i < len; i++)
        a[i] = b[i];
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

void bubblesort2(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i+1; j < len - 1; j++)
        {
            if (a[i] > a[j+1])
            {
                int t = a[i];
                a[i] = a[j+1];
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

void insertion_sort(int a[], int len)
{
    for (int i = 1; i < len; ++i) {
        int key = a[i];
        int j;
        for (j = i-1; j >= 0; --j) {
            if (a[j] > key) {
                a[j+1] = a[j];
            } else {
                break;
            }
        }
        a[j+1] = key;
    }    
}

void insert_sort(int a[], int len)
{
  int key;
  for (int i = 1; i < len; i++) {
    int j;
    key = a[i];
    for (j = i-1; j > 0; j--) {
      if (a[j] > key) {
        a[j+1] = a[j];
      }
      else 
        break;
    }
    a[j+1] = key;
  }
}

int main()
{
    int a[] = {77, 55, -44, 33, 11, 0, 2, 8, 10, -1, 30};
    int len = sizeof(a)/sizeof(a[0]);
    
    for (int i = 0; i < len; i++) printf("%d ", a[i]);
    printf("\n");

    //mergesort(a, len);
    //bubblesort2(a, len);
    //quicksort(a, 0, len-1);
    insert_sort(a, len);    
    
    for (int i = 0; i < len; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
