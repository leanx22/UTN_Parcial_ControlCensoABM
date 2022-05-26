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
