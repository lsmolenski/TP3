/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Passenger* Passenger_new(){
	/**/
	Passenger* auxPassenger;
	auxPassenger = (Passenger*)malloc(sizeof(Passenger));

	if(auxPassenger != NULL){
		auxPassenger->id =0;
		strcpy(auxPassenger->nombre, "");
		strcpy(auxPassenger->apellido, "");
		auxPassenger->isEmpty = 1;

	}
	return auxPassenger;
}


Passenger* Passenger_newParametros(char *idStr, char *nombreStr, char *apellStr, char *flyCode, char *tipoPasajeroStr) {
	int id;

	Passenger *newPassenger;

	newPassenger = Passenger_new();

	if (newPassenger != NULL) {
		id = atoi(idStr);

		//ir implementando todo lo de aca
		if (	Passenger_setId(newPassenger, id)
				|| Passenger_setNombre(newPassenger, nombreStr)
				|| Passenger_setApellido(newPassenger,apellStr)
				|| Passenger_setCodigoVuelo(newPassenger, flyCode)) {
			free(newPassenger);
			newPassenger = NULL;
		}
	}


	return newPassenger;
}


int Passenger_setId(Passenger *this, int id) {
	int retorno = 1;

	if (this != NULL && id > 0 && id <= 1000) {
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getId(Passenger* this, int* id){
    int retorno=1;

    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;

}

int Passenger_setNombre(Passenger* this,char* nombre){
    int retorno=1;

    if(this!=NULL && strlen(nombre)>=3 && strlen(nombre)<=20)
    {
//        strcpy(this->nombre,nombre);

        strncpy(this->nombre, nombre, strlen(nombre)+1);
        retorno=0;
    }
    return retorno;

}



int Passenger_getNombre(Passenger* this,char* nombre){
    int retorno=1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido){
	int retorno=1;

	    if(this!=NULL && strlen(apellido)>=3 && strlen(apellido)<=20)
	    {
	//        strcpy(this->nombre,nombre);

	        strncpy(this->apellido, apellido, strlen(apellido)+1);
	        retorno=0;
	    }
	    return retorno;

}


int Passenger_getApellido(Passenger* this,char* apellido){
    int retorno=1;

    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno=1;

	    if(this!=NULL && strlen(codigoVuelo)>=1 && strlen(codigoVuelo)<=7)
	    {
	//        strcpy(this->nombre,nombre);

	        strncpy(this->codigoVuelo, codigoVuelo, strlen(codigoVuelo)+1);
	        retorno=0;
	    }
	    return retorno;

}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio){

	int retorno = 1;

	if (this != NULL && precio > 0 ) {
		this->precio = precio;
		retorno = 0;
	}
	return retorno;

}
int Passenger_getPrecio(Passenger* this,float* precio){
	   int retorno=1;

	    if(this!=NULL && precio!=NULL)
	    {
	        *precio = this->precio;
	        retorno=0;
	    }
	    return retorno;
}


int Passenger_print(Passenger* this){
	int retorno=-1;

	    if(this!=NULL)
	    {
	        printf(" %d    %20s %20s  Pasajero tipo: %s Vuelo: %s -  $%.2f   \n", this->id, this->nombre, this->apellido,  this->tipoPasajero, this->codigoVuelo, this->precio );
	        retorno=0;
	    }
	    return retorno;

}
