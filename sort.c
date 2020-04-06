/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int a[] = {7, 5, 4, 3, 1, 0, 2, 8, 10, -1, 100};
    int len = sizeof(a)/sizeof(a[0]);
    
    for (int i = 0; i < len; i++) printf("%d ", a[i]);
    printf("\n");
    
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
    
    for (int i = 0; i < len; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
