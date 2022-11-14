#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
        int data;
        struct Node * next;
};

typedef struct Node node;
//hi
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
        int ele, len;
        node *head;
        head = malloc(sizeof(node));
        printf("Enter number of elements you'd like to input:\t");
        scanf("%d\n",&len);
        printf("Enter element:\t");
        scanf("%d\n",&head->data);
        head->next=NULL;
        Traversal(head);
        len=len-1;
        while(len>=0){
                printf("===============\n");
                printf("Enter element:\t");
                scanf("%d\n",&ele);
                printf("------------\n");
                appendm(ele,head);
                printf("===============\n");
                len=len-1;
                printf("%d\n",len);
        }
        Traversal(head);
        return 0;

}