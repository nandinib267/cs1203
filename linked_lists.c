#include <stdio.h>
#include <stdlib.h>

struct Node {
        int data;
        struct Node * next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(int argc, char **argv) {
        struct Node * head = NULL;
        struct Node * second = NULL;
        struct Node * third = NULL;

        // allocating memory to each Node
	
	head = malloc(sizeof(struct Node));
	second = malloc(sizeof(struct Node));
	third = malloc(sizeof(struct Node));
	
	//allocating data to each node
	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	linkedListTraversal(head);
	return 0;


}
