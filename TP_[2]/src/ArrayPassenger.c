/*
 * ArrayPassenger.c
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


int initTypePassengers(eTypePassenger* list, int len)
{
	int ret;
	ret=-1;
	if(list!=NULL && len>0)
	{
		(list)->typePassenger = 1;
		strcpy((list)->description,"Infante");
		(list+1)->typePassenger = 2;
		strcpy((list+1)->description,"Adolescente");
		(list+2)->typePassenger = 3;
		strcpy((list+2)->description,"Adulto");
	}

	return ret;
}
int initStatusFlight(eStatusFlight* list, int len)
{
	int ret;
	ret=-1;
	if(list!=NULL && len>0)
	{
		(list)->statusFlight=1;
		strcpy((list)->description,"ACTIVO");
		(list+1)->statusFlight=2;
		strcpy((list+1)->description,"INACTIVO");
	}
	return ret;
}

int initPassengers(ePassenger* list,int  len)
{
	int ret;
	int i;
	ret=-1;
	if(list!=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			(list+i)->isEmpty=1;
		}
		ret=0;

	}
	return ret;
}

int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int ret;
	int i;
	ret=-1;
	if(list!=NULL && len>0 && name!=NULL && lastName!=NULL && flycode!=NULL)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==1)
			{
				(list+i)->id = id;
				strcpy((list+i)->name, name);
				strcpy((list+i)->lastName, lastName);
				(list+i)->price = price;
				(list+i)->typePassenger = typePassenger;
				strcpy((list+i)->flycode, flycode);
				(list+i)->statusFlight = 1;
				(list+i)->isEmpty = 0;
				break;
			}
		}
		ret=0;

	}

	return ret;
}

int findPassengerById(ePassenger* list, int len,int id)
{
	int i;
	int ret;
	ret=-1;
	if(list!=NULL && len>0 && id>1000)
	{
		for(i=0; i<len; i++)
		{
			if((list+i)->id == id && (list+i)->isEmpty == 0)
			{
				ret=i;
				break;
			}
		}
	}
	return ret;
}

int removePassenger(ePassenger* list, int len, int id)
{
	int ret;
	int i;
	ret=-1;
	if(list!=NULL && len>0 )
	{
		for(i=0; i<len; i++)
		{
			if((list+i)->id==id && (list+i)->isEmpty==0)
			{
				(list+i)->isEmpty=1;
				ret=0;
				break;
			}
		}
	}

	return ret;
}

int sortPassengers(ePassenger* list, int len, int order)
{
	int ret;
	int flag;
	int flag2;
	ePassenger aux;
	flag2=1;
	int i;
	ret=-1;
	flag=1;
	if(list!=NULL && len>0 && (order==0 || order == 1))
	{
		if(order==0)
		{
			while(flag==1)
			{
				flag=0;
				for(i=1;i<len;i++)
				{
					if(strcmp((list+i)->lastName, (list+i-1)->lastName)>0)
					{
						aux=list[i];
						list[i]=list[i-1];
						list[i-1]=aux;
						flag=1;
					}
				}
			}
			while(flag2==1)
			{
				flag2=0;
				for(i=1;i<len;i++)
				{
					if((((list+i)->typePassenger)>((list+i-1)->typePassenger)))
					{
						aux=list[i];
						list[i]=list[i-1];
						list[i-1]=aux;
						flag2=1;
					}
				}
			}
			ret=0;
		}
		else
		{
			while(flag==1)
			{
				flag=0;
				for(i=1;i<len;i++)
				{
					if(strcmp((list+i)->lastName, (list+i-1)->lastName)<0)
					{
						aux=list[i];
						list[i]=list[i-1];
						list[i-1]=aux;
						flag=1;
					}
				}
			}
			while(flag2==1)
			{
				flag2=0;
				for(i=1;i<len;i++)
				{
					if(((list+i)->typePassenger<(list+i-1)->typePassenger))
					{
						aux=list[i];
						list[i]=list[i-1];
						list[i-1]=aux;
						flag2=1;
					}
				}
			}
			ret=0;
		}
	}
	return ret;
}

int printPassenger(ePassenger* list, eTypePassenger* type, eStatusFlight* status, int len)
{
	int ret;
	int i;
	int j;
	int k;
	ret=-1;
	if(list!=NULL && len>0)
	{
		printf("                                           LISTA DE PASAJEROS\n");
		printf("*******************************************************************************************************************************\n");
		printf("| ID |  |APELLIDO|             |NOMBRE|               |PRECIO|       |CODIGO DE VUELO|    |TIPO DE PASAJERO|      |ESTADO DE VUELO|\n");
		for(i=0;i<len;i++)
		{
			if((list+i)->isEmpty==0)
			{
				for(j=0;i<len;j++)
				{
					if((list+i)->typePassenger == (type+j)->typePassenger)
					{
						for(k=0;i<len;k++)
						{
							if((list+i)->statusFlight ==(status+k)->statusFlight)
							{
								printf(" %-4d    %-20s   %-20s  %-10.2f      %-10s           %-12s            %-10s\n",(list+i)->id, (list+i)->lastName, (list+i)->name, (list+i)->price, (list+i)->flycode, (type+j)->description, (status+k)->description);
								break;
							}
						}
						break;
					}
				}
			}
		}
		printf("\n*******************************************************************************************************************************\n");
		ret=0;
	}
	return ret;
}

int sortPassengersByCode(ePassenger* list, int len, int order)
{
	int ret;
	int flag;
	ePassenger aux;
	int i;
	ret=-1;
	flag=1;
	if(list!=NULL && len>0 && (order==0 || order == 1))
	{
		if(order==0)
		{
			while(flag==1)
			{
				flag=0;
				for(i=1;i<len;i++)
				{
					if(strcmp((list+i)->flycode, (list+i-1)->flycode)>0 && (list+i)->isEmpty == 0)
					{
						aux=list[i];
						list[i]=list[i-1];
						list[i-1]=aux;
						flag=1;
					}
				}
			}
			ret=0;
		}
		else
		{
			while(flag==1)
			{
				flag=0;
				for(i=1;i<len;i++)
				{
					if(strcmp((list+i)->flycode, (list+i-1)->flycode)<0  && (list+i)->isEmpty == 0)
					{
						aux=list[i];
						list[i]=list[i-1];
						list[i-1]=aux;
						flag=1;
					}
				}
			}
			ret=0;
		}
	}
	return ret;
}
