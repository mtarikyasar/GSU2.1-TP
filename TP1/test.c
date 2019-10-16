#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mylib.h"

// to complile from terminal, run: gcc test.c mylib.c -o ApplicationName -lm
// to run the complied application, run: ./ApplicatioName

int main(void)
{
    // a remplir
    
    // Test 1 
    //isLetter function
    /* char a = 'a';
    char y = '15';
    printf("%c, %c\n", a, y);
    int x = isLetter(a);
    printf("%d\n", x);
    x = isLetter(y);
    printf("%d\n", x);
    */

    // Test 2
    //isDigit function
    /* char a = 'a';
    char b = '0';
    printf("%d\n", isDigit(a));
    printf("%d\n", isDigit(b));
    */

   //Test 3
   //isEven function
   /*
    int x = 21;
    int y = 30;
    int z = 0;

    printf("%d\n", isEven(x));
    printf("%d\n", isEven(y));
    printf("%d\n", isEven(z));
   */

  //Test 4
  //isPrime function
  /*
    int x = 2;
    int y = 1224;
    int z = 79;
    
    isPrime(x);
    isPrime(y);
    isPrime(z);
  */

  //Test 5
  //digitSum function
  /*
    int x = 123;
    int y = 716124;
    printf("Number: %d, Sum: %d\n", x,digitSum(x));
    printf("Number: %d, Sum: %d\n", y, digitSum(y));
  */

  //Test 6
  //reverseNumber function
  /*
    int x =7237234;

    printf("Number: %d\nReversed: %d",x ,reverseNumber(x));
  */

  //Test 7 and 8
  //upperCase and downCase functions
  /*
    char a = 'A';
    char b = 'b';

    upperCase(a);
    downCase(b);
  */

  //Test 9
  //isUpperCase function
  /*
    char a = 'A';
    char b = 'b';
  
    printf("%d\n", isUpperCase(a));
    printf("%d\n", isUpperCase(b));
  */

  //Test 10
  //factoriel function
  /*
    int x = 3;
    int y = 7;

    printf("%d! = %d\n", x, factoriel(x));
    printf("%d! = %d\n", y, factoriel(y));
  */

  //Test 11
  //power function
  /*
    int x = 3;
    int y = 5;

    printf("%d^%d = %d", x, y, power(x,y));
  */

  //Test 12
  //findRoots function
  /*
  //equation is x^2-4x+3
      int x = 1, y = -4, z = 3;
      findRoots(x, y, z);
  */

  //Test 13
  //isPalindromeNumber function
  /*
    int x = 1441;
    int y = 1524;

    printf("%d\n", isPalindromeNumber(x));
    printf("%d\n", isPalindromeNumber(y));
  */

  //Test 14
  //isPalindromeText function
  /*
    char *c;
    int size;
    isPalindromeText(c, size);
  */

  //Test 15
  //isVowel function
  /*
    char a = 'a';
    char b = 'b';
  
    printf("%d\n", isVowel(a));
    printf("%d\n", isVowel(b));
  */

  //Test 16
  //exist function
  /*
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", exist(arr, 10, 3));
    printf("%d\n", exist(arr, 10, 12));
  */

  //Test 17
  //getIndex function
  /*
    int arr[] = {1, 2, 2, 1, 1, 3, 2, 1, 3, 1};
    printf("%d", getIndex(arr, 10, 1));
  */

  //Test 18
  //count function
  /*
    int arr[] = {1, 2, 2, 1, 1, 3, 2, 1, 3, 1};
    printf("%d", count(arr, 10, 1));
  */

  //Test 19 and 20
  //findMax and findMax2 functions
  /*
    int arr[] = {1, 2, 5, 6, 16, 12, 53, 6, 12, 9};

    printf("%d\n", findMax(arr, 10));
    printf("%d\n", findMax2(arr, 10));
  */

  //Test 21 and 22
  //findMin and findMin2 functions
  /*
    int arr[] = {5, 2, 5, 6, 16, 12, 53, 6, 12, 9};

    printf("%d\n", findMin(arr, 10));
    printf("%d\n", findMin2(arr, 10));
  */

  //Test 23 and 24
  //sumArray and averageArr functions
  /*
    int arr[] = {5, 2, 5, 6, 16, 12, 53, 6, 12, 9};

    printf("%d\n", sumArray(arr, 10));
    printf("%.2lf\n", averageArr(arr, 10));
  */

  //Test 25
  //deviationArr function
  
    int arr[] = {2, 2, 6, 3, 1};

    printf("%lf", deviationArr(arr, 5));
  

  //Test 26, 27 and 28
  //printMatrix, transposeMatrix and fillMatrix functions
  /*
    int **matrixTest = fillMatrix(matrixTest, 3, 3);
    printMatrix(matrixTest, 3, 3);

    printf("\n\n");

    matrixTest = transposeMatrix(matrixTest, 3, 3);
    printMatrix(matrixTest, 3 ,3);
  */


    return 0;
}
