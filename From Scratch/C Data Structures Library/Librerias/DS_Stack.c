#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DS_Stack.h"

struct DS_Pila* DS_crearPila(size_t tamanoObjetos){
	struct DS_Pila* pila = malloc(sizeof(struct DS_Pila));
	
	pila->n = 0;
	pila->tamanoObjetos = tamanoObjetos;
	pila->tamanoMaximo = 256*tamanoObjetos;
	pila->datos = malloc(pila->tamanoMaximo*pila->tamanoObjetos);
	
	return pila;
}

void PILA_push(struct DS_Pila* pila, void* dato){
	
	//Realloc para evitar overflow
	if(pila->n + 1 >= pila->tamanoMaximo){
		pila->datos = realloc(pila->datos, 2*pila->tamanoMaximo);
		pila->tamanoMaximo *= 2;
	}
	
	//Guardar el dato
	size_t n = pila->n;
	unsigned char* datoConvertido = dato;
	size_t tamanoObjetos = pila->tamanoObjetos;
	for(size_t i=n*tamanoObjetos;i<(n + 1)*tamanoObjetos;i++){
		pila->datos[i] = datoConvertido[i - n*tamanoObjetos];
	}
	pila->n++;
	
	return;
}

void* PILA_pop(struct DS_Pila* pila){
	
	size_t tamanoObjetos = pila->tamanoObjetos;
	
	//Obtener el último elemento
	char* ultimo = malloc(tamanoObjetos);
	memcpy(ultimo, pila->datos[(pila->n - 1)*tamanoObjetos], tamanoObjetos);
	
	//Eliminar el último
	pila->n--;
	
	return (void*)ultimo;
}

int PILA_len(struct DS_Pila* pila){
	return pila->n;
}


void DS_mostrarPila(struct DS_Pila* pila){
	size_t n = pila->n;
	size_t tamanoObjetos = pila->tamanoObjetos;
	
	for(size_t chunk=0;chunk<n;chunk++){
		
		//Obtener objeto actual
		char* objeto = malloc(tamanoObjetos);
		for(size_t offset=0;offset<tamanoObjetos;offset++){
			objeto[offset] = pila->datos[chunk*tamanoObjetos + offset];
		}
		
		//Mostrarlo
		DS_mostrarObjeto((void*)objeto);
		printf(" ");
		
		//Liberar memoría que no se usará
		free(objeto);
	}
	printf("\n");
	
	return;
}