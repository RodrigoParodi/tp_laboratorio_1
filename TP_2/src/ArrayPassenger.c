/*
 * ArrayPassenger.c
 *
 *  Created on: 7 may. 2022
 *      Author: Rodrigo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "menu.h"
#include "sector.h"
#include "sectorDos.h"

int initPassengers(Passenger vec[], int tam)
{
    int todoOk = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int addPassengers(Passenger vec[], int tam, Sector tipos[], int tamSec, Estados est[], int tamSecDos, int* pNextId)
{
	int todoOk = 0;
	int indice;
	int idPasajero;
	int estadoVuelo;
	char auxCad[100];
	Passenger nuevoPasajero;




	    if( vec != NULL && pNextId != NULL && tam > 0)
	    {
	        system("cls");
	        printf("    *** Alta Pasajero ***\n\n");
	        buscarLibre(vec, tam, &indice);

	        if(indice == -1)
	        {
	            printf("No hay lugar en el sistema\n");
	        }
	        else
	        {
	        	nuevoPasajero.id = *pNextId;

	        	printf("Ingrese Nombre: ");
	        	fflush(stdin);
	        	gets(auxCad);

	        	while(strlen(auxCad) >= 20)
	        	{
	        		printf("Nombre demasiado largo. Reingrese nombre: ");
	        		fflush(stdin);
	        		gets(auxCad);
	        	}

	        	strcpy(nuevoPasajero.name, auxCad);

	        	printf("Ingrese Apellido: ");
	        	fflush(stdin);
	        	gets(auxCad);

	        	while(strlen(auxCad) >= 20)
	        	{
	        		printf("Apellido demasiado largo. Reingrese nombre: ");
	        		fflush(stdin);
	        		gets(auxCad);
	        	}

	        	strcpy(nuevoPasajero.lastName, auxCad);

	        	printf("Ingrese precio: ");
	        	scanf("%f", &nuevoPasajero.price);

	        	while(nuevoPasajero.price < 0)
	        	{
		        	printf("Precio invalido !!. Reingrese precio: ");
		        	scanf("%f", &nuevoPasajero.price);
	        	}

	        	printf("Ingrese codigo de vuelo : ");
	        	fflush(stdin);
	        	gets(auxCad);

	        	while(strlen(auxCad) >= 20)
	        	{
	        		printf("Codigo demasiado largo. Reingrese nombre: ");
	        		fflush(stdin);
	        		gets(auxCad);
	        	}

	        	strupr(auxCad);
	        	strcpy(nuevoPasajero.flycode, auxCad);


	        	listarTiposDePasajeros(tipos, tamSec);

	        	printf("Ingrese Tipo de pasajero: ");
	        	scanf("%d", &idPasajero);

	        	while(idPasajero <= 0 || idPasajero > tamSec)
	        	{
		        	printf("Ese ID no existe!!, ingrese Tipo de pasajero: ");
		        	scanf("%d", &idPasajero);
	        	}

	        	nuevoPasajero.typePassenger = idPasajero;

	        	listarTiposDeEstados(est, tamSecDos);

	        	printf("Ingrese estado del vuelo: ");
	        	scanf("%d", &estadoVuelo);

	        	while(estadoVuelo <= 0 || estadoVuelo > tamSecDos)
	        	{
		        	printf("Este Estado no exsite, ReIngrese estado del vuelo: ");
		        	scanf("%d", &estadoVuelo);
	        	}

	        	nuevoPasajero.statusFlight = estadoVuelo;

	        	nuevoPasajero.isEmpty = 0;


	            vec[indice] = nuevoPasajero;

	            (*pNextId)++;

	            todoOk = 1;
	        }
	    }
	    return todoOk;
	}




int findPassengerById(Passenger vec[], int tam, int id, int* pIndex){

	int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty  && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



int removePassenger(Passenger vec[], int tam, Sector tipo[], int tamSec, Estados est[], int tamSecDos){

	   	int todoOk = 0;
	    int indice;
	    int id;
	    char confirma;
	    if( vec != NULL && tam > 0 )
	    {
	    	if(printPassengers(vec, tam, tipo, tamSec, est, tamSecDos) == 0)
	    	{

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

	    			        	 mostrarPasajero(vec[indice], tipo, est, tam);
	    			             printf("Confirma baja?: ");
	    			             fflush(stdin);
	    			             scanf("%c", &confirma);

	    			              if(confirma == 's' || confirma == 'S')
	    			               {
	    			                   vec[indice].isEmpty = 1;
	    			                   printf("Baja exitosa!!!\n");
	    			               }
	    			               else
	    			               {
	    			                   printf("Baja cancelada por el usuario\n");
	    			               }

	    			            }

	    			   todoOk = 1;
	    			 }

	    	}

	    }
	    return todoOk;
}

int printPassengers(Passenger vec[], int tam, Sector tipos[], int tamSec, Estados est[], int tamSecDos){
    int bandera = 0;
    int flag = 1;
    if( vec != NULL && tam > 0)
    {
        system("cls");
        printf("       *** Listado de Pasajeros ***\n");
        printf("  id          Nombre y Apellido         Precio      Codigo de vuelo    Tipo Pasajero     Estado de vuelo\n");
        printf("______________________________________________________________________________________________________________\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {
            	mostrarPasajeros(vec[i], tipos, est, tamSec);
                flag = 0;
            }
        }
        printf("______________________________________________________________________________________________________________\n\n");
        if(flag)
        {
            printf("  No hay pasajeros cargados en el sistema!!!\n\n");
            bandera = 1;
        }


    }
    return bandera;
}

int sortPassengers(Passenger vec[], int tam){

    int todoOk = 0;
    Passenger auxPasajero;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {
                if( strcmp(vec[i].lastName, vec[j].lastName) > 0)
                {
                	auxPasajero = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajero;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int sortPassengersByCode(Passenger vec[], int tam){

    int todoOk = 0;
    Passenger auxPasajero;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if(vec[i].flycode > vec[j].flycode)
                {
                	auxPasajero = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajero;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

