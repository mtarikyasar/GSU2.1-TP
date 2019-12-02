#ifndef functions_h
#define functions_h

void fillArray(int array[], int size);
void fillArrayReverse(int *arr, int size);
int* randomize (int *arr, int size);
void bubbleSort(int a[], int size);
void printArray(int arr[], int size);
void insertionSort(int a[], int size);
void measureTime(int arr[], int size, int choice);
void selectionSort(int arr[], int size);
void merge(int *array, int low, int middle, int high);
void mergeSort(int *array, int low, int high);
void shellSort(int *array, int size);
void quickSortWrapper(int *array, int low, int high);
void quickSort(int *array, int size);
int partition(int *array, int low, int high);
void sortByChoice(int *array1, int *array2, int *array3, int size, int choice);
void bucketSort(int *arr, int size);
void fastestAlgorithm(int *arr, int size);

#endif