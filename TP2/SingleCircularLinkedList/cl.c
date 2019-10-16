#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cl.h"

Person *addNewContact(Person *node){//done
    
    Person *iter = node;
    Person *newNode = (Person*)malloc(sizeof(Person));
    int i = 0;

    if (node == NULL){
        node = (Person*)malloc(sizeof(Person));
        node->next = node;
        printf("Enter the name: ");
        scanf("%s", node->name);
        printf("Enter the surname: ");
        scanf("%s", node->surname);
        printf("Enter the city name: ");
        scanf("%s", node->city);
        printf("Enter the home number: ");
        scanf("%s", node->homeNumber);

        return node;
    }

    else{
        printf("Enter the name: ");
        scanf("%s", newNode->name);
        printf("Enter the surname: ");
        scanf("%s", newNode->surname);
        printf("Enter the city name: ");
        scanf("%s", newNode->city);
        printf("Enter the home number: ");
        scanf("%s", newNode->homeNumber);

        if(strcmp(newNode->surname, iter->surname) < 0){
            newNode->next = iter;
            while(iter->next != node){
                iter = iter->next;
            }
            iter->next = newNode;
            return newNode;
        }

        while(iter->next != node){
            if(strcmp(newNode->surname, iter->next->surname) < 0){
                newNode->next = iter->next;
                iter->next = newNode;
                return node;
            }
            iter = iter->next;
        }
        
        newNode->next = node;
        iter->next = newNode;
    }
    
    return node;
}

City* addNewCity(City* node){//done
    City *iter = node;
    City *newNode = (City*)malloc(sizeof(City));

    newNode->next = node;

	if (node == NULL){
		node = (City*)malloc(sizeof(Person));
        node->next = node;
        printf("Enter city name: ");
        scanf("%s", node->cityName);
        printf("Enter city code: ");
        scanf("%d", &node->code);

        return node;
	}

	else{
        printf("Enter city name: ");
        scanf("%s", newNode->cityName);
        printf("Enter city code: ");
        scanf("%d", &newNode->code);

        if (strcmp(newNode->cityName, iter->cityName) < 0){
            newNode->next = iter;
            while(iter->next != node){
                iter = iter->next;
            }
            iter->next = newNode;
            return newNode;
        }

		while(iter->next != node){
            if(strcmp(newNode->cityName, iter->next->cityName) < 0){
                newNode->next = iter->next;
                iter->next = newNode;
                return node;
            }
            iter = iter->next;
        }

        newNode->next = node;
        iter->next = newNode;
	}

    return node;
}

Person *deleteContact(Person *node, char *nameD, char *surnameD){//done
    Person *iter = node;
    Person *temp;
    int flag = 0;

    if(node == NULL){
        printf("\nERROR: There's no one in the list!\n");
        return NULL;
    }

    //checking if the contact that user wants to
    //delete is the first contact
    if(node == NULL){
        printf("\nThere's no one in the list to delete!\n");
        return NULL;
    }
    if((strcmp(iter->name, nameD) == 0) && (strcmp(iter->surname, surnameD) == 0)){
        free(node);
        return NULL;
    }

    while(iter->next->next != node && flag == 0){
        iter = iter->next;

        if ((strcmp(iter->next->name, nameD) == 0) && (strcmp(iter->next->surname, surnameD) == 0)){
            flag = 1;
        }
    }

    if (iter->next == node && flag == 0){
        printf("This contact doesn't exist!\n");
        return node;
    }

    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);

    return node;
}

City *deleteCity(City *node, char *cityD){ //done
    City *iter = node;
    City *temp;
    int flag = 0;

    if(node == NULL){
        printf("\nERROR: There's no city in the list!\n");
        return NULL;
    }

    if(strcmp(node->cityName, cityD) == 0){
        while(iter->next != node){
            iter = iter->next;
        }

        temp = iter->next;
        iter->next = iter->next->next;
        free(temp);

        return iter->next;
    }

    while(iter->next != node && flag == 0){
        iter = iter->next;

        if (strcmp(iter->next->cityName, cityD) == 0){
            flag = 1;
        }
    }

    if (iter->next == node && flag == 0){
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
    int i = 1;

    if(node == NULL){
        printf("\nERROR: There's no one in the list!\n");
        return;
    }

    printf("\n--- Contact Number %d ---\n", i);
    printf("Name: %s\n", iter->name);
    printf("Surname: %s\n", iter->surname);

    if(strcmp(iterCity->cityName, iter->city) == 0){
        printf("City: %s\n", iterCity->cityName);
        printf("Home Number: 0 (%d) ", iterCity->code);
    }

    else{
        iterCity = iterCity->next;

        while(iterCity != cities){
                if(strcmp(iterCity->cityName, iter->city) == 0){
                    printf("City: %s\n", iterCity->cityName);
                    printf("Home Number: 0 (%d) ", iterCity->code);
                }

            iterCity = iterCity->next;
        }
    }

    printf("%s\n\n-------------------\n", iter->homeNumber);
    iter = iter->next;
    iterCity = cities;
    i++;

    while(iter != node){

        printf("\n--- Contact Number %d ---\n", i);
        printf("Name: %s\n", iter->name);
        printf("Surname: %s\n", iter->surname);

        if(strcmp(iterCity->cityName, iter->city) == 0){
            printf("City: %s\n", iterCity->cityName);
            printf("Home Number: 0 (%d) ", iterCity->code);
        }

        else{
            iterCity = iterCity->next;
            
            while(iterCity != cities){
                if(strcmp(iterCity->cityName, iter->city) == 0){
                    printf("City: %s\n", iterCity->cityName);
                    printf("Home Number: 0 (%d) ", iterCity->code);
                }

            iterCity = iterCity->next;
            }
        }
        
        printf("%s\n\n-------------------\n", iter->homeNumber);

        iter = iter->next;
        iterCity = cities;
        i++;
    }
}

void printCities(City *node){//done
    City *iter = node;
    int i = 1;

    if(node == NULL){
        printf("\nERROR: There's no city in the list!\n");
        return;
    }

    printf("\n--- City Number %d ---\n", i);
    printf("City: %s\n", iter->cityName);
    printf("City Code: %d\n-------------------\n", iter->code);

    iter = iter->next;
    i++;

    while(iter != node){
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
 
    while (iter != node){
        if ((strcmp(iter->name, name) == 0) && (strcmp(iter->surname, surname) == 0)){
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
 
    while (iter != node){
        if (strcmp(iter->cityName, name) == 0){
            printf("\nCity Name: %s\n", iter->cityName);
            printf("City code: %d\n", iter->code);
        }
        
        iter = iter->next;
    }
}

