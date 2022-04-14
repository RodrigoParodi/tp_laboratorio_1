/*
 * menu.c
 *
 *  Created on: 4 abr. 2022
 *      Author: Rodrigo
 */

//FUNCIONES DEL MUNO.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ingresarKilometros(){

	int kilometros;
	int cont;

	printf("Ingrese la cantidad de kilometros : ");
	cont = scanf("%d", &kilometros);

	while(kilometros < 0 || cont == 0 )										//Funcion para pedir que ingrese cantidad de kilometros
	{
		fflush(stdin);
		printf("ERROR, Reingrese la cantidad de kilometros : ");
		cont = scanf("%d", &kilometros);
	}

	return kilometros;
}

void resultados(int kilometros, float precioVuelosLatam, float debitoLatam, float creditoLatam, float bitCoinLatam, float unitarioLatam,
				float precioVuelosAerolineas, float debitoAero, float creditoAero, float bitCoinAero, float unitarioAero,
				float diferencia){

	printf("Kilometros Ingresados: %d  KM\n\n", kilometros);						//kilometros ingresados

	printf("Latam :$ %.2f\n", precioVuelosLatam);
	printf("A)Precio con tarjeta de debito: $  %.2f\n", debitoLatam);
	printf("B)Precio con tarjeta de credito: $  %.2f\n", creditoLatam);				//Resultados Latam
	printf("C)Precio pagando con BitCoin: %.5f    BTC\n", bitCoinLatam);
	printf("D)Precio Unitario: $ %.2f\n\n", unitarioLatam);

	printf("Aerolineas :$ %.2f\n", precioVuelosAerolineas);
	printf("A)Precio con tarjeta de debito: $  %.2f\n", debitoAero);
	printf("B)Precio con tarjeta de credito: $  %.2f\n", creditoAero);				//Resultados aerolineas
	printf("C)Precio pagando con BitCoin: %.5f    BTC\n", bitCoinAero);
	printf("D)Precio Unitario: $ %.2f\n\n", unitarioAero);

	printf("La diferencia de precio es de : $ %.2f\n\n", diferencia);				//Diferencia de precios

}

float precioUno(){

	float precioVuelosAerolineas;
	int cant;

	printf("Ingrese El precio de Aerolineas : ");
	cant = scanf("%f", &precioVuelosAerolineas);

	while(precioVuelosAerolineas < 0 || cant == 0)
	{
		fflush(stdin);
		printf("ERROR , Reingrese el precio (Mayor a 0) : ");			//ingresar precio de aerolineas
		cant = scanf("%f", &precioVuelosAerolineas);
	}


	return precioVuelosAerolineas;
}

float precioDos(){

	float precioVuelosLatam;
	int cant;

	printf("Ingrese El precio de Latam : ");
	fflush(stdin);
	cant = scanf("%f", &precioVuelosLatam);

	while(precioVuelosLatam < 0 || cant == 0)
	{
		fflush(stdin);
		printf("ERROR , Reingrese el precio (Mayor a 0) : ");				//ingresar precio de latam
		cant = scanf("%f", &precioVuelosLatam);
	}

	return precioVuelosLatam;
}

int menuPrincipal(){

	int opciones;

	printf("\n\n MENU DE OPCIONES.\n\n");
	printf("1)Ingresar Kilometros.\n");
	printf("2)Ingresar Precio de vuelos.\n");
	printf("3)Calcular todos los costos.\n");					//menu principal.
	printf("4)Mostrar resultados.\n");
	printf("5)Carga forzada de datos.\n");
	printf("6)Salir.\n\n");

	printf("Eliga que opcion desea iniciar : ");
	fflush(stdin);
	scanf("%d", &opciones);

	return opciones;

}

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
