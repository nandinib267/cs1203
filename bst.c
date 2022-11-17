#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node* right; //larger
	struct node* left; //smaller
};

typedef struct node* nodeAddress;
typedef struct node node;

nodeAddress create(int i){

	nodeAddress root = malloc(sizeof(node));

	root->val = i;
	root->right = root->left = NULL;

	return root;
}


nodeAddress insertIntoTree(nodeAddress root, int i){
	if(root == NULL){
		return create(i);
	}

	else if(i<root->val){
		root->left = insertIntoTree(root->left, i);
	}
	else{
		root->right = insertIntoTree(root->right, i);
	}

	return root;
}

int search(nodeAddress root, int i){
	nodeAddress curr = root;

	while(curr->val != i){
		if(curr != NULL){

			if(curr->val > i){
				curr = curr->left;
			}
			else{
				curr = curr->right;
			}
		}

		if(curr==NULL){
			printf("Not found");
			return 0;
		}
	}

	printf("Found!");
	return 1;
}

nodeAddress minValueNode(nodeAddress root){
	nodeAddress curr = root;


	while(curr && curr->left != NULL){
		curr = curr->left;
	}
	return curr;
}

nodeAddress deleteNode(nodeAddress root, int i){
	if(root==NULL){
		return root;
	}

	if(i < root->val){
		root->left = deleteNode(root->left, i);
	}

	else if(i > root->val){
		root->right = deleteNode(root->right, i);
	}

	else{
		if(root->left == NULL){
			nodeAddress temp = root->right;
			free(root);
			return temp;
		}

		else if(root->right == NULL){
			nodeAddress temp = root->left;
			free(root);
			return temp;
		}

		nodeAddress temp = minValueNode(root->right);

		root->val = temp->val;

		root->right = deleteNode(root->right, temp->val);
	}
	return root;
}

void inorderPrint(nodeAddress root){
	if(root == NULL){
		return;
	}

	inorderPrint(root->left);
	printf("%d ", root->val);
	inorderPrint(root->right);

}

void preorderPrint(nodeAddress root){
	if (root == NULL)
        return;
	
	printf("%d ", root->val);
 
	preorderPrint(root->left);
 
	preorderPrint(root->right);
}

void postorderPrint(nodeAddress root){
	if(root == NULL){
		return;
	}

	postorderPrint(root->left);
	postorderPrint(root->right);
	printf("%d ", root->val);
}

nodeAddress arrayToBST(int* a, int n){

	nodeAddress root = create(a[0]);

	for(int count = 1; count<n; count++){
		insertIntoTree(root, a[count]);
	}

	return root;

}

int main(int argc, char const *argv[]){
	
	int a[] = {841, 378, 34, 914, 538, 649, 729, 874, 878};
	int n = 9;

	nodeAddress root = arrayToBST(a,n);

	inorderPrint(root);
	printf("\n");
	postorderPrint(root);
	printf("\n");
	preorderPrint(root);
	printf("\n");
	search(root, 914);
	printf("\n");
	deleteNode(root, 914);
	printf("\n");
	inorderPrint(root);
	return 0;
}