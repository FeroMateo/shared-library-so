/*
 * estructurasCliente-Servidor.c
 *
 *  Created on: 22 may. 2021
 *      Author: utnso
 */

#include "estructurasCliente-Servidor.h"

Tripulante* crearTripulante(void* funcion)
{
	Tripulante* tripulante = malloc(sizeof(Tripulante));

	pthread_create(&(tripulante->hilo),NULL,funcion,NULL);
	pthread_detach(tripulante->hilo);

	tripulante->pid = pthread_self(tripulante->hilo);

	return tripulante;

}
