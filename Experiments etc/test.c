#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
	int i;
	int sum = 0;

	for(i=0;i-=1000;i++){
		printf("%d \n", i);
		
		sum = sum+i;
	}

	assert(i<=1000);

	printf("sum: %d\n",sum);
	return 0;
}