#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int * a, int n){
	printf("Array = ");
	for(int i=0;i<n;i++){
		printf(i?", %d":"[%d",a[i]);
	}
	printf("]\n");
}

int * generateArray(int n){
	int * t = malloc(n * sizeof(int));
	if (t){
		for(int i=0;i<n;i++){
			t[i]=rand()%1000;
		}
	}
	return t;
}

void insertSort(int* a, int n){

	for(int i=1;i<n;i++){
		int curr = a[i];
		int wall = i;
		while(wall>0 && a[wall-1]>curr){
			a[wall] = a[wall-1];
			wall-=1;

		}
		a[wall] = curr;
	}

	printArray(a,n);
}

int main(int argc, char **argv){
	int n=10;
	int * a;

	srand(time(NULL));

	a = generateArray(n);
	printArray(a,n);

	insertSort(a,n);
	
	free(a);

	return 0;
}