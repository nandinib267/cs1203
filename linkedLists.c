#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node * next;
};

typedef struct Node node;

void Traversal(node *ptr){
	while (ptr!=NULL){
		printf("Element: %d\n", ptr->data);
		ptr=ptr->next;
	}
}

void appendm(int ele, node *ptr){
	node *temp;
	temp=malloc(sizeof(node));
	temp->data=ele;
	temp->next=NULL;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
}

int main(int argc, char **argv){
	node *head;
	int ele, comp;
	char res;
	head=malloc(sizeof(node));
	printf("Enter element:\t");
	scanf("%d%*c\n",&head->data);
	head->next=NULL;
	printf("Would you like to add more elements? (Y/N)\t");
	scanf("%c\n",&res);
	while(1){
		printf("Enter element:\t");
                scanf("%d\n",&ele);
                appendm(ele,head);
		printf("------------\n");
		printf("Would you like to enter another element? (Y/N)\t");
		scanf("%c\n",&res);
		if(res=="N" || res=="n"){
			break;
		}
	}
	Traversal(head);
	printf("Thank You!");
	return 0;
}
