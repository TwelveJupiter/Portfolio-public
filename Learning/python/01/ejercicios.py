#A1
x = 10 #x apunta a un objeto entero con valor 10
y = x #y apunta al mismo objeto que x
x += 1 #int es inmutable, se crea otro objeto entero con valor igual al resultado de 10 + 1
print(x, y) #11 10


#A2
a = [1, 2] #a apunta a un objeto lista con valor [1, 2]
b = a #b apunta al mismo objeto que a
a = a + [3] 
print(a, b) #[1, 2, 3] [1, 2]. b apunta igual que a, pero luego a se reasigna


#A3
a = [1, 2, 3] #a apunta a un objeto lista con valor [1, 2, 3]
b = [1, 2, 3] #b apunta a un objeto lista con valor [1, 2, 3]
c = a #c apunta al mismo objeto que a
print(a == b, a is b, a is c) #True False True


#A4
t = ([1, 2], 3) #t apunta a un objeto tupla
t[0].append(99) #se muta un objeto al que la tupla apunta, no se está mutando la tupla en sí
print(t) #([1, 2, 99], 3)


#A5
grid = [[0] * 3] * 3 #se crea una lista de 3 listas, cada una contiene 3 listas [0]
grid[0][0] = 1 #todos los elementos apuntan al mismo objeto [0]
print(grid) # [[1, 1, 1], [1, 1, 1], [1, 1, 1]]
#AQUI ME EQUIVOQUÉ. No interpreté bien la sintaxis [0] * 3

#A6
import copy
original = [[1, 2], [3, 4]]
superficial = original.copy() #Copia de los punteros, no de todo
profunda = copy.deepcopy(original) #Copia totalmente independiente

original[0].append(5)
original.append([6])

print(superficial) # [[1, 2, 5], [3, 4]]
print(profunda) # [[1, 2], [3, 4]]


#A7
def modificar(lista, numero):
    lista.append(numero)
    numero += 1
    lista = [0]
    return numero

nums = [1]
n = 5
r = modificar(nums, n)
print(nums, n, r) #[1, 5] 5 6


#A8
d = {"items": []}
copia = dict(d)
copia["items"].append(1) #mutable
copia["nuevo"] = 2
print(d) #{"items": [1]}






'''
B1. Escribe agregar_sin_modificar(lista, elemento). Debe retornar una lista nueva
con el elemento al final, sin modificar la original. Incluye un assert que
demuestre que la original quedó intacta.
'''

import copy
def agregar_sin_modificar(lista, elemento):
    lista2 = copy.deepcopy(lista)
    lista2.append(elemento)
    return lista2


a = [[1, 2], 2, 3]
b = agregar_sin_modificar(a, 4)

del b[2]
del b[1]
del b[0]

assert len(a) == 3, "Acciones en la lista copiada afectaron a la original"




'''
B2 (inspirado en tu parser de PDFs). Escribe normalizar_registros(registros), que
recibe una lista de diccionarios como esta:

python
registros = [
    {"nombre": "  ana pérez ", "edad": "30", "tags": ["a"]},
    {"nombre": "LUIS soto",    "edad": " 25", "tags": []},
]

Debe retornar una lista nueva donde:

nombre quede sin espacios en los extremos y en formato título ("Ana Pérez").
edad sea un int.
tags sea una lista nueva, independiente de la original.

Requisito clave: los registros originales no deben cambiar en absoluto. Agrega al
final asserts que lo comprueben, incluyendo que modificar tags en el resultado no
afecte al original.
'''
def _normalizar_texto(texto):
    palabras = texto.lower().split()
    return " ".join(palabra.capitalize() for palabra in palabras)

def normalizar_registros(registros):
    nuevos_registros = []
    for registro in registros:
        nuevo_registro = {}
        nuevo_registro["nombre"] = _normalizar_texto(registro["nombre"])
        nuevo_registro["edad"] = int(registro["edad"])
        nuevo_registro["tags"] = list(registro["tags"])
        nuevos_registros.append(nuevo_registro)
    return nuevos_registros



## Errores ##
## B1. deepcopy suele ser lento, mejor solo ocupar lista + [elemento]
## B2. Olvidé los assert
