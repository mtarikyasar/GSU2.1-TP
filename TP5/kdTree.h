#ifndef kdtree_h
#define kdtree_h
#include <stdio.h>

//Data dosyasinden verileri cekmek icin kullanilan bir struct
typedef struct temp{
    char gateInTemp;
    char gateNameTemp[50];
    int gateXTemp;
    int gateYTemp;
}tempList;

typedef struct node{
    char gateIn;
    char gateName[50];
    int gateX;
    int gateY;
    struct node* left;
    struct node* right;
}kdTree;

int countCalculator(tempList* node);
int getLevelUtil(kdTree *node, int x, int y, int level);
int getLevel(kdTree *node, int x, int y);
kdTree *createTree(kdTree *node, char* name, char index, int x, int y);
tempList *getData(tempList* node);
void printDataList(tempList* node, int count);
kdTree *insert(kdTree* tree, char index, char *name, int x, int y);
kdTree *initTree(kdTree *node, int count, int choiceRoot);
int heightOfTree(kdTree *tree);
void inorderPrint(kdTree *tree);
void preorderPrint(kdTree *tree);
void postorderPrint(kdTree *tree);
void searchIndex(kdTree *tree, char searchValue);
void searchPort(kdTree* tree, char *name);
kdTree *killTree(kdTree* tree);
double findMin(double *list, int count);
double findMin2(double *arr, int size);
void getDistances(kdTree* tree, int x, int y, FILE *dataFile);
void searchCoordinate(kdTree* tree, int x, int y, char *filename, int count);

#endif