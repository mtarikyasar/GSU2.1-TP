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

kdTree *createTree(kdTree *node, char* name, char index, int x, int y){

    node = (kdTree*)malloc(sizeof(kdTree));
    node->gateIn = index;
    node->gateX = x;
    node->gateY = y;
    strcpy(node->gateName, name);
    node->left = NULL;
    node->right = NULL;

  return node;
}

int getLevelUtil(kdTree *node, int x, int y, int level){ 
    if (node == NULL) 
        return 0; 
  
    if (node->gateX == x && node->gateY == y){ 
        return level; 
    }

    int downlevel = getLevelUtil(node->left, x, y, level+1); 
    if (downlevel != 0) 
        return downlevel; 
  
    downlevel = getLevelUtil(node->right, x, y, level+1); 
    return downlevel; 
} 

int getLevel(kdTree *node, int x, int y){ 
    return getLevelUtil(node,x, y, 1); 
} 

int countCalculator(tempList* node){
  FILE *dataFile = fopen("data.txt", "r");
  
  if(dataFile == NULL){
    printf("File opening error!\n");
  }
  int i = 0;
  char lineRead[200];

  while(fgets(lineRead, sizeof(lineRead), dataFile)){
    i++;
  }

  fclose(dataFile);

  return i;
}

tempList *getData(tempList* node){
    node = (tempList*)malloc(sizeof(tempList));

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
    fclose(dataFile);

    printf("Gate count: %d\n", i);

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

int heightOfTree(kdTree *tree){
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

kdTree *insert(kdTree* tree, char index, char *name, int x, int y){
  int height = 0;
	if(tree == NULL){
		kdTree *root = (kdTree*)malloc(sizeof(kdTree));
		root->left = NULL;
		root->right = NULL;
    root->gateIn = index;
    strcpy(root->gateName, name);
		root->gateX = x;
    root->gateY = y;
		return root;
	}
	
	kdTree *iter = tree;

  if((height=getLevel(iter, iter->gateX, iter->gateY)) % 2 == 1){

	if(iter->gateX <= x){
		tree -> right = insert(tree -> right, index, name, x, y);
		return tree;	
	}

	tree->left = insert(tree -> left, index, name, x, y);
  }

  else if((height=getLevel(iter, iter->gateX, iter->gateY)) % 2 == 0){
    if(iter->gateY <= y){
		  tree -> right = insert(tree -> right, index, name, x, y);
		  return tree;	
	  }

	  tree->left = insert(tree -> left, index, name, x, y);
  }

	return tree;
}

kdTree *initTree(kdTree *node, int count, int choiceRoot){
  
  //Aslinda burada yazdigim getData fonksiyonuyla
  //.txt dosyasindan aldigim bilgileri for'la girmeyi
  //amaclamistim ama bir turlu calistiramadim fonksiyonu
  //O yuzden mecburen boyle amalelik yaptim
  if(choiceRoot == 0){
    node = createTree(node, "Oruculer", 'A', 16, 43);
    node = insert(node, 'B', "CebeciHan", 5, 33);
    node = insert(node, 'C', "Lutfullah", 4, 22);
    node = insert(node, 'D', "Yorgancilar", 6, 17);
    node = insert(node, 'E', "BodrumHan", 3, 10);
    node = insert(node, 'F', "Fesciler", 4, 5);
    node = insert(node, 'G', "HaciHusnu", 4, 4);
    node = insert(node, 'H', "Beyazit", 5, 2);
    node = insert(node, 'I', "CarsiKapi", 16, 3);
    node = insert(node, 'J', "SorgucluHan", 25, 2);
    node = insert(node, 'K', "Merdivenli", 32, 3);
    node = insert(node, 'L', "Kurkculer", 39, 2);
    node = insert(node, 'M', "Nuruosmaniye", 46, 7);
    node = insert(node, 'N', "SandalBedesteni", 45, 13);
    node = insert(node, 'O', "Kilitciler", 45, 17);
    node = insert(node, 'P', "MahmutPasa", 44, 24);
    node = insert(node, 'R', "Mercan", 32, 29);
    node = insert(node, 'S', "Taciler", 26, 31);
    node = insert(node, 'T', "CevahirBedesteniMerkez", 28, 16);
  }

  if(choiceRoot == 1){
    node = createTree(node, "BodrumHan", 'E', 3, 10);
    node = insert(node, 'T', "CevahirBedesteniMerkez", 28, 16);
    node = insert(node, 'H', "Beyazit", 5, 2);
    node = insert(node, 'I', "CarsiKapi", 16, 3);
    node = insert(node, 'D', "Yorgancilar", 6, 17);
    node = insert(node, 'A', "Oruculer", 16, 43);
    node = insert(node, 'B', "CebeciHan", 5, 33);
    node = insert(node, 'C', "Lutfullah", 4, 22);
    node = insert(node, 'R', "Mercan", 32, 29);
    node = insert(node, 'L', "Kurkculer", 39, 2);
    node = insert(node, 'S', "Taciler", 26, 31);
    node = insert(node, 'P', "MahmutPasa", 44, 24);
    node = insert(node, 'O', "Kilitciler", 45, 17);
    node = insert(node, 'K', "Merdivenli", 32, 3);
    node = insert(node, 'M', "Nuruosmaniye", 46, 7);
    node = insert(node, 'G', "HaciHusnu", 4, 4);
    node = insert(node, 'F', "Fesciler", 4, 5);
    node = insert(node, 'N', "SandalBedesteni", 45, 13);
    //Bu pdf'te yoktu ben de en son eklendigini farz ettim
    node = insert(node, 'J', "SorgucluHan", 25, 2);
  }
  /*for (int i = 1; i < count; i++){
    strcpy(name, list[i].gateNameTemp);
    index = list[i].gateInTemp;
    x = list[i].gateXTemp;
    y = list[i].gateYTemp;
    node = insert(node, index, name, x, y);
  }*/

  return node;
}

void inorderPrint(kdTree *tree){
    if(tree == NULL) return;

    inorderPrint(tree->left);
    printf("%c - ", tree->gateIn);
    inorderPrint(tree->right);
}

void preorderPrint(kdTree *tree){
    if(tree == NULL) return;

    printf("%c - ", tree->gateIn);
    preorderPrint(tree->left);
    preorderPrint(tree->right);
}

void postorderPrint(kdTree *tree){
    if(tree == NULL) return;

    postorderPrint(tree->left);
    postorderPrint(tree->right);
    printf("%c - ", tree->gateIn);
}

void searchIndex(kdTree* tree, char searchValue){
  if(tree == NULL) return;

  if(tree->gateIn == searchValue){
    printf("Index: %c\nName: %s\nX: %d\nY: %d\n\n", tree->gateIn, tree->gateName, tree->gateX, tree->gateY);
    return;
  }
  
  searchIndex(tree->left, searchValue);
  searchIndex(tree->right, searchValue);
}

void searchPort(kdTree* tree, char *name){
  if(tree == NULL) return;

  if(strcmp(tree->gateName, name) == 0){
    printf("Index: %c\nName: %s\nX: %d\nY: %d\n\n", tree->gateIn, tree->gateName, tree->gateX, tree->gateY);
    return;
  }

  searchPort(tree->left, name);
  searchPort(tree->right, name);
}

kdTree *killTree(kdTree* tree){
  tree = NULL;

  return tree;
}

double findMin(double *list, int count){
  double min = list[0];

  for (int i = 0; i < count; i++){
    if(list[i] < min)
      min = list[i];
  }
  
  return min;
}

double findMin2(double *arr, int size){
    double min = findMin(arr, size);
    double min2 = arr[(rand()%(size-1)) + 1];
    //burada rand fonksiyonunu kullanmamin sebebi
    //dizideki minimum sayiyi yanlislikla min2'ye
    //atama olasiligini en aza indirmek. 

    for (int i = 0; i < size; i++){
        if (arr[i] < min2 && arr[i] > min){
            min2 = arr[i];
        }
    }
    
    return min2;
}

//Sonuclari inorderPrint fonksiyonu ile ayni sirada basar
void getDistances(kdTree* tree, int x, int y, FILE* dataFile){

  if(tree == NULL) return;

    getDistances(tree->left, x, y, dataFile);
    fprintf(dataFile, "%c,%.2lf\n", tree->gateIn, sqrt((pow(x - tree->gateX, 2) + pow(y - tree->gateY, 2))));
    getDistances(tree->right, x, y, dataFile);
}

void searchCoordinate(kdTree* tree, int x, int y, char* filename, int count){
  char indexList[count];
  char lineRead[100];
  char *field;
  double distanceList[count];
  double min = 0;
  int i = 0;
  int index = 0;

  FILE *dataFile = fopen(filename, "w");

  if(dataFile == NULL)
    printf("File opening error!\n");

  getDistances(tree, x, y, dataFile);
  fclose(dataFile);

  FILE *newFile = fopen(filename, "r");

  if(newFile == NULL)
    printf("File opening error!\n");

  while(fgets(lineRead, sizeof(lineRead), newFile)){
    field = strtok(lineRead, ",");
    indexList[i] = *field;

    field = strtok(NULL, ",");
    distanceList[i] = atoi(field);

    i++;
  }

  min = findMin(distanceList, count);
  if(min == 0)
    min = findMin2(distanceList, count);

    for (int i = 0; i < count; i++){
      if(min == distanceList[i]){
          index = i;
          break;
      }
    }

  searchIndex(tree, indexList[index]);

  fclose(newFile);
}
