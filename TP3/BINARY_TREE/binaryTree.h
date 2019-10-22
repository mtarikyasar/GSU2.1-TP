#ifndef binarytree_h
#define binarytree_h

typedef struct n{
	int data;
	struct n* left;
	struct n* right;
}node;

node *insert(node* tree, int x);
node *deleteNode(node *tree, int x);
void travers(node *tree);
int findMin(node *tree);
int findMax(node *tree);
void preorderPrint(node *tree);
void inorderPrint(node *tree);
void postorderPrint(node *tree);
void levelorderPrint(node *tree);
int heightOfTree(node *tree);
void printCurrentLevel(node *tree, int level);

#endif