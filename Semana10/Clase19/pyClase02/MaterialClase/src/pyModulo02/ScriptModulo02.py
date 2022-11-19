'''
Created on Oct 18, 2022

@author: freddy
@modified: Richard
'''
#%%
# Comparaciones y Booleanos
#====================================================

from re import L


estudiante = 'John'
boleano = (estudiante == 'John')
print(boleano)

print( estudiante == 'Michael')

#%%
# != es el operador de diferente
      
estudiante = 'John'
boleano= estudiante != 'John'
print( estudiante != 'Michael')

#%%
# Otros operadores de comparación
      
edad = 20
print( edad < 21 )
print( edad <= 21)
print( edad > 21 )
print( edad >= 21)
print( edad == 22 )
print( edad == 18 )
print( not(edad >= 21) or (edad >= 20))
#%%

# Operador in

alumnos = ['alice', 'david', 'carolina','john','paul']
es_parte_de = 'david' in alumnos
print(es_parte_de)
print(  'carolina' in alumnos)

#%%
# Sentencia if, elif, else

edad = 19
if edad >= 18:
    print("Usted puede votar!")

for alumno in alumnos:
    if alumno == 'paul':
        print(alumno.upper())
    else:
        print(alumno.title())


      
#%%
 
# Verificar que una lista está vacia

lista = []
if lista:
    print("No está vacía")
else:
    print("La lista está vacía")

#%%
lista = ["uno", "dos"]
if lista:
    print("No está vacía")
else:
    print("La lista está vacía")

#%%
# Sentencia elif
edad = 12
if edad < 4:
    precio = 0
elif edad < 18:
    precio = 5
elif edad < 65:
    precio = 10
else:
    precio = 5
print("El precio de la entrada es $" + str(precio) + ".")
      
#%%
# Sentencia while
# Ciclos while, ejemplo de un contador
contador = 1
while contador <= 33:
    print(contador)
    contador += 1
    
#%%

# Un caso no determinado tomando información de una lista   
# Capturando una condición de salida
mensaje = ["entrada1","entrada2","entrada3","salir"]
indice =0
while mensaje[indice] != 'salir':
    print(mensaje[indice])
    indice+=1
    
#%%

# Variación de código usando una indicación booleana
# Usando una bandera
mensaje = ["entrada1","entrada2","entrada3","entrada4","entrada5","salir"]
indice =0
activo = True
while activo:
    if mensaje[indice] == 'salir':
        activo = False
    else:
        print(mensaje[indice])
        indice+=1
        
#%%  
# Sentencias break y continue en Python.
# Usando continue
mensaje = ["inicio","entrada1","entrada2","entrada3","entrada4","entrada5","salir"]
indice =0
activo = True
while activo:
    if mensaje[indice] == 'inicio':
        indice+=1
        continue
    elif mensaje[indice] == 'salir':
        break
    else:
        print(mensaje[indice])
    indice+=1
print("fin") 
#%%
# Operador módulo %

numero= 151
if numero % 2 == 0:
    print("\nEl número " + str(numero) + " es par.")
else:
    print("\nEl número " + str(numero) + " es impar.")
   
#%%
# Diccionarios de Datos en Python
contenedor = {'color': 'azul', 'distancia': 5}
print(contenedor['color'])
print(contenedor['distancia'])
print(contenedor)

#%%
pablo=24
contenedor={"color":"azul","distancia":5,"edad":20, "nombres": ["jose", pablo]}
print(contenedor)

#%%
# Un diccionario vacío
contenedor = {}
contenedor['color']='rojo'
contenedor['distancia']=2
contenedor['planeta'] = 'tierra'
contenedor['edad'] = 23
contenedor

#%%
# Modificar un diccionario
contenedor['planeta'] = 'marte'
contenedor

#%%
if contenedor['edad'] >= 23:
    contenedor['planeta'] = 'jupiter'
    
print(contenedor)

#%%
usuario = {
  'nombre_usuario': 'rmarinbe',
  'nombre': 'Richard',
  'apellido': 'Marin',
}

print(usuario.items())

#%%
for k, v in usuario.items():
    print("\nLlave: " + k)
    print("Valor: " + v)
    
print(list(usuario.keys()))

print(list(usuario.values())) 

print(list(usuario.items()))   
  
#%%
programadores={"juan":"Java","jose":"Python","eduardo":"C++","juan_carlos":"Python","carla":"R","monica":"Ruby"} 

#Ordena por lenguaje
for lenguaje in sorted(programadores.values()):
    print(lenguaje)

#%%
#Ordena por usuario
for usuario in sorted(programadores.keys()):
    print(usuario)
    
#%%
# Listas dentro de un diccionario
   
programadores_avanzados = {
  'juan': ['Java','python','C++'],
  'jose': ['Python',"C++"],
  'eduardo': ['C++','Java'],
  'juan_carlos': ['Python','C','Pascal'],
  'carla': ["R","Python"],
  "monica": ["Ruby,C++"]
}
    
#Ordena por lenguaje
for lenguaje in sorted(programadores_avanzados.values()):
    print(lenguaje)


#%%

#Ordena por usuario
for usuarios in sorted(programadores_avanzados.keys()):
    print(usuarios)
    
#%%

# Diccionarios de diccionarios.
usuarios = {
  'mcespedes': {
     'nombre': 'maría',
     'apellido': 'céspedes',
     'lugar': 'alajuela',
   },
   'malfaro': {
     'nombre': 'mario',
     'apellido': 'alfaro',
     'lugar': 'heredia',
   },
   'jrojas': {
     'nombre': 'julián',
     'apellido': 'rojas',
     'lugar': 'curridabat',
   },
}

for usuario, info_usuario in usuarios.items():
    print("\nNombre de usuario: " + usuario)
    nombre_completo = info_usuario['nombre'] + " " + info_usuario['apellido'] 
    lugar = info_usuario['lugar']
    print("\tNombre Completo: " + nombre_completo.title())
    print("\tLugar: " + lugar.title())
    

# %%
persona = {
    "cedula": 23333,
    "hijos": {"marco": {"edad":23,"altura": 171}, "maria": {"edad":12,"altura": 173}}
}

# %%
