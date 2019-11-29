#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HUN 100
#define TH 1000
#define TENTH 10000

int main(void){
    int *arrHun, *arrHunStB, *arrHunBtS;
    int *arrTh, *arrThStB, *arrThBtS;
    int *arrTenTh, *arrTenThStB, *arrTenThBtS;
    int choice = 0;
    
    arrHun = malloc(HUN*sizeof(int));
    arrHunStB = malloc(HUN*sizeof(int));
    arrHunBtS = malloc(HUN*sizeof(int));
    arrTh = malloc(TH*sizeof(int));
    arrThStB = malloc(TH*sizeof(int));
    arrThBtS = malloc(TH*sizeof(int));
    arrTenTh = malloc(TENTH*sizeof(int));
    arrTenThStB = malloc(TENTH*sizeof(int));
    arrTenThBtS = malloc(TENTH*sizeof(int));

    fillArray(arrHunStB, HUN);
    fillArrayReverse(arrHunBtS, HUN);
    arrHun = randomize(arrHunStB, HUN);

    fillArray(arrThStB, TH);
    fillArrayReverse(arrThBtS, TH);
    arrTh = randomize(arrThStB, TH);

    fillArray(arrTenThStB, TENTH);
    fillArrayReverse(arrTenThBtS, TENTH);
    arrTenTh = randomize(arrTenThStB, TENTH);

    while(choice != 8){
        
        printf("\n[1] Bubble Sort\n");
        printf("[2] Selection Sort\n");
        printf("[3] Insertion Sort\n");
        printf("[4] Quick Sort\n");
        printf("[5] Merge Sort\n");
        printf("[6] Bucket Sort\n"); //not done yet
        printf("[7] Shell Sort\n"); 
        printf("[8] Exit\n");
        printf("Your choice is: ");
        scanf("%d", &choice);

        sortByChoice(arrHunStB, arrHunBtS, arrHun, HUN, choice);
        ////////////////////////////////////
        sortByChoice(arrThStB, arrThBtS, arrTh, TH, choice);
        ////////////////////////////////////
        sortByChoice(arrTenThStB, arrTenThBtS, arrTenTh, TENTH, choice);
        }

    free(arrHun);
    free(arrHunStB);
    free(arrHunBtS);
    free(arrTh);
    free(arrThStB);
    free(arrThBtS);
    free(arrTenTh);
    free(arrTenThStB);
    free(arrTenThBtS);
}