/*
 * ArrayPassenger.h
 *
 *  Created on: 7 may 2022
 *      Author: --
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{
	int typePassenger;
	char description[15];
}eTypePassenger;

typedef struct{
	int statusFlight;
	char description[15];
}eStatusFlight;

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}ePassenger;

int initPassengers(ePassenger* list,int len);
///@brief To indicate that all position in the array are empty,
///this function put the flag (isEmpty) in TRUE in all
///position of the array
///@param list Passenger* Pointer to array of passenger
///@param len int Array length
///@return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initTypePassengers(eTypePassenger* list, int len);
/// Function inicializa los tipos de pasajeros type1-descriptionInfante type2-descriptionAdolescente type3-descriptionAdulto
/// @param list -array de estructura a iniciliza
/// @param len -longitud de array de estructura
/// @return -retorna 0 si recorrio bien o -1 si hubo algun error

int initStatusFlight(eStatusFlight* list, int len);
/// funcion inicializa los estados de vuelo status1-descriptionACTIVO status2-descriptionINACTIVO
/// @param list -array de estructura a iniciliza
/// @param len -longitud de array de estructura
/// @return -retorna 0 si recorrio bien o -1 si hubo algun error

int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
/// @brief add in a existing list of passengers the values received as parameters
///in the first empty position
/// @param list passenger*
/// @param len int
/// @param id int
/// @param name[] char
/// @param lastName[] char
/// @param price float
/// @param typePassenger int
/// @param flycode[] char
/// @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok

int findPassengerById(ePassenger* list, int len,int id);
/// @brief find a Passenger by Id en returns the index position in array.
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]

int removePassenger(ePassenger* list, int len, int id);
/// @brief Remove a Passenger by Id (put isEmpty Flag in 1)
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return int Return (-1) if Error [Invalid length or NULL pointer or if can'tfind a passenger] - (0) if Ok


int sortPassengers(ePassenger* list, int len, int order);
/// @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
/// @param list Passenger*
/// @param len int
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok

int printPassenger(ePassenger* list, eTypePassenger* type, eStatusFlight* status, int len);
/// @brief print the content of passengers array
/// @param type TypePassenger*
/// @param status StatusFlight*
/// @param list Passenger*
/// @param length int
/// @return int

int sortPassengersByCode(ePassenger* list, int len, int order);
/// @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
/// @param list Passenger*
/// @param len int
/// @param order int [1] indicate UP - [0] indicate DOWN


#endif /* ARRAYPASSENGER_H_ */
