#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Passenger.h"
#include "BiblioPersonal.h"
#include "LinkedListA.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* auxPassenger;
	int ret;
	int r;
	char id[5];
	char name[20];
	char lastName[20];
	char price[15];
	char flyCode[8];
	char typePassenger[16];
	char statusFlight[16];
	ret=-1;
	r=0;
	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,name,lastName,price,flyCode,typePassenger,statusFlight);
		while(!feof(pFile))
		{
			r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,name,lastName,price,flyCode,typePassenger,statusFlight);
			if(r<7)
			{
				break;
			}
			auxPassenger = Passenger_newParametros(id,name,lastName,price,flyCode,typePassenger,statusFlight);
			if(auxPassenger!=NULL && findId(pArrayListPassenger,atoi(id))==-1)
			{
				ll_add(pArrayListPassenger, auxPassenger);
				ret=0;
			}
		}
	}
    return ret;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger aux;
	Passenger* auxP;
	int ret;
	int id;
	char name[20];
	char lastName[20];
	float price;
	char flyCode[8];
	char typePassenger[16];
	char statusFlight[16];
	int r;
	ret=-1;
	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		do
		{
			r=fread(&aux,sizeof(Passenger),1,pFile);
			if(Passenger_getId(&aux,&id)==0
							&& Passenger_getNombre(&aux,name)==0
							&& Passenger_getApellido(&aux,lastName)==0
							&& Passenger_getPrecio(&aux,&price)==0
							&& Passenger_getCodigoVuelo(&aux,flyCode)==0
							&& Passenger_getTipoPasajero(&aux,typePassenger)==0
							&& Passenger_getEstadoVuelo(&aux,statusFlight)==0)
			{
				if(r==1 && findId(pArrayListPassenger,id)==-1)
				{
					auxP = Passenger_newParametrosReally(id,name,lastName,price,flyCode,typePassenger,statusFlight);
					ll_add(pArrayListPassenger, auxP);
				}
			}

		}while(feof(pFile)==0);

		ret=0;
	}
    return ret;
}


int parser_IdFromBinary(FILE* pFile,int* id)
{
	int auxId;
	int ret;
	ret=-1;
	if(pFile!=NULL && id!=NULL)
	{
		if(fread(&auxId,sizeof(int),1,pFile)==1)
		{
			*id = auxId;
			ret=0;
		}
	}
	return ret;
}
