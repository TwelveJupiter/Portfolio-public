#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DS_Stack.h"

struct Integer{
	int val;
};

struct Integer* crearEntero(int val){
	struct Integer* objeto = malloc(sizeof(struct Integer));
	objeto->val = val;
	return objeto;
}

void DS_mostrarObjeto(void* objeto){
	int val = ((struct Integer*)objeto)->val;
	printf("%03d", val);
	return;
}


int main(){
	struct DS_Pila* pila = DS_crearPila(sizeof(struct Integer));
	
	srand(7);
	
	for(int i=1;i<10;i++){
		int val = rand()&0xFF;
		struct Integer* objeto = crearEntero(val);
		PILA_push(pila, (void *)objeto);
	}
	
	DS_mostrarPila(pila);
	
	for(int i=1;i<10;i++){
		struct Integer* objeto = PILA_pop(pila);
		DS_mostrarObjeto(objeto);
		printf("\n");
		free(objeto);
	}
	
	DS_mostrarPila(pila);
	
	printf("%ld\n", pila->n);
	printf("%ld\n", pila->tamanoMaximo);

	return 0;
}
