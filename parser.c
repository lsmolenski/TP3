#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"

#include "PedirDatos.h"
#define CANT_PARAMETROS_CSV 7



/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int cantParametros = 0;

	int cantTotalRegistros = 0;


	//datos obtenidos del file
	char idAux[10];
	char name[10];
	char lastName[20];
	char priceAux[10];
	char flyCode[10];
	char psgrType[10];
	char flightStatus[10];

	Passenger *auxPsg;


	//variables auxiliares
	float priceFinal;
	int idFinal;

	if (pFile != NULL) {
		//LEER ARCHIVO

		//skip primera linea HEADEr
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, name,
				lastName, priceAux, flyCode, psgrType, flightStatus);
		do {
			cantParametros = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					idAux, name, lastName, priceAux, flyCode, psgrType, flightStatus);


			if (cantParametros == CANT_PARAMETROS_CSV) {

				if (esNumeroEntero(idAux)){
					idFinal = getIntFromStr(idAux,strlen(idAux));
				}

				auxPsg = Passenger_newParametros( idAux, name, lastName, flyCode, psgrType);
				//convierto a numeros
				if (getFinalFloat(priceAux, &priceFinal)){
					Passenger_setPrecio(auxPsg, priceFinal);
				}


				Passenger_print(auxPsg);

//				printf("Id: %s - Nombre %s - %s\n", id, name, lastName);
				if (ll_add(pArrayListPassenger, auxPsg)){
					cantTotalRegistros++;
				}

			} else {
				printf("Error lectura");
			}

		} while (!feof(pFile));
		//			}while(c > 0);
	}

	fclose(pFile);
	printf("\nFin ejecucion archivo - cantidad elementos: %d", cantParametros);

	return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
