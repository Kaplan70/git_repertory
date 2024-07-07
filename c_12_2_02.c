#include <stdio.h>

#define LEN 3

char buf[LEN] = {'a', 'b', 'c'};

int dprintfs(int l)
{
    if (l == LEN) return 0;
    dprintfs(l + 1);
    putchar(buf[l]);
    return 0;
}

int main(void)
{
    dprintfs(0);
    printf("\n");
    return 0;
}
