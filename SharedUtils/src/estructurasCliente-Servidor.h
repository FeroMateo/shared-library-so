/*
 * estructurasCliente-Servidor.h
 *
 *  Created on: 11 may. 2021
 *      Author: utnso
 */

#ifndef SRC_ESTRUCTURASCLIENTE_SERVIDOR_H_
#define SRC_ESTRUCTURASCLIENTE_SERVIDOR_H_


#include<stdlib.h>
#include<stdio.h>
//#include<stddef.h>

typedef enum
{
	MENSAJE,
	CONEXION,
	PAQUETE
}op_code;

typedef struct
{
	int size;
	void* stream;
} t_buffer;

typedef struct
{
	op_code codigo_operacion;
	t_buffer* buffer;
} t_paquete;


typedef struct
{
	int pid;
	pthread_t hilo;
	pthread_mutex_t mutex;


}Tripulante;


#endif /* SRC_ESTRUCTURASCLIENTE_SERVIDOR_H_ */
