#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define MAXCHARCOUNT 100

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