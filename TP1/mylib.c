#include "mylib.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int isLetter(char c){ //Tested
    int x = c;

    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')){
        return 1;
    }
    
    else return 0;
}

int isDigit(char c){ //Tested
    int x = c;

    if (x >= '0' && x <= '9'){
        return 1;
    }

    else return 0;  
}

int isEven(int x){ //Tested
    if (x % 2 == 0 || x == 0){
        return 1;
    }

    else return 0;
}

void isPrime(int x){ //Tested
    int flag = 0;
    if(x < 2){
        printf("%d is not a prime number.\n", x);
        return;
    }

    else if(x == 2){
        printf("%d is a prime number.\n", x);
        return;
    }

    else if(x > 2){
        int y = x/2;

        for (int i = 2; i < y+1; i++){
            if(x % i == 0){
                printf("%d is not a prime number.\n", x);
                flag = 1;
                break;
        }
    }
    }

    if (flag == 0){
        printf("%d is a prime number.\n", x);
    }
    
}

int digitSum(int x){ //Tested
    int sum = 0;
    int remain;

    while (x != 0){
        sum += x%10;
        x /= 10;
    }
    
    return sum;
}

int reverseNumber(int x){ //Tested
    int revNumber = 0;
    int remain = 0;

    while(x != 0){
        remain = x%10;
        revNumber = revNumber*10 + remain;
        x /= 10;
    }

    return revNumber;
}

void upperCase(char c){ //Tested
    if (c >= 'a' && c <= 'z'){
        printf("%c", c - 32);
    }
    else printf("It's already upper case!\n");
    
}

void downCase(char c){ //Tested
    if (c >= 'A' && c <= 'Z'){
        printf("%c", c + 32);
    }
    else printf("It's already lower case!\n");
}

int isUpperCase(char c){ //Tested
    int x = c;
    if (x >= 'A' && x <= 'Z')
    {
        return 1;
    }
    else return 0;
    
}

int factoriel(int x){ //Tested
    if (x == 0) return 1;

    int res = 1;
    res = x*factoriel(x-1);
    return res;
}


int power(int x, int y){ //Tested
    int res = 1;
    for (int i = 0; i < y; i++){
        res = res*x;
    }
    
    return res;
}

int add(int x, int y){ //no need to be tested
    return x + y;
}

void findRoots(int a, int b, int c){ //Tested
    double delta = (double)(b*b-4*a*c);
    
    double root1, root2;

    root1 = (sqrt(delta)-b)/(2*a);
    root2 = (-sqrt(delta)-b)/(2*a);

    printf("First Root: %lf\nSecond Root: %lf", root1, root2);
}

int isPalindromeNumber(int x){ //Tested
    int y = reverseNumber(x);

    if (x == y){
        return 1;
    }
    else return 0;
}

void isPalindromeText(char *c, int size){
    printf("Enter a word please: ");
    gets(c);
    printf("Enter size of the word: ");
    scanf("%d", &size);
    int flag = 0;
    
    for (int i = 0; i < size; i++){
        if (c[i] == c[size-i-1]){
            flag = 1;
        }
        else flag = 0;
    }
       if (flag == 1){
           printf("Word '%s' is palindrome.\n", c);
       }
       else printf("Word '%s' is not palindrome.\n", c);
    
}


int isVowel(char c){ //Tested

    switch(c){
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      return 1;
    default:
      return 0;
  }
}

int exist(int *arr, int size, int value){ //Tested
    int flag;
    for (int i = 0; i < size; i++){
        if (value == arr[i]){
            flag = 1;
            break;
        }
        else flag = 0;
    }

    if(flag == 1) return 1;
    else return 0;
}

int getIndex(int *arr, int size, int value){ //Tested
    int ctr = 0;
    for (int i = 0; i < size; i++){
        if (value == arr[i]){
            ctr++;
            break;
        }
    }
    
    return ctr;
}

int count(int *arr, int size, int value){ //Tested
    int counter = 0;
    for (int i = 0; i < size; i++){
        if (value == arr[i]){
            counter++;
        }
    }

    return counter;
}

int findMax(int *arr, int size){ //Tested
    int max = arr[0];

    for (int i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

int findMax2(int *arr, int size){ //Tested
    int max = findMax(arr, size);
    int max2 = arr[0];

    for (int i = 0; i < size; i++){
        if (arr[i] > max2 && arr[i] < max){
            max2 = arr[i];
        }
    }
    
    return max2;
}

int findMin(int *arr, int size){ //Tested
    int min = arr[0];

    for (int i = 0; i < size; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}

int findMin2(int *arr, int size){ //Tested
    int min = findMin(arr, size);
    int min2 = arr[(rand()%(size-1)) + 1];
    //burada rand fonksiyonunu kullanmamin sebebi
    //dizideki minimum sayiyi yanlislikla min2'ye
    //atama olasiligini en aza indirmek. 

    for (int i = 0; i < size; i++){
        if (arr[i] < min2 && arr[i] > min){
            min2 = arr[i];
        }
    }
    
    return min2;
}

int sumArray(int *arr, int size){ //Tested
    int total = 0;

    for (int i = 0; i < size; i++){
        total = total + arr[i];
    }

    return total;
}

double averageArr(int *arr, int size){//Tested
    int total = 0;
    double avg = 0;

    for (int i = 0; i < size; i++){
        total = total + arr[i];
    }

    avg = ((double)total)/size;

    return avg;
}

double deviationArr(int *arr, int size){ //Tested
    double avg = averageArr(arr, size);
    double avg2 = 0;

    for (int i = 0; i < size; i++){
        avg2 += (avg - arr[i])*(avg - arr[i]);
    }

    avg2 = avg2/(size-1);
    printf("%lf\n", avg2);

    return sqrt(avg2);
}

void printMatrix(int **matrix, int row, int column){ //Tested
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

int ** transposeMatrix(int **matrix, int row, int column){ //Tested
    int **newMatrix;
    newMatrix = fillMatrixWithZero(newMatrix, row, column);
    
    if (newMatrix == NULL){
        printf("Matrix Memory Allocation Error!\n");
        printf("(mylib.c, 344");
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            newMatrix[j][i] = matrix[i][j];
        }
    }

    return newMatrix;
}

int** fillMatrix(int **matrix, int row, int column){ //Tested
    srand(time(NULL));
    matrix = malloc(column * sizeof(int*));

    for (int i = 0; i < column; i++){
        matrix[i] = malloc(row * sizeof(int));
    }

    if (matrix == NULL){
        printf("Matrix Memory Allocation Error!\n");
    }
    

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            matrix[j][i] = ((rand()%50)+50);
        }
    }

    return matrix;
}


//Deger atamamaktan kaynaklanan problemleri gidermek icin yazildi.
int** fillMatrixWithZero(int **matrix, int row, int column){ 
    matrix = malloc(column * sizeof(int*));

    for (int i = 0; i < column; i++){
        matrix[i] = malloc(row * sizeof(int));
    }

    if (matrix == NULL){
        printf("Matrix Memory Allocation Error!\n");
    }
    

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            matrix[j][i] = 0;
        }
    }

    return matrix;
}

// ...
