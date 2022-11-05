#include <stdio.h>
#include <stdlib.h>

void printArray(int list[], int n){
	for(int i=0;i<n;i++){
		printf(i?", %d":"[%d", list[i]);
	}
	printf("]\n");
}

void selectionSort(int list[],int n){

	for(int j=0;j<n-1;j++){
		int min = j;

		for(int i=j+1;i<n;i++){
			if(list[min]>list[i]){

				min = i;
			}
		}
		if(min != j){
			int t = list[j];
			list[j]=list[min];
			list[min]=t;

		}
	}

	printArray(list,n);
}


int main(int argc, char const *argv[])
{
	int list[20] = {0,4,2,5,6,7,1,44,9};

	int n = 9;

	printArray(list,n);
	selectionSort(list,n);
	return 0;
}