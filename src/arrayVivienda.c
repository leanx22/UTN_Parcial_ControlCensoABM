/*
 * arrayVivienda.c
 *
 *  Created on: 24 may. 2022
 *      Author: Leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayVivienda.h"

int inicializarArray(eVivienda* array, int tamanio)
{
	int retorno = -1;

	if(array != NULL)
	{
		for(int i=0;i<tamanio;i++){
			(*(array+i)).permiteCarga = 1;
			//array[i].permiteCarga = 1;
		}
		retorno = 0;
	}
	return retorno;
}


int buscarLibre(eVivienda* array, int tamanio)
{
	int indice = -1;

	if(array != NULL)
	{
		for(int i=0;i<tamanio;i++){
			if((*(array+i)).permiteCarga == 1)
			{
				indice = i;
				break;
			}
		}

	}

	return indice;
}


int altaVivienda(eVivienda* array,int tamanio,int* contadorId,int* pCensista)
{
	int retorno = -1;
	int indice;
	//int id;

	char bufferCalle[25];
	int bufferPersonas;
	int bufferHabitaciones;
	int bufferTipo;
	int bufferlegajo;

	//eVivienda* pLista = array;
	if(array !=NULL && contadorId!=NULL)
	{
		indice = buscarLibre(array, tamanio);
		if(indice != -1)
		{
			system("CLS");
			if(utn_getStr(bufferCalle,"\nIngrese el nombre de la calle: ","\nerror",25,3)==0
				&& utn_pedirInt(&bufferPersonas,"\nIngrese la cantidad de personas que viven en el hogar: ","\nerror",1,500,3)==0
				&& utn_pedirInt(&bufferHabitaciones,"\nIngrese la cantidad de habitaciones: ","\nerror",1,500,3)==0
				&& utn_pedirInt(&bufferTipo,"\nIngrese el tipo de vivienda (1.CASA - 2.DPTO - 3.CASILLA - 4.RANCHO): ","\nerror",1,4,3)==0
				&& utn_pedirInt(&bufferlegajo,"\nIngrese el legajo del censista (100-102): ","\nerror",100,102,3)==0)
			{
			*contadorId += 1;
			strcpy((*(array+indice)).calle,bufferCalle);
			(*(array+indice)).cantidadPersonas = bufferPersonas;
			(*(array+indice)).cantidadHabitaciones = bufferHabitaciones;
			(*(array+indice)).tipoVivienda = bufferTipo;
			(*(array+indice)).legajoCensista = bufferlegajo;
			(*(array+indice)).idVivienda = *contadorId;
			(*(array+indice)).permiteCarga = 0;

			*pCensista = (*(array+indice)).legajoCensista;

			system("CLS");
			printf("\n\x1b[32mLA VIVIENDA SE CARGO CORRECTAMENTE. ID: %d\n\x1b[0m", *contadorId);
			retorno = 0;
			system("PAUSE");
		}else
		{
			printf("\n\x1b[31mHubo un error durante la carga de datos, los mismos no seran guardados!.\x1b[0m\n");
			system("PAUSE");
		}
	}
}

return retorno;
}

int busquedaIndice(eVivienda* array,int tamanio, int* pResultado)
{
	int retorno = -1;
	int idBusqueda;

	if(array != NULL)
	{
		if(utn_pedirInt(&idBusqueda,"\nIngrese el ID de vivienda: ","\nerror",20000,99999,3)==0)
		{
			for(int i=0;i<tamanio;i++)
			{
				if((*(array+i)).idVivienda == idBusqueda && (*(array+i)).permiteCarga==0)
				{
					retorno = 0;
					*pResultado = i;
				}

			}
		}
	}
	return retorno;
}

int modificarVivienda(eVivienda* array, int tamanio)
{
	int retorno = 0;
	int indice;
	int opcion;
	int continuar = 1;

	if(array != NULL)
	{
		if(busquedaIndice(array, tamanio, &indice)==0)
		{

			while(continuar == 1)
			{
				system("CLS");
				printf("\n|  ID  |           CALLE          |  PERSONAS  |  HABITACIONES  |  TIPO  |  CENSADA POR  |");
				imprimirDatosVivienda(array,tamanio, indice);
				//printf("\n|\x1b[33m%-6d\x1b[0m|%-26s|%12d|%16d|%8d|%15d|\n", (*(array+indice)).idVivienda, (*(array+indice)).calle, (*(array+indice)).cantidadPersonas, (*(array+indice)).cantidadHabitaciones, (*(array+indice)).tipoVivienda, (*(array+indice)).legajoCensista);
				if(utn_pedirInt(&opcion,"----------\x1b[36mMODIFICAR\x1b[0m----------\n1) Calle.\n2) Cantidad de personas.\n3) Cantidad de habitaciones.\n4) Tipo vivienda.\n5) Volver al menu","\n\x1b[31mError, reintente\x1b[0m\n",1,5,3)==0)
				{
					switch(opcion)
					{
					case 1:
						if(utn_getStr((*(array+indice)).calle,"\nIngrese el nombre de la calle: ","\nerror",25,3)==0)
						{
							printf("\n\x1b[32mACTUALIZADO CORRECTAMENTE.\n\x1b[0m");
							system("PAUSE");
						}
						break;
					case 2:
						if(utn_pedirInt(&(*(array+indice)).cantidadPersonas,"\nIngrese la cantidad de personas que viven en el hogar: ","\nerror",1,500,3)==0)
						{
							printf("\n\x1b[32mACTUALIZADO CORRECTAMENTE.\n\x1b[0m");
							system("PAUSE");
						}
						break;
					case 3:
						if(utn_pedirInt(&(*(array+indice)).cantidadHabitaciones,"\nIngrese la cantidad de habitaciones: ","\nerror",1,500,3)==0)
						{
							printf("\n\x1b[32mACTUALIZADO CORRECTAMENTE.\n\x1b[0m");
							system("PAUSE");
						}
						break;
					case 4:
						if(utn_pedirInt(&(*(array+indice)).tipoVivienda,"\nIngrese el tipo de vivienda: ","\nerror",1,4,3)==0)
						{
							printf("\n\x1b[32mACTUALIZADO CORRECTAMENTE.\n\x1b[0m");
							system("PAUSE");
						}
						break;
					case 5:
						continuar = 0;
						break;
					}
				}
				else
				{
					retorno = -1;
					printf("\nERROR O MUCHOS REINTENTOS!\n");
					system("PAUSE");
				}
			}
		}
		else
		{
			retorno = -1;
			printf("\n\x1b[31mNO SE ENCONTRO VIVIENDA CON ESE ID.\n\x1b[0m");
			system("PAUSE");
		}
	}

	return retorno;
}

int bajaVivienda(eVivienda* array, int tamanio)
{
	int retorno = -1;
	int indice;
	int opcion;

	if(array != NULL)
	{
		if(busquedaIndice(array,tamanio,&indice)==0)
		{
			system("CLS");
			printf("-------------------------------------------\x1b[33mELIMINAR\x1b[0m--------------------------------------");
			printf("\n|  ID  |           CALLE          |  PERSONAS  |  HABITACIONES  |  TIPO  |  CENSADA POR  |");
			imprimirDatosVivienda(array, tamanio, indice);
			utn_pedirInt(&opcion,"Seguro que desea \x1b[31meliminar\x1b[0m esta vivienda?\n0)CANCELAR.\n1)CONFIRMAR.","ERROR",0,1,3);
			if(opcion == 1)
			{
				(*(array+indice)).permiteCarga = 1;
				printf("\n\x1b[33m>>LA VIVIENDA SE ELIMINO CORRECTAMENTE<<\x1b[0m\n");
				retorno = 0;
				system("PAUSE");
			}
		}
		else
		{
			printf("\nNo se encontro ninguna vivienda con ese ID!.");
			system("PAUSE");
		}
	}

	return retorno;
}

int ordenarViviendas(eVivienda* array,int tamanio)
{
	int retorno = -1;

	eVivienda eAux;

	if(array != NULL)
	{
		for(int i=0;i<tamanio;i++)
		{
			for(int j=i+1;j<tamanio;j++)
			{
				if(strcmp((*(array+i)).calle,(*(array+j)).calle)==0)
				{
					if((*(array+i)).cantidadPersonas > (*(array+j)).cantidadPersonas)
					{
						eAux = (*(array+i));
						(*(array+i)) = (*(array+j));
						(*(array+j)) = eAux;
					}
				}
				else if(strcmp((*(array+i)).calle,(*(array+j)).calle)>0)
				{
					eAux = (*(array+i));
					(*(array+i)) = (*(array+j));
					(*(array+j)) = eAux;
				}
			}
		}

		system("CLS");
		printf("-------------------------------------------\x1b[33mVIVIENDAS\x1b[0m--------------------------------------");
		printf("\n|  ID  |           CALLE          |  PERSONAS  |  HABITACIONES  |  TIPO  |  CENSADA POR  |");
		printf("\n------------------------------------------------------------------------------------------");

		for(int i=0;i<tamanio;i++)
		{
			imprimirDatosVivienda(array,tamanio, i);
		}
		printf("\n");
		system("PAUSE");
		retorno = 0;
	}
	return retorno;
}

int imprimirDatosVivienda(eVivienda* array, int tamanio, int indice)
{
	int retorno = -1;
	if(array != NULL)
	{
		if((array+indice)->permiteCarga == 0)
			{
				//printf("\n------------------------------------------------------------------------------------------");
				printf("\n|%-6d|%-26s|%12d|%16d|%8d|%15d|", (*(array+indice)).idVivienda, (*(array+indice)).calle, (*(array+indice)).cantidadPersonas, (*(array+indice)).cantidadHabitaciones, (*(array+indice)).tipoVivienda, (*(array+indice)).legajoCensista);
				printf("\n------------------------------------------------------------------------------------------");
			}
		retorno = 0;
	}


	return retorno;
}

int cargaForzada(eVivienda* array, int lugar,int tamanio, int* contadorId, char* calle,int personas, int habit, int tipo, int legajo)
{
	int retorno = -1;

	if(array != NULL)
	{
		*contadorId +=1;
		strcpy((*(array+lugar)).calle, calle);
		(*(array+lugar)).cantidadPersonas = personas;
		(*(array+lugar)).cantidadHabitaciones = habit;
		(*(array+lugar)).tipoVivienda = tipo;
		(*(array+lugar)).legajoCensista = legajo;
		(*(array+lugar)).idVivienda = *contadorId;
		(*(array+lugar)).permiteCarga = 0;
		retorno = 0;
	}
	return retorno;
}

/*
int imprimirDatosCompletos(eVivienda* array, int tamanio)
{
	int retorno = -1;

	for(int i=0;i<tamanio;i++)
	{
		imprimirDatosVivienda(array,tamanio, i);
	}
	printf("\n");
	system("PAUSE");

	return retorno;
}
*/
