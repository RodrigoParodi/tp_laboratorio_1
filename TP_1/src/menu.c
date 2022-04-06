/*
 * menu.c
 *
 *  Created on: 4 abr. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>

void resuladosLatam(float precioVuelosLatam, float debitoLatam, float creditoLatam, float bitCoinLatam, float unitarioLatam){

	printf("Latam :$ %.2f\n", precioVuelosLatam);
	printf("A)Precio con tarjeta de debito: $  %.2f\n", debitoLatam);
	printf("B)Precio con tarjeta de credito: $  %.2f\n", creditoLatam);
	printf("C)Precio pagando con BitCoin: %.5f    BTC\n", bitCoinLatam);
	printf("D)Precio Unitario: $ %.2f\n", unitarioLatam);


}

void resuladosAerolineas(float precioVuelosAerolineas, float debitoAero, float creditoAero, float bitCoinAero, float unitarioAero){

	printf("Aerolineas :$ %.2f\n", precioVuelosAerolineas);
	printf("A)Precio con tarjeta de debito: $  %.2f\n", debitoAero);
	printf("B)Precio con tarjeta de credito: $  %.2f\n", creditoAero);
	printf("C)Precio pagando con BitCoin: %.5f    BTC\n", bitCoinAero);
	printf("D)Precio Unitario: $ %.2f\n", unitarioAero);


}

void mensajeDifPrecios(float precioVuelosLatam , float precioVuelosAerolineas , float diferencia){

	if(precioVuelosLatam > 0 && precioVuelosAerolineas > 0)
	{
		printf("La diferencia de precio es de : $ %.2f\n\n", diferencia);
	}
	else
	{
		printf("Solo se ingreso un precio por lo cual no se calculara la diferencia!!!\n\n");
	}





}
