#include "kdTree.h"
#include <stdio.h>

int main(void){
    printf("WARNING! Please do not forget to initialize before using other options!\n");
    int choice = 0;
    int choiceRoot = 0;
    char in;
    char name[50];
    kdTree *root;
    tempList* liste;
    int count = countCalculator(liste);
    int x = 0, y = 0;
    double distanceList[count];

    while(choice != 8){
        
        printf("\n[1] Initialize Tree.\n");
        printf("[2] Search gate by index.\n");
        printf("[3] Search gate by name.\n");
        printf("[4] The nearest gate by coordinates.\n");
        printf("[5] Print tree inorder.\n");
        printf("[6] Kill tree.\n");
        printf("[7] Soru 13\n");

        printf("Please make your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Input 0 for normal insertion and 1 for question 11: ");
                scanf("%d", &choiceRoot);
                printf("Initializing tree...\n");
                root = initTree(root, count, choiceRoot);
                printf("Tree initalized successfully.\n");
                break;

            case 2:
                printf("Enter a letter from A to T: ");
                scanf(" %c", &in);
                searchIndex(root, in);
                break;

            case 3:
                printf("Enter name of the gate: ");
                scanf("%s", name);
                searchPort(root, name);
                break;

            case 4:
                printf("Enter a x value: ");
                scanf("%d", &x);
                printf("Enter a y value: ");
                scanf("%d", &y);
                printf("\nThe nearest gate is: \n");
                searchCoordinate(root, x, y, "distances.txt", count);
                break;

            case 5:
                printf("Printing tree inorder...\n");
                inorderPrint(root);
                break;


            case 6:
                root = killTree(root);
                break;

            case 7:
                printf("\n\n");
                searchCoordinate(root, 25, 25, "distances.txt", count);
                searchCoordinate(root, 14, 34, "distances.txt", count);
                searchCoordinate(root, 5, 27, "distances.txt", count);
                break;
                
                
        }
    }
}