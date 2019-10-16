#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sl.h"

Person *addNewContact(Person *node){//working
    Person *iter = node;
    Person *newNode = (Person*)malloc(sizeof(Person));
    Person *temp;
    int i = 0;

    newNode->next = NULL;

    printf("Enter the name: ");
    scanf("%s", newNode->name);
    printf("Enter the surname: ");
    scanf("%s", newNode->surname);
    printf("Enter the city name: ");
    scanf("%s", newNode->city);
    printf("Enter the home number: ");
    scanf("%s", newNode->homeNumber);

	if (iter == NULL){
        node = (Person*)malloc(sizeof(Person));
        node->next = NULL;
		node = newNode;
	}

	else{
        if (strcmp(newNode->surname, iter->surname) < 0){
            newNode->next = node;
            return newNode;
        }
        
		while(iter->next != NULL){
            if (strcmp(newNode->surname, iter->next->surname) < 0){
                newNode->next = iter->next;
                iter->next = newNode;
                return node;                
            }

			iter = iter -> next;
		}

		iter->next = newNode;
	}

    return node;
}

City* addNewCity(City* node){//working
    City *iter = node;
    City *newNode = (City *)malloc(sizeof(City));

        newNode -> next = NULL;

        printf("Enter city name: ");
        scanf("%s", newNode->cityName);
        printf("Enter city code: ");
        scanf("%d", &newNode->code);

	if (iter == NULL){
		node = newNode;
	}

	else{
        if (strcmp(newNode->cityName, iter->cityName) < 0){
            newNode->next = iter;
            return newNode;
        }

		while(iter -> next != NULL){
            if (strcmp(iter->cityName, newNode->cityName) < 0){
                newNode->next = iter->next;
                iter->next = newNode;
                return node;
            }   

		    iter = iter->next;
		}

        iter->next = newNode;

	}
        return node;
}

Person *deleteContact(Person *node, char *nameD, char *surnameD){//working
    Person *iter = node;
    Person *temp;
    int flag = 0;

    if(node == NULL){
        printf("\nERROR: There's no one in the list!\n");
        return NULL;
    }

    //checking if the contact that user wants to
    //delete is the first contact
    if((strcmp(node->name, nameD) == 0) && (strcmp(node->surname, surnameD) == 0)){
        temp = node;
        node = node->next;
        free(temp);
        return node;
    }

    while(iter->next->next != NULL && flag == 0){
        if ((strcmp(iter->next->name, nameD) == 0) && (strcmp(iter->next->surname, surnameD) == 0)){
            flag = 1;
            break;
        }

        iter = iter->next;
    }

    if (iter->next->next == NULL && flag == 0){
        if((strcmp(iter->next->name, nameD) == 0) && (strcmp(iter->next->surname, surnameD) == 0)){
            temp = iter->next;
            iter->next = iter->next->next;
            free(temp);
            return node;
        }
        
        printf("This contact doesn't exist!\n");
        return node;
    }

    else if (flag == 1){
        temp = iter->next;
        iter->next = iter->next->next;
        free(temp);
        return node;
    }

    else return node;

}

City *deleteCity(City *node, char *cityD){
    City *iter = node;
    City *temp;
    int flag = 0;

    if(node == NULL){
        printf("\nERROR: There's no city in the list!\n");
        return NULL;
    }

    if(strcmp(node->cityName, cityD) == 0){
        temp = node;
        node = node->next;
        free(temp);
        return node;
    }

    while(iter->next != NULL && flag == 0){
        iter = iter->next;

        if (strcmp(iter->next->cityName, cityD) == 0){
            flag = 1;
        }
    }

    if (flag == 0){
        printf("This city doesn't exist!\n");
        return node;
    }

    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    
    return node;
} 

void printContacts(Person* node, City* cities){//working
    Person *iter = node;
    City *iterCity = cities;
    int flagC = 0;
    int i = 1;

    if(node == NULL){
        printf("\nERROR: There's no one in the list!\n");
        return;
    }

    while(iter != NULL){
        printf("\n--- Contact Number %d ---\n", i);
        printf("Name: %s\n", iter->name);
        printf("Surname: %s\n", iter->surname);
        while(iterCity != NULL){
            if(strcmp(iterCity->cityName, iter->city) == 0){
                printf("City: %s\n", iterCity->cityName);
                printf("Home Number: 0 (%d) ", iterCity->code);
            }

            iterCity = iterCity->next;
        }
        printf("%s\n\n-------------------\n", iter->homeNumber);

        iter = iter->next;
        iterCity = cities;
        i++;
    }
}

void printCities(City *node){//working
    City *iter = node;
    int i = 1;

    if(node == NULL){
        printf("\nERROR: There's no city in the list!\n");
        return;
    }

    while(iter != NULL){
        printf("\n--- City Number %d ---\n", i);
        printf("City: %s\n", iter->cityName);
        printf("City Code: %d\n-------------------\n", iter->code);

        iter = iter->next;
        i++;
    }
}

void searchContacts(Person *node, char *name, char *surname){ //working
    Person *iter = node;
    
    if(node == NULL){
        printf("\nERROR: There's no one in the list!\n");
        return;
    }

    while (iter != NULL){
        if ((strcmp(iter->name, name) == 0) && (strcmp(iter->surname, surname)) == 0){
            printf("\nName: %s\n", iter->name);
            printf("Surname: %s\n", iter->surname);
            printf("City: %s\n", iter->city);
            printf("Home Number: %s\n", iter->homeNumber);
        }
        
        iter = iter->next;
    }
}

void searchCity(City *node, char *name){ //working
    City *iter = node;

    if(node == NULL){
        printf("\nERROR: There's no city in the list!\n");
        return;
    }
 
    while (iter != NULL){
        if (strcmp(iter->cityName, name) == 0){
            printf("\nCity Name: %s\n", iter->cityName);
            printf("City code: %d\n", iter->code);
        }
        
        iter = iter->next;
    }
}

