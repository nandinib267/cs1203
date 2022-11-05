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

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int* a, int start, int stop) {
  
  int pivot = a[stop];
  
  int i = (start - 1);

  for (int j = start; j < stop; j++) {
    if (a[j] <= pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }

  swap(&a[i + 1], &a[stop]);
  
  return (i + 1);
}

void quickSort(int* a, int start, int stop) {
  if (start < stop) {
    
    int p = partition(a, start, stop);
    
    quickSort(a, start, p - 1);
    
    quickSort(a, p + 1, stop);
  }
}


int main(int argc, char **argv){
	int n=10;
	int * a;

	srand(time(NULL));

	a = generateArray(n);
	printArray(a,n);
	
	quickSort(a,0,n-1);

	printArray(a,n);

	free(a);

	return 0;
}