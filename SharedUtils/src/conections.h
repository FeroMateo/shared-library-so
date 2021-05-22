
#ifndef CONECTIONS_H_
#define CONECTIONS_H_

//normales
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

//commons
#include<commons/string.h>
#include<commons/log.h>
#include<commons/config.h>
#include<readline/readline.h>

//shared
#include "utils_servidor.h"
#include "utils_cliente.h"
#include "estructurasCliente-Servidor.h"
#include "conexiones.h"


pthread_t array_hilos[4];


void holaMundo();

void conectar_envio(int codigoDeConexion,char* ip,int PUERTO_PARA_ENVIAR,t_log* logg);
int escuchar_puerto(int conexion_server,int puerto,t_log* logger);
void recibir_mensaje_encriptado(int cliente_fd,t_log* logg);
void asignar_escuchas(int conexion_server,int puerto, t_log* logger);
void leer_mensajes(int socket_interno,t_log* log);
void* aceptar();
void chat(int);
void terminar_programa(int,t_config*,t_log*);
void asignar_hilo(void* funcion);












#endif /* CONECTIONS_H_ */
