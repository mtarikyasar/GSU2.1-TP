gcc -c avlTree.c -o avlTree.o
gcc -c main.c -o main.o
gcc main.c avlTree.o -o main -lm
