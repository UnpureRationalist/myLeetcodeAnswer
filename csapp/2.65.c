#include <stdio.h>

/** 
 * Return 1 when x contains an odd number of 1; 0 otherwise.
 */
int odd_ones(unsigned x)
{
    // assume that width of x is 32 bits
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1;
}

int main(int argc, char **argv)
{
    unsigned x = 0b0000'0000'0100'0000'0000'0000'0000'0000;
    int ans = odd_ones(x);
    printf("%d\n", ans);
    return 0;
}