#include <stdio.h>
#include <stdlib.h>

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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int i) {
    int temp = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[temp]) {
        temp = left;
    }

    if (right < size && arr[right] > arr[temp]) {
        temp  = right;
    }

    if (temp!= i) {
        swap(&arr[i], &arr[temp]);
        heapify(arr, size, temp);
    }
}

void heapSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        heapify(arr, size, i);
    }

    for(int i = size - 1; i >= 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main(int argc, char **argv){
    int size = 10;
    int* arr = generateArray(size);
    printArray(arr,size);

    heapify(arr, size, 0);
    printArray(arr,size);

    printf("\n");

    heapSort(arr, size);
    printArray(arr,size);
}