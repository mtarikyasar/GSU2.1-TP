#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Students *root;
    root = (Students*)malloc(sizeof(Students));
    root = NULL;
    Tree *binaryTree;
    binaryTree = (Tree*)malloc(sizeof(Tree));
    binaryTree = NULL;
    int x = 0;
    int choice = 0;

    printf("How many students do you want to add: ");
    scanf("%d", &x);

    //Belirlenen sayida ogrenci ekle
    for (int i = 0; i < x; i++){
        root = addNewContact(root);
    }
    
    //Notlari doldur
    root = fillGrades(root);

    //Ortalamalari hesapla
    root = calculateAverageGrade(root);

    //Ortalamalari PDF dosyasinda belirlenen sekilde encrypt et
    root = encryptionStudent(root);

    //Ogrencileri binary tree yapisinda olustur
    binaryTree = createBinaryTree(binaryTree, root);

    while(choice != 4){
        printf("\n[1] Print Students\n");
        printf("[2] Print Binary Tree(inorder)\n");
        printf("[3] Compare Grades\n");
        printf("[4] Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printStudents(root);
                break;

            case 2:
                travers(binaryTree);
                break;

            case 3:
                printf("Enter a minimum grade value: ");
                scanf("%d", &x);
                compareGrades(root, x);
                break;

            case 4:
                break;
        }
    }
}