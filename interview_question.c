#include <stdio.h>
#include <string.h>

void question_process_sections()
{
    /*
     * High addr |-----------------|
     *           | stack           | 
     *           |-----------------|
     *           |                 |
     *           |                 |  
     *           |-----------------| 
     *           | heap            |    
     *           |-----------------|
     *           | bss             |    
     *           |-----------------|
     *           | data            | 
     *           |-----------------|
     *           | text            |
     * Low addr  |-----------------|
     */ 

    static int var1 = 5;
    static int var2 = 0;
    int *var3 = malloc(sizeof(int));

    printf("%s\n", (&var1 < &var2) ? "Yes" : "No");
    printf("%s\n", (&var2 < &var3) ? "Yes" : "No");
    printf("%s\n", (&var3 < var3) ? "Yes" : "No");
    
    //printf("%p, %p, %p, %p\n", &var1, &var2, &var3, var3);
}


void quetion_buffer_overflow()
{
    /*
     * High addr |-----------------|
     *           | return addr     | addr + 12
     *           | stack base addr | addr + 8
     *           | str2[4]         | addr + 4
     *           | str1[4]         | addr
     * Low addr  |-----------------|
     */ 

    char str1[4] = {"111"};
    char str2[4] = {"222"};
 
    strcpy(str1, "3333333");    // Question 1: What is the problem with the following strcpy()?

    printf("%s\n", str1);       // Question 2: What is the output by the following printf()?  (A) "3333" (B) "3333333"

    printf("%s\n", str2);       // Question 3: What is the output by the following printf()?  (A) "222" (B) "333"    
}

void question_pointer_of_array()
{
    int a[5] = {1,2,3,4,5};

    printf("(a+1) - a:      %d\n", (int)(a+1) - (int)a);
    printf("&a - a:         %d\n", (int)&a - (int)a);
    printf("(&a+1) - a:     %d\n", (int)(&a+1) - (int)a);

    printf("sizeof(a[0]) :  %ld\n", sizeof(a[0]));
    printf("sizeof(a) :     %ld\n", sizeof(a));
    printf("sizeof(&a) :    %ld\n", sizeof(&a));

    printf("*a+1 :          %d\n", *(a+1));

    int *p = (int*)(&a+1);
    printf("*(p-1) :        %d\n", *(p-1));    
}

int main()
{

    
    return 0;
}