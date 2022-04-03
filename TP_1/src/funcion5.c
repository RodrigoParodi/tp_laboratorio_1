/*
 * funcion5.c
 *
 *  Created on: 3 abr. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>


float diferenciaPrecios(float operador1, float operador2){

	float resultado;


	if(operador1>operador2)
	{
		resultado = operador1 - operador2;
	}
	else
	{
		resultado = operador2 - operador1;
	}




	return resultado;
}


