#include <stdio.h>

int main(void){
    int i = 100;
    int j = i;
    int num_9 = 0;
    while(i > 0){
        if(!((i - 9) % 10)) num_9 = num_9 + 1;
        if(!(((i / 10) - 9) % 10)) num_9 = num_9 + 1;
        i = i - 1;
    }
    printf("1-%d have %d 9\n", j, num_9);
    return 0;
}
