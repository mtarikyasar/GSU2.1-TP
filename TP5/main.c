#include "kdTree.h"
#include <stdio.h>

int main(void){
    int count = 0;
    tempList* liste;
    liste = getData(liste);
    printf("Please input the count: ");
    scanf("%d", &count);
    printDataList(liste, count);
}