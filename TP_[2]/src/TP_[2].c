/*
 ============================================================================

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "biblio.h"

#define QTY_PASSENGERS 200
#define QTY_TYPEPASSENGER 3
#define QTY_STATUSFLIGHT 2

int main(void) {
	setbuf(stdout,NULL);
	ePassenger aPassenger[QTY_PASSENGERS];
	eTypePassenger aTypePassenger[QTY_TYPEPASSENGER];
	eStatusFlight aStatusFlight[QTY_STATUSFLIGHT];
	int idPassenger;
	int bufferID;
	int optionMenu;
	int optionCaseOne;
	char auxName[51];
	char auxLastName[51];
	float auxPrice;
	char auxFlycode[10];
	int auxTypePassenger;
	int returnAddPassenger;
	int returnRemovePassenger;
	int returnChargeForce;
	int positionModify;
	float sumPrice;
	float promedyPrice;
	idPassenger=1000;
	initPassengers(aPassenger, QTY_PASSENGERS);
	initTypePassengers(aTypePassenger, QTY_TYPEPASSENGER);
	initStatusFlight(aStatusFlight, QTY_STATUSFLIGHT);
	do{
		if(getMenu(&optionMenu, "1. ALTAS \n2. MODIFICAR \n3. BAJAS \n4. INFORMAR \n5. CARGA FORZADA \n6. SALIR \nIngrese una opcion: ",
				"1. ALTAS \n2. MODIFICAR \n3. BAJA \n4. INFORMAR \n5. CARGA FORZADA \n6. SALIR \nError ingrese una opcion valida: ",6,1)!=0)
		{
			printf("ERROR FUNTION GETMENU");
			break;
		}
		switch(optionMenu)
		{
			case 1:
				do{
					if(getDataPassenger(&idPassenger, auxName, auxLastName, &auxPrice, auxFlycode, &auxTypePassenger)==0)
					{
						returnAddPassenger = addPassenger(aPassenger, QTY_PASSENGERS, idPassenger, auxName, auxLastName, auxPrice, auxTypePassenger, auxFlycode);
						showMessageReturn(returnAddPassenger, "Alta exitosa.","Error, no se cargaron los datos.");
						getMenu(&optionCaseOne,"1. Continuar cargando pasajeros \n2.Salir \nElija una opcion: ","1. Continuar cargando pasajeros \n2.Salir \nError, elija una opcion valida: ",2,1);
					}
					else
					{
						printf("ERROR C1\n");
						system("pause");
						break;
					}
				}while(optionCaseOne!=2);
				break;
			case 2:
				if(thereArePassengers(aPassenger, QTY_PASSENGERS)!=0 && printPassenger(aPassenger,aTypePassenger,aStatusFlight,QTY_PASSENGERS)==0)
				{
					if(getID(aPassenger, QTY_PASSENGERS, &bufferID, "\nIngrese el ID a modificar datos: ", "Error ingrese un ID valido: ")==0)
					{
						positionModify = findPassengerById(aPassenger, QTY_PASSENGERS, bufferID);
						if(positionModify!=-1)
						{
							if(modifyPassengers(aPassenger, QTY_PASSENGERS, positionModify)!=0)
							{
								printf("ERROR FUNTION MODIFYPASSENGERS");
							}
						}
						else
						{
							printf("ERROR FUNTION FINDPASSENGERBYID\n");
							system("pause");
						}
					}
					else
					{
						printf("ERROR C2\n");
						system("pause");
						break;
					}
				}
				else
				{
					printf("Error, no hay pasajeros.\n");
					system("pause");
				}
				break;
			case 3:
				if(thereArePassengers(aPassenger, QTY_PASSENGERS)!=0 && printPassenger(aPassenger,aTypePassenger,aStatusFlight,QTY_PASSENGERS)==0)
				{
					if(removeWithValidationPassenger(aPassenger, QTY_PASSENGERS, &bufferID)==0)
					{
						returnRemovePassenger = removePassenger(aPassenger, QTY_PASSENGERS, bufferID);
						showMessageReturn(returnRemovePassenger,"Eliminado con exito.", "Error, no se pudo eliminar.");
					}
					else
					{
						printf("\nEliminacion cancelada.\n");
						system("pause");
						break;
					}
				}
				else
				{
					printf("Error, no hay pasajeros.\n");
					system("pause");
				}
				break;
			case 4:
				if(thereArePassengers(aPassenger, QTY_PASSENGERS)!=0)
				{
					if(haveSumAndPromedy(aPassenger,QTY_PASSENGERS,&promedyPrice,&sumPrice)!=0)
					{
						printf("ERROR FUNTION HAVESUMANDPROMEDY");
						break;
					}
					if(menuShowListPassengers(aPassenger,aTypePassenger,aStatusFlight, QTY_PASSENGERS, promedyPrice, sumPrice)!=0)
					{
						printf("ERROR FUNTION MENUSHOWLISTPASSENGERS");
						break;
					}
				}
				else
				{
					printf("Error, no hay pasajeros.\n");
					system("pause");
				}
				break;
			case 5:
				returnChargeForce=chargeForce(aPassenger, QTY_PASSENGERS, &idPassenger);
				showMessageReturn(returnChargeForce,"Carga forzada exitosa.", "Error, no se pudo hace la carga forzada.");
				break;
			default:
				break;
		}

	}while(optionMenu!=6);
	return 0;
}
