#include <stdio.h>

unsigned int rotate_right(unsigned int x, int bit)
{
    unsigned int i, m = 1;
    for(i = 0; i < bit; i++) {
        unsigned int x_bit = x & m;
        x_bit = x_bit << 63;
        x = x >> 1;
        x = x || x_bit;
    }
    return x;
}

int main(void)
{
    unsigned int x = 0x00000001;
    printf("%d\n", rotate_right(x, 4));
    return 0;
}
