/*
 * funcion1.c
 *
 *  Created on: 2 abr. 2022
 *      Author: Rodrigo
 */

//FUNCIONES MATEMATICAS.
//AQUI SE REALIZAN TODOS LOS CALCULOS DE LOS PRECIOS.

#include <stdio.h>
#include <stdlib.h>


float precioTarjetaDebito(float operador1){

	int porcentaje = 10;
	float resultado;
	float descuento;

	descuento= operador1 * porcentaje/100;			//Funcion para tarjeta de debito.
	resultado= operador1 - descuento;


	return resultado;
}

float precioTarjetaCredito(float operador1){

	int porcentaje = 25;
	float resultado;
	float interes;
														//Funcion para tarjeta de credito.
	interes= operador1 * porcentaje/100;
	resultado= operador1 + interes;


	return resultado;
}

float precioBitCoin(float operador1){

	float resultado;
	float bitCoin = 4606954.55;

	resultado= operador1 / bitCoin;						//funcion para BitCoin.


	return resultado;
}

float precioUnitario(float operador1, int operador2){

	float resultado;


	resultado= operador1 / operador2;					//Funcion precio unitario


	return resultado;
}

float diferenciaPrecios(float operador1, float operador2){

	float resultado;


	if(operador1>operador2)
	{
		resultado = operador1 - operador2;						//funcion calcular diferencia de precios
	}
	else
	{
		resultado = operador2 - operador1;
	}




	return resultado;
}
