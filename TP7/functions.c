#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int *array, int size){
    for (int i = 0; i < size; i++){
        array[i] = i;
    }  
}

void fillArrayReverse(int *array, int size){
    for (int i = 0; i < size; i++){
        array[i] = size-i-1;
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n\n");
}

//Fisher and Yates Algorithm
int *randomize(int *a, int size){
    int *arr;
    arr = malloc(size*sizeof(int));
    srand (time(NULL));

    for (size_t i = 0; i < size; i++){
        arr[i] = a[i];
    }
    
    int temp = 0;
  
    for (int i = size-1; i > 0; i--){ 
        int j = rand() % (i+1); 

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    return arr;
}

void bubbleSort(int *a, int size){
	int temp = 0;

    for (int i = 0; i < size-1; i++){ 
       for (int j = 0; j < size-i-1; j++){
           if (a[j] > a[j+1]){
               temp = a[j];
               a[j] = a[j+1];
               a[j+1] = temp;
           }
       }
    }

}

void insertionSort(int *a, int size){
	int temp = 0;
	int hole = 0;
	for (int i = 1; i < size-1; i++)
	{
		temp = a[i];
		hole = i;

		while(hole>0 && a[hole-1]>temp){
			a[hole] = a[hole-1];
			hole = hole-1;
		}
		a[hole] = temp;
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
        start = clock();
        selectionSort(arr, size);
        stop = clock();
        elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC; printf("\tTime elapsed for Selection Sort (For %d number) in ms: %.5f\n", size, elapsed);
        break;

    case 3:
        start = clock();
        insertionSort(arr, size);
        stop = clock();
        elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC; printf("\tTime elapsed for Insertion Sort (For %d number) in ms: %.5f\n", size, elapsed);
        break;

    case 4:
        start = clock();
        quickSort(arr, size);
        stop = clock();
        elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC; printf("\tTime elapsed for Quick Sort (For %d number) in ms: %.5f\n", size, elapsed);
        break;

    case 5:
        start = clock();
        mergeSort(arr, 0, size-1);
        stop = clock();
        elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC; printf("\tTime elapsed for Merge Sort (For %d number) in ms: %.5f\n", size, elapsed);
        break;

    case 7:
        start = clock();
        shellSort(arr, size);
        stop = clock();
        elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC; printf("\tTime elapsed for Shell Sort (For %d number) in ms: %.5f\n", size, elapsed);
        break;
    }
}

void selectionSort(int arr[], int size){
    int i, j, min, temp;
    int arrCop[size];

    for (int i = 0; i < size; i++){
        arrCop[i] = arr[i];
    }
    

    for(i = 0; i < size; i++){
        min = i;

        for(j = i; j < size; j++){

            if(arrCop[j] < arrCop[min]) {
                min = j;
            }
        }

        temp = arrCop[min];
        arrCop[min] = arrCop[i];
        arrCop[i] = temp;
    }
}

void merge(int *array, int low, int middle, int high){
  int i, j, k;

  int szLeftHalf = middle - low + 1;
  int szRightHalf = (high - middle);

  int arrLeftHalf[szLeftHalf];
  int arrRightHalf[szRightHalf];
  
  for (size_t x = 0; x < szLeftHalf; x++){
    arrLeftHalf[x] = array[low + x];
  }

  for (size_t y = 0; y < szRightHalf; y++){
    arrRightHalf[y] = array[middle + 1 + y];
  }
  
  i = 0;
  j = 0;
  k = low;

  while(i < szLeftHalf && j < szRightHalf){
    if(arrLeftHalf[i] <= arrRightHalf[j]){
      array[k] = arrLeftHalf[i];
      i++;
    }
    else{
      array[k] = arrRightHalf[j];
      j++;
    } 
    k++;
  }
  
    while(i < szLeftHalf){
      array[k] = arrLeftHalf[i];
      i++;
      k++;
    }

    while(j < szRightHalf){
      array[k] = arrRightHalf[j];
      j++;
      k++;
    }
}

void mergeSort(int *array, int low, int high){
  if (low < high) {
    int middle = low + (high-low)/2;

    mergeSort(array, low, middle);
    mergeSort(array, middle+1, high);
    
    merge(array, low, middle, high);
  }
}

void shellSort(int *array, int size){
  int gaps[] = {4193, 1073, 281, 77, 23, 8, 1};
  int i, j, k;
  int sizeGaps = sizeof(gaps)/sizeof(int);

  int h, v;
  for(i = 0; i<sizeGaps; i++){
      h = gaps[i];

      for(j=h; j<size; j++){
        v=array[j];
        k = j;
        while(k>=h && array[k-h]>v){
          array[k] = array[k-h];
          k = k-h;
        }
        array[k] = v;
      }
  }
}

void quickSortWrapper(int *array, int low, int high){
    // TODO
    int p;
    if (low < high) {
        p = partition(array, low, high);
        quickSortWrapper(array, low, p-1);
        quickSortWrapper(array, p+1, high);
    }
}

void quickSort(int *array, int size){
    quickSortWrapper(array, 0, size-1);
}

int partition(int *array, int low, int high){
    int pivot = high;
    int newPivot = low;
    int i;
    int temp = 0;

    for (i = low; i < high; i++){
        if (array[i] < array[pivot]){
            temp = array[i];
            array[i] = array[newPivot];
            array[newPivot] = temp;
            newPivot++;
        }
    }
    temp = array[newPivot];
    array[newPivot] = array[pivot];
    array[pivot] = temp;

    return newPivot;
}

void sortByChoice(int *array1, int *array2, int *array3, int size, int choice){
    printf("\n\nSorted %d Number (Smaller to Greater)\n", size);
    measureTime(array1, size, choice);
    printf("Sorted %d Number (Greater to Smaller)\n", size);
    measureTime(array2, size, choice);
    printf("Unsorted %d Number\n", size);
    measureTime(array3, size, choice);
}