#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

int main(void){
	node *tree = NULL;
	int choice = 0;
	int x = 0;
	int y = 0;

	while(choice != 9){
		printf("\nWelcome to the Binary Tree Application!\n");
		printf("[1]Add number\n");
		printf("[2]Find smallest number\n");
		printf("[3]Find biggest number\n");
		printf("[4]Print list preorder\n");
		printf("[5]Print list inorder\n");
		printf("[6]Print list postorder\n");
		printf("[7]Print list levelorder\n");
		printf("[8]Delete number from tree\n");
		printf("[9]Exit\n");
		printf("Please make your choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 0://Secret case for testing
				tree = insert(tree, 12);  
				tree = insert(tree, 200);  
				tree = insert(tree, 190);  
				tree = insert(tree, 213);  
				tree = insert(tree, 56);  
				tree = insert(tree, 24);  
				tree = insert(tree, 18);  
				tree = insert(tree, 27);  
				tree = insert(tree, 28);
				tree = insert(tree, 2);
				tree = insert(tree, 15);
				tree = insert(tree, 53);
				tree = insert(tree, 312);
				break;

			case 1:
				printf("Enter the number that you want to add: ");
				scanf("%d", &x);
				tree = insert(tree, x);
				break;

			case 2:
				printf("\nSmallest number: %d\n", findMin(tree));
				break;
			
			case 3:
				printf("\nBiggest number: %d\n", findMax(tree));
				break;

			case 4:
				printf("\nPrinting list in preorder...\n[");
				preorderPrint(tree);
				printf("]\n");
				break;

			case 5:
				printf("\nPrinting list in inorder...\n[");
				inorderPrint(tree);
				printf("]\n");
				break;

			case 6:
				printf("\nPrinting list in postorder...\n[");
				postorderPrint(tree);
				printf("]\n");
				break;

			case 7:
				printf("Height: %d\n", heightOfTree(tree));
				printf("\nPrinting list in levelorder...\n");
				levelorderPrint(tree);
				break;
			
			case 8:
				printf("Enter the number that you want to delete: ");
				scanf("%d", &y);
				tree = deleteNode(tree, y);
				break;

			case 9:
				break;
		}
	}

}
