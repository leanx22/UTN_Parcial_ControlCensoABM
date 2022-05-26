/*
 ============================================================================
 Name        : PParcial.c
 Author      : Guia Leandro Emanuel.
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : pequenio ABM para parcial de programacion I.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "censista.h"
#include "arrayVivienda.h"

#define TAM 20
#define TAM_CENSISTAS 3
//00:22 16/05
//47:13 12/05
int main(void) {
	setbuf(stdout, NULL);

	int idViviendas = 20000;
	int opcionElegida;
	int salir = 0;
	int flagPrimerAlta=-1;

	int ultimoCensista = -1;

	eCensista listaCensistas[TAM_CENSISTAS];

	eVivienda arrayViviendas[TAM];

	inicializarArray(arrayViviendas, TAM);
	inicializarCensistas(listaCensistas,TAM_CENSISTAS);

	cargaForzadaCensistas(listaCensistas,0,100,"Ana",34,"1203-2345");
	cargaForzadaCensistas(listaCensistas,1,101,"Juan",24,"4301-54678");
	cargaForzadaCensistas(listaCensistas,2,102,"Sol",47,"5902-37487");

	/*//CARGA FORZADA DE VIVIENDAS.
	cargaForzada(arrayViviendas, 0,	TAM, &idViviendas,"tucuman",4,4,1,100);
	cargaForzada(arrayViviendas, 1,	TAM, &idViviendas,"bletra",12,4,1,100);
	cargaForzada(arrayViviendas, 2,	TAM, &idViviendas,"aletra",2,4,1,101);
	cargaForzada(arrayViviendas, 3,	TAM, &idViviendas,"zletra",3,4,1,102);
	cargaForzada(arrayViviendas, 4,	TAM, &idViviendas,"tucuman",8,2,3,101);
	*/

	while(salir == 0)
	{
		system("CLS");
		if(utn_pedirInt(&opcionElegida, "MENU:\n1)Alta vivienda.\n2)Modificar vivienda.\n3)Baja vivienda.\n"
						"4)Listar viviendas.\n5)Listar censistas.\n6)Imprimir mejores censistas.\n7)Imprimir datos completos.\n8)Salir.", "error\n",1,8,3)==0)//Imprime el menu.
		{
			switch(opcionElegida)
			{
			case 1:
				if(altaVivienda(arrayViviendas,TAM, &idViviendas, &ultimoCensista)==0)
				{
					if(contadorCensistas(listaCensistas,TAM_CENSISTAS, ultimoCensista)==0)
					{
						flagPrimerAlta = 0;
					}
				}
				break;
			case 2:
				if(flagPrimerAlta == 0)
				{
					modificarVivienda(arrayViviendas, TAM);
				}
				else
				{
					printf("\n\x1b[31mPRIMERO DEBE HACERSE UN ALTA!\n\x1b[0m");
					system("PAUSE");
				}
				break;
			case 3:
				if(flagPrimerAlta ==0)
				{
					bajaVivienda(arrayViviendas, TAM);
				}
				else
				{
					printf("\n\x1b[31mPRIMERO DEBE HACERSE UN ALTA!\n\x1b[0m");
					system("PAUSE");
				}
				break;
			case 4:
				if(flagPrimerAlta==0)
				{
					ordenarViviendas(arrayViviendas, TAM);
				}
				else
				{
					printf("\n\x1b[31mPRIMERO DEBE HACERSE UN ALTA!\n\x1b[0m");
					system("PAUSE");
				}
				break;
			case 5:
				listarCensistas(listaCensistas,TAM_CENSISTAS);
				break;
			case 6:
				if(flagPrimerAlta==0)
				{
					imprimirMejorCensista(listaCensistas,TAM_CENSISTAS);
				}
				else
				{
					printf("\n\x1b[31mPRIMERO DEBE HACERSE UN ALTA!\n\x1b[0m");
					system("PAUSE");
				}
				break;
			case 7:
				//imprimir
				break;
			case 8:
				salir = 1;
				break;
			}

		}
		else
		{
			printf("\nTe quedaste sin reintentos o hubo un NULL en la funcion!");
			system("PAUSE");
			system("CLS");
			salir = 1;
		}
	}


	return 0;
}
