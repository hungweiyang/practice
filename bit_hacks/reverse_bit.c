#include <stdio.h>

void reverse_bits()
{
  // method 1
  // for (int i = 0; i < 8; i++)
  // {
  //   r |= (v & (1<<i)) >> i << (7-i);
  // }

  // method 2
  // const int s = sizeof(v) * 8 - 1;
  // for (int i = 0; i < s; i++)
  // {
  //   r |= v & 0x1;
  //   r <<= 1;
  //   v >>= 1;
  // }

  // method 3
  // unsigned char v = 0b01010101;
  // unsigned char r = 0;
  // int s = sizeof(v) * 8 - 1;
  // for (;v;)
  // {
  //   r |= v & 0x1;
  //   r <<= 1;
  //   v >>= 1;
  //   --s;
  // }
  // r <<= s;

  // method 4
  // http://graphics.stanford.edu/~seander/bithacks.html#BitReverseObvious
  // eliminated one iteration of the for loop
  unsigned int v = 0x12345678;
  unsigned int r = v;  // get LSB while assigning
  int s = sizeof(v) * 8 - 1;
  for (v >>= 1; v; v >>= 1)
  {
    r <<= 1;
    r |= v & 0x1;
    --s;
  }
  r <<= s;

  printf("%x\n", r);
  for (int i = sizeof(r)*8-1; i >= 0; i--)
  {
    printf("%d", (r >> i) & 1);    
  }
  printf("\n");
}

int main()
{
  reverse_bits();
}