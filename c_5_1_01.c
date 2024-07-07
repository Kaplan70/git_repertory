#include <stdio.h>

int is_leap_year(int year){
	if((!(year % 4 ) && (year % 100)) || !(year % 400)) return 1;
	else return 0;
}

int main(void){
	int year = 365;
	printf("this is_not leap year : %d\n", is_leap_year(year));
	return 0;	
}
