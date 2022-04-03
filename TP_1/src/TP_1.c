//Trabajo Practico 1
//Parodi Rodrigo
//Programacion 1

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

	printf("Latam :$ %.2f\n", precioVuelosLatam);
	debito=precioTarjetaDebito(precioVuelosLatam);
	printf("A)Precio con tarjeta de debito: $  %.2f\n", debito);
	credito=precioTarjetaCredito(precioVuelosLatam);
	printf("B)Precio con tarjeta de credito: $  %.2f\n", credito);
	bitCoin=precioBitCoin(precioVuelosLatam);
	printf("C)Precio pagado con BitCoin: %.5f    BTC\n", bitCoin);
	//printf()
	printf("Aerolineas :$ %.2f\n", precioVuelosAerolineas);
	debito=precioTarjetaDebito(precioVuelosAerolineas);
	printf("A)Precio con tarjeta de debito: $  %.2f\n", debito);
	credito=precioTarjetaCredito(precioVuelosAerolineas);
	printf("B)Precio con tarjeta de credito: $  %.2f\n", credito);
	bitCoin=precioBitCoin(precioVuelosAerolineas);
	printf("C)Precio pagado con BitCoin: %.5f    BTC\n", bitCoin);
	//printf()
	//printf()



	return 0;
}




