/*
 * estructurasMemoria.h
 *
 *  Created on: 23 jul. 2021
 *      Author: utnso
 */

#ifndef ESTRUCTURASMEMORIA_H_
#define ESTRUCTURASMEMORIA_H_


#include <commons/bitarray.h>
#include "miram.h"
#include <math.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <commons/temporal.h>
#include <commons/collections/list.h>

#include "paginacion.h"
#include "segmentacion.h"

#define MEM_PPAL 0
#define MEM_VIRT 1

//COMUNES A TODOS LOS ARCHIVOS

pthread_mutex_t mutexMemoria;
pthread_mutex_t mutexIdGlobal;


//VIENE DE MEMORIA.H


t_log* logger;


//VARIABLES GLOBALES
char* memoriaPrincipal;

int idGlobal;



//FUNCIONES
int iniciarMemoria(void);
char* asignarMemoriaBits(int bits);
char* asignarMemoriaBytes(int bytes);
void liberarMemoria();
void ocuparBitMap(t_bitarray* , int ,int );
void liberarBitMap(t_bitarray* , int , int );
int bitsToBytes(int bits);
int contarEspaciosLibresDesde(t_bitarray* unBitmap, int base);
int contarEspaciosOcupadosDesde(t_bitarray* unBitmap, int base);
void showbitarr(t_bitarray*);
void eliminarLista(t_list* lista);
void eliminarAlgo(void* algo);
char* dameNombre();


char* separarTareas(char* tareas, int desplazamiento, int* esUltima);




void mostrarTcb(t_tcb* unaTcb);

#endif /* ESTRUCTURASMEMORIA_H_ */
