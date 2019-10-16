#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sl.h"

int main(){
    int choice = 0;
    char nameD[20];
    char surnameD[20];
    char cityD[20];
    char nameS[20];
    char surnameS[20];
    char cityS[20];
    char are_u_sure_p = 'Y';
    char are_u_sure_c = 'Y';

    Person *contacts = (Person*)malloc(sizeof(Person));
    contacts = NULL;

    City *cityList = (City *)malloc(sizeof(City));
    cityList = NULL;

    while(choice != 9){
            printf("\nWelcome to Contacts Application.\n");
            printf("[1] Create new contact\n");
            printf("[2] Add new city\n");
            printf("[3] Delete contact\n");
            printf("[4] Delete city\n");
            printf("[5] Search contact\n");
            printf("[6] Search city\n");
            printf("[7] Print contacts\n");
            printf("[8] Print city list\n");
            printf("[9] Exit\n");
            printf("Please make your choice: ");
            scanf(" %d", &choice);

    switch(choice){
        default:
        case 1:
            contacts = addNewContact(contacts);
            break;

        case 2:
            cityList = addNewCity(cityList);
            break;

        case 3:
            printf("Enter name of the contact: ");
            scanf("%s", nameD);
            printf("Enter surname of the contact: ");
            scanf("%s", surnameD);
            printf("'%s %s' contact will be deleted.\n", nameD, surnameD);
            printf("Are you sure?\n[Y/N]: ");
            scanf(" %c", &are_u_sure_p);

            if (are_u_sure_p == 'Y' || are_u_sure_p == 'y'){
                contacts = deleteContact(contacts, nameD, surnameD);
            }
            else break;
            break;
        
        case 4:
            printf("Enter name of the city: ");
            scanf("%s", cityD);
            printf("'%s' city will be deleted.\n", cityD);
            printf("Are you sure?\n[Y/N]: ");
            scanf(" %c", &are_u_sure_c);

            if (are_u_sure_c == 'Y' || are_u_sure_c == 'y'){
                cityList = deleteCity(cityList, cityD);
            }

            else break;
            break;
        
        case 5:
            printf("Enter name of the person you're looking for: ");
            scanf("%s", nameS);
            printf("Enter surname of the person you're looking for: ");
            scanf("%s", surnameS);
            searchContacts(contacts, nameS, surnameS);
            break;
        
        case 6:
            printf("Enter name of the city you're looking for: ");
            scanf("%s", cityS);
            searchCity(cityList, cityS);
            break;
        
        case 7:
            printContacts(contacts, cityList);
            break;
        
        case 8:
            printCities(cityList);
            break;

        case 9:
            return 1;
    }
    }
}