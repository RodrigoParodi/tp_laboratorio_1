/*
 * menu.h
 *
 *  Created on: 28 abr. 2022
 *      Author: Rodrigo
 */

#include "ArrayPassenger.h"

#ifndef MENU_H_
#define MENU_H_

int menuPrincipal();
char preguntaSalirDelMenu();
void mostrarPasajeros(Passenger Pass, Sector tipos[], Estados est[], int tam);
int buscarLibre(Passenger vec[], int tam, int* pIndex);
int listarPasajeros(Passenger vec[], int tam, Sector tipos[], int tamSec, Estados est[], int tamSecDos);
void mostrarPasajero(Passenger pass);
int modificarPasajero(Passenger vec[], int tam);
int menuModificarPasajero();


#endif /* MENU_H_ */
