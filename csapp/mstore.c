long mult2(long, long);

void multstore(long x, long y, long *dest)
{
    long t = x * y;
    *dest = t;
}