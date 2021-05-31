
#include "conections.h"


void conectar_envio(int codigoDeConexion,char* ip,int PUERTO_PARA_ENVIAR)
{
	if(conectarA(codigoDeConexion,ip,PUERTO_PARA_ENVIAR))
			{
				//log_info(logg,"SE CONECTO UN CLIENTE");
				chat(codigoDeConexion);
			}else
			{
				//log_info(logg,"ERROR AL CONECTAR");
			}
}

int escuchar_puerto(int conexion_server,int puerto, t_log* logger)
{
	int conexion_escucha;
			if(escuchaEn(conexion_server,puerto))
			{
				conexion_escucha = aceptarConexion(conexion_server);
				if(conexion_escucha == -1)
						{
							log_info(logger,"ERROR: LA CONEXION ES -1");
						}
				return conexion_escucha;

			}else
			{
				log_info(logger,"ERROR: NO ESCUCHA");
				return -1;
			}
}

void asignar_escuchas(int conexion_server,int puerto)
{
		if(escuchaEn(conexion_server,puerto))
		{
			while(1)
			{
				aceptar_tripulante(conexion_server);
			}
		}
}
void* atender_tripulante(Tripulante* trip)
{
	while(1)
		{
		int cod_op = recibir_operacion(trip->conexion);
						switch(cod_op)
						{

						case MENSAJE:
							//recibir_mensaje(cliente_fd);
							recibir_mensaje_encriptado(trip->conexion,trip->log);
							break;
						case -1:
							log_error(trip->log, "El cliente se desconecto. Terminando servidor");
							break;
						default:
							//log_warning(trip->log, "Operacion desconocida. No quieras meter la pata");
							break;
						}
		}
}

void aceptar_tripulante(int conexion)
{
	Tripulante* nuevo_tripulante = crearTripulante();
	nuevo_tripulante->conexion = aceptarConexion(conexion);
	if(nuevo_tripulante->conexion != -1)
	{
		log_info(nuevo_tripulante->log,"NUEVO TRIPULANTE");
		pthread_create(&(nuevo_tripulante->hilo),NULL,atender_tripulante,nuevo_tripulante);
		pthread_detach(nuevo_tripulante->hilo);
	}
}

void* leer_mensajes(int socket_interno)
{
t_log* log = log_create("logger.log", "OTRO", 1, LOG_LEVEL_DEBUG);

while(1)
	{
	int cod_op = recibir_operacion(socket_interno);
					switch(cod_op)
					{

					case MENSAJE:
						//recibir_mensaje(cliente_fd);
						recibir_mensaje_encriptado(socket_interno,log);
						break;
					case -1:
						log_error(log, "El cliente se desconecto. Terminando servidor");
						break;
					default:
						log_warning(log, "Operacion desconocida. No quieras meter la pata");
						break;
					}
	}
}



void recibir_mensaje_encriptado(int cliente_fd,t_log* logg)
{
	char* mensaje;
	char** mensaje_decriptado;

	mensaje = recibir_y_guardar_mensaje(cliente_fd);

	mensaje_decriptado = string_split(mensaje,",");


	int hora = atoi(mensaje_decriptado[0]);
	char* lugar = mensaje_decriptado[1];
	int cant_participantes = atoi(mensaje_decriptado[2]);

	hora += 18;

	//"2" -> 2
	//STRING -> INT

	log_info(logg,"La hora es %d", hora);
	log_info(logg,"La ubicacion es %s", lugar);
	log_info(logg,"La cantidad de tripulantes es %d", cant_participantes);


}



void chat(int conexion)
{
	char* leido;
	leido = readline(">");

	while(strcmp(leido,"\0") != 0) {
			enviar_mensaje(leido,conexion);
			free(leido);
			leido = readline(">");
		}
	enviar_mensaje(leido,conexion);
	free(leido);

}


void terminar_programa(int conexion,t_config* unConfig,t_log* unLogger)
{
	liberar_conexion(conexion);
	log_destroy(unLogger);
	config_destroy(unConfig);
}




















