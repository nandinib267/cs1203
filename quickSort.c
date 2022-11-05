#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int * a, int start, int stop){

	int pivot = a[start];

	int i = start+1;
	int j = stop;
	
	while(i<=j){
		if(a[i]>pivot) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			j=j-1;
		}

		else if (a[i]<pivot) {
			i+=1;
		}

		//swap the pivot with a[j]
		int t=a[j];
		a[j] = pivot;
		pivot = t;
	}

	return j;
}

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

void quicksort(int * a, int start, int stop){
	if(!a || start>stop) {
		exit(-1);
	}

	int p = partition(a, start, stop); //returns an element at pos p where everything at the right is <p and everything to the left is >p.
	
	quicksort(a,start,p-1); //sorts the "lesser" pile
	
	quicksort(a, p+1,stop); //sorts the "greater" pile

	printArray(a,stop);

}

int main(int argc, char **argv){
	int n=10;
	int * a;

	srand(time(NULL));

	a = generateArray(n);
	printArray(a,n);
	
	quicksort(a,0,n);

	free(a);

	return 0;
}