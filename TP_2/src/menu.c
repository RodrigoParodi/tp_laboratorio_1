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
	fflush(stdin);
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

char preguntaSalirDelMenuModificar(){

	char respuesta;

	printf("Desea modificar otro dato ?('s' o 'n'): ");
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
	system("cls");

	printf("\n\n MENU DE OPCIONES.\n\n");
	printf("1)ALTAS.\n");
	printf("2)MODIFICAR.\n");
	printf("3)BAJA.\n");													//menu principal.
	printf("4)INFORMAR.\n");
	printf("5)Carga Forzada de pasajeros.\n");
	printf("6)Salir.\n\n");

	printf("Eliga que opcion desea iniciar : ");
	fflush(stdin);
	scanf("%d", &opciones);

	return opciones;

}

void mostrarPasajeros(Passenger Pass, Sector tipos[], Estados est[], int tam){

	char tipo[20];
	char estadoDeVuelo[20];

	cargarDescripcionSector(tipos, tam, Pass.typePassenger, tipo);
	cargarDescripcionEstado(est, tam, Pass.statusFlight, estadoDeVuelo);

	printf("| %-6d|    %-10s %-10s|     $%-10.2f|     %-10s|     %-15s|     %-10s|           \n",
			Pass.id,
			Pass.lastName,
			Pass.name,
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


void mostrarPasajero(Passenger pass, Sector tipos[], Estados est[], int tam){

	char tiposPasajeros[20];
	char tiposEstados[20];

	cargarDescripcionSector(tipos, tam, pass.typePassenger, tiposPasajeros);
	cargarDescripcionEstado(est, tam, pass.statusFlight, tiposEstados);

    printf("ID: %d\n", pass.id);
    printf("Nombre y apellido: %s %s\n", pass.name, pass.lastName);
    printf("Precio: %.2f\n", pass.price);
    printf("Codigo de vuelo: %s\n", pass.flycode);
    printf("Tipo de pasajero: %10s\n", tiposPasajeros);
    printf("Estado de vuelo: %10s\n\n", tiposEstados);
}

int menuModificarPasajero(){
	int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("1. Nombre.\n");
    printf("2. Apellido.\n");
    printf("3. Precio.\n");
    printf("4. Codigo de vuelo.\n");
    printf("5. Tipo de pasajero.\n");
    printf("6. Estado de vuelo.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int modificarPasajero(Passenger vec[], int tam, Sector tipo[], int tamSec, Estados est[], int tamSecDos){

    int todoOk = 0;
    int indice;
    int id;
    int cant;
    float precio;
    int idPasajero;
    int estadoVuelo;
    char auxCad[100];
    char respuesta = 's';


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
    		            	system("cls");
    		            	mostrarPasajero(vec[indice], tipo, est, tam);
    		            	printf("Estos son los datos que desea modificar ?: ");
    		            	fflush(stdin);
    		            	scanf("%c", &respuesta);

    		            	if(respuesta == 's' || respuesta == 'S')
    		            	{
    	   		            	do{

    	    		                    switch(menuModificarPasajero())
    	    		                    {

    	    		                    case 1:
    	    		                        printf("Ingrese nuevo nombre: ");
    	    		                        fflush(stdin);
    	    		                        gets(auxCad);

    	    		        	        	while(strlen(auxCad) >= 20)
    	    		        	        	{
    	    		        	        		printf("Nombre demasiado largo. Reingrese nombre: ");
    	    		        	        		fflush(stdin);
    	    		        	        		gets(auxCad);
    	    		        	        	}

    	    		                        strcpy(vec[indice].name, auxCad);
    	    		                        printf("Nombre modificado!\n\n");
    	    		                        break;
    	    		                    case 2:
    	    		                        printf("Ingrese nuevo Apellido: ");
    	    		                        fflush(stdin);
    	    		                        gets(auxCad);

    	    		        	        	while(strlen(auxCad) >= 20)
    	    		        	        	{
    	    		        	        		printf("Apellido demasiado largo. Reingrese nombre: ");
    	    		        	        		fflush(stdin);
    	    		        	        		gets(auxCad);
    	    		        	        	}

    	    		                        strcpy(vec[indice].lastName, auxCad);
    	    		                        printf("Apellido modificado!\n\n");
    	    		                        break;
    	    		                    case 3:
    	    		                        printf("Ingrese nueva Precio: ");
    	    		                        cant = scanf("%f", &precio);

    	    		        	        	while(precio < 0 || cant == 0)
    	    		        	        	{
    	    		        		        	printf("Precio invalido !!. Reingrese precio: ");
    	    		        		        	fflush(stdin);
    	    		        		        	cant = scanf("%f", &precio);
    	    		        	        	}

    	    		                        vec[indice].price = precio;
    	    		                        printf("Precio modificada!\n\n");
    	    		                        break;
    	    		                    case 4:
    	    		        	        	printf("Ingrese codigo de vuelo : ");
    	    		        	        	fflush(stdin);
    	    		        	        	gets(auxCad);

    	    		        	        	while(strlen(auxCad) >= 20)
    	    		        	        	{
    	    		        	        		printf("Codigo demasiado largo. Reingrese nombre: ");
    	    		        	        		fflush(stdin);
    	    		        	        		gets(auxCad);
    	    		        	        	}

    	    		        	        	strcpy(vec[indice].flycode, auxCad);
    	    		        	        	printf("Codigo de vuelo modificada!\n\n");
    	    		                    	break;
    	    		                    case 5:
    	    		        	        	listarTiposDePasajeros(tipo, tamSec);

    	    		        	        	printf("Ingrese Tipo de pasajero: ");
    	    		        	        	scanf("%d", &idPasajero);

    	    		        	        	while(idPasajero <= 0 || idPasajero > tamSec)
    	    		        	        	{
    	    		        		        	printf("Ese ID no existe!!, ingrese Tipo de pasajero: ");
    	    		        		        	scanf("%d", &idPasajero);
    	    		        	        	}

    	    		        	        	vec[indice].typePassenger = idPasajero;
    	    		        	        	printf("Tipo de pasajero modificada!\n\n");
    	    		                    	break;
    	    		                    case 6:
    	    		        	        	listarTiposDeEstados(est, tamSecDos);

    	    		        	        	printf("Ingrese estado del vuelo: ");
    	    		        	        	scanf("%d", &estadoVuelo);

    	    		        	        	while(estadoVuelo <= 0 || estadoVuelo > tamSecDos)
    	    		        	        	{
    	    		        		        	printf("Este Estado no exsite, ReIngrese estado del vuelo: ");
    	    		        		        	scanf("%d", &estadoVuelo);
    	    		        	        	}

    	    		        	        	vec[indice].statusFlight = estadoVuelo;
    	    		        	        	printf("Estado de vuelo modificada!\n\n");
    	    		                    	break;
    	    		                    }
    	    		                    respuesta=preguntaSalirDelMenuModificar();
    	    		                    system("cls");
    	    		            	}while(respuesta != 'n');

    		            	}else{
    		            		printf("Modificacion cancelada por el usuario!!!!\n\n");
    		            	}


    		            }

    		            todoOk = 1;
    		        }

    	}


    }
    return todoOk;

}

int hardcodearPasajeros(Passenger vec[], int tam, int cant, int* pNextId){

    int todoOk = 0;
    Passenger pasajeros[5] =
    {
        {0, "Pedro", "Rodriguez", 35000, "AR 4512", 1, 3},
        {0, "Miguel", "Angel", 24000, "AR 4200", 2, 3},
        {0, "Juan", "Fernandez", 21500, "AR 3340", 4, 1},
        {0, "Nicolas", "Gutierrez", 45700, "AR 3230", 3, 2},
        {0, "Martina", "Lopez", 29500, "AR 2110", 2, 3},
    };

    if( vec != NULL && pNextId != NULL && tam > 0 && tam <= 20 && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
            vec[i] = pasajeros[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        printf("Pasajeros cargados con exito!!!!\n");
        todoOk = 1;
    }
    return todoOk;

}

int menuInformes(int banderaListado){
	int opcion;

	if(banderaListado == 0)
	{
		printf("-----Menu de informes------\n\n");
		printf("1)Mostrar Pasajeros ordenados alfabeticamente y por tipo de pasajero.\n");
		printf("2)Total y promedio de los precios y muestra pasajeros que lo superaron.\n");
		printf("3)Listado de pasajeros por codigo de vuelo y estado de vuelo Activo.\n");
		printf("4)Volver al menu.\n\n");

		printf("Ingrese opcion: ");
		scanf("%d", &opcion);
	}else{
		opcion = 0;
	}
	return opcion;
}

int promedioSueldos(Passenger vec[], int tam)
{
    int todoOk = 0;
    float acumPrecio = 0;
    int contPasajeros = 0;
    float promedio = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {
            	acumPrecio += vec[i].price;
            	contPasajeros++;
            }
        }
        if(contPasajeros != 0)
        {
            promedio = acumPrecio / contPasajeros;
        }

        system("cls");
        printf("     *** Total y promedio de los precios ***\n\n");

        printf("Total: $ %.2f\n", acumPrecio);
        printf("Promedio: $ %.2f\n\n", promedio);
        todoOk = 1;

        printf("------Pasajeros que superaro el precio promedio-----\n");

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].price > promedio)
            {
                printf(" %s %s \n", vec[i].name, vec[i].lastName);
            }
        }
        printf("\n\n");

    }
    return todoOk;
}

int mayusculaPrimerCaracter(char cadena[]){
	int todoOK = 0;
	if(cadena !=NULL)
	{
		todoOK = 1;
		strlwr(cadena);
		cadena[0] = toupper(cadena[0]);
	}

	return todoOK;
}

int validarCadena(char cadena[50]){

	int i=0;
	int sw=0;
	int j;

	j=strlen(cadena);

	while(i<j && sw==0)
	{
		if(isalpha(cadena[i]) != 0)
		{
			i++;
		}
		else
		{
			sw=1;
		}
	}




	return sw;
}



