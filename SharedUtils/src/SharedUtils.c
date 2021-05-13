
#include "SharedUtils.h"


void holaMundo()
{
	printf("Hola Mundo");
}


/*
void escuchar_y_enviar(char* ip,char *puerto_escucha,t_log logger){

	pthread_t hiloEscuchar;
	pthread_t hiloEnviar;
	pthread_create(&hiloEscuchar, NULL, escuchar,(ip,puerto_escucha,logger)); //(void*)codigoDeconexion
	pthread_create(&hiloEnviar, NULL, enviar,NULL);


}*/


int escuchar(char* ip, char*puerto_escucha,t_log* logger){


	void iterator(char* value)
	{
		printf("%s\n", value);
	}

	int server_fd = iniciar_servidor(ip,puerto_escucha);

	log_info(logger, "Servidor listo para recibir al cliente en %d",server_fd);

	int cliente_fd = esperar_cliente(server_fd);

	log_info(logger,"Se conecto un cliente %d", cliente_fd);

	t_list* lista;

	while(1)
	{
		int cod_op = recibir_operacion(cliente_fd);
		switch(cod_op)
		{
	//	case CONEXION:
	//		recibir_codigo(cliente_fd); // ------------------------> Esto hay que sacarlo?

		case MENSAJE:
			//recibir_mensaje(cliente_fd);
			recibir_mensaje_encriptado(cliente_fd);
			break;
		case PAQUETE:
			lista = recibir_paquete(cliente_fd);
			printf("Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
		case -1:
			log_error(logger, "el cliente se desconecto. Terminando servidor");
			return EXIT_FAILURE;
		default:
			log_warning(logger, "Operacion desconocida. No quieras meter la pata");
			break;

	}

	return EXIT_SUCCESS;
}
}


void enviar(char* ip,char* puerto_para_enviar,t_config* unConfig,t_log* unLogger){

	int codigoDeconexion;
	codigoDeconexion = crear_conexion(ip,puerto_para_enviar);
	chat(codigoDeconexion);

	terminar_programa(codigoDeconexion,unConfig,unLogger);



}



/*
void* enviar_a_cliente(int conexion)
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
}*/


void recibir_mensaje_encriptado(int cliente_fd)
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

	log_info(logger,"La hora es %d", hora);
	log_info(logger,"La ubicacion es %s", lugar);
	log_info(logger,"La cantidad de tripulantes es %d", cant_participantes);


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




















