/*
 * sector.h
 *
 *  Created on: 8 may. 2022
 *      Author: Rodrigo
 */

#ifndef SECTOR_H_
#define SECTOR_H_

typedef struct{

	int id;
	char tipoPasajero[20];

} Sector;

#endif /* SECTOR_H_ */

int listarTiposDePasajeros(Sector tipos[], int tam);
/// Lista los tipos de pasajeros que existen y los muestra
/// @param Sector tipos
/// @param tam
/// @return todoOK

int cargarDescripcionSector(Sector tipos[], int tam, int id, char desc[]);
/// Carga la descripcion del tipo de pasajero en una variable
/// @param Sector tipos
/// @param int tam
/// @param int id
/// @param char desc
/// @return todoOK


