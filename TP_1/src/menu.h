/*
 * menu.h
 *
 *  Created on: 5 abr. 2022
 *      Author: Rodrigo
 */

#ifndef MENU_H_
#define MENU_H_

//FIRMAS DEL MENU.

void resuladosLatam(float precioVuelosLatam, float debitoLatam, float creditoLatam, float bitCoinLatam, float unitarioLatam);
void resuladosAerolineas(float precioVuelosAerolineas, float debitoAero, float creditoAero, float bitCoinAero, float unitarioAero);
void mensajeDifPrecios(float precioVuelosLatam , float precioVuelosAerolineas , float diferencia);
char seleccionarAerolineaa(char ingresarPrecio);
float precioUno(float precioVuelosAerolineas);
float precioDos(float precioVuelosLatam);
int menuPrincipal();

#endif /* MENU_H_ */
