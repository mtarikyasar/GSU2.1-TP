#include <stdio.h>
#include <stdlib.h>
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
    char letterTableLower[26][26];
    int index1 = 0, index2 = 0;
    int counter = 0;
    int i = 0;

    //create matrix
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            counter = 97+i+j;
            if(counter > 122) counter -= 26;
            letterTableLower[i][j] = counter;
        }
    }

    while(i < sizeOfWord(word)){
        newWord[i] = keyWord[i % sizeOfWord(keyWord)];
        i++;
    }

    i = 0;

    while(newWord[i] != '\0'){
        for (int x = 0; x < 26; x++)
        {
            if (word[i] == letterTableLower[x][0]){
                index1 = x;
            }
        }

        for (int x = 0; x < 26; x++)
        {
            if(newWord[i] == letterTableLower[0][x]){
                index2 = x;
            }
        }

        word[i] = letterTableLower[index1][index2];
        i++;
    }

    printf("Ciphertext is: %s\n\n", word);
}

void vigenereDecoder(char *word, char *keyWord){
    char newWord[MAXCHARCOUNT];
    char letterTableLower[26][26];
    char letterTableUpper[26][26];
    int index1 = 0, index2 = 0;
    int counter = 0;
    int i = 0;

    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            counter = 97+i+j;
            if(counter > 122) counter -= 26;
            letterTableLower[i][j] = counter;
        }
    }

    while(i < sizeOfWord(word)){
        newWord[i] = keyWord[i % sizeOfWord(keyWord)];
        i++;
    }

    i = 0;

    while(newWord[i] != '\0'){
        for (int x = 0; x < 26; x++)
        {
            if (newWord[i] == letterTableLower[0][x]){
                index1 = x;
            }
        }

        for (int x = 0; x < 26; x++)
        {
            if(word[i] == letterTableLower[x][index1]){
                index2 = x;
            }
        }

        word[i] = letterTableLower[index2][0];
        i++;
    }

    printf("Decoded text is: %s\n\n", word);
}

