/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "BiblioPersonal.h"
#include "Passenger.h"
Passenger* Passenger_new()
{
	Passenger* newPassenger;
	newPassenger=NULL;
	newPassenger=(Passenger*) malloc(sizeof(Passenger));
	if(newPassenger!=NULL)
	{
		newPassenger->id=0;
		strcpy(newPassenger->nombre," ");
		strcpy(newPassenger->apellido," ");
		newPassenger->precio=0;
		strcpy(newPassenger->tipoPasajero," ");
		strcpy(newPassenger->codigoVuelo," ");
	}
	return newPassenger;
}

Passenger* Passenger_newParametros(char* idStr,char* nameStr,char* lastNameStr,char* priceStr, char* flyCodeStr, char* typePassengerStr, char* statusFlightStr)
{
	Passenger* newPassenger;
	newPassenger = Passenger_new();
	if(newPassenger!=NULL)
	{
		if((Passenger_setId(newPassenger,atoi(idStr))==0
				&&Passenger_setNombre(newPassenger,nameStr)==0
				&&Passenger_setApellido(newPassenger,lastNameStr)==0
				&&Passenger_setPrecio(newPassenger,atof(priceStr))==0
				&&Passenger_setCodigoVuelo(newPassenger,flyCodeStr)==0
				&&Passenger_setTipoPasajero(newPassenger,typePassengerStr)==0
				&&Passenger_setEstadoVuelo(newPassenger,statusFlightStr)==0))
		{
		}
		else
		{
			free(newPassenger);
			newPassenger=NULL;
		}
	}
	return newPassenger;
}

Passenger* Passenger_newParametrosReally(int id,char* name,char* lastName,float price, char* flyCode, char* typePassenger, char* statusFlight)
{
	Passenger* newPassenger;
	newPassenger = Passenger_new();
	if(newPassenger!=NULL)
	{
		if((Passenger_setId(newPassenger,id)==0
				&&Passenger_setNombre(newPassenger,name)==0
				&&Passenger_setApellido(newPassenger,lastName)==0
				&&Passenger_setPrecio(newPassenger,price)==0
				&&Passenger_setCodigoVuelo(newPassenger,flyCode)==0
				&&Passenger_setTipoPasajero(newPassenger,typePassenger)==0
				&&Passenger_setEstadoVuelo(newPassenger,statusFlight)==0))
		{
		}
		else
		{
			free(newPassenger);
			newPassenger=NULL;
		}
	}
	return newPassenger;
}

void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int ret;
	ret=-1;
	if(this!=NULL && id>0)
	{
		this->id=id;
		ret=0;
	}
	return ret;
}

int Passenger_getId(Passenger* this,int* id)
{
	int ret;
	ret=-1;
	if(this!=NULL)
	{
		*id = this->id;
		ret=0;
	}
	return ret;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int ret;
	ret=-1;
	if(this!=NULL && isText(nombre)==1)
	{
		strcpy(this->nombre,nombre);
		ret=0;
	}
	return ret;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int ret;
	ret=-1;
	if(this!=NULL)
	{
		strcpy(nombre,this->nombre);
		ret=0;
	}
	return ret;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int ret;
	ret=-1;
	if(this!=NULL && isText(apellido)==1)
	{
		strcpy(this->apellido,apellido);
		ret=0;
	}
	return ret;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int ret;
	ret=-1;
	if(this!=NULL)
	{
		strcpy(apellido,this->apellido);
		ret=0;
	}
	return ret;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int ret;
	ret=-1;
	if(this!=NULL && isAlphanumeric(codigoVuelo)==1 && strlen(codigoVuelo)>1)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		ret=0;
	}
	return ret;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int ret;
	ret=-1;
	if(this!=NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		ret=0;
	}
	return ret;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int ret;
	ret=-1;
	if(this!=NULL && tipoPasajero!=NULL && strlen(tipoPasajero)>1 && isText(tipoPasajero)==1)
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		ret=0;
	}
	return ret;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int ret;
	ret=-1;
	if(this!=NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		ret=0;
	}
	return ret;
}

int Passenger_setTipoPasajeroForInt(Passenger* this, int tipoPasajero)
{
	int ret;
	ret=-1;
	if(this!=NULL && tipoPasajero>=1)
	{
		switch(tipoPasajero)
		{
		case 1:
			Passenger_setTipoPasajero(this,"FirstClass");
			ret=0;
			break;
		case 2:
			Passenger_setTipoPasajero(this,"ExecutiveClass");
			ret=0;
			break;
		case 3:
			Passenger_setTipoPasajero(this,"EconomyClass");
			ret=0;
			break;
		default:
			break;
		}
	}
	return ret;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int ret;
	ret=-1;
	if(this!=NULL && precio>0)
	{
		this->precio=precio;
		ret=0;
	}
	return ret;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int ret;
	ret=-1;
	if(this!=NULL)
	{
		*precio = this->precio;
		ret=0;
	}
	return ret;
}

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int ret;
	ret=-1;
	if(this!=NULL && strlen(estadoVuelo)>1 && isText(estadoVuelo)==1)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		ret=0;
	}
	return ret;
}

int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int ret;
	ret=-1;
	if(this!=NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		ret=0;
	}
	return ret;
}

int Passenger_setEstadoVueloForInt(Passenger* this, int estadoVuelo)
{
	int ret;
	ret=-1;
	if(this!=NULL && estadoVuelo>=1)
	{
		switch(estadoVuelo)
		{
		case 1:
			Passenger_setEstadoVuelo(this,"En horario");
			ret=0;
			break;
		case 2:
			Passenger_setEstadoVuelo(this,"En vuelo");
			ret=0;
			break;
		case 3:
			Passenger_setEstadoVuelo(this,"Aterrizado");
			ret=0;
			break;
		case 4:
			Passenger_setEstadoVuelo(this,"Demorado");
			ret=0;
			break;
		default:
			break;
		}
	}
	return ret;
}

int Passenger_sortLastName(void* itemOne, void* itemTwo)
{
	Passenger* auxPassengerOne;
	Passenger* auxPassengerTwo;
	char lastNameOne[50];
	char lastNameTwo[50];
	int ret;
	ret=0;
	if(itemOne!=NULL && itemTwo!=NULL)
	{
		auxPassengerOne = (Passenger*) itemOne;
		auxPassengerTwo = (Passenger*) itemTwo;
		if(Passenger_getApellido(auxPassengerOne,lastNameOne)==0
				&&Passenger_getApellido(auxPassengerTwo,lastNameTwo)==0)
		{
			if(strcmp(lastNameOne,lastNameTwo)>0)
			{
				ret=1;
			}
			else
			{
				ret=-1;
			}
		}
	}
	return ret;
}

int Passenger_sortId(void* itemOne, void* itemTwo)
{
	Passenger* auxPassengerOne;
	Passenger* auxPassengerTwo;
	int idOne;
	int idTwo;
	int ret;
	ret=0;
	if(itemOne!=NULL && itemTwo!=NULL)
	{
		auxPassengerOne = (Passenger*) itemOne;
		auxPassengerTwo = (Passenger*) itemTwo;
		if(Passenger_getId(auxPassengerOne,&idOne)==0
				&&Passenger_getId(auxPassengerTwo,&idTwo)==0)
		{
			if(idOne>idTwo)
			{
				ret=1;
			}
			else
			{
				ret=-1;
			}
		}
	}
	return ret;
}

int Passenger_sortPrice(void* itemOne, void* itemTwo)
{
	Passenger* auxPassengerOne;
	Passenger* auxPassengerTwo;
	float priceOne;
	float priceTwo;
	int ret;
	ret=0;
	if(itemOne!=NULL && itemTwo!=NULL)
	{
		auxPassengerOne = (Passenger*) itemOne;
		auxPassengerTwo = (Passenger*) itemTwo;
		if(Passenger_getPrecio(auxPassengerOne,&priceOne)==0
				&&Passenger_getPrecio(auxPassengerTwo,&priceTwo)==0)
		{
			if(priceOne>priceTwo)
			{
				ret=1;
			}
			else
			{
				ret=-1;
			}
		}
	}
	return ret;
}

int Passenger_validacionEliminar(Passenger* this, int* option)
{
	int ret;
	int id;
	char name[50];
	char lastName[50];
	char bufferOption[2];
	int errorOption;
	errorOption=0;
	ret=-1;
	if(this!=NULL)
	{
		if(Passenger_getId(this,&id)==0 && Passenger_getNombre(this,name)==0
				&& Passenger_getApellido(this,lastName)==0)
		{
			do
			{
				if(errorOption==0)
				{
					system("cls");
					printf("Esta seguro que desea dar de baja al siguiente: \n ID:%d  NOMBRE:%s  APELLIDO:%s\n",id,name,lastName);
					printf("1)DAR DE BAJA \n2)CANCELAR BAJA\nElija una opcion:");
					fflush(stdin);
					gets(bufferOption);
					errorOption++;
				}
				else
				{
					system("cls");
					printf("Esta seguro que desea dar de baja al siguiente: \n ID:%d  NOMBRE:%s  APELLIDO:%s\n",id,name,lastName);
					printf("1)DAR DE BAJA \n2)CANCELAR BAJA\nError,e lija una opcion valida:");
					fflush(stdin);
					gets(bufferOption);
				}
			}while(isNum(bufferOption)==0 || atoi(bufferOption)<1 || atoi(bufferOption)>2);
			if(isNum(bufferOption)==1 && (atoi(bufferOption)==1 || atoi(bufferOption)==2))
			{
				*option = atoi(bufferOption);
				ret=0;
			}
		}
	}

	return ret;
}

