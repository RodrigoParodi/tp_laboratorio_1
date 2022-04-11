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

void resultadosLatam(float precioVuelosLatam, float debitoLatam, float creditoLatam, float bitCoinLatam, float unitarioLatam){

	printf("Latam :$ %.2f\n", precioVuelosLatam);
	printf("A)Precio con tarjeta de debito: $  %.2f\n", debitoLatam);
	printf("B)Precio con tarjeta de credito: $  %.2f\n", creditoLatam);				//Menu resultados Latam
	printf("C)Precio pagando con BitCoin: %.5f    BTC\n", bitCoinLatam);
	printf("D)Precio Unitario: $ %.2f\n", unitarioLatam);


}

void resultadosAerolineas(float precioVuelosAerolineas, float debitoAero, float creditoAero, float bitCoinAero, float unitarioAero){

	printf("Aerolineas :$ %.2f\n", precioVuelosAerolineas);
	printf("A)Precio con tarjeta de debito: $  %.2f\n", debitoAero);
	printf("B)Precio con tarjeta de credito: $  %.2f\n", creditoAero);				//menu resultados aerolineas
	printf("C)Precio pagando con BitCoin: %.5f    BTC\n", bitCoinAero);
	printf("D)Precio Unitario: $ %.2f\n", unitarioAero);


}

void mensajeDifPrecios(float precioVuelosLatam , float precioVuelosAerolineas , float diferencia){

	if(precioVuelosLatam > 0 && precioVuelosAerolineas > 0)
	{
		printf("La diferencia de precio es de : $ %.2f\n\n", diferencia);				//Mnesaje de precios
	}
	else
	{
		printf("Solo se ingreso un precio por lo cual no se calculara la diferencia!!!\n\n");
	}

}

char seleccionarAerolineaa(char ingresarPrecio){

	printf("Eliga que empresa de vuelo quiere.\n");
	printf("A)Aerolineas.\n");
	printf("B)Latam.\n\n");

	printf("Elija una opcion : ");						//seleccionar aerolinea
	fflush(stdin);
	scanf("%c", &ingresarPrecio);
	ingresarPrecio = tolower(ingresarPrecio);

	return ingresarPrecio;
}

float precioUno(float precioVuelosAerolineas){

	printf("Ingrese El precio de Aerolineas : ");
	scanf("%f", &precioVuelosAerolineas);
	while(precioVuelosAerolineas < 0)
	{
		printf("ERROR , Reingrese el precio (Mayor a 0) : ");			//ingresar precio de aerolineas
		scanf("%f", &precioVuelosAerolineas);
	}


	return precioVuelosAerolineas;
}

float precioDos(float precioVuelosLatam){

	printf("Ingrese El precio de Latam : ");
	scanf("%f", &precioVuelosLatam);
	while(precioVuelosLatam < 0)
	{
		printf("ERROR , Reingrese el precio (Mayor a 0) : ");				//ingresar precio de latam
		scanf("%f", &precioVuelosLatam);
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
