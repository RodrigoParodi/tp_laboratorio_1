/*
 * menu.h
 *
 *  Created on: 5 abr. 2022
 *      Author: Rodrigo
 */

#ifndef MENU_H_
#define MENU_H_

//FIRMAS DEL MENU.

int ingresarKilometros();
void resultados(int kilometros, float precioVuelosLatam, float debitoLatam, float creditoLatam, float bitCoinLatam, float unitarioLatam,
				float precioVuelosAerolineas, float debitoAero, float creditoAero, float bitCoinAero, float unitarioAero,
				float diferencia);
float precioUno();
float precioDos();
int menuPrincipal();
char preguntaSalirDelMenu();

#endif /* MENU_H_ */
