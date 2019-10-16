#ifndef sl_h
#define sl_h

typedef struct m{
    char cityName[20];
    int code;
    struct m *next;
}City;

typedef struct n{
    char name[20];
    char surname[20];
    char city[20];
    char homeNumber[20];
    struct n *next;
}Person;

Person *addNewContact(Person *node);
City* addNewCity(City* node);
Person *deleteContact(Person *node, char *nameD, char *surnameD);
City *deleteCity(City *node, char *cityD);
void printContacts(Person* node, City *cities);
void printCities(City *node);
void searchContacts(Person *node, char *name, char *surname);
void searchCity(City *node, char *name);

#endif
