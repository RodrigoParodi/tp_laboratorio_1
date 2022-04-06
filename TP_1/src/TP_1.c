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
	float debitoLatam;
	float creditoLatam;
	float bitCoinLatam;
	float unitarioLatam;
	float debitoAero;
	float creditoAero;
	float bitCoinAero;
	float unitarioAero;
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
				ingresarPrecio=seleccionarAerolineaa(ingresarPrecio);
				banderaPrecios = 1;

				switch(ingresarPrecio)
				{
				case 'a':
					precioVuelosAerolineas=precioUno(precioVuelosAerolineas);
				break;
				case 'b':
					precioVuelosLatam=precioDos(precioVuelosLatam);
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
				debitoLatam=precioTarjetaDebito(precioVuelosLatam);
				creditoLatam=precioTarjetaCredito(precioVuelosLatam);
				bitCoinLatam=precioBitCoin(precioVuelosLatam);
				unitarioLatam=precioUnitario(precioVuelosLatam, kilometros);

				debitoAero=precioTarjetaDebito(precioVuelosAerolineas);
				creditoAero=precioTarjetaCredito(precioVuelosAerolineas);
				bitCoinAero=precioBitCoin(precioVuelosAerolineas);
				unitarioAero=precioUnitario(precioVuelosAerolineas, kilometros);

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
					resuladosLatam(precioVuelosLatam, debitoLatam, creditoLatam, bitCoinLatam, unitarioLatam);
				}

				if(precioVuelosAerolineas > 0)
				{
					resuladosAerolineas(precioVuelosAerolineas, debitoAero, creditoAero, bitCoinAero, unitarioAero);;
				}

				mensajeDifPrecios(precioVuelosLatam, precioVuelosAerolineas, diferencia);
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
			debitoLatam=precioTarjetaDebito(159339);
			creditoLatam=precioTarjetaCredito(159339);
			bitCoinLatam=precioBitCoin(159339);
			unitarioLatam=precioUnitario(159339, kilometros);

			precioVuelosAerolineas=162965;
			debitoAero=precioTarjetaDebito(162965);
			creditoAero=precioTarjetaCredito(162965);
			bitCoinAero=precioBitCoin(162965);
			unitarioAero=precioUnitario(162965, kilometros);

			diferencia=diferenciaPrecios(162965, 159339);

			printf("Los datos fueron cargados con exito!!!\n\n");
			printf("Estos son los resultados:\n\n");

			printf("Kilometros Ingresados: %d  KM\n\n", kilometros);
			resuladosLatam(precioVuelosLatam, debitoLatam, creditoLatam, bitCoinLatam, unitarioLatam);
			resuladosAerolineas(precioVuelosAerolineas, debitoAero, creditoAero, bitCoinAero, unitarioAero);;
			mensajeDifPrecios(precioVuelosLatam, precioVuelosAerolineas, diferencia);

			system("pause");
		break;
		}

	}while(opciones !=6 );





	printf("\n Adios que tenga un buen viaje!!!");

	return 0;
}







