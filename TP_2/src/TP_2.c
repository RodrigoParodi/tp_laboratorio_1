/*
 ============================================================================
 Name        : TP_2.c
 Author      : Rodrigo Parodi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ArrayPassenger.h"
#include "sector.h"
#include "sectorDos.h"


#define TAM 10
#define TAMS 4
#define TAMSS 3


int main() {
	setbuf(stdout, NULL);

	char respuesta = 'n';
	int proximoId=1000;

	Passenger lista[TAM];
	Sector tiposDePasajeros[TAMS] =
	{
			{1, "Primera clase"},
			{2, "Promocional"},
			{3, "Ejecutiva"},
			{4, "Turista"}
	};

	Estados estado[TAMSS]=
	{
			{1, "Activo"},
			{2, "Cancelado"},
			{3, "Demorado"}
	};


	initPassengers(lista, TAM);
	printf("Hola bienvenido\n\n");

	do{
		system("cls");
		switch(menuPrincipal())
		{
		case 1:
	           if(addPassengers(lista, TAM, tiposDePasajeros, TAMS, estado, TAMSS, &proximoId))
	            {
	                printf("Pasajero cargado con exito!!!\n");
	            }
	            else
	            {
	                printf("No se pudo cargar al pasajero\n");
	            }
		break;
		case 2:
			//modificarPasajero(lista, TAM);
		break;
		case 3:
			//removePassenger(lista, TAM);
		break;
		case 4:
			listarPasajeros(lista, TAM, tiposDePasajeros, TAMS, estado, TAMSS);
		break;
		case 5:
			respuesta=preguntaSalirDelMenu();
		break;
		default:
			printf("Opcionon Invalida!!!!\n");
			system("pause");							//EN CASO DE USAR UN NUMERO MAYOR DE 5 O LETRA SALDRA ESTE MENSAJE DE ERROR
		break;
		}
	}while(respuesta != 's');

	printf("Adios!!!");

	return 0;
}
