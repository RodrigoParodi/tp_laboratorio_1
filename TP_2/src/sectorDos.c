/*
 * sectorDos.c
 *
 *  Created on: 9 may. 2022
 *      Author: Rodrigo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"
#include "menu.h"
#include "ArrayPassenger.h"



int listarTiposDeEstados(Estados tipos[], int tam){

    int todoOk = 0;
    if(tipos != NULL && tam > 0 ){

        printf("*****LISTADO DE TIPOS*****\n");
        printf("   id    TIPOS DE ESTADOS\n");
        printf("_______________________________\n");

         for(int i= 0; i < tam; i++){

                printf("     %4d     %10s\n", tipos[i].id, tipos[i].estadosVuelos);

            }
        todoOk = 1;
         }
    return todoOk;
    }

int cargarDescripcionEstado(Estados est[], int tam, int id, char desc[]){

    int todoOk = 0;
    if(est != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( est[i].id == id){
                strcpy( desc, est[i].estadosVuelos);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}
