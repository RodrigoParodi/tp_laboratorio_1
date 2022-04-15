/*
 * menu.h
 *
 *  Created on: 5 abr. 2022
 *      Author: Rodrigo
 */
/// funciones del menu:
/// menuPrincipal = nos muestra el menu de opciones y nos deja elegir la opcion que queramos.
/// IngresarKilometros = nos pide ingresar kilometros que no sean negativos o una letra/simbolo.
/// precioUno = nos pide ingresar el preciode aerolineas que no sean negativos o un letra/simbolo.
/// precioDos = nos pide ingresar el preciode Latam que no sean negativos o un letra/simbolo.
/// Resultados = Muestra los resultados calculados.
/// preguntaSalirDelMenu = nos pregunta si queremos salir del menu o no.

#ifndef MENU_H_
#define MENU_H_

int ingresarKilometros();
void resultados(int kilometros, float precioVuelosLatam, float debitoLatam, float creditoLatam, float bitCoinLatam, float unitarioLatam,
				float precioVuelosAerolineas, float debitoAero, float creditoAero, float bitCoinAero, float unitarioAero,
				float diferencia);
float precioUno();
float precioDos();
int menuPrincipal(int operador1, float operador2, float operador3);
char preguntaSalirDelMenu();

#endif /* MENU_H_ */
