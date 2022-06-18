/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	char tipoPasajero[16];
	char estadoVuelo[16];
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nameStr,char* lastNameStr,char* priceStr, char* flyCodeStr, char* typePassengerStr, char* statusFlightStr);
Passenger* Passenger_newParametrosReally(int id,char* name,char* lastName,float price, char* flyCode, char* typePassenger, char* statusFlight);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_setTipoPasajeroForInt(Passenger* this, int tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo);
int Passenger_setEstadoVueloForInt(Passenger* this, int estadoVuelo);

int Passenger_sortLastName(void* itemOne, void* itemTwo);
int Passenger_sortId(void* itemOne, void* itemTwo);
int Passenger_sortPrice(void* itemOne, void* itemTwo);

int Passenger_validacionEliminar(Passenger* this, int* option);

#endif /* PASSENGER_H_ */
