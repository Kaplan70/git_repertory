#include <stdio.h>

int countbit(unsigned int x)
{
    unsigned int m = 1, y, i = 0;
    while (m) {
        y = m & x;
        if (y) i++;
        m = m << 1;
    }

    return i;
}

int main(void)
{
    unsigned int x = 0x0000ffff;
    printf("%d\n", countbit(x));

    return 0;
}
