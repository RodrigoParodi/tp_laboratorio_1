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
int addPassengers(Passenger vec[], int tam, Sector tipos[], int tamSec, Estados est[], int tamSecDos, int* pNextId);
int removePassenger(Passenger vec[], int tam, Sector tipo[], int tamSec, Estados est[], int tamSecDos);
int findPassengerById(Passenger vec[], int tam, int id, int* pIndex);
int printPassengers(Passenger vec[], int tam, Sector tipos[], int tamSec, Estados est[], int tamSecDos);
int sortPassengers(Passenger vec[], int tam);
int sortPassengersByCode(Passenger vec[], int tam);
