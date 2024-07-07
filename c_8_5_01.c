#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
 * ret为scanf()函数的返回值，用于做判断
 * */
int main(void)
{
    int man, computer, result, ret;
    srand(time(NULL));
    switch (1) {
        computer = rand() % 3;
        printf("you select in 0-1-2:\n");
        ret = scanf("%d", &man);
        if (ret != 1 || man < 0 || man > 2) printf("errer\n");
        else {
            printf("you select are:%d\n", man);
            result = (man - computer + 4) % 3 - 1;
        }
    }
    computer = 
    printf("%ld", time(NULL));

    return 0;

}
