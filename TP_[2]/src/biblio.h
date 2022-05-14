/*
 * biblio.h
 *
 *  Created on: 7 may 2022
 *      Author: --
 */

#ifndef BIBLIO_H_
#define BIBLIO_H_

int isNum(char* string);
/// funcion validar si una cadena es numero
/// @param string -cadena a validar si es numero
/// @return -retorna 1 si es numero, retorna 0 si no es numero
int isText(char* string);
/// funcion validar si una cadena es texto
/// @param string -cadena a validar si es texto
/// @return -retorna 1 si es texto, retorna 0 si no es texto

int isFloat(char* string);
/// funcion validar si una cadena es flotante
/// @param string -cadena a validar si es flotante
/// @return -retorna 1 si es flotante retorna 0 si no es flotante

int isAlphanumeric(char* string);
///funcion validar si una cadena es alfanumerica
///  @param string -cadena a validar si es alfanumerica
/// @return -retorna 1 si es alfanumerica, retorna 0 si no es alfanumerica

int convertName(char* string);
/// funcion convierte primer char en mayus y las siguientes en minus
/// @param string -cadena a convertir
/// @return -retorna 0 si lo convirtio, retorna -1 si hubo algun error


int convertFlyCode(char* string);
/// funcion convierte toda la cadena en mayus
/// @param -string cadena  convertir en mayus
/// @return -retorna 0 si convirtio correctamente, retorna -1 si hubo algun error

int getMenu(int* option, char* message, char* messageError, int maxOption, int minOption);
/// funcion genera un menu de opciones validadas
/// @param option -devuelve la opcion que se eligio ya validado
/// @param message -muestra el mensaje que quiere pedir
/// @param messageError -muestra el mensaje si las opciones que se ingreso no fueron validas
/// @param maxOption -opcion maxima entera
/// @param minOption -opcion minima entera
/// @return -retorna 0 si se ejecuto correctamente, retorna -1 si hubo algun error

int generateID(int* id);
/// funcion suma +1 al id anterior
/// @param id -recibe el id en donde se queda y devuelve el id sumado +1
/// @return retorn 0 si salio todo bien , retorna -1 si hubo algun error

int getID(ePassenger* list, int len, int* id, char* message, char* messageError);
/// funcion obtener el id mediante pregunta y devuelve la id validada existente
/// @param list -puntero array de structura
/// @param len -longitud del array
/// @param id -devuelve el id
/// @param message -mensaje que se muestra para obtener el id
/// @param messageError -mensaje que se muestra si no paso la validacion del id y vuelve a pedir
/// @return  retorna 0 si se ejecuto correctamente, retorna -1 si hubo algun error

int getName(char* name,char* message, char*messageError, int retry);
/// funcion obtener un nombre validado
/// @param name -devuelve la cadena ya validado si es nombre
/// @param message -mensaje pedir nombre
/// @param messageError -mensaje error si no pasa la validacion de nombre y vuelve a pedir
/// @param retry -numero de intentos a pedir
/// @return retorna 0 si se ejecuto correctamente, retorna -1 si hubo algun error

int getPriceFloat(float* numFloat, char* message, char* messageError, int retry);
/// funcion obtener precio tipo flotante validado(si recibe un entero lo convierte a flotante)
/// @param numFloat -devuelve el numero flotante validado
/// @param message -mensaje para pedir el numero flotante
/// @param messageError -mensaje error si no cumplio validacion flotante y vuelve a pedir
/// @param retry -numero de intentos a pedir
/// @return retorna 0 si se ejecuto correctamente, retorna -1 si hubo algun error

int getFlycode(char* flycode,char* message, char* messageError, int retry);
/// funcion obtener codigo de vuelo que es un alfanumerico
/// @param flycode -devuelve el codigo de vuelo alfanumerico validado
/// @param message -mensaje a pedir codigo alfanumerico
/// @param messageError -mensaje error si no valida codigo de vuelo alfanumerico y vuelve a pedir
/// @param retry -numero de intentos a pedir
/// @return retorna 0 si se ejecuto correctamente, retorna -1 si hubo algun error



int getDataPassenger(int* id, char* name, char* lastname, float* price, char* flycode, int* typePassenger);
/// funcion obtener datos de pasajeros con los parametros dados
/// @param id -devuelve id validado.
/// @param name -devuelve nombre validado.
/// @param lastname -devuelve apellido validado.
/// @param price -devuelve precio validado.
/// @param flycode -devuelve codigo de vuelo validado.
/// @param typePassenger -devuelve tipo de pasajero validado
/// @return retorna 0 si se ejecuto correctamente, retorna -1 si hubo algun error

void showMessageReturn(int ret, char* message, char* messageError);
/// funcion mostrar mensajes para retornos
/// @param ret -recibe el retorno 0 o !=0
/// @param message -mensaje que se muestra al ret==0
/// @param messageError -mensaje que se muestra al ret!=0

int thereArePassengers(ePassenger* list, int len);
/// funcion para saber si hay pasajeros cargados
/// @param list -puntero array de estructura de pasajeros
/// @param len -longitud del array de estructura de pasajeros
/// @return retorna 1 si hay pasajeros o retorna 0 si no hay pasajeros

int modifyPassengers(ePassenger* list, int len, int modifyPosition);
/// funcion para modificar los pasajeros validando la entrada de datos
/// @param list -puntero array de estructura de pasajeros
/// @param len -longitud del array de estructura de pasajeros
/// @param modifyPosition -posicion del array a modificar
/// @return retorna 0 si se ejecuto correctamente, retorna -1 si hubo algun error

int askValidationRemove(ePassenger* list, int len, int* option, int id);
/// funcion pregunta y valida para eliminar al pasajero
/// @param list -puntero array de estructura de pasajeros
/// @param len -longitud del array de estructura de pasajeros
/// @param option -devuelve 1 si se elimina o 2 si no se elimina
/// @param id -el id a eliminar datos
/// @return retorna 0 si se ejecuto correctamente, retorna -1 si hubo algun error

int removeWithValidationPassenger(ePassenger* list, int len, int* id);
/// funcion para eliminar al pasajero con las todas las validaciones
/// @param list -puntero array de estructura de pasajeros
/// @param len -longitud del array de estructura de pasajeros
/// @param id -id a eliminar datos
/// @return retorna 0 para eliminar o -1 si no se elimina

int chargeForce(ePassenger* list, int len, int* id);
/// funcion carga forzada de 10 pasajeros
/// @param list -puntero array de estructura de pasajeros
/// @param len -longitud del array de estructura de pasajeros
/// @param id -devuelve en donde se quedo el id para que no se repita
/// @return -retorna 0 si paso correctamente toda la funcion o -1 si hubo algun error

int haveSumAndPromedy(ePassenger* list,int len,float* promedy, float* sum);
/// funcion para hacer suma y promedio de los pasajeros
/// @param list -puntero array de estructura de pasajeros
/// @param len -longitud del array de estructura de pasajeros
/// @param promedy -devuelve el promedio de los precios
/// @param sum -devuelve la suma de los precios
/// @return retorna 0 si no hubo algun error o -1 si hubo algun error

int menuShowListPassengers(ePassenger* list,eTypePassenger* type, eStatusFlight* status, int len, float promedy, float sum);
///funcion muestra un menu con opciones para informar listas de pasajero
/// @param list -puntero array de estructura de pasajeros
/// @param len -longitud del array de estructura de pasajeros
/// @param type -puntero array de estructura de tipos de pasajero
/// @param status -puntero array de estructura de estados de vuelo
/// @param promedy -recibe promedio a mostrar
/// @param sum -recibe suma a mostrar
/// @return retorna 0 si paso toda la funcion correctamente o -1 si hubo algun error

#endif /* BIBLIO_H_ */
