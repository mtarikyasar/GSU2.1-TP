#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n{
	char country[25];
	int code;
	struct n* left;
	struct n* right;
}node;

node *insert(node* tree){
	node* newNode = (node*)malloc(sizeof(node));
	printf("Enter the country: ");
	scanf("%s", newNode->country);
	printf("Enter the code: ");
	scanf("%d", &newNode->code);
	newNode->left = NULL;
	newNode->right = NULL;
	
	if(tree == NULL){
		node *root = (node*)malloc(sizeof(node));
		root = newNode;	
		return root;
	}
	
	node *iter = tree;
	
	if(iter->code < newNode->code){
		tree -> right = insert(tree -> right);
		return tree;	
	}
	
	tree -> left = insert(tree -> left);	

	return tree;
}

void travers(node *tree){
	if(tree == NULL) return;
	printf("[%s, %d]\n",tree->country, tree->code);
	travers(tree->right);
	travers(tree->left);
}

int main(void){
	node *tree = NULL;
	int choice = 0;

	while(choice != 3){
		printf("[1] Add Data\n");
		printf("[2] Print Tree\n");
		printf("[3] Exit\n");
		printf("Make your choice, let the game begin: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				tree = insert(tree);
				break;
			case 2:
				travers(tree);
				break;
			case 3:
				break;
		}
	}
}
