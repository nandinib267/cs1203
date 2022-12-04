#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tree{
    int val;
    struct tree* left;
    struct tree* right;
    int height;
};

typedef struct tree treeNode;
typedef struct tree* NodeAddress;

int findMax(int x, int y){
    if(x >= y){
        return x;
    }
    else{
        return y;
    }
}

NodeAddress findMinimum(NodeAddress root){
    NodeAddress curr = root;
    if(!(curr->left)){
        return curr;
    }

    else{
        return findMinimum(curr->left);
    }
}

treeNode* createNewNode(int n){
    NodeAddress newNode = (NodeAddress)malloc(sizeof(treeNode));

    newNode->val = n;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->height = 1;

    return newNode;
}

int findTreeHeight(NodeAddress root){
    if(!root){
        return 0;
    }
    
    return root->height;
    
}

int deltaHeight(NodeAddress root){
    if(!root){
        return 0;
    }
    
    return (findTreeHeight(root->left) - findTreeHeight(root->right));  
}

NodeAddress rightRotate(NodeAddress root){
    NodeAddress leftChild = root->left;
    NodeAddress rightSubChild = leftChild->right;

    leftChild->right = root;
    root->left = rightSubChild;
    root->height = findMax(findTreeHeight(root->left), findTreeHeight(root->right)) + 1;
    leftChild->height = findMax(findTreeHeight(leftChild->left), findTreeHeight(leftChild->right)) + 1;

    return leftChild;
}

NodeAddress leftRotate(NodeAddress root){
    NodeAddress rightChild = root->right;
    NodeAddress leftSubChild = rightChild->left;

    rightChild->left = root;
    root->right = leftSubChild;
    root->height = findMax(findTreeHeight(root->left), findTreeHeight(root->right)) + 1;
    rightChild->height = findMax(findTreeHeight(rightChild->left), findTreeHeight(rightChild->right)) + 1;

    return rightChild;
}

NodeAddress balTree(NodeAddress root){
    int bal = deltaHeight(root);

    if(deltaHeight(root->left) >= 0&& bal > 1){
        return rightRotate(root);
    }

    if(deltaHeight(root->right) <= 0 && bal < -1 ){
        return leftRotate(root);
    }

    if(deltaHeight(root->left) < 0 && bal > 1){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(deltaHeight(root->right) > 0 && bal < -1){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }


    return root;
}

NodeAddress insert(NodeAddress root, int x){
    if(root == NULL){
        return createNewNode(x);
    }
    else if(x < root->val){
        root->left = insert(root->left, x);
    }
    else if(x > root->val){
        root->right = insert(root->right, x);
    }
    else{
        return root;
    }
    
    root->height = findMax(findTreeHeight(root->left), findTreeHeight(root->right)) + 1;

    return balTree(root);
}

NodeAddress delete(NodeAddress root, int x){
    if(!root){
        return root;
    }
    else if (x > root->val){
        root->right = delete(root->right, x);
    }
    else if (x < root->val){
        root->left = delete(root->left, x);
    }
    else{
        NodeAddress t = NULL;
        if(!(root->left) && !(root->right)){
            free(root);
            return t;
        }
        else if(!(root->left)){
            t = root->right;
            free(root);
            return t;
        }
        else if(!(root->right)){
            t = root->left;
            free(root);
            return t;
        }
        else{
            NodeAddress s = findMinimum(root);
            root->val = s->val;
            free(s);        
            }
    }
}   
    
void printInOrder(NodeAddress root){ //Print the values in left, root, right order
    if(root->left){
        printInOrder(root->left);
    }
    if(root){
        printf("%d, ", root->val);
    }
    if(root->right){
        printInOrder(root->right);
    }
}

NodeAddress createTree(int* a, int n){
    NodeAddress root = NULL;
    if(n > 0){
        root = createNewNode(a[0]);
        for(int i = 1; i < n; i++){
            root = insert(root, a[i]);
        }
    }

    return root;
}

int* createRandomArray(int n){
    int* arr = malloc(n*sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        arr[i] = rand()%1000;
    }
    return arr;
}

int main(int argc, char *argv[]){

    int n = 5;
    int* a = createRandomArray(n);
    
    NodeAddress root = createTree(a, 5);
    printInOrder(root);

    printf("\n");

    insert(root, 5);
    insert(root, 4);
    insert(root, 3);
    printInOrder(root);
    printf("\n");
    delete(root, 4);
    printInOrder(root);
}
