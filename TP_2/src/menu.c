/*
 * menu.c
 *
 *  Created on: 28 abr. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "sector.h"
#include "sectorDos.h"

char preguntaSalirDelMenu(){

	char respuesta;

	printf("Desea salir ?('s' o 'n'): ");
	fflush(stdin);						      //FUNCION PARA SALIR DEL MENU O NO
	scanf("%c", &respuesta);
	respuesta = tolower(respuesta);

	while(respuesta !='s' && respuesta !='n')
	{
		printf("Error, Desea salir ? ('s' o 'n'): ");
		fflush(stdin);
		scanf("%c", &respuesta);
		respuesta = tolower(respuesta);
	}

	return respuesta;
}

int menuPrincipal(){

	int opciones;

	system("pause");

	printf("\n\n MENU DE OPCIONES.\n\n");
	printf("1)ALTAS.\n");
	printf("2)MODIFICAR.\n");
	printf("3)BAJA.\n");													//menu principal.
	printf("4)INFORMAR.\n");
	printf("5)Salir.\n\n");

	printf("Eliga que opcion desea iniciar : ");
	fflush(stdin);
	scanf("%d", &opciones);

	return opciones;

}

void mostrarPasajeros(Passenger Pass, Sector tipos[], Estados est[], int tam){

	char tipo[20];
	char estadoDeVuelo[20];

	cargarDescripcionSector(tipos, tam, Pass.typePassenger, tipo);
	cargarDescripcionEstado(est, tam, tipos->statusFlight, estadoDeVuelo);

	printf("     %d    %s %s     %.2f     %s     %10s     %10s\n",
			Pass.id,
			Pass.name,
			Pass.lastName,
			Pass.price,
			Pass.flycode,
			tipo,
			estadoDeVuelo);

}

int buscarLibre(Passenger vec[], int tam, int* pIndex)
{

    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarPasajeros(Passenger vec[], int tam, Sector tipos[], int tamSec, Estados est[], int tamSecDos){
    int todoOk = 0;
    int flag = 1;
    if( vec != NULL && tam > 0)
    {
        system("cls");
        printf("       *** Listado de Pasajeros ***\n");
        printf("   id       Nombre y Apellido      Precio     Codigo de vuelo     Tipo Pasajero     Estado de vuelo\n");
        printf("-------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {
            	mostrarPasajeros(vec[i], tipos, est, tamSec);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay pasajeros en el sistema\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

void mostrarPasajero(Passenger pass){

    printf("ID: %d\n", pass.id);
    printf("Nombre y apellido: %s %s\n", pass.name, pass.lastName);
    printf("Precio: %.2f\n", pass.price);
}

int menuModificarPasajero(){
	int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("1. Nombre.\n");
    printf("2. Apellido.\n");
    printf("3. Precio.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int modificarPasajero(Passenger vec[], int tam){

    int todoOk = 0;
    int indice;
    int id;
    float precio;
    char auxCad[100];


    if( vec != NULL && tam > 0 )
    {
    	//listarPasajeros(vec, tam);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( findPassengerById(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe un pasajero con id: %d en el sistema\n", id);
            }
            else
            {

            	mostrarPasajero(vec[indice]);

                switch(menuModificarPasajero())
                {

                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                    strcpy(vec[indice].name, auxCad);
                    printf("Nombre modificado!\n\n");
                    break;
                case 2:
                    printf("Ingrese nuevo Apellido: ");
                    fflush(stdin);
                    gets(auxCad);
                    strcpy(vec[indice].lastName, auxCad);
                    printf("Apellido modificado!\n\n");
                    break;
                case 3:
                    printf("Ingrese nueva Precio: ");
                    scanf("%f", &precio);
                    vec[indice].price = precio;
                    printf("Precio modificada!\n\n");
                    break;
                }
            }

            todoOk = 1;
        }
    }
    return todoOk;

}



