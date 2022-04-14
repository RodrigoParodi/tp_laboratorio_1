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
#include <ctype.h>                                //Bibliotecas usadas
#include "funciones.h"
#include "menu.h"


int main(){
	setbuf(stdout, NULL);

	int kilometros;
	int banderaKilometros = 0;
	int banderaPrecios = 0;
	int banderaCalculos = 0;
	char respuesta ='n';
	float precioVuelosLatam = 0;
	float precioVuelosAerolineas = 0;                        //Variables usadas
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
	system("pause");

	do{
		system("cls");
		switch(menuPrincipal())  //menu principal
		{
		case 1:

			kilometros=ingresarKilometros();					//Pedir que ingrese los kilometros

			banderaKilometros = 1;
			system("pause");
		break;
		case 2:
			if(banderaKilometros == 1)
			{
				precioVuelosAerolineas=precioUno(precioVuelosAerolineas);		//pedir que ingrese ambos precios.
				precioVuelosLatam=precioDos(precioVuelosLatam);
				banderaPrecios = 1;
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

				debitoAero=precioTarjetaDebito(precioVuelosAerolineas);           //Calcular todos los datos atravez de funciones
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
			if(banderaPrecios ==1 && banderaKilometros == 1 && banderaCalculos == 1)	//MOSTAR RESULTADOS
			{
				printf("Estos son los resultados:\n\n");

				resultados(kilometros, precioVuelosLatam, debitoLatam, creditoLatam, bitCoinLatam, unitarioLatam,
							precioVuelosAerolineas, debitoAero, creditoAero, bitCoinAero, unitarioAero,
							diferencia);
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
			creditoAero=precioTarjetaCredito(162965);		//CARGA FORZADA DE DATOS , DIRECTAMENTE MUESTRA LOS RESULTADOS
			bitCoinAero=precioBitCoin(162965);
			unitarioAero=precioUnitario(162965, kilometros);

			diferencia=diferenciaPrecios(162965, 159339);

			printf("La carga forzada de datos fue realizada con exito!!!\n\n");
			printf("Estos son los resultados:\n\n");

			resultados(kilometros, precioVuelosLatam, debitoLatam, creditoLatam, bitCoinLatam, unitarioLatam,
						precioVuelosAerolineas, debitoAero, creditoAero, bitCoinAero, unitarioAero,
						diferencia);

			system("pause");
		break;
		case 6:
			respuesta=preguntaSalirDelMenu();						//PREGUNTAR PARA SALIR O NO DEL MENU.
		break;
		default:
			printf("Opcionon Invalida!!!!\n");
			system("pause");							//EN CASO DE USAR UN NUMERO MAYOR DE 6 O LETRA SALDRA ESTE MENSAJE DE ERROR
		break;
		}

	}while(respuesta !='s');

	printf("\n Adios que tenga un buen viaje!!!");

	return 0;
}//FIN DEL PROGRAMA.







