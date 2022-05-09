/*
 * sector.c
 *
 *  Created on: 8 may. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "menu.h"
#include "sector.h"
#include "sectorDos.h"

int listarTiposDePasajeros(Sector tipos[], int tam){

    int todoOk = 0;
    if(tipos != NULL && tam > 0 ){

        printf("*****LISTADO DE TIPOS*****\n");
        printf("   id    TIPOS DE PASAJEROS\n");
        printf("_______________________________\n");

         for(int i= 0; i < tam; i++){

                printf("     %4d     %10s\n", tipos[i].id, tipos[i].tipoPasajero);

            }
        todoOk = 1;
         }
    return todoOk;
    }

int cargarDescripcionSector(Sector tipos[], int tam, int id, char desc[]){

    int todoOk = 0;
    if(tipos != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( tipos[i].id == id){
                strcpy( desc, tipos[i].tipoPasajero);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}






