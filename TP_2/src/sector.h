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
int cargarDescripcionSector(Sector tipos[], int tam, int id, char desc[]);


