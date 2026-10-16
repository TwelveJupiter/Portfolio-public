# Como usar las librerías rápidamente (solo 6 pasos)

1. Escribir un programa en el que quiera usar estas librerías
1. En su cabecera (probablemente cerca de `#include <stdio.h>`) escriba `#include <[nombre librería]>`
1. Cree una carpeta llamada "Librerias" al mismo nivel que su programa
1. Pegue el `.h` y el `.a` de la librería del paso 2 en la carpeta "Librerias"
1. Compile agregando `-ILibrerias` y el `.c` de la librería deseada
1. Ejecute

## Ejemplo
1. Escribo `main.c`
1. Quiero usar la estructura de dato `DS_Stack` (pila), entonces escribo `#include <DS_Stack.h>`
1. Creo la carpeta "Librerias"
1. Pego `DS_Stack.h` y `DS_Stack.c` en la carpeta "Librerias"
1. Compilo todo usando el comando `gcc main.c -ILibrerias DS_Stack.c -o programa`
1. Ejecuto usando el comando `./programa`
