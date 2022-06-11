#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Controller.h"
#include "BiblioPersonal.h"
#include "parser.h"
#include "LinkedList.h"
#include "Passenger.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int ret;
	ret=-1;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL)
		{
			if(parser_PassengerFromText(pFile, pArrayListPassenger)==0)
			{
				ret=0;
			}
		}
	}
	fclose(pFile);
    return ret;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pFile;
	int ret;
	ret=-1;
	if(path!=NULL && pArrayListPassenger)
	{
		pFile = fopen(path,"rb");
		if(pFile != NULL)
		{
			if(parser_PassengerFromBinary(pFile, pArrayListPassenger)==0)
			{
				ret=0;
			}
		}
	}
	fclose(pFile);
	return ret;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* ID)
{
	int ret;
	Passenger* auxPassenger;
	auxPassenger=Passenger_new();
	int id;
	char name[50];
	char lastName[50];
	float price;
	char flyCode[7];
	int optionTypePassenger;
	int optionStatusFlight;
	id=*ID+1;
	ret=-1;
	if(pArrayListPassenger!=NULL)
	{
		if(	getText(name,"Ingrese el nombre: ", "Error ingrese un nombre valido: ", 10)==0
				&& getText(lastName,"Ingrese el apellido: ", "Error ingrese un apellido valido: ",10)==0
				&& getFloat(&price, "Ingrese el precio: ", "Error ingrese un precio valido: ", 10)==0
				&& getAlphanumeric(flyCode,"Ingrese el codigo de vuelo(7 DIGITOS): ", "Error ingrese un codigo de vuelo valido(7 DIGITOS):", 10)==0
				&& getMenuForInt(&optionTypePassenger, "1)FirstClass \n2)ExecutiveClass \n3)EconomyClass ",3,1)==0
				&& getMenuForInt(&optionStatusFlight,"1)En horario \n2)En vuelo \n3)Aterrizado \n4)Demorado", 4, 1)==0)
		{

			if(Passenger_setTipoPasajeroForInt(auxPassenger, optionTypePassenger)==0
					&& 	Passenger_setEstadoVueloForInt(auxPassenger, optionStatusFlight)==0
					&& 	Passenger_setId(auxPassenger,id)==0
					&&	Passenger_setNombre(auxPassenger,name)==0
					&&	Passenger_setApellido(auxPassenger,lastName)==0
					&&	Passenger_setPrecio(auxPassenger,price)==0
					&&	Passenger_setCodigoVuelo(auxPassenger,flyCode)==0)
			{
				ll_add(pArrayListPassenger,auxPassenger);
				*ID=id;
				ret=0;
			}
		}
		else
		{
			printf("ERROR NO SE PUDO DAR DE ALTA.");
		}
	}

    return ret;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* auxPassenger;
	auxPassenger=Passenger_new();
	int ret;
	char name[50];
	char lastName[50];
	float price;
	char flyCode[8];
	int optionTypePassenger;
	int optionStatusFlight;
	int optionEdit;
	int index;
	ret=-1;
	if(pArrayListPassenger!=NULL)
	{
		if(controller_ListPassenger(pArrayListPassenger)==0
				&& getId(pArrayListPassenger,"Escriba el id a modificar: ","Error escriba un id valido para modificar:",&index)==0)
		{
			auxPassenger=ll_get(pArrayListPassenger, index);
			do{
				if(getMenuForInt(&optionEdit,"1) Modificar nombre \n2) Modificar apellido \n3) Modificar precio"
						"\n4) Modificar codigo de vuelo \n5) Modificar tipo de pasajero "
						"\n6) Modificar estado de vuelo \n7) Salir", 7, 1)==0)
				{
					switch(optionEdit)
					{
					case 1:
						if(getText(name,"Ingrese el nuevo nombre: ", "Error ingrese un nombre nuevo valido", 10)==0
								&& Passenger_setNombre(auxPassenger,name)==0)
						{
								ll_set(pArrayListPassenger,index,auxPassenger);
								printf("Nombre modificado con exito.");
								system("pause");
						}
						else
						{
							printf("ERROR NO SE PUDO MODIFICAR EL NOMBRE.");
							system("pause");
						}
						break;
					case 2:
						if(getText(lastName,"Ingrese el nuevo apellido: ", "Error ingrese un apellido nuevo valido", 10)==0
								&& Passenger_setApellido(auxPassenger,lastName)==0)
						{
							ll_set(pArrayListPassenger,index,auxPassenger);
							printf("Apellido modificado con exito.");
							system("pause");
						}
						else
						{
							printf("ERROR NO SE PUDO MODIFICAR EL APELLIDO.");
							system("pause");
						}
						break;
					case 3:
						if(getFloat(&price, "Ingrese el nuevo precio: ", "Error ingrese un precio nuevo valido: ", 10)==0
								&& Passenger_setPrecio(auxPassenger,price)==0)
						{
							ll_set(pArrayListPassenger,index,auxPassenger);
							printf("Precio modificado con exito.");
							system("pause");
						}
						else
						{
							printf("ERROR NO SE PUDO MODIFICAR EL PRECIO.");
							system("pause");
						}
						break;
					case 4:
						if(getAlphanumeric(flyCode,"Ingrese el nuevo codigo de vuelo(7 DIGITOS): ", "Error ingrese un nuevo codigo de vuelo valido(7 DIGITOS):", 10)==0
								&& Passenger_setCodigoVuelo(auxPassenger,flyCode)==0)
						{
							ll_set(pArrayListPassenger,index,auxPassenger);
							printf("Codigo de vuelo modificado con exito.");
							system("pause");
						}
						else
						{
							printf("ERROR NO SE PUDO MODIFICAR EL CODIGO DE VUELO.");
							system("pause");
						}
						break;
					case 5:
						if(getMenuForInt(&optionTypePassenger, "MODIFICAR\n 1)FirstClass \n2)ExecutiveClass \n3)EconomyClass ",3,1)==0
								&& Passenger_setTipoPasajeroForInt(auxPassenger,optionTypePassenger)==0)
						{
							ll_set(pArrayListPassenger,index,auxPassenger);
							printf("Tipo de pasajero modificado con exito.");
							system("pause");
						}
						else
						{
							printf("ERROR NO SE PUDO MODIFICAR EL TIPO DE PASAJERO.");
							system("pause");
						}
						break;
					case 6:
						if(getMenuForInt(&optionStatusFlight,"1)En horario \n2)En vuelo \n3)Aterrizado \n4)Demorado", 4, 1)==0
								&& Passenger_setEstadoVueloForInt(auxPassenger,optionStatusFlight)==0)
						{
							ll_set(pArrayListPassenger,index,auxPassenger);
							printf("Estado de vuelo modificado con exito.");
							system("pause");
						}
						else
						{
							printf("ERROR NO SE PUDO MODIFICAR EL ESTADO DE VUELO.");
							system("pause");
						}
						break;
					default:
						break;
					}
				}
			}while(optionEdit!=7);
			ret=0;
		}
	}
    return ret;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	Passenger* auxPassenger;
	int ret;
	int optionRemove;
	int index;
	ret=-1;
	if(pArrayListPassenger!=NULL)
	{
		if(controller_ListPassenger(pArrayListPassenger)==0
				&& getId(pArrayListPassenger,"Escriba el id a dar de baja: ","Error escriba un id valido para dar de baja:", &index)==0)
		{
			auxPassenger = Passenger_new();
			auxPassenger = ll_get(pArrayListPassenger,index);
			if(auxPassenger!=NULL)
			{
				if(Passenger_validacionEliminar(auxPassenger, &optionRemove)==0)//optionRemove=1 DAR BAJA or optionRemove=2 CANCELAR BAJA
				{
					switch(optionRemove)
					{
						case 1:
							ll_remove(pArrayListPassenger,index);
							printf("BAJA EXITOSA.");
							system("pause");
							ret=0;
							break;
						case 2:
							printf("BAJA CANCELADA CON EXITO.");
							system("pause");
							ret=0;
							break;
						default:
							break;
					}
				}
			}
		}
	}
    return ret;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* auxPassenger;
	auxPassenger=Passenger_new();
	int ret;
	int id;
	char name[50];
	char lastName[50];
	float price;
	char flyCode[8];
	char typePassenger[16];
	char statusFlight[16];
	int i;
	ret=-1;
	if(pArrayListPassenger!=NULL)
	{
		printf("| ID |  | NOMBRE |        | APELLIDO |          | PRECIO |     | CODIGO DE VUELO |  | TIPO DE PASAJERO |  | ESTADO DE VUELO |\n");
		for(i=0;i<ll_len(pArrayListPassenger);i++)
		{
			if(auxPassenger!=NULL)
			{
				auxPassenger=ll_get(pArrayListPassenger, i);
				if(Passenger_getId(auxPassenger,&id)==0
							&& Passenger_getNombre(auxPassenger,name)==0
							&& Passenger_getApellido(auxPassenger,lastName)==0
							&& Passenger_getPrecio(auxPassenger,&price)==0
							&& Passenger_getCodigoVuelo(auxPassenger,flyCode)==0
							&& Passenger_getTipoPasajero(auxPassenger,typePassenger)==0
							&& Passenger_getEstadoVuelo(auxPassenger,statusFlight)==0)
				{
					printf("  %-5d  %-15s    %-15s      %-12.2f       %-8s          %-16s       %-16s\n",id, name, lastName, price, flyCode,
																										typePassenger,statusFlight);
				}
			}
		}
		ret=0;
	}
    return ret;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int ret;
	int option;
	ret=-1;
	if(pArrayListPassenger!=NULL)
	{
		if(getMenuForInt(&option,"ODENAMIENTO: \n1)Por Apellido \n2)Por ID \n3)Por Precio ",3,1)==0)
		{
			system("cls");
			printf("ORDENANDO....");
			switch(option)
			{
				case 1:
					ll_sort(pArrayListPassenger,Passenger_sortLastName,1);
					ret=0;
					break;
				case 2:
					ll_sort(pArrayListPassenger,Passenger_sortId,1);
					ret=0;
					break;
				case 3:
					ll_sort(pArrayListPassenger,Passenger_sortPrice,1);
					ret=0;
					break;
				default:
					break;
			}
		}
	}
    return ret;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* auxPassenger;
	auxPassenger=Passenger_new();
	int ret;
	int i;
	int id;
	char name[50];
	char lastName[50];
	float price;
	char flyCode[8];
	char typePassenger[16];
	char statusFlight[16];
	ret=-1;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile = fopen(path,"w");
		if(pFile!=NULL)
		{
			fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
			for(i=0;i<ll_len(pArrayListPassenger);i++)
			{
				auxPassenger=ll_get(pArrayListPassenger,i);
				if(auxPassenger!=NULL)
				{
					if(Passenger_getId(auxPassenger,&id)==0
							&& Passenger_getNombre(auxPassenger,name)==0
							&& Passenger_getApellido(auxPassenger,lastName)==0
							&& Passenger_getPrecio(auxPassenger,&price)==0
							&& Passenger_getCodigoVuelo(auxPassenger,flyCode)==0
							&& Passenger_getTipoPasajero(auxPassenger,typePassenger)==0
							&& Passenger_getEstadoVuelo(auxPassenger,statusFlight)==0)
					{
						fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",id,name,lastName,price,flyCode,typePassenger,statusFlight);
					}
				}
			}
			ret=0;
		}
		fclose(pFile);
	}
    return ret;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFileBin;
	Passenger* auxPass;
	auxPass=Passenger_new();
	int ret;
	int i;
	int r;
	int rSaved;
	rSaved=0;
	ret=-1;
	if(path!=NULL && pArrayListPassenger)
	{
		pFileBin = fopen(path,"wb");
		if(pFileBin!=NULL)
		{
			for(i=0;i<ll_len(pArrayListPassenger);i++)
			{
				auxPass = ll_get(pArrayListPassenger,i);
				r=fwrite(auxPass,sizeof(Passenger),1,pFileBin);
				rSaved=rSaved+r;
			}
			if(rSaved==ll_len(pArrayListPassenger))
			{
				ret=0;
			}
		}
		fclose(pFileBin);
	}
    return ret;
}


/// @brief Verifica si existen pasajeros en memoria
///
/// @param pArrayListPassenger
/// @return retorna 1 si existe alguno o 0 si no hay ninguno
int controller_ifExistPassenger(LinkedList* pArrayListPassenger)
{
	int ret;
	ret=0;
	if(pArrayListPassenger!=NULL)
	{
		if(ll_len(pArrayListPassenger)>0)
		{
			ret=1;
		}
	}
	return ret;
}



/// @brief Setea los id de pasajeros en memoria para que no se repitan
///
/// @param pArrayListPassenger
/// @param id
/// @return retorna 0 si lo hizo con exito o -1 si hubo algun error
int controller_setID(LinkedList* pArrayListPassenger,int* id)
{
	Passenger* bufferPass;
	bufferPass=Passenger_new();
	int ret;
	int auxId;
	char name[50];
	char lastName[50];
	int bufferId;
	int i;
	bufferId=*id;
	ret=-1;
	if(pArrayListPassenger!=NULL)
	{
		system("cls");
		printf("PASAJEROS CON ID CAMBIADO POR CARGA DE ARCHIVO:\n");
		printf("***************************************************\n");
		for(i=0;i<ll_len(pArrayListPassenger);i++)
		{
			bufferPass=ll_get(pArrayListPassenger,i);
			if(bufferPass!=NULL)
			{
				bufferId++;
				if(Passenger_getId(bufferPass, &auxId)==0
						&&Passenger_getNombre(bufferPass, name)==0
						&&Passenger_getApellido(bufferPass, lastName)==0)
				{
					printf("ID:%d NOMBRE:%s APELLIDO:%s ------> NUEVO ID:%d\n",auxId,name,lastName,bufferId);

				}
				if(Passenger_setId(bufferPass,bufferId)==0)
				{
					ll_set(pArrayListPassenger, i,bufferPass);
				}
			}
		}
		system("pause");
		*id=bufferId;
		ret=0;
	}
	return ret;
}



/// @brief Guarda el id en un archivo binario
///
/// @param pArrayListPassenger
/// @param id ID a guardar
/// @return retorna 0 si se guardo correctamente o -1 si hubo algun error
int controller_saveIdFromBinary(LinkedList* pArrayListPassenger, int id)
{
	FILE* pFileBin;
	int ret;
	ret=-1;
	if(pArrayListPassenger!=NULL)
	{
		pFileBin=fopen("saveID.dat","wb");
		if(pFileBin!=NULL)
		{
			id=1000;
			if(fwrite(&id,sizeof(int),1,pFileBin)==1)
			{
				ret=0;
			}
		}
		fclose(pFileBin);
	}
	return ret;
}


/// @brief Abre el archivo binario para lectura del id
///
/// @param pArrayListPassenger
/// @param id devuelve id leido del archivo binario
/// @return retorna 0 si se lee correctamente o -1 si hubo algun error
int controller_loadIdFromBinary(LinkedList* pArrayListPassenger, int* id)
{
	FILE *pFile;
	int ret;
	ret=-1;
	if(pArrayListPassenger!=NULL)
	{
		pFile = fopen("saveID.dat","rb");
		if(pFile != NULL)
		{
			if(parser_IdFromBinary(pFile,id)==0)
			{
				ret=0;
			}
		}
	}
	fclose(pFile);
	return ret;
}
