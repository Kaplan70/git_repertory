#include <stdio.h>
#include <math.h>

double myround(double x){
	double x0;
	x0 = x - 0.5;
	return ceil(x0);
}

int main(void){
	double x = -4.49;
	printf("x round is %f\n", myround(x));
	return 0;
}
