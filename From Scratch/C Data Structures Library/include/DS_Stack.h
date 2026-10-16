#ifndef DS_Stack_H
#define DS_Stack_H

typedef struct DS_Pila {
	unsigned char* datos;
	size_t n;
	size_t tamanoObjetos;
	size_t tamanoMaximo;
} DS_Pila;

struct DS_Pila* DS_crearPila(size_t tamanoObjetos);

void DS_push(struct DS_Pila* pila, void* dato);
void* DS_pop(struct DS_Pila* pila);


void DS_mostrarObjeto(void* objeto);
void DS_mostrarPila(struct DS_Pila* pila);

#endif