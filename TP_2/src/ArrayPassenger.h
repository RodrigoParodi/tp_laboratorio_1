/*
 * ArrayPassenger.h
 *
 *  Created on: 7 may. 2022
 *      Author: Rodrigo
 */
#include "sector.h"
#include "sectorDos.h"

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct {

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

} Passenger;

#endif /* ARRAYPASSENGER_H_ */

int initPassengers(Passenger vec[], int tam);
///Inicialisa los campos isEmpty en 1
/// @param Passenger vec
/// @param int tam
/// @return todoOK

int addPassengers(Passenger vec[], int tam, Sector tipos[], int tamSec, Estados est[], int tamSecDos, int* pNextId);
/// Le pide datos al pasajero y los carga en el sistema
/// @param Passenger vec
/// @param int tam
/// @param Sector tipos
/// @param int tamSec
/// @param Estados est
/// @param int tamSecDos
/// @param int* pNextId
/// @return todoOK

int removePassenger(Passenger vec[], int tam, Sector tipo[], int tamSec, Estados est[], int tamSecDos);
///Elimina X pasajero del sistema buscandolo por su ID
/// @param Passenger vec
/// @param int tam
/// @param Sector tipo
/// @param int tamSec
/// @param Estados est
/// @param int tamSecDos
/// @return todoOK

int findPassengerById(Passenger vec[], int tam, int id, int* pIndex);
/// Busca un pasajero cargado en el sistema por su numero de ID
/// @param Passenger vec
/// @param int tam
/// @param int id
/// @param int* pIndex
/// @return todoOK

int printPassengers(Passenger vec[], int tam, Sector tipos[], int tamSec, Estados est[], int tamSecDos);
/// Lista todos los pasajeros cargados en el sistema
/// @param Passenger vec
/// @param int tam
/// @param tipos
/// @param tamSec
/// @param Estados est
/// @param int tamSecDos
/// @return banderaListado

int sortPassengers(Passenger vec[], int tam);
///Ordena los pasajeros por apellido y tipo de pasajero
/// @param Passenger vec
/// @param int tam
/// @return todoOK

int sortPassengersByCode(Passenger vec[], int tam);
///Ordena los pasajeros por codigo  y estado de vuelo
/// @param Passenger vec
/// @param int tam
/// @return todoOK

