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

void bubbleSort(int * a, int n){
	for(int i=n;i>0;i=i-1){
		for(int j=0;j<i-1;j++){
			if (a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printArray(a,n);
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

void bubbleSortLinkedLists(nodeAddress head){
	nodeAddress c, lastDone; 
	int t;

	for(lastDone=NULL; lastDone!=head; lastDone=c){

		for(c=head; c->next!=lastDone; c=c->next){

			if(c->val > c->next->val){

				t = c->val;
				c->val = c->next->val;
				c->next->val = t;
			}
		} //end of c loop; element has been bubbled up to pos c
	} //end of lastDone val
}

int main(int argc, char **argv){
	int n=10;
	int * a;
	nodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	printArray(a,n);
	//bubbleSort(a,n);
	
	list = linkedListFromArray(a,n);

	Traverse(list);
	bubbleSortLinkedLists(list);
	Traverse(list);

	bubbleSort(a,n);

	free(a);
	freeLinkedList(list);

	return 0;
}