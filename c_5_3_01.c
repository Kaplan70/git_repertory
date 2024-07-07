#include <stdio.h>

int num_max(int a, int b){
    if(!(a % b)) return b;
    else return num_max(b, a % b);
    /*
    if(!(a % b)) printf("if %d \n", (a/b));
    else printf("else %d \n", (a/b));
    return 0;
    */
}

int main(void){
   int a = 36;
   int b = 48;
   printf("the num_max is %d\n", num_max(a, b));
   return 0;
}
