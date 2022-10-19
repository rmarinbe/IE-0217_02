'''
Created on Jan 23, 2021
Modified on Oct 13, 2022

@author: Freddy
@modified by: Richard
'''

#%%

# Hola Mundo en Python
#====================================================

print("Hola Mundo ahora en Python!")


#%%

# VARIABLES y STRINGS
#====================================================
# Mejor usarlas en minúscula por estándar de Python

mensaje = "Hola Mundo ahora en Python!"
print(mensaje)


#%%

# Strings
nombre = "estructuras abstractas y algoritmos en ingeniería"
print(nombre)
print(nombre.title()) # Usa el método title() de la clase String
 

#%%
print(nombre.upper()) # Usa el método upper() declarado en la clase String
print(nombre.lower()) # Usa el método lower() declarado en la clase String
 

#%%
nombre = "clodomiro"
apellido = "picado"
nombre_completo = nombre + " " + apellido # Operación de concatenación entre strings
 
mensaje = "Investigador y científico importante de Costa Rica: " + nombre_completo.title() + "!"
print(mensaje)


#%%

# Usando la forma de retorno de línea en Python similar a la de C/C++
print("Lenguajes:\nC++\nPython\nJava")


#%%
# Eliminando espacios en blanco y caracteres especiales
lenguaje = ' python'
print(lenguaje.rstrip())
print(lenguaje.lstrip())
print(lenguaje.strip())
#tvar = lenguaje.strip()

#%%
# Uso de números en Python
# Números enteros
2 + 3 +10
3 - 4
2 * 9
5 / 2
5//2
2 ** 2
3 ** 200
5%2


#%%
# Manejo de la precedencia (INFIX/POSFIX)
2 + 3 * 4
(2 + 3) * 4
2+5**3*20


#%%

# Uso de Números reales
0.15 + 0.12456
0.27 + 0.33 *2.15
3 * 0.15
2+ 2 * 0.2


#%%

# Casos mistos de números y cadenas en Python

iteraciones = 25
mensaje1 = "Un total de " + str(iteraciones) + " iteraciones fueron realizadas en algoritmo"
print(mensaje1)



#%%

# Uso de bibliotecas en Python
# Usando la biblioteca math
import math as mt # Carga el paquete




#%%

# Para obtener el valor de pi esta ya está definido en 'math' PI=3.141592653589793
print(mt.pi)


#%%
x = 3
y = 4
print("La hipotenusa del triangulo 3 4 es:  " +str( mt.sqrt(x*x + y*y)) )
      
res = mt.pi*2**3-mt.sqrt(4)
print(res)


#%%

#Asignacioens de Listas
#====================================================
marcas_de_bicicleta = ['trek', 'cannondale', 'redline', 'specialized']
mensaje = "La marca de bicicleta en primer componente de 'marcas_de_bicicleta' índice primero es: " + marcas_de_bicicleta[0].title() + "."
print(mensaje)
mensaje = "La bicicleta en primer componente de 'marcas_de_bicicleta' índice tercero es:" +  marcas_de_bicicleta[2].title() + "."
print(mensaje)


#%%

# Uso de listas en Python
# Modificando la entrada de una lista
marcas_motocicleta = ['honda', 'yamaha', 'suzuki']
print("Lista original")
print(marcas_motocicleta)
print("+++++++++++++++++\n")
marcas_motocicleta[0] = 'ducati'
print("Lista modificada")
print(marcas_motocicleta)
print("+++++++++++++++++\n")


#%%

# Agregando una entrada
print("Lista insertada")

marcas_motocicleta.append('ducati')
print(marcas_motocicleta)
print("+++++++++++++++++\n")

#%%

# Inicia con una lista vacía
print("Lista vacia con insercciones")
marcas_motocicleta = []
marcas_motocicleta.append('honda')
marcas_motocicleta.append('yamaha')
marcas_motocicleta.append('suzuki')
print(marcas_motocicleta)
print("+++++++++++++++++\n")



#%%
print("Lista con diferentes tipos de componentes")
lista_hibrida = ['honda', 1200,'yamaha', 'suzuki']
lista_hibrida.insert(0, 27.5)
print(lista_hibrida)
print("+++++++++++++++++\n")


#%%

# Insertando en una lista
print("Lista declarada y una insercción por la 'izquierda'")
marcas_motocicleta = ['honda', 'yamaha', 'suzuki']
marcas_motocicleta.insert(0, 'ducati')
print(marcas_motocicleta)
print("+++++++++++++++++\n")


#%%

# Borrando elementos de la lista
print("Lista declarada y borrando elementos por la 'izquierda'")
marcas_motocicleta = ['honda', 'yamaha', 'suzuki']
print(marcas_motocicleta)
del marcas_motocicleta[0]
print(marcas_motocicleta)
print("+++++++++++++++++\n")


#%%
print("Lista declarada y borrando elementos en 'indice' 1 (segundo elemento")
marcas_motocicleta = ['honda', 'yamaha', 'suzuki']
print(marcas_motocicleta)
del marcas_motocicleta[1]
print(marcas_motocicleta)
print("+++++++++++++++++\n")


#%%

# El comando para eliminar el último elemento de una lista
print("Lista declarada y vaciando por la derecha")
marcas_motocicleta = ['honda', 'yamaha', 'suzuki']
print(marcas_motocicleta)
motocicleta_i = marcas_motocicleta.pop()
print(marcas_motocicleta)
print("+++++++++++++++++\n")


#%%
print("Lista declarada y vaciando por la izquierda")
marcas_motocicleta = ['honda', 'yamaha', 'suzuki']
motocicleta_i = marcas_motocicleta.pop(0)
print('La primera motocicleta en la lista es:  ' + motocicleta_i.title() + '.')
print(marcas_motocicleta)
print("+++++++++++++++++\n")


#%%
print("Lista declarada y vaciando por nombre explícito ej: 'ducati'")
marcas_motocicleta = ['honda', 'ducati', 'yamaha', 'suzuki']
print(marcas_motocicleta)
posicion = 'ducati'
marcas_motocicleta.remove(posicion)
print(marcas_motocicleta)
print("+++++++++++++++++\n")


#%%

# Ordenando una lista ascendente.
print("Lista declarada y ordenamiento ascendente")
marcas_motocicleta = ['honda', 'ducati', 'yamaha', 'suzuki']
marcas_motocicleta.sort()
print(marcas_motocicleta)
print("+++++++++++++++++\n")


# Ondernamiento de lista en forma reversa
print("Lista declarada y ordenamiento descendente")
marcas_motocicleta.sort(reverse=True)
print(marcas_motocicleta)
print("+++++++++++++++++\n")


#%%
# Longitud de una lista
print("Longitud de lista (número de elementos en esta)")
print(len(marcas_motocicleta))
print("+++++++++++++++++\n")


#%%
#Sentencias de control en Python
## Ciclos for
#====================================================

alumnos = ['alice', 'david', 'carolina','john','paul']
for m in alumnos:
    print(m)

   
for m in alumnos:
    print(m.title() + ", primera letra en mayúscula")
   
print("+++++++++++++++++\n")
 

#%%
# Un bloque de ejecución
i=0
for m in alumnos: #Sentencia base con tres líneas de ejecución mediante tabulación.
    print(m)  #tabulada
    i=i+1     #tabulado
    print(i)  #tabulada
print("Este print está fuera del ciclo por NO estar en la misma tabulación que las tres líneas anteriores") #fuera de tabulado. Se ejecuta después del for
print("+++++++++++++++++\n")

#%%

i=0
for m in alumnos: #Sentencia base con tres líneas de ejecución mediante tabulación.
  print(m)  #tabulada
  i=i+1     #tabulado
  print(i)  #tabulada
  print("Este print NO está fuera del ciclo por estar en la misma tabulación que las tres líneas anteriores") #fuera de tabulado. Se ejecuta después del for
print("Fuera de ciclo por tabulación" )
print("+++++++++++++++++\n")

#%%
# Listas Numéricas
# Observe que termina en 4
print("Iteraciones sobre index range(1,5)")
for i in range(1,5):
    print(i)

print("+++++++++++++++++\n")


#%%
# Observe que termina en 5
print("Iteraciones sobre index range(1,6)")
for i in range(1,6):
    print(i)
print("+++++++++++++++++\n")


#%%   
# Lista de números al cuadrado
print("Iteraciones sobre lista vacia que se agrega por iteración")
lista_cuadrados = []
for i in range(1,11):
    cuadrado = i**2
    lista_cuadrados.append(cuadrado)
print(lista_cuadrados)
print("+++++++++++++++++\n")

#%% 

print("Sin for usando lista y range")
lista_numeros = list(range(1,6))
print(lista_numeros)
print("+++++++++++++++++\n")

# Lista de números pares, pues suma 2 y va de 2 en 2

print("Otro caso sin for usando lista y range ")
lista_pares = list(range(2,1300,2))
print(lista_pares)
print("+++++++++++++++++\n")

# Lista de números impares, pues suma 2 y va de 2 en dos
print("Otro caso sin for usando lista y range ")
lista_impares = list(range(1,15,2))
print(lista_impares)
print("+++++++++++++++++\n")


#%%

# Operaciones básicas en una lista, no hay mean, sd... 
print("Operaciones básicas sobre lista")
digitos = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
print(min(digitos))
print(max(digitos))
print(sum(digitos))
media=sum(digitos)/len(digitos)
print(media)
print("+++++++++++++++++\n")


#%%
# Partes de una lista
print("Selecciones por ambitos de elementos de lista")
alumnos = ['alice', 'david', 'carolina','john','Paul']
print(alumnos[0:3]) # de 0 a menor que 3 (0,1,2)
print(alumnos[1:2]) # de 1 a menor que 2 (1)
print(alumnos[1:4]) # de 1 a menor que 4 (1,2,3)
print(alumnos[:4])  # menor que 4 (0,1,2,3)
print(alumnos[3:])  # mayores que 3 (3,4)
print(alumnos[:-3]) # Del último de la lista 3 posiciones hacia atrás pero en el mismo orden (2,3,4) longitud=5-3=2-> (2,3,4)
print("+++++++++++++++++\n")


#%%
print("Los primeros tres alumnos son:")
for i in alumnos[:3]:  #(0,1,2)
    print(i.title())
print("+++++++++++++++++\n")

#%%
# Copiando la dirección de una lista (por refencia)
print("Copias por referencia (como punteros) de listas:")
alumnos = ['alice', 'david', 'carolina','john','Paul']
alumnos2 = alumnos   # Copia por REFERENCIA (ambos apunta a mismo dirección.

print("Alumnos enlistados (lista 1):")
print(alumnos)
print("\n La MISMA de valores de los alumnos está conformada (lista 2 es la misa lista 1) por:")
print(alumnos2)   
print("+++++++++++++++++\n")

#%%
# Copiando una lista por valor
print("Copias por valor de listas:")
alumnos = ['alice', 'david', 'carolina','john','Paul']
alumnos2 = alumnos[:]   # Copia por VALOR
print("Alumnos enlistados (lista 1):")
print(alumnos)
print("\n La copia de valores de los alumnos está conformada (lista 2 que es copia de la lista 1) por:")
print(alumnos2)   
print("+++++++++++++++++\n")

#%%
#Modificando ambas listas copiadas por valor
print("Copias por VALOR de listas insertando nuevos elementos:")
alumnos = ['alice', 'david', 'carolina','john','Paul']
alumnos2 = alumnos[:]   # Copia por VALOR

alumnos.append('Jenny')
alumnos2.append('Jimmy')
print("Alumnos en la lista 1:")
print(alumnos)
print("\nAlumnos en la lsita 2:")
print(alumnos2)
print("+++++++++++++++++\n")


#%%
#Modificando la misma lista copiada por referencia.
print("Copias por REFERENCIA de listas insertando nuevos elementos:")
alumnos = ['alice', 'david', 'carolina','john','Paul']
alumnos2 = alumnos   # Copia por REFERENCIA

alumnos.append('Jenny')
alumnos2.append('Jimmy')
print("Alumnos en la lista 1: (iguales por ser la misma dirección)")
print(alumnos)
print("\nAlumnos en la lsita 2: (iguales por ser la misma dirección)")
print(alumnos2)
print("+++++++++++++++++\n")


#%%
# Listas que no cambias -> tuples, usa parétensis () en lugar de []
print("Uso de 'Tuplas' listas que no se pueden alterar")
datos = (201, 52, 7)
print(datos[0])
print(datos[1])
print(datos[2])
print("+++++++++++++++++\n")

datos=(-3,8,3.7,81,-5.24)
print(datos)
datos[0]=2
print("+++++++++++++++++\n")


#%%
## MATRICES COMO UNA LISTA DE LISTAS
#====================================================

print("Uso de 'Matrices' en Python (intríncicas)")
matriz = [[4,5,-3],[2,3.8,0],[-53,90,198],[2,-4,-15]]
print(matriz)
print("+++++++++++++++++\n")


#%%
print("Impresión por filas")
for fila in range(4):
    print("--> Fila"+str(fila))
    for columna in range(3):
        print(matriz[fila][columna])
    print("+++++++")

print("Impresión por columnas")
for columna in range(3):
    print("--> Columna"+str(columna))
    for fila in range(4):
        print(matriz[fila][columna])
    print("+++++++")

len(matriz)
len(matriz[0])
print("+++++++++++++++++\n")


#%%
print("Impresión por columna")
for columna in range(len(matriz[0])):
    for fila in range(len(matriz)):
        print(matriz[fila][columna])
print("+++++++++++++++++\n")


#%%
# Creando una matriz en forma interactiva n x n   
print("Construcción de matriz desde una lista vacia en forma iterativa con listas de filas N cuadrada (N=4)") 
n = 4
Matriz = []
for i in range(n):
    Filas = []
    for j in range(n):
        Filas.append(0)
    Matriz.append(Filas)
print(Matriz)
print("+++++++++++++++++\n")


#%%
# Creando una matriz en forma interactiva n x m    
print("Construcción de matriz desde una lista vacia en forma iterativa con listas de filas NxM (4x3)") 
n = 4
m = 3
Matriz = []
for i in range(n):
    Filas = []
    for j in range(m):
        Filas.append(0)
    Matriz.append(Filas)
print(Matriz)
print("+++++++++++++++++\n")


#%%
# Matriz cuadrada compacta.
print("Construcción de matriz (forma compacta) desde una lista vacia en forma iterativa con listas de filas N cuadrada (N=4)") 
n = 4
Matriz = []
for i in range(n):
    Matriz.append([0]*n) # Agrega el 0 n=4 veces
print(Matriz)
print("+++++++++++++++++\n")



#%%
print("Construcción de matriz identindad dimensión N (N=4)") 
# Matriz Identidad
n = 4
Matriz= [];
for i in range(n):
    Filas = []
    for j in range(n):
        if i==j:
            Filas.append(1)
        else:
            Filas.append(0) 
    Matriz.append(Filas)
print(Matriz)
print("+++++++++++++++++\n")


#%%
# Usando la biblioteca numpy se puede simplificar la creación de matrices
import numpy as np # Carga el paquete

print("Construcción de matriz con librería NUMPY") 
A = np.matrix([[4,5,-3],[2,3.8,0],[-53,90,198],[2,-4,-15]])
print(A)
print("+++++++++++++++++\n")



#%%
# La matriz Identidad
print("Construcción de matriz identidad con librería NUMPY N=7") 
n = 7
Matriz = np.zeros((n,n), int)
print(Matriz)
print("\n")
for i in range(n):
    Matriz[i,i] = 1
print(Matriz)
print("+++++++++++++++++\n")


#%%
# Multiplicación de Matrices
print("Multiplicación de matrices con librería NUMPY") 
A = np.matrix([[1,4,2],[2,8,3],[5,7,0]])
print("Matriz A")
print(A)
B = np.matrix([[1],[2],[3]])
print("\nMatriz B")
print(B)
print("\nMatriz C=A*B")
C=A*B
print(C)
print("+++++++++++++++++\n")


#%%
print("Operación de raíz cuadrada a los elementos de la  matriz A")
print(np.sqrt(A))
print("+++++++++++++++++\n")
#====================================================

# %%
