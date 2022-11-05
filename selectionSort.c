#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int val;
	struct node * next;
};

typedef struct node *nodeAddress;

void printArray(int * a, int n){
	printf("Array = ");
	for(int i=0;i<n;i++){
		printf(i?", %d":"[%d",a[i]);
	}
	printf("]\n");
}

void Traverse(nodeAddress head){
	nodeAddress c;
	for(c=head; c!=NULL; c=c->next){
		printf(c==head?"[%d":", %d",c->val);
	}
	printf("]\n");
}

nodeAddress linkedListFromArray(int * a, int n){
	nodeAddress temp = NULL; 
	nodeAddress head = NULL;
	if (n>0){
		head = malloc(sizeof(struct node));
		head->val = a[0];
		head->next = NULL;
		temp = head;
	}
	for(int i=1;i<n;i++){
		temp->next = malloc(sizeof(struct node));
		temp=temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}

	return head;
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

void freeLinkedList(nodeAddress head){
	nodeAddress prev;

	while(head){
		prev = head;
		head = head->next;
		free(prev);
	}
}

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

// int findAddressOfMax(int* a, int n){
// 	int* amax = NULL;

// 	if (n>=1){
// 		amax = a;
// 		for(int i = 1; i<n; i++){
// 			if(*(a+i) > *(a+amax)){
// 				amax = i;
// 			}
// 		}
// 	}

// 	return amax;
// }

void selectionSort(int * a,int n){

	for(int j=0;j<n-1;j++){
		int min = j;

		for(int i=j+1;i<n;i++){
			if(a[min]>a[i]){

				min = i;
			}
		}
		if(min != j){
			int t = a[j];
			a[j]=a[min];
			a[min]=t;

		}
	}

	printArray(a,n);
}

int main(int argc, char **argv){
	int n=10;
	int * a;
	nodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	printArray(a,n);
	
	//list = linkedListFromArray(a,n);

	//Traverse(list);
	//selectionSortLinkedList(list,n);
	//Traverse(list);

	selectionSort(a,n);


	free(a);
	freeLinkedList(list);

	return 0;
}