#ifndef DS_Stack_H
#define DS_Stack_H

struct DS_Pila {
	unsigned char* datos;
	size_t n;
	size_t tamanoObjetos;
	size_t tamanoMaximo;
};

struct DS_Pila* DS_crearPila(size_t tamanoObjetos);
void DS_mostrarObjeto(void* objeto);
void DS_mostrarPila(struct DS_Pila* pila);

void PILA_push(struct DS_Pila* pila, void* dato);
void* PILA_pop(struct DS_Pila* pila);
int PILA_len(struct DS_Pila* pila);



#endif