
#ifndef SHAREDUTLIS_H_
#define SHAREDUTLIS_H_

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







t_log* discordiador_logger;
t_config* discordiador_config;


pthread_t hilo;

void holaMundo();


//void escuchar_y_enviar(char*,char*);



//FUNCIONES PARA RECIBIR
int escuchar(char*,char*,t_log*);
//void* enviar_a_cliente();
void recibir_mensaje_encriptado(int cliente_fd);

// FUNCIONES PARA ENVIAR
void enviar(char*,char*,t_config*,t_log*);
void chat(int);
void iniciar_logger(void);
//void leer_config(void);
void terminar_programa(int,t_config*,t_log*);












#endif /* SHAREDUTLIS_H_ */
