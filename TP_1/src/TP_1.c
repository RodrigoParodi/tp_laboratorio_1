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
#include <ctype.h>
#include "funciones.h"
#include "menu.h"


int main(){
	setbuf(stdout, NULL);

	int opciones;
	int kilometros;
	int banderaKilometros = 0;
	int banderaPrecios = 0;
	int banderaCalculos = 0;
	char ingresarPrecio;
	float precioVuelosLatam = 0;
	float precioVuelosAerolineas = 0;
	float debito;
	float credito;
	float bitCoin;
	float unitario;
	float diferencia;

	printf("Hola bienvenido!!!\n\n");

	do{
		printf("\n\n MENU DE OPCIONES.\n\n");
		printf("1)Ingresar Kilometros.\n");
		printf("2)Ingresar Precio de vuelos.\n");
		printf("3)Calcular todos los costos.\n");
		printf("4)Mostrar resultados.\n");
		printf("5)Carga forzada de datos.\n");
		printf("6)Salir.\n\n");

		printf("Eliga que opcion desea iniciar : ");
		scanf("%d", &opciones);

		switch(opciones)
		{
		case 1:
			printf("Ingrese la cantidad de kilometros : ");
			scanf("%d", &kilometros);

			while(kilometros < 0)
			{
				printf("ERROR, Reingrese la cantidad de kilometros : ");
				scanf("%d", &kilometros);
			}

			banderaKilometros = 1;
			system("pause");
		break;
		case 2:
			if(banderaKilometros == 1)
			{
				printf("Eliga que empresa de vuelo quiere.\n");
				printf("A)Aerolineas.\n");
				printf("B)Latam.\n\n");

				printf("Elija una opcion : ");
				fflush(stdin);
				scanf("%c", &ingresarPrecio);
				ingresarPrecio = tolower(ingresarPrecio);
				banderaPrecios = 1;

				switch(ingresarPrecio)
				{
				case 'a':
					printf("Ingrese El precio de Aerolineas : ");
					scanf("%f", &precioVuelosAerolineas);
					while(precioVuelosAerolineas < 0)
					{
						printf("ERROR , Reingrese el precio (Mayor a 0) : ");
						scanf("%f", &precioVuelosAerolineas);
					}
				break;
				case 'b':
					printf("Ingrese El precio de Latam : ");
					scanf("%f", &precioVuelosLatam);
					while(precioVuelosLatam < 0)
					{
						printf("ERROR , Reingrese el precio (Mayor a 0) : ");
						scanf("%f", &precioVuelosLatam);
					}
				break;
				}
			}
			else
			{
				printf("ERROR, Ingresar los kilometros antes de ingresar los precios!!!\n\n");
			}
			system("pause");
		break;
		case 3:
			if(banderaPrecios ==1 && banderaKilometros == 1)
			{
				debito=precioTarjetaDebito(precioVuelosLatam);
				credito=precioTarjetaCredito(precioVuelosLatam);
				bitCoin=precioBitCoin(precioVuelosLatam);
				unitario=precioUnitario(precioVuelosLatam, kilometros);

				debito=precioTarjetaDebito(precioVuelosAerolineas);
				credito=precioTarjetaCredito(precioVuelosAerolineas);
				bitCoin=precioBitCoin(precioVuelosAerolineas);
				unitario=precioUnitario(precioVuelosAerolineas, kilometros);

				diferencia=diferenciaPrecios(precioVuelosLatam, precioVuelosAerolineas);

				banderaCalculos = 1;
				printf("Los datos han sido calculados con exito!!!\n\n");
			}
			else
			{
				printf("Error, Ingrese los precios y KMs antes de pedir los resultados!!!\n\n");
			}
			system("pause");

		break;
		case 4:
			if(banderaPrecios ==1 && banderaKilometros == 1 && banderaCalculos == 1)
			{
				printf("Estos son los resultados:\n\n");

				printf("Kilometros Ingresados: %d  KM\n\n", kilometros);

				if(precioVuelosLatam > 0)
				{
					printf("Latam :$ %.2f\n", precioVuelosLatam);
					printf("A)Precio con tarjeta de debito: $  %.2f\n", debito);
					printf("B)Precio con tarjeta de credito: $  %.2f\n", credito);
					printf("C)Precio pagando con BitCoin: %.5f    BTC\n", bitCoin);
					printf("D)Precio Unitario: $ %.2f\n", unitario);
				}

				if(precioVuelosAerolineas > 0)
				{
					printf("Aerolineas :$ %.2f\n", precioVuelosAerolineas);
					printf("A)Precio con tarjeta de debito: $  %.2f\n", debito);
					printf("B)Precio con tarjeta de credito: $  %.2f\n", credito);
					printf("C)Precio pagando con BitCoin: %.5f    BTC\n", bitCoin);
					printf("D)Precio Unitario: $ %.2f\n", unitario);

				}

				printf("La diferencia de precio es de : $ %.2f\n\n", diferencia);
			}
			else
			{
				printf("Error antes de mostrar resultados ingrese los precios y KMs!!!\n");
				printf("Tampoco se olvide de seleccionar la opcion 3 antes de pedir los resultados!!!\n\n");
			}
				system("pause");
		break;
		case 5:
			kilometros = 7090;

			precioVuelosLatam=159339;
			debito=precioTarjetaDebito(159339);
			credito=precioTarjetaCredito(159339);
			bitCoin=precioBitCoin(159339);
			unitario=precioUnitario(159339, kilometros);

			precioVuelosAerolineas=162965;
			debito=precioTarjetaDebito(162965);
			credito=precioTarjetaCredito(162965);
			bitCoin=precioBitCoin(162965);
			unitario=precioUnitario(162965, kilometros);

			diferencia=diferenciaPrecios(162965, 159339);

			banderaKilometros=1;
			banderaPrecios=1;

			printf("Los datos fueron cargados con exito!!!\n\n");
			system("pause");
		break;
		}

	}while(opciones !=6 );





	printf("\n Adios que tenga un buen viaje!!!");

	return 0;
}








