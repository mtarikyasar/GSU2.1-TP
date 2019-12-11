#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lib.h"

#define MAXCHARCOUNT 100

int sizeOfWord(char *word){
    int i = 0;
    while(word[i] != '\0')
        i++;

    return i;
}

int upperCase(char c){
    if (c >= 'a' && c <= 'z'){
        return 0;
    }

    else return 1;
}

void ceaserEncoder(char *word, int shiftCount){
    int i = 0;
    int temp = 0;
    int size = sizeof(word)/sizeof(char);

    while (word[i] != '\0'){

        if(upperCase(word[i])){
            if(word[i] == 'Z') word[i] = 'A' + (shiftCount-1);

            else if(shiftCount >= 'Z'-word[i]){
                word[i] += ('Z'-word[i]);
                temp = shiftCount - (1 + 'Z' -word[i]);
                word[i] += temp;
            }

            else word[i] += shiftCount;
        }

        else if(!upperCase(word[i])){
            if(word[i] == 'z') word[i] = 'a' + (shiftCount-1);

            else if(shiftCount >= 'z'-word[i]){
                word[i] += ('z'-word[i]);
                temp = shiftCount - (1 + 'z' - word[i]);
                word[i] += temp;
            }

            else word[i] += shiftCount;
        }

        i++;
    }

    printf("%s\n", word);
}

void ceaserDecoder(char *word, int shiftCount){
    printf("Word '%s' will be decoded...\n", word);
    int i = 0;
    int temp = 0;
    int size = sizeof(word)/sizeof(char);
    printf("\n%s ---> ", word);

    while(word[i] != '\0'){
        if(upperCase(word[i])){
            if(word[i] == 'A') word[i] = 'Z' - (shiftCount-1);

            else if(shiftCount >= word[i] - 'A'){
                temp = word[i] - 'A';
                word[i] -= (word[i] - 'A');
                if(shiftCount >= temp){
                    temp = shiftCount - (1 + word[i] - 'A');
                    word[i] -= temp;
                }
            }

            else word[i] -= shiftCount;
        }

        else if(!upperCase(word[i])){
            if(word[i] == 'z') word[i] = 'a' - (shiftCount-1);

            else if(shiftCount >= word[i] - 'a'){
                temp = word[i] - 'a';
                word[i] -= (word[i] - 'a');
                if(shiftCount != (temp)){
                    temp = shiftCount - (1 + word[i] - 'a');
                    word[i] -= temp;
                }
            }

            else word[i] -= shiftCount;
        }

        i++;
    }

    printf("%s\n", word);
}

void vigenereEncoder(char *word, char *keyWord){
    char newWord[MAXCHARCOUNT];
    char letterTable[26][26];
    int index1 = 0, index2 = 0;
    int counter = 0;
    int i = 0;

    //create matrix
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            counter = 'a' + i + j;
            if(counter > 122) counter -= 26;
            letterTable[i][j] = counter;
        }
    }

    while(i < sizeOfWord(word)){
        newWord[i] = keyWord[i % sizeOfWord(keyWord)];
        i++;
    }

    i = 0;

    while(newWord[i] != '\0'){
        for (int x = 0; x < 26; x++){
            if ((word[i] == letterTable[x][0])||(word[i]+32 == letterTable[x][0])){
                index1 = x;
            }
        }

        for (int x = 0; x < 26; x++){
            if((newWord[i] == letterTable[0][x])||(newWord[i]+32 == letterTable[0][x])){
                index2 = x;
            }
        }

        word[i] = letterTable[index1][index2];
        i++;
    }

    printf("Ciphertext is: %s\n\n", word);
}

void vigenereDecoder(char *word, char *keyWord){ 
    char newWord[MAXCHARCOUNT];
    char letterTable[26][26];
    int index1 = 0, index2 = 0;
    int counter = 0;
    int i = 0;

    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            counter = 'a' + i + j;
            if(counter > 122) counter -= 26;
            letterTable[i][j] = counter;
        }
    }

    while(i < sizeOfWord(word)){
        newWord[i] = keyWord[i % sizeOfWord(keyWord)];
        i++;
    }

    i = 0;

    while(newWord[i] != '\0'){
        for (int x = 0; x < 26; x++){
            if ((newWord[i] == letterTable[0][x])||(newWord[i]+32 == letterTable[0][x])){
                index1 = x;
            }
        }

        for (int x = 0; x < 26; x++){
            if((word[i] == letterTable[x][index1])||(word[i]+32 == letterTable[x][index1])){
                index2 = x;
            }
        }

        word[i] = letterTable[index2][0];
        i++;
    }

    printf("Decoded text is: %s\n\n", word);
}

void matrixCipherEncoder(char *word){
    int size = 0;
    int k = 0;
    size = sizeOfWord(word);
    int matrixSize = ceil(sqrt(size));
    char encryptionMatrix[matrixSize][matrixSize];
    char newWord[size];

    printf("Size of the matrix: %d\n", matrixSize);

    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            if(k >= size) encryptionMatrix[i][j] = '-';
            else encryptionMatrix[i][j] = word[k];

            k++;
        }
    }

    k = 0;
    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            if(encryptionMatrix[j][i] != '-'){
                newWord[k] = encryptionMatrix[j][i];
                k++;
            }
        }
    }

    printf("Encrypted word is --> %s\n\n", newWord);
}

void matrixCipherDecoder(char *word){
    int size = 0;
    int k = 0;
    size = sizeOfWord(word);
    int matrixSize = ceil(sqrt(size));
    char encryptionMatrix[matrixSize][matrixSize];
    char newMatrix[matrixSize][matrixSize];
    char newWord[size];

    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            if(k >= size) encryptionMatrix[i][j] = '-';
            else encryptionMatrix[i][j] = word[k];

            k++;
        }
    }

    k = 0;
    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            if(encryptionMatrix[j][i] != '-'){
                newWord[k] = encryptionMatrix[j][i];
                k++;
            }
        }
    }

    printf("\nWord '%s' will be decoded...\n", newWord);
    
    //matrix transpose
    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            newMatrix[i][j] = encryptionMatrix[j][i];
        }
    }

    k = 0;
    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < matrixSize; j++){
            if(newMatrix[j][i] == '-') break;
            newWord[k] = newMatrix[j][i];
            k++;
        }
    }
    
    printf("Decrypted word is --> %s\n\n", newWord);
}

void rsaAlgorithmEncoder(char* word, int p, int q){
    int size = sizeOfWord(word);
    long double result = 0;
    
    //Public key
    double x = p*q;
    double e = 2;

    //Private key
    double phi = (p-1)*(q-1);
    double k = 2;
    double d = ((k*phi) + 1)/e;
    
    while (e < phi) { 
        if (gcd(e, phi)==1) 
            break; 
        else
            e++; 
    }

    int i = 0;

    while(word[i] != '\0'){
        if((upCase(word[i])-64 >= 10)){
            result = result*100 + ((long double)upCase(word[i])-64);
        }
        else{
            result = result*10 + ((long double)upCase(word[i])-64);
        }

        i++;
    }

    long double encrypted = pow(result, e);
    encrypted = fmod(encrypted, x);
    printf("Encrypted message is: %.0LF\n", encrypted);
}

//Not working
void rsaAlgorithmDecoder(char* word, int p, int q){
    int size = sizeOfWord(word);
    long double result = 0;
    
    //Public key
    double x = p*q;
    double e = 2;
    
    //Private key
    double phi = (p-1)*(q-1);
    double k = 2;
    double d = ((k*phi) + 1)/e;

    while (e < phi){ 
        if (gcd(e, phi)==1) 
            break; 
        else
            e++; 
    } 
    
    int i = 0;

    while(word[i] != '\0'){
        if((upCase(word[i])-64 >= 10)){
            result = result*100 + ((long double)upCase(word[i])-64);
        }
        else{
            result = result*10 + ((long double)upCase(word[i])-64);
        }

        i++;
    }


    long double encrypted = pow(result, e);
    encrypted = fmod(encrypted, x);
    printf("\n\n\n%LF and %lf\n\n\n", encrypted, d);

    double decrypted = pow(encrypted, d);
    printf("\n\n\n--|%F|--\n\n\n", decrypted);
    decrypted = fmod(decrypted, x);

}

int isPrime(int x){
    int flag = 0;
    if(x < 2){
        return 0;
    }

    else if(x == 2){
        return 1;
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

    if (flag == 0) return 1;
    else return 0;
}

int reverseNumber(int x){
    int revNumber = 0;
    int remain = 0;

    while(x != 0){
        remain = x%10;
        revNumber = revNumber*10 + remain;
        x /= 10;
    }

    return revNumber;
}

int upCase(char c){
    if (c >= 'a' && c <= 'z'){
        return (c - 32);
    }
        return c;
}

int gcd(int x, int y){ 
    int temp; 
    while (1){ 
        temp = x%y; 
        if (temp == 0) 
          return y; 
        x = y; 
        y = temp; 
    } 
} 