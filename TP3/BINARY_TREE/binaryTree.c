#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

node *insert(node* tree, int x){
	if(tree == NULL){
		node *root = (node*)malloc(sizeof(node));
		root -> left = NULL;
		root -> right = NULL;
		root -> data = x;
		return root;
	}
	
	node *iter = tree;
	
	if(iter->data < x){
		tree -> right = insert(tree -> right, x);
		return tree;	
	}
	
	tree->left = insert(tree -> left, x);	

	return tree;
}

node *deleteNode(node *tree, int x){
    if(tree == NULL){
        return NULL;
    }

    if(tree->data == x){
        if(tree->left == NULL && tree->right == NULL){
            return NULL;
        }

        if(tree->right != NULL){
            tree->data = findMin(tree->right);
            tree->right = deleteNode(tree->right, findMin(tree->right));
            return tree;
        }

        tree->data = findMax(tree->left);
        tree->left = deleteNode(tree->left, findMax(tree->left));
        return tree;
    }

    if(tree->data < x){
        tree->right = deleteNode(tree->right, x);
        return tree;
    }

    tree->left = deleteNode(tree->left, x);
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

void travers(node *tree){
	if(tree == NULL) return;
	travers(tree->left);
	printf("%d  ", tree->data);
	travers(tree->right);
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

int heightOfTree(node *tree){
    if(tree ==NULL){
        return 0;
    }

   else{ 
       int lD = heightOfTree(tree->left); 
       int rD = heightOfTree(tree->right); 
  
       if(lD > rD){
           return(lD+1);
       }

       else return(rD+1); 
   }
}

void printCurrentLevel(node *tree, int level){
    if(tree == NULL){
        return;
    }

    if(level == 1){ 
        printf("%d ", tree->data);
    } 

    else if(level > 1){ 
        printCurrentLevel(tree->left, level-1); 
        printCurrentLevel(tree->right, level-1); 
    } 
}

void levelorderPrint(node *tree){
    int height = heightOfTree(tree);

    for(int i = 0; i <= height; i++){
        printCurrentLevel(tree, i);
        printf("\n");
    }
}