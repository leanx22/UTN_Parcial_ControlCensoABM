/*
 * censista.h
 *
 *  Created on: 24 may. 2022
 *      Author: Leandro
 */

typedef struct{
	int legajoCensista;
	char nombre[20];
	int edad;
	char telefono[15]; //puede cambiar a int?

}eCensista;

/// @brief  Esta funcion imprime todos los datos del array en forma
/// de tabla.
/// @param array puntero a array de estructuras o lista de censistas.
/// @param tamanio del array.
/// @return retorna 0(EXITO) o -1(puntero NULL).
int listarCensistas(eCensista* array,int tamanio);

/// @brief Imprime los datos guardados en el indice que se le indica
/// esto en forma de tabla.
/// @param array puntero a array de estructuras (lista) de censistas.
/// @param tamanio del array/lista.
/// @param indice indica en cual posicion del array queremos imprimir los datos.
/// @return retorna 0(EXITO) o -1(puntero NULL).
int imprimirDatosCensista(eCensista* array, int tamanio,int indice);

/// @brief Funcion de "carga forzada" de datos en la lista de censistas.
/// (Para Debug).
/// @param lista
/// @param indice indice de la lista en donde se quieren cargar los datos.
/// @param legajo
/// @param nombre
/// @param edad
/// @param telefono
/// @return retorna 0(EXITO) o -1(puntero NULL).
int cargaForzadaCensistas(eCensista* lista,int indice, int legajo, char* nombre, int edad, char* telefono);

#ifndef CENSISTA_H_
#define CENSISTA_H_
#endif /* CENSISTA_H_ */
