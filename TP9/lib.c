#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "lib.h"

Students *addNewContact(Students *node){
    Students *iter;
    Students *newNode = (Students*)malloc(sizeof(Students));
    int i = 0;
    iter = node;
    newNode->next = NULL;

    printf("\n----New Student---\n");
    printf("Enter the student name: ");
    scanf("%s", newNode->name);
    printf("Enter the student surname: ");
    scanf("%s", newNode->surname);

    if(node == NULL){
        node = (Students*)malloc(sizeof(Students));
        node = newNode;
        node->prev = NULL;
        return node;
    }

	else{
        if(strcmp(newNode->surname, iter->surname) < 0){
            newNode->next = node;
            node->prev = newNode;
            newNode->prev = NULL;
            return newNode;
        }

		while(iter->next != NULL){
			if(strcmp(newNode->surname, iter->next->surname) < 0){
                iter->next->prev = newNode;
                newNode->next = iter->next;
                iter->next = newNode;
                newNode->prev = iter;
                return node;                
            }

            iter = iter->next;
		}

        iter->next = newNode;
        newNode->prev = iter;
        
        return node;
	}
}

Students *fillGrades(Students *node){
    srand(time(0));
    Students *iter = node;

    if(node == NULL){
        printf("There is no one in the list!\nExiting...\n");
        return NULL;
    }

    while(iter != NULL){
        iter->gradeOne = rand()%100 + 1;
        fillGradeWithLetters(iter->gradeOne, iter->courseOne);
        iter->gradeTwo = rand()%100 + 1;
        fillGradeWithLetters(iter->gradeTwo, iter->courseTwo);
        iter->gradeThree = rand()%100 + 1;
        fillGradeWithLetters(iter->gradeThree, iter->courseThree);
        iter->creditCourseOne = rand()%3 + 3;
        iter->creditCourseTwo = rand()%3 + 3;
        iter->creditCourseThree = rand()%3 + 3;

        iter = iter->next;
    }

    return node;
}

void printStudents(Students *node){
    int i = 1;
    Students *iter = node;

    if(node == NULL){
        printf("There is no one in the list!\nExiting...\n");
        return;
    }

    while(iter != NULL){
        printf("\n----%d. Student----\n", i);
        printf("Name: %s\n", iter->name);
        printf("Surname: %s\n", iter->surname);
        printf("Course One and its letter note: %d - %c%c (%d)\n", iter->gradeOne, iter->courseOne[0], iter->courseOne[1], iter->creditCourseOne);
        printf("Course Two and its letter note: %d - %c%c (%d)\n", iter->gradeTwo, iter->courseTwo[0], iter->courseTwo[1], iter->creditCourseTwo);
        printf("Course Three and its letter note: %d - %c%c (%d)\n", iter->gradeThree, iter->courseThree[0], iter->courseThree[1], iter->creditCourseThree);
        printf("Average Grade: %.2lf\n", iter->averageGrade/(iter->name[0]*iter->surname[0]));
        printf("Average Grade(encrpyted): %.2lf\n\n", iter->averageGrade);

        i++;
        iter = iter->next;
    }
}

void fillGradeWithLetters(int grade, char finalGrade[]){
    if(grade < 50){
        finalGrade[0] = 'F';
        finalGrade[1] = ' ';
    }
    else if(grade >= 50 && grade < 60){
        finalGrade[0] = 'C';
        finalGrade[1] = 'C';
    }
    else if(grade >= 60 && grade < 70){
        finalGrade[0] = 'C';
        finalGrade[1] = 'B';
    }
    else if(grade >= 70 && grade < 80){
        finalGrade[0] = 'B';
        finalGrade[1] = 'B';
    }
    else if(grade >= 80 && grade < 90){
        finalGrade[0] = 'B';
        finalGrade[1] = 'A';
    }
    else if(grade >= 90 && grade <= 100){
        finalGrade[0] = 'A';
        finalGrade[1] = 'A';
    }
}

Students *calculateAverageGrade(Students* node){
    int totalCredit = 0;
    double result = 0;
    Students *iter = node;

    while(iter != NULL){
        result = (double)((iter->gradeOne*iter->creditCourseOne) + (iter->gradeTwo*iter->creditCourseTwo) + (iter->gradeThree*iter->creditCourseThree));
        totalCredit = (iter->creditCourseOne) + (iter->creditCourseTwo) + (iter->creditCourseThree); 
        result = result/totalCredit;
        iter->averageGrade = result;

        iter = iter->next;
    }

    return node;
}

Students *encryptionStudent(Students* node){
    Students *iter = node;
    double encryptedData = 0;

    while(iter != NULL){
        encryptedData = (iter->averageGrade)*(iter->name[0])*(iter->surname[0]);
        iter->averageGrade = encryptedData;

        iter = iter->next;
    }

    return node;
}

Tree *insert(Tree *binaryTree, char *name, char *surname){
    Tree *binaryIter = binaryTree;

	if(binaryTree == NULL){
		Tree *root = (Tree*)malloc(sizeof(Tree));
		root->left = NULL;
		root->right = NULL;
		strcpy(root->name, name);
		strcpy(root->surname, surname);
		return root;
	}
	
	else{
        if(strcmp(binaryIter->name, name) < 0){
            binaryTree->right = insert(binaryTree->right, name, surname);
            return binaryTree;
        }

        binaryTree->left = insert(binaryTree->left, name, surname);
        return binaryTree;
    }
}

void travers(Tree *tree){
	if(tree == NULL) return;
	travers(tree->left);
	printf("%s %s - ", tree->name, tree->surname);
	travers(tree->right);
}

Tree *createBinaryTree(Tree *binaryTree, Students *node){
    Students *iter = node;
    Tree *binaryIter = binaryTree;

    while(iter != NULL){
        binaryTree = insert(binaryTree, iter->name, iter->surname);
        iter = iter->next;
    }

    return binaryTree;
}

void compareGrades(Students *node, double x){
    printf("\n---Students who have average grade greater than %.0lf---\n", x);
    Students *iter = node;
    double decryptedGreade = 0;

    while(iter != NULL){
        decryptedGreade = iter->averageGrade/((iter->name[0])*(iter->surname[0]));

        if(decryptedGreade > x){
            printf("Name: %s\n", iter->name);
            printf("Surname: %s\n\n", iter->surname);
        }

        iter = iter->next;
    }

}