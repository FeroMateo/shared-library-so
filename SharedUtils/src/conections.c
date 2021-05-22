
#include <conections.h>


void holaMundo()
{
	printf("Hola Mundo");
}


void conectar_envio(int codigoDeConexion,char* ip,int PUERTO_PARA_ENVIAR,t_log* logg)
{
	if(conectarA(codigoDeConexion,ip,PUERTO_PARA_ENVIAR))
			{
				log_info(logg,"SE CONECTO UN CLIENTE");
			}else
			{
				log_info(logg,"ERROR AL CONECTAR");
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

void asignar_escuchas(int conexion_server,int puerto, t_log* logger)
{
	while(1)
	{
		if(escuchaEn(conexion_server,puerto))
		{
			log_info(logger,"NUEVO CLIENTE");
			void* aceptar()
			{
				int socket_interno = aceptarConexion(conexion_server);
				log_info(logger,"Se acepto");
				leer_mensajes(socket_interno, logger);
			}
			Tripulante* nuevo_tripulante = crearTripulante(aceptar);
		}
	}
}

void asignar_hilo(void* funcion)
{
	Tripulante* nuevo_tripulante = crearTripulante(funcion);
}

void leer_mensajes(int socket_interno,t_log* log)
{
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




















