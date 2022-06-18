#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Passenger.h"
#include "BiblioPersonal.h"
#include "LinkedListA.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

///IMPORTANTE: EJECUTAR DESDE EL EXE CON TP_[3].exe

int main()
{
	setbuf(stdout,NULL);
    int option;
    int ID;
    int itsSaved;
    int itsCharged;
    itsCharged=0;
    ID=0;
    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	if(getMenuForInt(&option,"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
    							"2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n"
    							"3. Alta de pasajero\n"
    							"4. Modificar datos de pasajero\n"
    							"5. Baja de pasajero\n"
    							"6. Listar pasajeros\n"
    							"7. Ordenar pasajeros\n"
    							"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    							"9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n"
    							"10. Salir\n",10,1)==0)
    	{
    		switch(option)
    		{
    			case 1:
    				if(controller_ifExistPassenger(listaPasajeros)==0)//SOLO ENTRA SI NO HAY PASAJEROS CARGADOS
    				{
    					if(controller_loadFromText("data.csv",listaPasajeros)==0//CARGA ARCHIVO DE TEXTO A LISTAPASAJEROS
    							&& controller_loadIdFromBinary(listaPasajeros, &ID)==0)  //ABRIMOS ARCHIVO BINARIO DONDE GUARDAMOS EL ID
    					{
    						itsCharged=1;//ARCHIVO CARGADO
    						system("cls");
    						printf("data.csv CARGADO CON EXITO.\n");
    						system("pause");
    					}
    					else
    					{
    						system("cls");
    						printf("ERROR NO SE PUDO CARGAR data.csv\n");
    						system("pause");
    					}
    				}
    				else//ENTRA SI HAY ALGUN PASAJERO CARGADO
    				{
    					if(itsCharged==0)//ENTRA SI NO HAY ARCHIVO CARGADOS
    					{
    						if(controller_loadIdFromBinary(listaPasajeros, &ID)==0//ABRIMOS ARCHIVO BINARIO DONDE GUARDAMOS EL ID
    								&& controller_setID(listaPasajeros,&ID)==0)//SETEAMOS LOS NUEVOS ID DE LOS PASAJEROS CARGADOS MANUALMENTE
    						{
    							if(controller_loadFromText("data.csv",listaPasajeros)==0)//ABRIMOS ARCHIVO TEXTO DE LISTA PASAJEROS
    							{
    								itsCharged=1;//ARCHIVO CARGADO
    								system("cls");
    								printf("data.csv CARGADO CON EXITO.\n");
    								system("pause");
    							}
    							else
    							{
    								system("cls");
    								printf("ERROR NO SE PUDO CARGAR data.csv\n");
    								system("pause");
    							}
    						}
    					}
    					else//ENTRA SI HAY ALGUN ARCHIVO CARGADO
    					{
    						system("cls");
    						printf("ERROR YA SE CARGO UN ARCHIVO.");
    						system("pause");
    					}
    				}
    				break;
    			case 2:
    				if(controller_ifExistPassenger(listaPasajeros)==0)//SOLO ENTRA SI NO HAY PASAJEROS CARGADOS
    				{
    					if(controller_loadFromBinary("data.dat", listaPasajeros)==0//CARGA ARCHIVO BINARIO A LISTAPASAJEROS
    							&& controller_loadIdFromBinary(listaPasajeros, &ID)==0)//ABRIMOS ARCHIVO BINARIO DONDE GUARDAMOS EL ID
    					{
    						itsCharged=1;//ARCHIVO CARGADO
    						system("cls");
    						printf("data.bin CARGADO CON EXITO.\n");
    						system("pause");
    					}
    					else
    					{
    						system("cls");
    						printf("ERROR NO SE PUDO CARGAR data.bin\n");
    						system("pause");
    					}
    				}
    				else//ENTRA SI HAY ALGUN PASAJERO CARGADO
    				{
    					if(itsCharged==0)//ENTRA SI NO HAY ARCHIVO CARGADOS
    					{
    						if(controller_loadIdFromBinary(listaPasajeros, &ID)==0//ABRIMOS ARCHIVO BINARIO DONDE GUARDAMOS EL ID
    								&& controller_setID(listaPasajeros,&ID)==0)//SETEAMOS LOS NUEVOS ID DE LOS PASAJEROS CARGADOS MANUALMENTE
    						{
    							if(controller_loadFromBinary("data.dat", listaPasajeros)==0)//ABRIMOS ARCHIVO BINARIO DE LISTA PASAJEROS
    							{
    								itsCharged=1;//ARCHIVO CARGADO
    								system("cls");
    								printf("data.csv CARGADO CON EXITO.\n");
    								system("pause");
    							}
    							else
    							{
    								system("cls");
    								printf("ERROR NO SE PUDO CARGAR data.csv\n");
    								system("pause");
    							}
    						}
    					}
    					else//ENTRA SI HAY ALGUN ARCHIVO CARGADO
    					{
    						system("cls");
    						printf("ERROR YA SE CARGO UN ARCHIVO.");
    						system("pause");
    					}

    				}
    				break;
    			case 3:
    				if(controller_addPassenger(listaPasajeros, &ID)==0)//ALTA PASAJERO A LISTA DE TEXTO
    				{
    					system("cls");
    					printf("ALTA EXITOSA.\n");
    					system("pause");
    					itsSaved=0;//INDICO QUE AUN NO SE GUARDA EL ARCHIVO
    				}
    				else
    				{
    					system("cls");
    					printf("ERROR NO SE PUDO DAR EL ALTA.\n");
    					system("pause");
    				}
    				break;
    			case 4:
    				if(controller_ifExistPassenger(listaPasajeros)==1)//ME ASEGURO QUE HAYA AL MENOS 1 PASAJERO PARA ENTRAR A EDITAR
    				{
    					if(controller_editPassenger(listaPasajeros)!=0)//EDITAR PASAJERO POR ID
    					{
    						system("cls");
    						printf("ERROR EN EDITAR PASAJERO.\n");
    						system("pause");
    					}
    				}
    				else
    				{
    					system("cls");
    					printf("ERROR NO HAY PASAJEROS CARGADOS.\n");
    					system("pause");
    				}
    				break;
    			case 5:
    				if(controller_ifExistPassenger(listaPasajeros)==1)//ME ASEGURO QUE HAYA AL MENOS 1 PASAJERO PARA ENTRAR A DAR DE BAJA
    				{
    					if(controller_removePassenger(listaPasajeros)!=0)//DAR DE BAJA PASAJERO
    					{
    						system("cls");
    						printf("ERROR EN DAR DE BAJA.\n");
    						system("pause");;
    					}
    				}
    				else
    				{
    					system("cls");
    					printf("ERROR NO HAY PASAJEROS CARGADOS.\n");
    					system("pause");
    				}
    				break;
    			case 6:
    				if(controller_ifExistPassenger(listaPasajeros)==1)//ME ASEGURO QUE HAYA AL MENOS 1 PASAJERO PARA ENTRAR A LISTAR
    				{
    					if(controller_ListPassenger(listaPasajeros)==0)//LISTA PASAJEROS
    					{
    						system("pause");
    					}
    					else
    					{
    						system("cls");
    						printf("ERROR EN LISTAR PASAJEROS.\n");
    						system("pause");
    					}
    				}
    				else
    				{
    					system("cls");
    					printf("ERROR NO HAY PASAJEROS CARGADOS.\n");
    					system("pause");
    				}
    				break;
    			case 7:
    				if(controller_ifExistPassenger(listaPasajeros)==1)//ME ASEGURO QUE HAYA AL MENOS 1 PASAJERO PARA ENTRAR A LISTAR
    				{
    					if(controller_sortPassenger(listaPasajeros)==0)//ORDENA PASAJEROS POR APELLIDO
    					{
    						system("cls");
    						printf("PASAJEROS ORDENADOS CON EXITO\n");
    						system("pause");
    					}
    				}
    				else
    				{
    					system("cls");
    					printf("ERROR NO HAY PASAJEROS CARGADOS.\n");
    					system("pause");
    				}
    				break;
    			case 8:
    				if(controller_ifExistPassenger(listaPasajeros)==1)//ME ASEGURO QUE HAYA AL MENOS 1 PASAJERO PARA GUARDAR
    				{
    					if(controller_saveAsText("data.csv",listaPasajeros)==0 &&//GUARDAR DATOS A ARCHIVO TEXTO
    							controller_saveIdFromBinary(listaPasajeros, ID)==0)//GUARDO ID EN ARCHIVO BINARIO
    					{
    						system("cls");
    						printf("PASAJEROS GUARDADOS CON EXITO EN data.csv\n");
    						system("pause");
    						itsSaved=1;
    					}
    					else
    					{
    						system("cls");
    						printf("ERROR NO SE PUDO GUARDAR LOS DATOS\n");
    						system("pause");
    					}
    				}
    				else
    				{
    					system("cls");
    					printf("ERROR NO HAY PASAJEROS CARGADOS.\n");
    					system("pause");
    				}
    				break;
    			case 9:
    				if(controller_ifExistPassenger(listaPasajeros)==1)//ME ASEGURO QUE HAYA AL MENOS 1 PASAJERO PARA GUARDAR
    				{
    					if(controller_saveAsBinary("data.dat" ,listaPasajeros)==0//GUARDAR DATOS A ARCHIVO BINARIO
    							&& controller_saveIdFromBinary(listaPasajeros, ID)==0 )//GUARDO ID EN ARCHIVO BINARIO
    					{
    						system("cls");
    						printf("PASAJEROS GUARDADOS CON EXITO EN data.bin\n");
    						system("pause");
    						itsSaved=1;//VERIFICO QUE SE HAYA GUARDADO
    					}
    					else
    					{
    						system("cls");
    						printf("ERROR NO SE PUDO GUARDAR LOS DATOS\n");
    						system("pause");
    					}
    				}
    				else
    				{
    					system("cls");
    					printf("ERROR NO HAY PASAJEROS CARGADOS.\n");
    					system("pause");
    				}
    				break;
    			case 10:
    				if(controller_ifExistPassenger(listaPasajeros)==1)//ME ASEGURO SI SE CARGARON PASAJEROS PARA SALIR
    				{
    					if(itsSaved==1)//VERIFICO QUE SE GUARDARON LOS DATOS EN AL MENOS UN ARCHIVO
    					{
    						ll_deleteLinkedList(listaPasajeros);
    						break;
    					}
    					else//PIDO QUE GUARDE EL ARCHIVO PARA PODER SALIR
    					{
    						system("cls");
    						printf("GUARDE LOS DATOS ANTES DE SALIR.");
    						system("pause");
    						option=-1;
    					}
    				}
    				else//SALGO DEL PROGRAMA SI NO SE CARGO NINGUN DATO
    				{
    					if(controller_saveIdFromBinary(listaPasajeros, ID)==0)
    					{
    						ll_deleteLinkedList(listaPasajeros);
    						break;
    					}
    				}
    		}
    	}
    }while(option != 10);
    return 0;

}

