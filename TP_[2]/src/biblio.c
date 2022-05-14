/*
 * biblio.c
 *
 *  Created on: 7 may 2022
 *      Author: --
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "biblio.h"
int isNum(char* array)

{
	int i;
	int haveWord;
	int haveNum;
	int haveSpace;
	int ret;
	haveSpace = 0;
	haveNum = 0;
	haveWord = 0;
	ret=0;
	if(array!=NULL)
	{
		for (i = 0; i < strlen(array); i++)
		{
			char word = array[i];
			if(isalpha(word))
			{
				haveWord = 1;
			}
			if(isdigit(word))
			{
				haveNum = 1;
			}
			if(word==32)
			{
				haveSpace = 1;
			}
		}
		if(haveWord==0 && haveNum==1 && haveSpace==0)
		{
			ret=1;
		}
	}
	return ret;// retorna 1 si es numero o 0 si no es numero
}
int isFloat(char* array)

{
	int i;
	int haveWord;
	int haveNum;
	int havePoint;
	int haveSpace;
	int flagNum;
	int flagPoint;
	int ret;
	havePoint = 0;
	haveNum = 0;
	haveWord = 0;
	haveSpace = 0;
	flagPoint = 0;
	flagNum = 0;
	ret=0;
	if(array!=NULL)
	{
		for (i = 0; i < strlen(array); i++)
		{
			char word = array[i];
			if(isalpha(word))
			{
				haveWord = 1;
			}
			if(isdigit(word))
			{
				haveNum = 1;
				flagNum++;
			}
			if(word==32)// ASCII 32 -> SPACE
			{
				haveSpace = 1;
			}
			if (word==46 && flagNum!=0)// ASCII 46 -> .
			{
				havePoint = 1;
				flagPoint++;
			}
		}
		if(haveWord==0 && haveNum==1 && havePoint == 1 && flagPoint == 1 && haveSpace == 0)
		{
			ret=1;
		}
	}
	return ret;// retorna 1 si es flotante o 0 si no es flotante
}

int isText(char* string)
{
	int ret;
	int i;
	int tieneLetra = 0;
	int tieneNumero = 0;
	ret=0;
	if(string!=NULL)
	{
		for (i = 0; i < strlen(string); i++)
		{
			char letra = string[i];
			if (isalpha(letra))
			{
				tieneLetra = 1;
			}
			if (isdigit(letra))
			{
				tieneNumero = 1;
			}
		}
		if(tieneLetra==1 && tieneNumero==0)
		{
			ret=1;
		}
	}
	return ret; //retorna 1 si es Texto o 0 si no es texto

}
int isAlphanumeric(char *string)
{
	int ret;
	int i;
	int tieneLetra = 0;
	int tieneNumero = 0;
	ret=0;
	if(string!=NULL)
	{
		for (i = 0; i < strlen(string); i++)
		{
			char word = string[i];
			if (isalpha(word))
			{
				tieneLetra = 1;
			}
			if (isdigit(word))
			{
				tieneNumero = 1;
			}
		}
		if(tieneLetra==1 && tieneNumero==1)
		{
			ret=1;
		}
		else
		{
			ret=0;
		}
	}
	return ret;
}

int convertName(char* string)
{
	int ret;
	int i;
	char convertMayus;
	char convertMinus;
	ret=-1;
	if(string!=NULL)
	{
		for(i=0;i<strlen(string);i++)
		{
			if(i==0)
			{
				convertMayus = toupper(string[i]);
				string[i]=convertMayus;
			}
			else
			{
				convertMinus=tolower(string[i]);
				string[i]=convertMinus;
			}
		}
		ret=0;
	}
	return ret;
}

int convertFlyCode(char* string)
{
	int ret;
	int i;
	char convertMayus;
	ret=-1;
	if(string!=NULL)
	{
		for(i=0;i<strlen(string);i++)
		{
			if(isalpha(string[i])!=0)
			{
				convertMayus = toupper(string[i]);
				string[i]=convertMayus;
			}
		}
		ret=0;
	}
	return ret;
}

int getMenu(int* option, char* message, char* messageError, int maxOption, int minOption)
{
	char bufferOption[1024];
	int ret;
	ret=-1;
	if(option!=NULL && message!=NULL && messageError!=NULL)
	{
		system("cls");
		printf(message);
		fflush(stdin);
		gets(bufferOption);
		while(isNum(bufferOption)==0 || strlen(bufferOption)!=1 || atoi(bufferOption)<minOption || atoi(bufferOption)>maxOption)
		{
			system("cls");
			printf(messageError);
			fflush(stdin);
			gets(bufferOption);
		}
		*option = atoi(bufferOption);
		ret=0;
	}


	return ret;
}
int generateID(int* id)
{
	int ret;
	ret=-1;
	int bufferID;
	bufferID= *id;
	if(id!=NULL)
	{
		bufferID++;
		*id=bufferID;
		ret=0;
	}
	return ret;
}
int getName(char* name,char* message, char* messageError, int retry)

{
	int ret;
	char bufferNombre[51];
	ret=-1;
	if(name!=NULL && message!=NULL && messageError!=NULL && retry>0)
	{
		printf(message);
		fflush(stdin);
		gets(bufferNombre);
		while(isText(bufferNombre)==0 || strlen(bufferNombre)>51)
		{
			printf(messageError);
			fflush(stdin);
			gets(bufferNombre);
			retry--;
			if(retry==0)
			{
				break;
			}
		}
		if(isText(bufferNombre)!=0)
		{
			convertName(bufferNombre);
			strcpy(name, bufferNombre);
			ret=0;
		}
		else
		{
			ret=-1;
		}
	}


	return ret; // retorna 1 si es un Nombre, retorna 0 si no es un nombre
}
int getPriceFloat(float* numFloat, char* message, char* messageError, int retry)
{
	int ret;
	char bufferFloat[1024];
	ret=-1;
	if(numFloat!=NULL && message!=NULL && messageError!=NULL)
	{
		printf(message);
		fflush(stdin);
		gets(bufferFloat);
		while(isFloat(bufferFloat)==0 || atof(bufferFloat)<0)
		{
			if(isNum(bufferFloat)!=0)
			{
				break;
			}
			printf(messageError);
			fflush(stdin);
			gets(bufferFloat);
			retry--;
			if(retry==0)
			{
				break;
			}
		}
		if((isFloat(bufferFloat)!=0 && atof(bufferFloat)>=0)||isNum(bufferFloat)!=0)
		{
			*numFloat =atof(bufferFloat);
			ret=0;
		}
		else
		{
			ret=-1;
		}


	}


	return ret;
}

int getFlycode(char* flycode,char* message, char* messageError, int retry)
{
	int ret;
	char bufferFlycode[1024];
	ret=-1;
	if(flycode!=NULL && message!=NULL && messageError!=NULL && retry>0)
	{
		printf(message);
		fflush(stdin);
		gets(bufferFlycode);
		while(isAlphanumeric(bufferFlycode)== 0 || strlen(bufferFlycode)!=10 )
		{
			printf(messageError);
			fflush(stdin);
			gets(bufferFlycode);
			retry--;
			if(retry==0)
			{
				break;
			}

		}
		if(isAlphanumeric(bufferFlycode)!=0 && strlen(bufferFlycode)==10)
		{
			convertFlyCode(bufferFlycode);
			strcpy(flycode, bufferFlycode);
			ret=0;
		}
		else
		{
			ret=-1;
		}

	}
	return ret;
}

int getID(ePassenger* list, int len, int *id, char* message, char* messageError)
{
	int ret;
	int i;
	ePassenger bufferList[len];
	char bufferID[1024];
	ret=-1;
	if(list!=NULL && id!=NULL && message!=NULL && messageError!=NULL)
	{
		for(i=0; i<len; i++)
		{
			bufferList[i] = list[i];
		}
		printf(message);
		fflush(stdin);
		gets(bufferID);
		while(isNum(bufferID)==0 || findPassengerById(bufferList, len, atoi(bufferID))== -1)
		{
			printf(messageError);
			fflush(stdin);
			gets(bufferID);
		}
		if(isNum(bufferID)!=0)
		{
			*id = atoi(bufferID);
			ret=0;
		}
	}

	return ret;
}

int getDataPassenger(int* id, char* name, char* lastname, float* price, char* flycode, int* typePassenger)
{
	int ret;
	int bufferID;
	int retID;
	char bufferName[51];
	int retName;
	char bufferLastName[51];
	int retLastName;
	float bufferPrice;
	int retPrice;
	char bufferFlycode[10];
	int retFlycode;
	int bufferTypePassenger;
	int retTypePassenger;
	bufferID=*id;
	ret=-1;
	if(id!=NULL && name!=NULL && lastname!=NULL && price!=NULL && flycode!=NULL && typePassenger!=NULL )
	{
		system("cls");
		retID = generateID(&bufferID);
		retName = getName(bufferName, "Ingrese el nombre: ", "Error, ingrese un nombre valido: ",100);
		retLastName = getName(bufferLastName, "Ingrese el apellido: ", "Error, ingrese un apellido valido: ", 100);
		retPrice = getPriceFloat(&bufferPrice, "Ingrese el precio : ", "Error, ingrese un precio valido: ",100);
		retFlycode = getFlycode(bufferFlycode, "Ingrese el codigo de vuelo: ", "Error, ingrese un codigo de vuelo valido: ", 100);
		retTypePassenger = getMenu(&bufferTypePassenger, "1. Infante \n2. Adolescente \n3. Adulto \nElija una opcion de tipo de pasajero: ",
				"1. Infante \n2. Adolescente \n3. Adulto \nError, elija una opcion valida de tipo de pasajero: ", 3, 1);
		//                ^Funcion para obtener tipo de pasajero^
		if(retID==0 && retName==0 && retLastName==0 && retPrice==0 && retFlycode==0 && retTypePassenger==0)
		{
			*id = bufferID;
			strcpy(name, bufferName);
			strcpy(lastname, bufferLastName);
			*price = bufferPrice;
			strcpy(flycode, bufferFlycode);
			*typePassenger = bufferTypePassenger;
			ret=0;
		}
		else
		{
			ret=-1;
		}
	}

	return ret; // retornara 0 si todos los datos fueron ingresados correctamente o -1 si hubo algun error en la funcion
}
void showMessageReturn(int ret, char* message, char* messageError)
{
	if(ret==0)
	{
		system("cls");
		printf(message);
		system("pause");
	}
	else
	{
		system("cls");
		printf(messageError);
		system("pause");
	}
}

int thereArePassengers(ePassenger* list, int len)
{
	int ret;
	int i;
	ret=0;
	if(list!=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==0)
			{
				ret=1;
				break;
			}
		}
	}
	return ret;// retorna 0 si no hay pasajeros o retorna 1 si hay pasajeros
}

int modifyPassengers(ePassenger* list, int len, int modifyPosition)
{
	int ret;
	int optionModify;
	char bufferName[51];
	char bufferLastName[51];
	float bufferPrice;
	int bufferTypePassenger;
	char bufferFlyCode[10];
	int bufferStatusFlight;
	ret=-1;
	if(list!=NULL && len>0)
	{
		do
		{
			if(getMenu(&optionModify,"1.Modificar Nombre \n2.Modificar Apellido \n3.Modificar precio \n4.Modificar tipo de pasajero "
					"\n5.Modificar codigo de vuelo \n6.Modificar estado de vuelo \n7.Salir \nElija una opcion:  ",
					"1.Modificar Nombre \n2.Modificar Apellido \n3.Modificar precio \n4.Modificar tipo de pasajero \n5.Modificar codigo de vuelo "
					"\n6.Modificar estado de vuelo \n7.Salir \nError, elija una opcion valida:  ",7,1)==0)
			{
				switch(optionModify)

				{
					case 1:
						if(getName(bufferName, "Ingrese el nuevo nombre: ","Error ingrese un nombre valido: ",100)==0)
						{
							strcpy(list[modifyPosition].name, bufferName);
							system("cls");
							printf("Cambio de nombre exitoso.\n");
							system("pause");
						}
						else
						{
							system("cls");
							printf("Error, no se guardo el nombre.\n");
							system("pause");
						}
						break;
					case 2:
						if(getName(bufferLastName, "Ingrese el nuevo apellido: ", "Error ingrese un apellido valido: ",100)==0)
						{
							strcpy(list[modifyPosition].lastName, bufferLastName);
							system("cls");
							printf("Cambio de apellido exitoso.\n");
							system("pause");
						}
						else
						{
							system("cls");
							printf("Error, no se guardo el nombre.\n");
							system("pause");
						}
						break;
					case 3:
						if(getPriceFloat(&bufferPrice, "Ingrese el nuevo precio: ", "Error ingrese un precio valido: ", 100)==0)
						{
							list[modifyPosition].price = bufferPrice;
							system("cls");
							printf("Cambio de precio exitoso.\n");
							system("pause");
						}
						else
						{
							system("cls");
							printf("Error, no se guardo el precio.\n");
							system("pause");
						}
						break;
					case 4:
						if(getMenu(&bufferTypePassenger, "1. INFANTE \n2.ADOLESCENTE \n3.ADULTO \nElija una opcion: ","1. INFANTE \n2.ADOLESCENTE \n3.ADULTO \nError, elija una opcion valida: ",3,1 )==0)
						{
							list[modifyPosition].typePassenger = bufferTypePassenger;
							system("cls");
							printf("Cambio de tipo de pasajero exitoso.\n");
							system("pause");
						}
						else
						{
							system("cls");
							printf("Error, no se guardo el tipo de pasajero.\n");
							system("pause");
						}
						break;
					case 5:
						if(getFlycode(bufferFlyCode, "Ingrese el nuevo codigo de vuelo: ", "Error, ingrese un codigo de vuelo valido: ",100) == 0)
						{
							strcpy(list[modifyPosition].flycode, bufferFlyCode);
							system("cls");
							printf("Cambio codigo de vuelo exitoso.\n");
							system("pause");
						}
						else
						{
							system("cls");
							printf("Error, no se guardo el codigo de vuelo.\n");
							system("pause");
						}
						break;
					case 6:
						if(getMenu(&bufferStatusFlight,"CAMBIO DE ESTADO DE VUELO:\n1.ACTIVO \n2.INACTIVO \nElija una opcion: ","CAMBIO DE ESTADO DE VUELO:\n1.ACTIVO \n2.INACTIVO \nElija una opcion valida: ",2,1)==0)
						{
							(list+modifyPosition)->statusFlight = bufferStatusFlight;
							system("cls");
							printf("Cambio estado de vuelo exitoso.\n");
							system("pause");
						}
						else
						{
							system("cls");
							printf("Error, no se cambio el estado de vuelo.\n");
							system("pause");
						}
						break;
				}
				ret=0;
			}
		}while(optionModify!=7);
	}
	return ret;//
}

int removeWithValidationPassenger(ePassenger* list, int len, int* id)
{
	int ret;
	int i;
	int option;
	int returnValidation;
	int returnExistID;
	int bufferID;
	ePassenger bufferList[len];
	ret=-1;
	if(list!=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
				bufferList[i]= list[i];
		}

		returnExistID = getID(bufferList, len, &bufferID, "Ingrese el ID de la persona a eliminar a eliminar: ", "Error ingrese un ID correcto: ");
		if(returnExistID==0)
		{
			returnValidation=askValidationRemove(bufferList,len,&option, bufferID);
			if(returnValidation==0)
			{
				switch(option)
				{
					case 1:
						*id = bufferID;
						ret=0;
						break;
					default:
						break;
				}
			}
		}

	}
	return ret;
}

int chargeForce(ePassenger* list, int len, int* id)
{
	int ret;
	int i;
	float aumentPrice;
	int aumentTypePassenger;
	int aumentStatusFlight;
	int bufferID;
	bufferID=*id;
	aumentPrice=100000;
	aumentStatusFlight=1;
	aumentTypePassenger=1;
	ret=-1;
	if(list!=NULL && len>0 && id!=NULL)
	{
		strcpy((list)->name,"Jose");
		strcpy((list)->lastName,"Ramirez");
		strcpy((list)->flycode,"ABCDEF1234");
		strcpy((list+1)->name,"Mauro");
		strcpy((list+1)->lastName,"Reinosa");
		strcpy((list+1)->flycode,"ABC3EF1234");
		strcpy((list+2)->name,"Manuel");
		strcpy((list+2)->lastName,"Martinez");
		strcpy((list+2)->flycode,"AB35EF1234");
		strcpy((list+3)->name,"Leandro");
		strcpy((list+3)->lastName,"Paredes");
		strcpy((list+3)->flycode,"ABC12D1234");
		strcpy((list+4)->name,"Fernando");
		strcpy((list+4)->lastName,"Gale");
		strcpy((list+4)->flycode,"AB4251234");
		strcpy((list+5)->name,"Juan");
		strcpy((list+5)->lastName,"Martinez");
		strcpy((list+5)->flycode,"D31DEF1234");
		strcpy((list+6)->name,"Gabriel");
		strcpy((list+6)->lastName,"Duran");
		strcpy((list+6)->flycode,"D324K54KFD");
		strcpy((list+7)->name,"Dario");
		strcpy((list+7)->lastName,"Jimenez");
		strcpy((list+7)->flycode,"D345FGEDFD");
		strcpy((list+8)->name,"Martin");
		strcpy((list+8)->lastName,"Caceres");
		strcpy((list+8)->flycode,"B324FEKKFD");
		strcpy((list+9)->name,"Sandro");
		strcpy((list+9)->lastName,"Chavez");
		strcpy((list+9)->flycode,"D324442SFD");
		for(i=0;i<10;i++)
		{
			bufferID++;
			aumentStatusFlight++;
			aumentTypePassenger++;
			aumentPrice=aumentPrice+10000;
			if(aumentStatusFlight==3)
			{
				aumentStatusFlight=1;
			}
			if(aumentTypePassenger==4)
			{
				aumentTypePassenger=1;
			}
			list[i].id = bufferID;
			list[i].price = aumentPrice;
			list[i].typePassenger = aumentTypePassenger;
			list[i].statusFlight = aumentStatusFlight;
			list[i].isEmpty = 0;

		}
		*id = bufferID;
		ret=0;
	}

	return ret;
}

int menuShowListPassengers(ePassenger* list,eTypePassenger* type, eStatusFlight* status, int len, float promedy, float sum)
{
	int ret;
	int option;
	int i;
	int j;
	int k;
	ret=-1;
	if(list!=NULL && len>0)
	{
		do{
			if(getMenu(&option,"\n1. Lista de pasajeros ordenados por apellido y tipo de pasajero "
												"\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio "
												"\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ \n4.SALIR \nElija una opcion: ",
												"\n1. Lista de pasajeros ordenados por apellido y tipo de pasajero "
												"\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio "
															"\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ \n4.SALIR \nError, elija una opcion valida: ",4,1)==0)
			{
				ret=0;
				switch(option)
				{
					case 1:
						system("cls");
						sortPassengers(list,len,1);
						printPassenger(list,type, status, len);
						system("pause");
						break;
					case 2:
						system("cls");
						printf("********************************\n");
						printf("PRECIO TOTAL: %.2f\nPROMEDIO DE PRECIO: %.2f\n",sum, promedy);
						printf("********************************\n");
						printf("\n                              LISTA DE PERSONAS QUE SUPERAN EL PRECIO PROMEDIO");
						printf("\n*******************************************************************************************************************************\n");
						printf("| ID |  |APELLIDO|              |NOMBRE|           |PRECIO|          |CODIGO DE VUELO|    |TIPO DE PASAJERO|      |ESTADO DE VUELO|\n");
						for(i=0;i<len;i++)
						{
							if((list+i)->price > promedy && (list+i)->isEmpty == 0)
							{
								for(j=0;i<len;j++)
								{
									if((list+i)->typePassenger == (type+j)->typePassenger)
									{
										for(k=0;i<len;k++)
										{
											if((list+i)->statusFlight == (status+k)->statusFlight)
											{
												printf(" %-4d    %-20s   %-20s%-10.2f        %-10s           %-12s            %-10s\n",
														list[i].id,list[i].lastName, list[i].name, list[i].price,list[i].flycode, type[j].description, status[k].description);
												break;
											}
										}
										break;
									}
								}
							}
						}
						printf("\n*******************************************************************************************************************************\n");
						system("pause");
						break;
					case 3:
						system("cls");
						sortPassengersByCode(list,len,1);
						printf("\n                                    LISTA DE PERSONAS CON ESTADO DE VUELO ACTIVO ");
						printf("\n*******************************************************************************************************************************\n");
						printf("|CODIGO DE VUELO|  | ID |    |APELLIDO|           |NOMBRE|             |PRECIO|      |TIPO DE PASAJERO|  |ESTADO DE VUELO|\n");
						for(i=0;i<len;i++)
						{
							if((list+i)->statusFlight==1 && (list+i)->isEmpty == 0)
							{
								for(j=0;i<len;j++)
								{
									if((list+i)->typePassenger == (type+j)->typePassenger)
									{
										for(k=0;i<len;k++)
										{
											if((list+i)->statusFlight == (status+k)->statusFlight)
											{
												printf("    %-10s      %-4d      %-20s %-20s%-12.2f      %-11s           %-11s \n",(list+i)->flycode, (list+i)->id, (list+i)->lastName, (list+i)->name, (list+i)->price,(type+j)->description, (status+k)->description);
												break;
											}
										}
										break;
									}
								}
							}
						}
						printf("\n*******************************************************************************************************************************\n");
						system("pause");
						break;
				}
			}
		}while(option!=4);

	}
	return ret;
}

int askValidationRemove(ePassenger* list, int len, int* option, int id)
{

	char bufferOption[1024];
	int i;
	int ret;
	ret=-1;
	if(option!=NULL && list!=NULL && len>0)
	{
		system("cls");
		printf("ESTA A PUNTO DE DAR DE BAJA A :\n");
		printf("| ID |  |APELLIDO|              |NOMBRE|\n");
		for(i=0;i<len;i++)
		{
			if((list+i)->isEmpty==0 && (list+i)->id==id)
			{
				printf(" %-4d    %-20s   %-20s\n",(list+i)->id, (list+i)->lastName, (list+i)->name);
				break;
			}
		}
		printf("********************************************");
		printf("\n1.Dar de baja \n2.Cancelar la baja \nElija una opcion:");
		fflush(stdin);
		gets(bufferOption);
		while(isNum(bufferOption)==0 || strlen(bufferOption)!=1 || atoi(bufferOption)<1 || atoi(bufferOption)>2)
		{
			system("cls");
			printf("ESTA A PUNTO DE DAR DE BAJA A :\n");
			printf("| ID |  |APELLIDO|              |NOMBRE|\n");
			for(i=0;i<len;i++)
			{
				if((list+i)->isEmpty==0 && (list+i)->id==id)
				{
					printf(" %-4d    %-20s   %-20s\n",(list+i)->id, (list+i)->lastName, (list+i)->name);
					break;
				}
			}
			printf("********************************************");
			printf("\n1.Dar de baja \n2.Cancelar la baja \nElija una opcion valida:");
			fflush(stdin);
			gets(bufferOption);;
		}
		*option = atoi(bufferOption);
		ret=0;
	}
	return ret;
}

int haveSumAndPromedy(ePassenger* list,int len,float* promedy, float* sum)
{
	int ret;
	int acum;
	int count;
	int i;
	acum=0;
	count=0;
	ret=-1;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if((list+i)->isEmpty == 0)
			{
				acum=(list+i)->price+acum;
				count++;
			}
		}
		if(count>0)
		{
			*promedy=acum/count;
		}
		*sum=acum;
		ret=0;
	}

	return ret;
}
