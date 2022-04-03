/*
 * funcion2.c
 *
 *  Created on: 3 abr. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>


float precioTarjetaCredito(float operador1){

	int porcentaje = 25;
	float resultado;
	float interes;

	interes= operador1 * porcentaje/100;
	resultado= operador1 + interes;


	return resultado;
}


