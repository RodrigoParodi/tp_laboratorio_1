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
int cargarDescripcionEstado(Estados tipos[], int tam, int id, char desc[]);
