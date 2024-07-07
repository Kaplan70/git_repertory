#include <stdio.h>

#define N 3 /*数字总数*/
#define M 3 /*排序的数字*/

int num[N] = {1, 2, 3};

/* *
 * 位移函数
 * 参数为将一个数组-全局变量的数组，
 * 的第a位移动到第b位(0位计)
 * 保存i+1及a位，最后移动完b位后，存储
 * */
int move(int a, int b)
{
    int i = a - 1, temp;
    temp = num[i + 1];
    while (i >= b) {
        num[i + 1] = num[i];
        i--;
    }
    num[b] = temp;
    
    return 0;
}

int printf_num(void)
{
    int i;
    for (i = 0; i < N; i++) printf("%d ", num[i]);
    printf("\n");

    return 0;
}

/**
 * 排序函数
 * -参数x为对x个元素的？位排序
 *  N - x为总共的N个数排列的第几次操作
 **/
int sort(int x)
{
    int i;
    if (x == N - M + 1) printf_num();
    else { 
        for (i = N - x; i < N; i++) {
            move(i, N - x); 
            sort(x - 1);
        }
    }

    return 0;
}

int main(void)
{
    sort(3);
}
