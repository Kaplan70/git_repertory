#include <stdio.h>

int fib(int n){
    if(n == 0) return 1;
    else if(n == 1) return 1;
    else return fib(n - 1) + fib(n - 2);
}

int main(void){
   int n = 40;
   printf("fib(%d) is %d\n", n, fib(n));
   return 0;
}