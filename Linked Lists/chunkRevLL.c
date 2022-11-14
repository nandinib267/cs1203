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

nodeAddress chunkRevLL(nodeAddress head, int i){
	//i is the k that has to be chunked. 
	nodeAddress prevPtr, nextPtr, ptr;

	prevPtr = malloc(sizeof(struct node));
	nextPtr = malloc(sizeof(struct node));
	ptr = malloc(sizeof(struct node));

	prevPtr = NULL;
	nextPtr = NULL;
	ptr = head;
	int k = 0;
	while(k<i){
		nextPtr = ptr->next;
		ptr->next = prevPtr;

		prevPtr = ptr;

		ptr = nextPtr;

		k++;
	}

	if(nextPtr != NULL){
		head->next = chunkRevLL(nextPtr,i);
	}

	return prevPtr;

}

int main(int argc, char **argv){
	int n=10;
	int * a;
	nodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	printArray(a,n);
	
	list = linkedListFromArray(a,n);

	Traverse(list);

	Traverse(chunkRevLL(list, 5));

	free(a);
	freeLinkedList(list);

	return 0;
}