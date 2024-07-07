#include <stdio.h>
#include <stdlib.h>

#define N 20

int a[N];

int gen_random(void){
    int i;
    for (i = 0; i < N; i++){
        a[i] = rand() % 10;
    }
    return 0;
}

int main(void){
    int num[10] = {0}, i, j;
    gen_random();
    for (i = 0; i < N; i++) num[a[i]]++;
    for (j = 0; j < 10; j++) printf("%d\n", num[j]);

    return 0;
}
