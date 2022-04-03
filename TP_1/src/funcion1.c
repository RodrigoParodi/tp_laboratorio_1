/*
 * funcion1.c
 *
 *  Created on: 2 abr. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>


float precioTarjetaDebito(float operador1){

	int porcentaje = 10;
	float resultado;
	float descuento;

	descuento= operador1 * porcentaje/100;
	resultado= operador1 - descuento;


	return resultado;
}
