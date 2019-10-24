#include "avlTree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("\n\n~~~PDF'teki Soru 7 icin 0'a basiniz~~~\n\n");
    int x = 0;
    int y = 0;
    int choice = 0;

    node *tree = NULL;

    while(choice != 9){
        printf("\nWelcome to the AVL Tree Application!\n");
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
            case 0:
                //Secret case for PDF
                //Adding numbers 10,20,30,40,50,25
                printf("Adding 10...\n");
                tree = insertAVL(tree, 10);
                printf("Adding 20...\n");
                tree = insertAVL(tree, 20);
                printf("Adding 30...\n");
                tree = insertAVL(tree, 30);
                printf("Adding 40...\n");
                tree = insertAVL(tree, 40);
                printf("Adding 50...\n");
                tree = insertAVL(tree, 50);
                printf("Adding 25...\n");
                tree = insertAVL(tree, 25);
                //Printing tree in level order
                levelorderPrint(tree);
                printf("Deleting number 40...\n");
                //Deleting 40
                tree = deleteNodeAVL(tree, 40);
                levelorderPrint(tree);
                //Printing tree in level order
                printf("Deleting number 20...\n");
                //Deleting 20
                tree = deleteNodeAVL(tree, 20);
                //Printing tree in level order
                levelorderPrint(tree);
                printf("Deleting number 25...\n");
                //Deleting 25
                tree = deleteNodeAVL(tree, 25);
                //Printing tree in level order
                levelorderPrint(tree);
                break;

            case 1:
                printf("Enter the number you want to add: ");
                scanf("%d", &x);
                tree = insertAVL(tree, x);
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
                printf("Enter the number you want to delete: ");
                scanf("%d", &y);
                tree = deleteNodeAVL(tree, y);

            case 9:
                break;
        }
    }
}