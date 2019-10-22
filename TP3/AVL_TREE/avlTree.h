#ifndef avltree_h
#define avltree_h

typedef struct n{
    int data;
    struct n *left;
    struct n *right;
    int height;
}node;

int max(int a, int b);
node* leftRotateAVL(node *tree);
node* rightRotateAVL(node *tree);
node* deleteNodeAVL(node *tree, int x);
node* insertAVL(node *tree, int x);
int heightOfTree(node *tree);

//Functions from binary tree code
int findMin(node *tree);
int findMax(node *tree);
void preorderPrint(node *tree);
void inorderPrint(node *tree);
void postorderPrint(node *tree);
void printCurrentLevel(node *tree, int level);
void levelorderPrint(node *tree);

#endif