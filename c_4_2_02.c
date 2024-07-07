#include <stdio.h>

int typora_gs(int x){
	int g, s;
	g = x % 10;
	s = x / 10;
	printf("over\n");
	return 0;
}

int main(void){
	int x = 27;
	typora_gs(x);
	return 0;
}


