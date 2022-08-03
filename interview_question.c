#include <stdio.h>
#include <string.h>

void reverse_bits()
{
  unsigned char v = 0b01010101;
  unsigned char r = 0;
  
  for (int i = 0; i < 8; i++)
  {
    r |= (v & (1<<i)) >> i << (7-i);
  }

  // const int s = sizeof(v) * 8 - 1;
  // for (int i = 0; i < s; i++)
  // {
  //   r |= v & 0x1;
  //   r <<= 1;
  //   v >>= 1;
  // }

  printf("%x\n", r);
}

// void question_multiple_three()
// {
//     int target, i = 2;

//     for (i = 0; i < 1000; ++i) 
//     {
//         target = i;     
        
//         do {
//           int odd_sum = 0;
//           int even_sum = 0;
        
//           while (1) {
//               if (target > 0) {
//                   even_sum += target & 1;
//                   target >>= 1;
//               } else
//                   break;
              
//               if (target > 0) {
//                   odd_sum += target & 1;
//                   target >>= 1;
//               } else
//                   break;
//           }
//           target = abs(even_sum - odd_sum);
//         } while (target > 3);
  
//         if (target == 1 || target == 2)
//             printf("%d is not multiple of three\n", i);
//         else
//             printf("%d is multiple of three\n", i);
//     }
// }

// void question_process_sections()
// {
//     /*
//      * High addr |-----------------|
//      *           | stack           | 
//      *           |-----------------|
//      *           |                 |
//      *           |                 |  
//      *           |-----------------| 
//      *           | heap            |    
//      *           |-----------------|
//      *           | bss             |    
//      *           |-----------------|
//      *           | data            | 
//      *           |-----------------|
//      *           | text            |
//      * Low addr  |-----------------|
//      */ 

//     static int var1 = 5;
//     static int var2 = 0;
//     int *var3 = malloc(sizeof(int));

//     printf("%s\n", (&var1 < &var2) ? "Yes" : "No");
//     printf("%s\n", (&var2 < &var3) ? "Yes" : "No");
//     printf("%s\n", (&var3 < var3) ? "Yes" : "No");
    
//     //printf("%p, %p, %p, %p\n", &var1, &var2, &var3, var3);
// }


// void quetion_buffer_overflow()
// {
//     /*
//      * High addr |-----------------|
//      *           | return addr     | addr + 12
//      *           | stack base addr | addr + 8
//      *           | str2[4]         | addr + 4
//      *           | str1[4]         | addr
//      * Low addr  |-----------------|
//      */ 

//     char str1[4] = {"111"};
//     char str2[4] = {"222"};
 
//     strcpy(str1, "3333333");    // Question 1: What is the problem with the following strcpy()?

//     printf("%s\n", str1);       // Question 2: What is the output by the following printf()?  (A) "3333" (B) "3333333"

//     printf("%s\n", str2);       // Question 3: What is the output by the following printf()?  (A) "222" (B) "333"    
// }

// void question_pointer_of_array()
// {
//     int a[5] = {1,2,3,4,5};

//     printf("(a+1) - a:      %d\n", (int)(a+1) - (int)a);
//     printf("&a - a:         %d\n", (int)&a - (int)a);
//     printf("(&a+1) - a:     %d\n", (int)(&a+1) - (int)a);

//     printf("sizeof(a[0]) :  %ld\n", sizeof(a[0]));
//     printf("sizeof(a) :     %ld\n", sizeof(a));
//     printf("sizeof(&a) :    %ld\n", sizeof(&a));

//     printf("*a+1 :          %d\n", *(a+1));

//     int *p = (int*)(&a+1);
//     printf("*(p-1) :        %d\n", *(p-1));    
// }

int main()
{

    //question_pointer_of_array();
    reverse_bits();
    return 0;
}