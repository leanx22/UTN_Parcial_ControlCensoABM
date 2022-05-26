/*
 * censista.c
 *
 *  Created on: 24 may. 2022
 *      Author: Leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "censista.h"

int inicializarCensistas(eCensista* lista, int tamanio)
{
	int retorno = -1;

	if(lista != NULL)
	{
		for(int i=0;i<tamanio;i++)
		{
			(*(lista+i)).contadorCensos = 0;
		}
		retorno = 0;
	}

	return retorno;
}

int cargaForzadaCensistas(eCensista* lista,int indice, int legajo, char* nombre, int edad, char* telefono)
{
	int retorno = -1;

	if(lista != NULL)
	{
		(*(lista+indice)).legajoCensista = legajo;
		strcpy((*(lista+indice)).nombre,nombre);
		(*(lista+indice)).edad = edad;
		strcpy((*(lista+indice)).telefono,telefono);
		retorno = 0;
	}

	return retorno;
}

int listarCensistas(eCensista* array,int tamanio)
{
	int retorno = -1;

	if(array !=NULL)
	{
		system("CLS");
		printf("-------------------------\x1b[33mCENSISTAS\x1b[0m-------------------------");
		printf("\n|  LEGAJO  |         NOMBRE         |  EDAD  |  TELEFONO  |");
		printf("\n-----------------------------------------------------------");

		for(int i=0;i<tamanio;i++)
		{
			imprimirDatosCensista(array,tamanio,i);
		}
		printf("\n");
		system("PAUSE");
	}

	return retorno;
}

int imprimirDatosCensista(eCensista* array, int tamanio,int indice)
{
	int retorno = -1;
	if(array != NULL)
	{
		//if((array+indice)->permiteCarga == 0)
			//{
				printf("\n|%-10d|%-24s|%8d|%12s|", (*(array+indice)).legajoCensista, (*(array+indice)).nombre, (*(array+indice)).edad, (*(array+indice)).telefono);
				printf("\n-----------------------------------------------------------");
		//	}
		retorno = 0;
	}
	return retorno;
}

int contadorCensistas(eCensista* lista,int tamanio, int legajo)
{
	int retorno = -1;

	if(lista != NULL)
	{
		for(int i=0;i<tamanio;i++)
		{
			if((*(lista+i)).legajoCensista==legajo)
			{
				(*(lista+i)).contadorCensos += 1;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int imprimirMejorCensista(eCensista* array,int tamanio)
{
	int retorno = -1;

	eCensista eAux;

		if(array != NULL)
		{
			for(int i=0;i<tamanio;i++)
			{
				for(int j=i+1;j<tamanio;j++)
				{
					if((*(array+i)).contadorCensos<(*(array+j)).contadorCensos)
					{
							eAux = (*(array+i));
							(*(array+i)) = (*(array+j));
							(*(array+j)) = eAux;
					}
				}
			}

			system("CLS");
			printf("EL MEJOR CENSISTA FUE: %s con %d censos!", (*(array)).nombre, (*(array)).contadorCensos);
			printf("\nLista ordenada de censistas segun cantidad de censos: \n");

			printf("\n|  LEGAJO  |         NOMBRE         |  CENSOS  |");

			for(int i=0;i<tamanio;i++)
			{
				printf("\n|%-10d|%-24s|%10d|", (*(array+i)).legajoCensista, (*(array+i)).nombre, (*(array+i)).contadorCensos);
				printf("\n-----------------------------------------------");
			}
			retorno = 0;
			printf("\n");
			system("PAUSE");
		}
	return retorno;
}
