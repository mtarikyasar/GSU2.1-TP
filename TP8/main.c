#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXCHARCOUNT 100

int main(void){
    int p = 0, q = 0;
    char word[MAXCHARCOUNT];
    char keyWord[MAXCHARCOUNT];
    int shiftCount = 0;
    int choice = 0;

    while(choice != 9){
        printf("[1] Encrypt with Ceaser Cipher\n");
        printf("[2] Decrypt with Ceaser Cipher\n");
        printf("[3] Encrypt with Vigenere Cipher\n");
        printf("[4] Decrypt with Vigenere Cipher\n");
        printf("[5] Encrypt with Matrix Cipher\n");
        printf("[6] Decrypt with Matrix Cipher\n");
        printf("[7] Encrypt with RSA Algorithm\n");
        printf("[8] Decrypt with RSA Algorithm\n");
        printf("[9] Exit\n");
        printf("Make is your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the word that you want to encode: ");
                scanf("%s", word);
                printf("Enter shift count: ");
                scanf("%d", &shiftCount);
                ceaserEncoder(word, shiftCount);
                break;

            case 2:
                if(shiftCount == 0){
                    printf("You have to encrypt a file first!\n");
                    return 0;
                }

                ceaserDecoder(word, shiftCount);
                break;
            
            case 3:
                printf("Enter the word that you want to encode: ");
                scanf("%s", word);
                printf("Enter the keyword: ");
                scanf("%s", keyWord);
                vigenereEncoder(word, keyWord);
                break;

            case 4:
                printf("Word '%s' will be decoded by '%s' keyword.\n", word, keyWord);
                vigenereDecoder(word, keyWord);
                break;

            case 5:
                printf("Enter the word that you want to encode: ");
                scanf("%s", word);
                matrixCipherEncoder(word);
                break;

            case 6:
                matrixCipherDecoder(word);
                break;
            
            case 7:
                printf("Enter p and q 'PRIME' number: ");
                scanf("%d %d", &p, &q);
                if(isPrime(p) != 1 && isPrime(q) != 1){
                    printf("p and q must be prime numbers!\n");
                    break;
                }
                printf("Enter the word that you want to encode: ");
                scanf("%s", word);
                rsaAlgorithmEncoder(word, p, q);
                break;

            case 8:


            case 9:
                break;
        }
    }


}