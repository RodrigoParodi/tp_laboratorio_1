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
	char ingresarPrecio;
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

	do{
		switch(menuPrincipal())  //menu principal
		{
		case 1:

			kilometros=ingresarKilometros();					//Pedior que ingrese los kilometros

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
					precioVuelosAerolineas=precioUno(precioVuelosAerolineas);		//Elegir compania y escribir el precio del vuelo
				break;																//SI SE PONE UN NUMERO O OTRA LETRA QUE NO ESTA
				case 'b':															//EN EL SWICH SE REPRODUCE MENSAJE  DE ERROR Y
					precioVuelosLatam=precioDos(precioVuelosLatam);                 //REGRESA AL MENU.
				break;
				default:
					printf("Operacion invalida!!!\n\n");
					system("pause");
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
																				//Se tienen que ingresar ambos precios para mostrar
				printf("Kilometros Ingresados: %d  KM\n\n", kilometros);		//la diferencia , sino no hara falta mostrarla.

				resultadosLatam(precioVuelosLatam, debitoLatam, creditoLatam, bitCoinLatam, unitarioLatam);
				resultadosAerolineas(precioVuelosAerolineas, debitoAero, creditoAero, bitCoinAero, unitarioAero);

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
			creditoAero=precioTarjetaCredito(162965);		//CARGA FORZADA DE DATOS , DIRECTAMENTE MUESTRA LOS RESULTADOS
			bitCoinAero=precioBitCoin(162965);
			unitarioAero=precioUnitario(162965, kilometros);

			diferencia=diferenciaPrecios(162965, 159339);

			printf("La carga forzada de datos fue realizada con exito!!!\n\n");
			printf("Estos son los resultados:\n\n");

			printf("Kilometros Ingresados: %d  KM\n\n", kilometros);

			resultadosLatam(precioVuelosLatam, debitoLatam, creditoLatam, bitCoinLatam, unitarioLatam);
			resultadosAerolineas(precioVuelosAerolineas, debitoAero, creditoAero, bitCoinAero, unitarioAero);
			mensajeDifPrecios(precioVuelosLatam, precioVuelosAerolineas, diferencia);

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







