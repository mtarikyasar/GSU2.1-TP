gcc -c binaryTree.c -o binaryTree.o
gcc -c main.c -o main.o
gcc main.c binaryTree.o -o main -lm
