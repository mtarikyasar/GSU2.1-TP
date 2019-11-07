#ifndef kdtree_h
#define kdtree_h

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

tempList *getData(tempList* node);
void printDataList(tempList* node, int count);
kdTree *insert(kdTree* tree);
double calculateMeanByX();

#endif