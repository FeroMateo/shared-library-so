/*
 * conexiones.h
 *
 *  Created on: 2 mar. 2019
 *      Author: utnso
 */

#ifndef UTILS_CLIENTE_H_
#define UTILS_CLIENTE_H_

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<pthread.h>

#include "estructurasCliente-Servidor.h"
/*
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

*/
int crear_conexion(char* ip, char* puerto);
void enviar_mensaje(char* mensaje, int socket_cliente);
t_paquete* crear_paquete(void);

t_paquete* crear_patota_paquete(void);
//t_paquete* crear_super_paquete(void);
void agregar_a_paquete(t_paquete* paquete, void* valor, int tamanio);
void enviar_paquete(t_paquete* paquete, int socket_cliente);
void liberar_conexion(int socket_cliente);
void eliminar_paquete(t_paquete* paquete);
void enviar_codigo(char* mensaje, int socket_cliente);

void enviar_mensaje_por_codigo(char* mensaje,op_code codigo, int socket_cliente);


void solicitar_expulsar_tripulante(char* id_tripulante, int socket_cliente);
void enviar_nuevas_posiciones_tripulante(char* id_tripulante, int socket_cliente);
void enviar_nueva_tarea_tripulante(char* id_tripulante, int socket_cliente);
void enviar_iniciar_patota(char* id_tripulante, int socket_cliente);
///////////////////////




#endif /* UTILS_CLIENTE_H_ */
