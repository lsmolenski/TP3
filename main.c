#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList* listaPasajeros;// = ll_newLinkedList();
    listaPasajeros = ll_newLinkedList();

    do{
        switch(option)
        {
            case 0:
                controller_loadFromText("data.csv",listaPasajeros);

                break;
        }
        option = 10;
    }while(option != 10);

//    Passenger* psjPrint = ll_get(listaPasajeros, 0);
//    Passenger_print(psjPrint);
    return 0;
}

