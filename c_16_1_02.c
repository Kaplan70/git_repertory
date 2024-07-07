#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y)
{
    unsigned int m = 1, sum = 0, i = 0;
    while (m) {
        if (m & y) sum = sum + (x << i);
        i = i + 1;
        m = m << 1;
    }
    return sum;
}

int main(void)
{
    unsigned int mul;
    mul = multiply(5, 3);
    printf("%d\n", mul);

    return 0;
}
