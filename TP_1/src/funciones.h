/*
 * funciones.h
 *
 *  Created on: 2 abr. 2022
 *      Author: Rodrigo
 */

///funciones matematicas:
/// precioTarjetaDebito = calcula el precio a pagar con tarjeta de debito aplicadno un 10% de descuento.
/// precioTarjetaCredito = clacula el precio a pagar con tarjeta de credito aplicando un 25% de aumento.
/// precioBitCoin = calcula el valor del precio a pagar en bitcoins.
/// precioUnitario = calcula el precio unitario (precio/km).
/// diferenciaPrecios = calcula la diferencia que hay entre ambos precios.


#ifndef FUNCIONES_H_
#define FUNCIONES_H_

float precioTarjetaDebito(float operador1);
float precioTarjetaCredito(float operador1);
float precioBitCoin(float operador1);
float precioUnitario(float operador1, int operador2);
float diferenciaPrecios(float operador1, float operador2);

#endif /* FUNCIONES_H_ */
