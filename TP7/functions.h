#ifndef functions_h
#define functions_h

void fillArray(int array[], int size);
int findMin(int arr[], int size);
int findMax(int *arr, int size);
int *sortBySmallest(int arr[], int newArray[], int size);
int *sortByBiggest(int arr[], int newArray[], int size);
void bubbleSort(int a[], int size);
void printArray(int arr[], int size);
void insertionSort(int a[], int size);
void measureTime(int arr[], int size, int choice);
void selectionSort(int arr[], int size);

#endif