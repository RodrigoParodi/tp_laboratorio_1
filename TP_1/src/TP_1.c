/*
 ============================================================================
 Name        : TP_1
 Author      : Rodrigo Parodi Div 1G
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
	setbuf(stdout, NULL);

	int kilometros;
	float precioVuelosLatam;
	float precioVuelosAerolineas;
	float debito;
	float credito;
	float bitCoin;
	float unitario;
	float diferencia;

	printf("Ingrese la cantidad de kilometros: ");
	scanf("%d", &kilometros);

	while(kilometros <= 0)
	{
		printf("ERROR, Reingrese la cantidad de kilometros(Mayor a 0): ");
		scanf("%d", &kilometros);
	}

	printf("Ingrese el precio de vuelos Latam: ");
	scanf("%f", &precioVuelosLatam);

	while(precioVuelosLatam <= 0)
	{
		printf("ERROR, Reingrese el precio de vuelos Latam(Mayor a 0): ");
		scanf("%f", &precioVuelosLatam);
	}

	printf("Ingrese el precio de vuelos Aerolineas: ");
	scanf("%f", &precioVuelosAerolineas);

	while(precioVuelosAerolineas <= 0)
	{
		printf("ERROR, Reingrese el precio de vuelos Aerolineas(Mayor a 0): ");
		scanf("%f", &precioVuelosAerolineas);
	}


	printf("kilometros ingresada: %d  km\n", kilometros);

	debito=precioTarjetaDebito(precioVuelosLatam);
	credito=precioTarjetaCredito(precioVuelosLatam);
	bitCoin=precioBitCoin(precioVuelosLatam);
	unitario=precioUnitario(precioVuelosLatam, kilometros);

	printf("Latam :$ %.2f\n", precioVuelosLatam);
	printf("A)Precio con tarjeta de debito: $  %.2f\n", debito);
	printf("B)Precio con tarjeta de credito: $  %.2f\n", credito);
	printf("C)Precio pagando con BitCoin: %.5f    BTC\n", bitCoin);
	printf("D)Precio Unitario: $ %.2f\n", unitario);

	debito=precioTarjetaDebito(precioVuelosAerolineas);
	credito=precioTarjetaCredito(precioVuelosAerolineas);
	bitCoin=precioBitCoin(precioVuelosAerolineas);
	unitario=precioUnitario(precioVuelosAerolineas, kilometros);

	printf("Aerolineas :$ %.2f\n", precioVuelosAerolineas);
	printf("A)Precio con tarjeta de debito: $  %.2f\n", debito);
	printf("B)Precio con tarjeta de credito: $  %.2f\n", credito);
	printf("C)Precio pagando con BitCoin: %.5f    BTC\n", bitCoin);
	printf("D)Precio Unitario: $ %.2f\n", unitario);

	diferencia=diferenciaPrecios(precioVuelosLatam, precioVuelosAerolineas);

	printf("La diferencia de precio es de : $ %.2f\n", diferencia);



	return 0;
}








