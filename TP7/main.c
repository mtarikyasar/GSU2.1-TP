#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HUN 100
#define TH 1000
#define TENTH 10000

int main(void){
    int arrHun[HUN];
    int *arrHunStB, *arrHunBtS;
    int arrTh[TH];
    int *arrThStB, *arrThBtS;
    int arrTenTh[TENTH];
    int *arrTenThStB, *arrTenThBtS;
    int choice = 0;
    
    clock_t start;
    clock_t stop;
    double elapsed;
    
    arrHunStB = malloc(HUN*sizeof(int));
    arrHunBtS = malloc(HUN*sizeof(int));
    arrThStB = malloc(TH*sizeof(int));
    arrThBtS = malloc(TH*sizeof(int));
    arrTenThStB = malloc(TENTH*sizeof(int));
    arrTenThBtS = malloc(TENTH*sizeof(int));

    srand(time(NULL));

    fillArray(arrHun, HUN);
    fillArray(arrTh, TH);
    fillArray(arrTenTh, TENTH);

    //Buyukten kucuge dogru
    arrHunBtS = sortByBiggest(arrHun, arrHunBtS, HUN);
    arrThBtS = sortByBiggest(arrTh, arrThBtS, TH);
    arrTenThBtS = sortByBiggest(arrTenTh, arrTenThBtS, TENTH);

    //Kucukten buyuge dogru
    arrHunStB = sortBySmallest(arrHun, arrHunStB, HUN);
    arrThStB = sortBySmallest(arrTh, arrThStB, TH);
    arrTenThStB = sortBySmallest(arrTenTh, arrTenThStB, TENTH);

    while(choice != 8){
        printf("\n[1] Bubble Sort\n");
        printf("[2] Selection Sort\n");
        printf("[3] Insertion Sort\n");
        printf("[4] Quick Sort\n"); //not done yet
        printf("[5] Merge Sort\n");
        printf("[6] Bucket Sort\n"); //not done yet
        printf("[7] Shell Sort\n"); 
        printf("[8] Exit\n");
        printf("Your choice is: ");
        scanf("%d", &choice);

        switch (choice){

        case 1:

            printf("Sorted 100 Number (Smaller to Greater)\n");
            measureTime(arrHunStB, HUN, choice);
            printf("Sorted 100 Number (Greater to Smaller)\n");
            measureTime(arrHunBtS, HUN, choice);
            printf("Unsorted 100 Number\n");
            measureTime(arrHun, HUN, choice);
            
            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 1000 Number (Smaller to Greater)\n");
            measureTime(arrThStB, TH, choice);
            printf("Sorted 1000 Number (Greater to Smaller)\n");
            measureTime(arrThBtS, TH, choice);
            printf("Unsorted 1000 Number\n");
            measureTime(arrTh, TH, choice);

            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 10000 Number (Smaller to Greater)\n");
            measureTime(arrTenThStB, TENTH, choice);
            printf("Sorted 10000 Number (Greater to Smaller)\n");
            measureTime(arrTenThBtS, TENTH, choice);
            printf("Unsorted 10000 Number\n");
            measureTime(arrTenTh, TENTH, choice);

            break;

        case 2:

            printf("Sorted 100 Number (Smaller to Greater)\n");
            measureTime(arrHunStB, HUN, choice);
            printf("Sorted 100 Number (Greater to Smaller)\n");
            measureTime(arrHunBtS, HUN, choice);
            printf("Unsorted 100 Number\n");
            measureTime(arrHun, HUN, choice);
            
            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 1000 Number (Smaller to Greater)\n");
            measureTime(arrThStB, TH, choice);
            printf("Sorted 1000 Number (Greater to Smaller)\n");
            measureTime(arrThBtS, TH, choice);
            printf("Unsorted 1000 Number\n");
            measureTime(arrTh, TH, choice);

            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 10000 Number (Smaller to Greater)\n");
            measureTime(arrTenThStB, TENTH, choice);
            printf("Sorted 10000 Number (Greater to Smaller)\n");
            measureTime(arrTenThBtS, TENTH, choice);
            printf("Unsorted 10000 Number\n");
            measureTime(arrTenTh, TENTH, choice);

            break;

        case 3:
            printf("Sorted 100 Number (Smaller to Greater)\n");
            measureTime(arrHunStB, HUN, choice);
            printf("Sorted 100 Number (Greater to Smaller)\n");
            measureTime(arrHunBtS, HUN, choice);
            printf("Unsorted 100 Number\n");
            measureTime(arrHun, HUN, choice);
            
            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 1000 Number (Smaller to Greater)\n");
            measureTime(arrThStB, TH, choice);
            printf("Sorted 1000 Number (Greater to Smaller)\n");
            measureTime(arrThBtS, TH, choice);
            printf("Unsorted 1000 Number\n");
            measureTime(arrTh, TH, choice);

            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 10000 Number (Smaller to Greater)\n");
            measureTime(arrTenThStB, TENTH, choice);
            printf("Sorted 10000 Number (Greater to Smaller)\n");
            measureTime(arrTenThBtS, TENTH, choice);
            printf("Unsorted 10000 Number\n");
            measureTime(arrTenTh, TENTH, choice);
            break;
        
        case 5:
            printf("Sorted 100 Number (Smaller to Greater)\n");
            measureTime(arrHunStB, HUN, choice);
            printf("Sorted 100 Number (Greater to Smaller)\n");
            measureTime(arrHunBtS, HUN, choice);
            printf("Unsorted 100 Number\n");
            measureTime(arrHun, HUN, choice);
            
            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 1000 Number (Smaller to Greater)\n");
            measureTime(arrThStB, TH, choice);
            printf("Sorted 1000 Number (Greater to Smaller)\n");
            measureTime(arrThBtS, TH, choice);
            printf("Unsorted 1000 Number\n");
            measureTime(arrTh, TH, choice);

            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 10000 Number (Smaller to Greater)\n");
            measureTime(arrTenThStB, TENTH, choice);
            printf("Sorted 10000 Number (Greater to Smaller)\n");
            measureTime(arrTenThBtS, TENTH, choice);
            printf("Unsorted 10000 Number\n");
            measureTime(arrTenTh, TENTH, choice);
            break;

        case 7:
            printf("Sorted 100 Number (Smaller to Greater)\n");
            measureTime(arrHunStB, HUN, choice);
            printf("Sorted 100 Number (Greater to Smaller)\n");
            measureTime(arrHunBtS, HUN, choice);
            printf("Unsorted 100 Number\n");
            measureTime(arrHun, HUN, choice);
            
            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 1000 Number (Smaller to Greater)\n");
            measureTime(arrThStB, TH, choice);
            printf("Sorted 1000 Number (Greater to Smaller)\n");
            measureTime(arrThBtS, TH, choice);
            printf("Unsorted 1000 Number\n");
            measureTime(arrTh, TH, choice);

            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 10000 Number (Smaller to Greater)\n");
            measureTime(arrTenThStB, TENTH, choice);
            printf("Sorted 10000 Number (Greater to Smaller)\n");
            measureTime(arrTenThBtS, TENTH, choice);
            printf("Unsorted 10000 Number\n");
            measureTime(arrTenTh, TENTH, choice);
            break;
        }
    }

    
}