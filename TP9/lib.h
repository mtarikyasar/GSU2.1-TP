#ifndef lib_h
#define lib_h

typedef struct stud{
    char name[50];
    char surname[50];
    int gradeOne;
    int gradeTwo;
    int gradeThree;
    int creditCourseOne;
    int creditCourseTwo;
    int creditCourseThree;
    char courseOne[2];
    char courseTwo[2];
    char courseThree[2];
    double averageGrade;
    struct stud *next;
    struct stud *prev;
}Students;

typedef struct n{
	char name[50];
    char surname[50];
    int gradeOne;
    int gradeTwo;
    int gradeThree;
    int creditCourseOne;
    int creditCourseTwo;
    int creditCourseThree;
    char courseOne[2];
    char courseTwo[2];
    char courseThree[2];
    double averageGrade;
	struct n* left;
	struct n* right;
}Tree;

Students *addNewContact(Students *node);
Students *fillGrades(Students *node);
void printStudents(Students *node);
void fillGradeWithLetters(int grade, char finalGrade[]);
Students *calculateAverageGrade(Students* node);
Students *encryptionStudent(Students* node);
Tree *insert(Tree *binaryTree, char *name, char *surname);
void travers(Tree *tree);
Tree *createBinaryTree(Tree *binaryTree, Students *node);
void compareGrades(Students *node, double x);

#endif