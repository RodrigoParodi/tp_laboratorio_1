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


#define TAM 20
#define TAMS 4
#define TAMSS 3


int main() {
	setbuf(stdout, NULL);

	char respuesta = 'n';
	int proximoId=1000;
	int banderaListado;

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
			modificarPasajero(lista, TAM, tiposDePasajeros, TAMS, estado, TAMSS);
		break;
		case 3:
			removePassenger(lista, TAM, tiposDePasajeros, TAMS, estado, TAMSS);
		break;
		case 4:
			banderaListado=printPassengers(lista, TAM, tiposDePasajeros, TAMS, estado, TAMSS);
			switch(menuInformes(banderaListado))
			{
			case 0:
				printf("No se pueden realizar informes sin pasajeros registrados!!!\n");
			break;
			case 1:
				sortPassengers(lista, TAM);
				printPassengers(lista, TAM, tiposDePasajeros, TAMS, estado, TAMSS);
			break;
			case 2:
				promedioSueldos(lista,  TAM);
			break;
			case 3:
				sortPassengersByCode(lista, TAM);
				printPassengers(lista, TAM, tiposDePasajeros, TAMS, estado, TAMSS);
			break;
			case 4:
				printf("saliendo de informes!!!\n!!!!");
			break;
			default:
				printf("Opcion invalida!!!");
				system("pause");
			break;
			}
		break;
		case 5:
			hardcodearPasajeros(lista, TAM, 5, &proximoId);
		break;
		case 6:
			respuesta=preguntaSalirDelMenu();
		break;
		default:
			printf("Opcionon Invalida!!!!\n");
			system("pause");
		break;
		}
	}while(respuesta != 's');

	system("cls");
	printf("Adios!!!");

	return 0;
}
