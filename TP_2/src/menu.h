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
/// muestra el menu principal
/// @return int todoOK

char preguntaSalirDelMenu();
/// Pregunta si quiero salir del menu
/// @return opcion

char preguntaSalirDelMenuModificar();
/// Pregunta si quiero salir del menu de modificar pasajero
///@return opcion

void mostrarPasajeros(Passenger Pass, Sector tipos[], Estados est[], int tam);
///Muestra los pasajeros cargados en el sistema
/// @param Passenger pass (Passenger = estructura de pasajeros)
/// @param Sector tipos (Sector de tipos de pasajeros)
/// @param Estados esto (Estados = estructura de estados de vuelo)
/// @param int tam (tamaño del sistema)

int buscarLibre(Passenger vec[], int tam, int* pIndex);
///busca un lugar libre en el sistema
/// @param Passenger vec
/// @param int tam
/// @param int* pIndex (direccion de memoria de proximoid)
/// @return todoOK

void mostrarPasajero(Passenger pass, Sector tipos[], Estados est[], int tam);
///Muestra un solo pasajero
/// @param Passenger pass (Passenger = estructura de pasajeros)
/// @param Sector tipos (Sector de tipos de pasajeros)
/// @param Estados esto (Estados = estructura de estados de vuelo)
/// @param int tam (tamaño del sistema)

int modificarPasajero(Passenger vec[], int tam, Sector tipo[], int tamSec, Estados est[], int tamSecDos);
/// Modifica los datos de un pasajero
/// @param Paassenger vec
/// @param int tam
/// @param Sector tipo
/// @param int tamSec
/// @param  Estados est
/// @param int tamSecDos
/// @return todoOK

int menuModificarPasajero();
/// Menu para modificar datos de un pasajero
/// @return todoOK

int hardcodearPasajeros(Passenger vec[], int tam, int cant, int* pNextId);
/// Carga 5 pasajeros al sistema de forma forzada
/// @param Passenger vec
/// @param int tam
/// @param int cant		(cantidad de pasajeos que va a cargar en el sistema)
/// @param int* pNextId (direccion de memodia de proximoid)
///@return todoOK

int menuInformes(int banderaListado);
///Muestra el menu del informe que deseamos realizar
/// @param int banderaListado (bandera que da otra funcion)
/// @return todoOK

int promedioSueldos(Passenger vec[], int tam);
///Calcula el total y el promedio de los precios y muestra los pasajeros que superaron ese precio promedio
/// @param Passenger ver
/// @param int tam
/// @return todoOK


#endif /* MENU_H_ */
