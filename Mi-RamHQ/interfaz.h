/*
 * interfaz.h
 *
 *  Created on: 23 jul. 2021
 *      Author: utnso
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_

#include "estructurasMemoria.h"


typedef struct {

	uint32_t idPatota; 				//Identificador de la patota
	uint32_t tareas; 			//Direccion logica del inicio de las tareas

}t_pcb;

typedef struct {

	uint32_t idTripulante; 				//ID del tripulante
	uint32_t posX; 				//Pos en eje x
	uint32_t posY; 				//Pos en eje y
	uint32_t proxInstruccion; 	//Id de la proxima instruccion
	uint32_t puntero_pcb; 		//Direccion logica del PCB del tripulante, su patota
	char estado; 				//Estado del tripulante (N/R/E/B)

}t_tcb;



int elegirEsquema();
/////////////////////////////////////////////////////////////////////////////////////////////////////INICIAR PATOTA
void iniciarPatota(int socket_cliente);

int s_iniciarPatota(int cantTripus, int idPatota, char* tareas, int tamanioTotal);

int p_iniciarPatota(int cantTripus, int idPatota, char* tareas, int tamanioTotal);

////////////////////////////////////////////////////////////////////////////////////////INICIAR TRIPULANTE
void iniciarTripulante(int socket_cliente);

void s_iniciarTripulante(t_tcb* tripulanteNuevo,int idPato);

void p_iniciarTripulante(t_tcb* tripulanteNuevo, int idPatota);
/////////////////////////////////////////////////////////////////////////////EXPULSAR TRIPULANTE

void expulsarTripulante(int socket_cliente);

void s_expulsarTripulante(int idTripu);

void sacarTripulanteListaGlobal(int idTripulanteAEliminar);



/////////////////////////////////////////////////////////////////////////////////ACTUALIZAR UBICACION
void actualizarUbicacion(int socket_cliente);

/////////////////////////////////////////////////////////////////////////////////TOTO ES UN CAPO

t_tcb* buscarTcb(int tid);
void actualizarTripulante(t_tcb* tcb);
char* buscarTareaEsquema(t_tcb* tcb,int pid, int* esUltima);
void expulsarTripulanteID(int tid);

//////////////////////////////////////////////////////////////////////////////////////////ENVIAR OPERACION

void enviarOperacion(int socket_cliente);

char* s_enviarOp(t_tcb* tcb, int* esUltima);

char* p_enviarOp(t_tcb* tcb,int idPatota, int* esUltima);

//t_paquete* armarPaquete(char* tarea, int esLaUltima);

///////////////////////////////////////////////////////////////////////////////////////////////////CAMBIAR ESTADO
void cambiarEstado(int socket_cliente);


#endif /* INTERFAZ_H_ */
