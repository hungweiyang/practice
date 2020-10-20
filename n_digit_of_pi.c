#include <stdio.h>

int main()
{
    char pi[] = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    unsigned int i;
    
    printf("Enter a number (1~100): ");
    scanf("%d", &i);
    i = (i >= 100) ? 100 : i ;
    
    *(pi + i + 2) = 0;
    
    printf("%s\n", pi);
    
    return 0;
}
