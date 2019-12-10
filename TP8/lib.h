#ifndef lib_h
#define lib_h

int upperCase(char c);
void ceaserEncoder(char *word, int shiftCount);
void ceaserDecoder(char *word, int shiftCount);
void vigenereEncoder(char *word, char *keyWord);
void vigenereDecoder(char *word, char *keyWord);
int sizeOfWord(char *word);
void matrixCipherEncoder(char *word);
void matrixCipherDecoder(char *word);
void rsaAlgorithmEncoder(char* word, int p, int q);
int isPrime(int x);
int reverseNumber(int x);
int upCase(char c);

#endif