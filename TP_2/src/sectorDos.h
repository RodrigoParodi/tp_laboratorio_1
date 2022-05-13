/*
 * sectorDos.h
 *
 *  Created on: 9 may. 2022
 *      Author: Rodrigo
 */

#ifndef SECTORDOS_H_
#define SECTORDOS_H_

typedef struct{

	int id;
	char estadosVuelos[20];

} Estados;

#endif /* SECTORDOS_H_ */

int listarTiposDeEstados(Estados tipos[], int tam);;
/// Lista los tipos de estados de vuelo que existen y los muestra
/// @param Estados tipos
/// @param tam
/// @return todoOK

int cargarDescripcionEstado(Estados tipos[], int tam, int id, char desc[]);
/// Carga la descripcion del tipo de estados de vuelo en una variable
/// @param Estados tipos
/// @param int tam
/// @param int id
/// @param char desc
/// @return todoOK
