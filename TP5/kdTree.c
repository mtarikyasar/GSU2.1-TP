#include "kdTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Soru 1:
    Elimizdeki tum noktalarin -tercihe bagli olarak- x ya da y noktalarinin ortalamasini alip
    o ortalamaya en yakin olan noktayi root olarak almak agacin dengesi acisinden daha iyi bir sonuc
    verecektir.
*/

tempList *getData(tempList* node){
    node = (tempList*)malloc(sizeof(tempList));

    char lineBuffer[200];
    char lineRead[200];
    char *field;

    FILE *dataFile = fopen("data.txt", "r");

    if(dataFile == NULL){
        printf("File opening error!\n");
    }
    int i = 0;

    while (fgets(lineRead, sizeof(lineRead), dataFile)) {
    //Get index
      field = strtok(lineRead, ",");
      node[i].gateInTemp = *field;
    //Get gate name
      field = strtok(NULL, ",");
      strcpy(node[i].gateNameTemp, field);
    //Get x
      field = strtok(NULL, ",");
      node[i].gateXTemp = atoi(field);
    //Get y
      field = strtok(NULL, ",");
      node[i].gateYTemp = atoi(field);
      i++;
  }

    printf("Gate count: %d\n", i);
    printf("Please remember to input this value in the next step.\n");

    return node;
}

void printDataList(tempList* node, int count){

    for (int i = 0; i < count; i++){
        printf("\nGate Index: %c\n", node[i].gateInTemp);
        printf("Gate Name: %s\n", node[i].gateNameTemp);
        printf("Gate X Value: %d\n", node[i].gateXTemp);
        printf("Gate Y Value: %d\n", node[i].gateYTemp);
    }
}

kdTree *insert(kdTree* tree){
    
	/*if(tree == NULL){
		kdTree *root = (kdTree*)malloc(sizeof(kdTree));
		root -> left = NULL;
		root -> right = NULL;
		root ->  = x;
		return root;
	}
	
	node *iter = tree;
	
	if(iter->data < x){
		tree -> right = insert(tree -> right, x);
		return tree;	
	}
	
	tree->left = insert(tree -> left, x);

	return tree;*/
}

double calculateMeanByX(){
    printf("This function will calculate average of the x values of our datas.\n");


}