#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int array[], int size){
    for (int i = 0; i < size; i++){
        array[i] = rand()%size;
    }  
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n\n");
}

int findMin(int arr[], int size){
    int min = arr[0];
    int index = 0;

    for (int i = 0; i < size; i++){
        if (arr[i] < min){
            min = arr[i];
            index = i;
        }
    }

    arr[index] = size+1;
    return min;
}

int findMax(int *arr, int size){
    int max = arr[0];
    int index = 0;

    for (int i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
            index = i;
        }
    }

    arr[index] = size*(-1);
    return max;
}

int *sortBySmallest(int arr[], int newArray[], int size){
    int arrCop[size];

    for (int i = 0; i < size; i++){
        arrCop[i] = arr[i];
    }

    for (int i = 0; i < size; i++){
        newArray[i] = findMin(arrCop, size);
    }

    return newArray;
}

int *sortByBiggest(int arr[], int newArray[], int size){
    int arrCop[size];

    for (int i = 0; i < size; i++){
        arrCop[i] = arr[i];
    }

    for (int i = 0; i < size; i++){
        newArray[i] = findMax(arrCop, size);
    }
    
    return newArray;
}

void bubbleSort(int a[], int size){
    int arrCop[size];

    for (int i = 0; i < size; i++){
        arrCop[i] = a[i];
    }
    
	int temp = 0;

    for (int i = 0; i < size-1; i++){ 
       for (int j = 0; j < size-i-1; j++){
           if (arrCop[j] > arrCop[j+1]){
               temp = arrCop[j];
               arrCop[j] = arrCop[j+1];
               arrCop[j+1] = temp;
           }
       }
    }

}

void insertionSort(int a[], int size){
    int arrCop[size];

    for (int i = 0; i < size; i++){
        arrCop[i] = a[i];
    }
    
	int temp = 0;
	int hole = 0;
	for (int i = 1; i < size-1; i++)
	{
		temp = arrCop[i];
		hole = i;

		while(hole>0 && arrCop[hole-1]>temp){
			arrCop[hole] = arrCop[hole-1];
			hole = hole-1;
		}
		arrCop[hole] = temp;
	}
}

void measureTime(int arr[], int size, int choice){
    clock_t start;
    clock_t stop;
    double elapsed = 0;

    switch (choice)
    {
    case 1:
        start = clock();
        bubbleSort(arr, size);
        stop = clock();
        elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC; printf("\tTime elapsed for Bubble Sort (For %d number) in ms: %.5f\n", size, elapsed);
        break;
    
    case 2:

    case 3:
        start = clock();
        insertionSort(arr, size);
        stop = clock();
        elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC; printf("\tTime elapsed for Insertion Sort (For %d number) in ms: %.5f\n", size, elapsed);
        break;
    
    }
}