#include <stdio.h>
int main(void){
    struct ooo {
        int x, y;
    };
    struct ooo a[5] = {[0] = {.x = 1, .y = 1}, };
	printf("%%");
	printf("abc\ndef\\\nghi\"");
	return 0;
}
