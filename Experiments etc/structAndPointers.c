#include <stdio.h>
#include <stdlib.h>

struct test{
	int* p;
};


int main(){
	int x = 5;
	struct test y;
	y.p = &x;
	printf("%d\n",*(y.p));
	return 0;
}
