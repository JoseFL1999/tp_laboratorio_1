
#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger, int* ID);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_ifExistPassenger(LinkedList* pArrayListPassenger);
int controller_setID(LinkedList* pArrayListPassenger,int* id);
int controller_saveIdFromBinary(LinkedList* pArrayListPassenger, int id);
int controller_loadIdFromBinary(LinkedList* pArrayListPassenger, int* id);
