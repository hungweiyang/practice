#include <stdio.h>

// 0 : 00000000 -> 00000000
// 1 : 00000001 -> 10000000
// 2 : 00000010 -> 01000000
// 3 : 00000011 -> 11000000
// 4 : 00000100 -> 00100000
// 5 : 00000101 -> 10100000
// 6 : 00000110 -> 01100000
// 7 : 00000111 -> 11100000
// 8 : 00001000 -> 00010000
// ...
// 12 : 00001100 -> 00110000
// ...
// 16 : 0001_0000 -> 0000_1000
// ...
// 32 : 0010_0000 -> 0000_0100
// ...
// 48 : 0011_0000 -> 0000_1100 
// ...
// 64 : 0100_0000 -> 0000_0010
// ...
// 128 : 1000_0000 -> 0000_0001
// ...
// 192 : 0

#define R1(N) N, 64*2 + N, 64*1 + N, 64*3 + N
#define R2(N) R1(N), R1(N+32), R1(N+16), R1(N+48)
#define R3(N) R2(N), R2(N+8), R2(N+4), R2(N+12)
#define R4(N) R3(N), R3(N+2), R3(N+1), R3(N+3)

unsigned char tbl[] = {R4(0)};

void print_binary(unsigned char v)
{
    for (int i = 7; i >=0 ; i--)
        printf("%d", (v >> i) & 1);
    printf("\n");
    return;
}

int main(int argc, char *argv[])
{
	unsigned int v = 0x12345678;
    char *p = (char*) &v;
    printf("%x", tbl[p[0]]);
    printf("%x", tbl[p[1]]);
    printf("%x", tbl[p[2]]);
    printf("%x\n", tbl[p[3]]);
}