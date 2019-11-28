#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int arrHun[100];
    int *arrHunStB, *arrHunBtS;
    int arrTh[1000];
    int *arrThStB, *arrThBtS;
    int arrTenTh[10000];
    int *arrTenThStB, *arrTenThBtS;
    int choice = 0;
    
    clock_t start;
    clock_t stop;
    double elapsed;
    
    arrHunStB = malloc(100*sizeof(int));
    arrHunBtS = malloc(100*sizeof(int));
    arrThStB = malloc(1000*sizeof(int));
    arrThBtS = malloc(1000*sizeof(int));
    arrTenThStB = malloc(10000*sizeof(int));
    arrTenThBtS = malloc(10000*sizeof(int));

    srand(time(NULL));

    fillArray(arrHun, 100);
    fillArray(arrTh, 1000);
    fillArray(arrTenTh, 10000);

    //Buyukten kucuge dogru
    arrHunBtS = sortByBiggest(arrHun, arrHunBtS, 100);
    arrThBtS = sortByBiggest(arrTh, arrThBtS, 1000);
    arrTenThBtS = sortByBiggest(arrTenTh, arrTenThBtS, 10000);

    //Kucukten buyuge dogru
    arrHunStB = sortBySmallest(arrHun, arrHunStB, 100);
    arrThStB = sortBySmallest(arrTh, arrThStB, 1000);
    arrTenThStB = sortBySmallest(arrTenTh, arrTenThStB, 10000);

    while(choice != 8){
        printf("\n[1] Bubble Sort\n");
        printf("[2] Selection Sort\n");
        printf("[3] Insertion Sort\n");
        printf("[4] Quick Sort\n");
        printf("[5] Merge Sort\n");
        printf("[6] Bucker Sort\n");
        printf("[7] Shell Sort\n");
        printf("[8] Exit\n");
        printf("Your choice is: ");
        scanf("%d", &choice);

        switch (choice){

        case 1:

            printf("Sorted 100 Number (Smaller to Greater)\n");
            measureTime(arrHunStB, 100, 1);
            printf("Sorted 100 Number (Greater to Smaller)\n");
            measureTime(arrHunBtS, 100, 1);
            printf("Unsorted 100 Number\n");
            measureTime(arrHun, 100, 1);
            
            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 1000 Number (Smaller to Greater)\n");
            measureTime(arrThStB, 1000, 1);
            printf("Sorted 1000 Number (Greater to Smaller)\n");
            measureTime(arrThBtS, 1000, 1);
            printf("Unsorted 1000 Number\n");
            measureTime(arrTh, 1000, 1);

            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 10000 Number (Smaller to Greater)\n");
            measureTime(arrTenThStB, 10000, 2);
            printf("Sorted 10000 Number (Greater to Smaller)\n");
            measureTime(arrTenThBtS, 10000, 2);
            printf("Unsorted 1000 Number\n");
            measureTime(arrTenTh, 10000, 2);

            break;

        case 3:
            printf("Sorted 100 Number (Smaller to Greater)\n");
            measureTime(arrHunStB, 100, 2);
            printf("Sorted 100 Number (Greater to Smaller)\n");
            measureTime(arrHunBtS, 100, 2);
            printf("Unsorted 100 Number\n");
            measureTime(arrHun, 100, 2);
            
            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 1000 Number (Smaller to Greater)\n");
            measureTime(arrThStB, 1000, 2);
            printf("Sorted 1000 Number (Greater to Smaller)\n");
            measureTime(arrThBtS, 1000, 2);
            printf("Unsorted 1000 Number\n");
            measureTime(arrTh, 1000, 2);

            ////////////////////////////////////
            
            printf("\n\n");
            printf("Sorted 10000 Number (Smaller to Greater)\n");
            measureTime(arrTenThStB, 10000, 2);
            printf("Sorted 10000 Number (Greater to Smaller)\n");
            measureTime(arrTenThBtS, 10000, 2);
            printf("Unsorted 1000 Number\n");
            measureTime(arrTenTh, 10000, 2);
            break;
        
        }
    }

    
}