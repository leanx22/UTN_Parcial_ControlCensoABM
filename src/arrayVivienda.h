/*
 * arrayVivienda.h
 *
 *  Created on: 24 may. 2022
 *      Author: Leandro
 */

typedef struct{
	int idVivienda;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int permiteCarga;

}eVivienda;

/// @brief Esta funcion inicializa el flag permiteCarga en 1 para
/// indicar que el lugar esta libre.
/// @param array puntero a array viviendas
/// @param tamanio
/// @return retorna 0 si to.do OK, -1 si hay error (NULL o tamanio incorrecto)
int inicializarArray(eVivienda* array, int tamanio);

/// @brief Recorre el array hasta encontrar el flag "permiteCarga" inicializado en 1
/// luego retornara el indice.
/// @param puntero a array de viviendas.
/// @param tamanio  tamanio del array.
/// @return la funcion retornara el indice del array donde hay un lugar libre, -1 si hay error o sin espacios.
int buscarLibre(eVivienda* array, int tamanio);

/// @brief Esta funcion pide todos los datos y  los guarda en un buffer
/// en caso de ser validados procede a aumentar el contador general de IDS y asignar
/// todos los datos almacenados en los buffer a la estructura. Tambien cambia el valor del flag "PermiteCarga"
/// para que se sepa que ese indice esta ocupado.
/// @param array puntero a array de estructuras.
/// @param tamanio tamanio del array.
/// @param contadorId puntero a variable entera de controlador de IDS.
/// @return retorna 0(EXITO) o -1 si hay error en validaciones o puntero NULL.
int altaVivienda(eVivienda* array, int tamanio, int* contadorId);

/// @brief Esta funcion ofrece un submenu con el cual se pueden editar
/// los distintos campos de la estructura.
/// @param array puntero a array de estructuras de viviendas.
/// @param tamanio
/// @return retornara -1(error de reintentos,validaciones o puntero NULL)/0(EXITO)
int modificarVivienda(eVivienda* array, int tamanio);

/// @brief Esta funcion buscara el indice del array en el que el campo ID de su estructura
/// coincida con el ID que se desea buscar.
/// @param array puntero a array de estructuras de viviendas.
/// @param tamanio
/// @param pResultado puntero a variable donde se guardara el resultado (el indice que tiene el id que se busca).
/// @return retorna 0(EXITO) o -1(error o puntero NULL).
int busquedaIndice(eVivienda* array,int tamanio, int* pResultado);

/// @brief Esta funcion modifica el valor del flag "permiteCarga" de la estructura a 1 para que
/// se sobreescriban los datos al dar una nueva alta.
/// @param array puntero a array de estructuras viviendas.
/// @param tamanio
/// @return retorna 0(se dio de baja correctamente) o -1(error de validaciones o puntero NULL).
int bajaVivienda(eVivienda* array, int tamanio);

/// @brief Esta funcion ordena las viviendas alfabeticamente por calle(A-->z),
/// si son iguales lo hara por cant. de personas(de menos personas a mas).
/// @param array puntero a lista.
/// @param tamanio tamanio del array/lista.
/// @return retorna -1(error), 0(EXITO).
int ordenarViviendas(eVivienda* array, int tamanio);

/// @brief Esta funcion muestra en forma de tabla los datos de vivienda en el indice indicado del array.
/// @param array puntero a array de estructuras viviendas.
/// @param tamanio
/// @param indice indice del array del cual se quiere mostrar los datos.
/// @return retorna 0(EXITO) o -1(puntero NULL)
int imprimirDatosVivienda(eVivienda* array, int tamanio,int indice);

/// @brief carga forzada de datos en el array para debugear.
///
/// @param puntero a array de estructuras viviendas.
/// @param lugar = indice en el que se quieren cargar los datos.
/// @param tamanio del array.
/// @param contadorId puntero a variable que controla los ids.
/// @param calle
/// @param personas
/// @param habit
/// @param tipo
/// @param legajo
/// @return retorna 0(EXITO) o -1(puntero NULL)
int cargaForzada(eVivienda* array, int lugar,int tamanio, int* contadorId, char* calle,int personas, int habit, int tipo, int legajo);

#ifndef ARRAYVIVIENDA_H_
#define ARRAYVIVIENDA_H_
#endif /* ARRAYVIVIENDA_H_ */
