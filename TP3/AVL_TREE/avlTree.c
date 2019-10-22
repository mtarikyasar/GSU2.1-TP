#include "avlTree.h"
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    if(a >= b) return a;
    else return b;
}

int heightOfTree(node *tree){
    if (tree == NULL)  
        return 0;  
    return tree->height;
}

node* rightRotateAVL(node *tree){
    node *iter = tree->left;
    node *temp = iter->right;

    iter->right = tree;
    tree->left = temp;

    tree->height = max(heightOfTree(tree->left), heightOfTree(tree->right)) + 1;
    iter->height = max(heightOfTree(iter->left), heightOfTree(iter->right)) + 1;

    return iter;
}

node* leftRotateAVL(node *tree){
    node *iter = tree->right;
    node *temp = iter->left;

    iter->left = tree;
    tree->right = temp;

    tree->height = max(heightOfTree(tree->left), heightOfTree(tree->right)) + 1;
    iter->height = max(heightOfTree(iter->left), heightOfTree(iter->right)) + 1;

    return iter;
}

node* insertAVL(node *tree, int x){
    int balance = 0;

    if(tree == NULL){
		node *root = (node*)malloc(sizeof(node));
		root->left = NULL;
		root->right = NULL;
		root->data = x;
        root->height = 1;
		return root;
	}


    if(x < tree->data){
        tree->left = insertAVL(tree->left, x);
    }

    else if(x > tree->data){
        tree->right = insertAVL(tree->right, x);
    }

    else return tree;

    tree->height = max(heightOfTree(tree->left), heightOfTree(tree->right)) + 1;

    balance = (heightOfTree(tree->left)- heightOfTree(tree->right));

    //L-L Case
    if(balance > 1 && x < tree->left->data){
        return rightRotateAVL(tree);
    }

    //R-R Case
    if(balance < -1 && x > tree->right->data){
        return leftRotateAVL(tree);
    }

    //L-R Case
    if(balance > 1 && x > tree->left->data){
        tree->left = leftRotateAVL(tree->left);
        return rightRotateAVL(tree);
    }

    //R-L Case
    if(balance < -1 && x < tree->right->data){
        tree->right = rightRotateAVL(tree->right);
        return leftRotateAVL(tree);
    }

    return tree;
}

node *deleteNodeAVL(node *tree, int x){
    int balance = 0;

    if(tree == NULL){
        return NULL;
    }

    if(tree->data == x){
        if(tree->left == NULL && tree->right == NULL){
            return NULL;
        }

        if(tree->right != NULL){
            tree->data = findMin(tree->right);
            tree->right = deleteNodeAVL(tree->right, findMin(tree->right));
            return tree;
        }

        tree->data = findMax(tree->left);
        tree->left = deleteNodeAVL(tree->left, findMax(tree->left));
        return tree;
    }

    if(tree->data < x){
        tree->right = deleteNodeAVL(tree->right, x);
        return tree;
    }

    tree->left = deleteNodeAVL(tree->left, x);

    balance = heightOfTree(tree->left) - heightOfTree(tree->right);

    //L-L Case
    if(balance > 1 && x < tree->left->data){
        return rightRotateAVL(tree);
    }

    //R-R Case
    if(balance < -1 && x > tree->right->data){
        return leftRotateAVL(tree);
    }

    //L-R Case
    if(balance > 1 && x > tree->left->data){
        tree->left = leftRotateAVL(tree->left);
        return rightRotateAVL(tree);
    }

    //R-L Case
    if(balance < -1 && x < tree->right->data){
        tree->right = rightRotateAVL(tree->right);
        return leftRotateAVL(tree);
    }
    
    return tree;
}

int findMin(node *tree){
	if(tree == NULL){
		printf("ERROR! There is no element on the tree.\n");
        return 0;
	}

	node *iter = tree;

	while(iter->left != NULL){
		iter = iter->left;
	}

	return iter->data;
}

int findMax(node *tree){
	if(tree == NULL){
		printf("ERROR! There is no element on the tree.\n");
        return 0;
	}

	node *iter = tree;

	while(iter->right != NULL){
		iter = iter->right;
	}

	return iter->data;
}

void inorderPrint(node *tree){
    if(tree == NULL){
        return;
    }

    inorderPrint(tree->left);
    printf("%d ", tree->data);
    inorderPrint(tree->right);
}

void preorderPrint(node *tree){
    if(tree == NULL){
        return;
    }

    printf("%d ", tree->data);
    preorderPrint(tree->left);
    preorderPrint(tree->right);
}

void postorderPrint(node *tree){
    if(tree == NULL){
        return;
    }

    postorderPrint(tree->left);
    postorderPrint(tree->right);
    printf("%d ", tree->data);
}

void printCurrentLevel(node *tree, int level){
    if(tree == NULL){
        return;
    }

    if(level == 1){ 
        printf("%d ", tree->data);
    } 

    else if(level > 1) { 
        printCurrentLevel(tree->left, level-1); 
        printCurrentLevel(tree->right, level-1); 
    } 
}

void levelorderPrint(node *tree){
    int height = heightOfTree(tree);

    for (int i = 0; i <= height; i++){
        printCurrentLevel(tree, i);
        printf("\n");
    }
}