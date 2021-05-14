
#ifndef CONECTIONS_H_
#define CONECTIONS_H_

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<commons/string.h>
#include<commons/log.h>
#include<commons/config.h>
#include<readline/readline.h>


#include "utils_servidor.h"
#include "utils_cliente.h"
#include "estructurasCliente-Servidor.h"
#include "conexiones.h"

pthread_t hilo;

void holaMundo();

void conectar_envio(int codigoDeConexion,char* ip,int PUERTO_PARA_ENVIAR,t_log* logg);
int escuchar_puerto(int conexion_server,int puerto);
void recibir_mensaje_encriptado(int cliente_fd,t_log* logg);

void chat(int);
void terminar_programa(int,t_config*,t_log*);












#endif /* CONECTIONS_H_ */
