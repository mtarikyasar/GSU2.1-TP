#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXCHARCOUNT 100

int main(void){
    char word[MAXCHARCOUNT];
    int shiftCount = 0;
    int choice = 0;

    while(choice != 3){
        printf("[1] Encrypt with Ceaser Cipher\n");
        printf("[2] Decrypt with Ceaser Cipher\n");
        printf("[3] Exit\n");
        printf("Make is your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the word that you want to encrypt: ");
                scanf("%s", word);
                printf("Enter shift count: ");
                scanf("%d", &shiftCount);
                ceaserCoder(word, shiftCount);
                break;

            case 2:
                if(shiftCount == 0){
                    printf("You have to encrypt a file firs!\n");
                    return 0;
                }

                ceaserDecoder(word, shiftCount);
                break;
        }
    }


}