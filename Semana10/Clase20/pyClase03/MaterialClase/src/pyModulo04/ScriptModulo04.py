'''
Created on Jan 27, 2021
Modified on Oct 20, 2022

@author: freddy
@modificado: Richard
'''

#%%

# Se debe importar el paquete pandas
import pandas as pd
from numpy import mean, std

#%%


# DATA FRAMES EN PYTHON
#====================================================

# Primero registro en un diccionario.
datos = {'nombre': ["John","Paul","George"],
         'ciudad': ["Liverpool","USA","London"],
         'Edad': [55,65,52]
         }

datos_pandas = pd.DataFrame(datos)
print(datos_pandas)

#%%

datos_pandas.info() # Da información estructural del DataFrame.

#%%

datos_pandas.size # Cantidad de entradas o datos

#%%

datos_pandas.shape # Dimensión

#%%

datos_pandas.shape[0] # Número de Filas

#%%

datos_pandas.shape[1] # Número de Columnas


#%%

# Ahora usando listas
datos2 = [['John',55],['Paul',65],['George',52]]
DF = pd.DataFrame(datos2,columns=['Nombre','Edad'])
print(DF)

#%%

print("Información usando index como 'nombre' de filas")
datos3 = {'Nombre':['Tom', 'Jack', 'Steve', 'Ricky'],'Edad':[28,34,29,42]}
DF = pd.DataFrame(datos3, index=['ind1','ind2','ind3','ind4'])
print(DF)

#%%

print("Información usando index para recorrer datos\n")

print(DF[2:4])

#%%

print(DF.loc['ind2'])

#%%
print(DF.iloc[1]) # Es equivalente

#%%

# Extraer una columna
print(DF.loc[:,'Nombre'])

#%%
# Extraer más específicamente
print(DF.loc['ind2':'ind3':,'Nombre'])

#%%

# DIRECTORIO DE TRABAJO Y LECTURA DE ARCHIVOS CSV
#====================================================

# Paquete con funcionalidades para el sistema operativo
import os

# Retorna la carpeta actual
directorio_actual=os.getcwd()
print(directorio_actual) 

#%%

# Cambia la carpeta de trabajo
os.chdir("../Datos")
print(os.getcwd())

os.chdir(directorio_actual)
print(os.getcwd())

#%%
 
# Leyendo un archivo CSV
datos_est = pd.read_csv('../Datos/EjemploEstudiantes.csv',delimiter=';',decimal=",",index_col=0)
print(datos_est)
#%%
datos_est.info()
#%%
 
print(datos_est[2:4])
print(datos_est.iloc[2:4,1:2])
print(datos_est.iloc[0,0])

#%%
 
# Extraer filas
print(datos_est.loc['Ines'])
print(datos_est.iloc[2]) # Es equivalente

#%%

# Extraer una columna
print(datos_est.loc[:,'Ciencias'])

#%%

sum(datos_est.loc[:,'Ciencias'])

#%%

mean(datos_est.loc[:,'Ciencias'])

#%%

std(datos_est.loc[:,'Ciencias'])

#%%
  
# Extraer una observación específica
print(datos_est.loc['Ines','Ciencias'])
 
#%%
 
# Extraer una porción de la tabla
print(datos_est.loc['Ines':'Ana','Ciencias':'Historia'])
 
print(datos_est)

#%%


datos_est.iloc[0,0]
datos_est.iloc[-1,-2]
datos_est.iloc[3,4]
datos_est.iloc[3,:]
datos_est.iloc[3:6,]
datos_est.iloc[:,2:4]
datos_est.iloc[:,2]
datos_est.loc[:,'Espanol']
datos_est.iloc[:,3]
datos_est.info()
 
#%%

import numpy as np
nombres_variables = datos_est.columns.values 


print(nombres_variables)
print(nombres_variables[0])
print(nombres_variables[3])


#%%
print(np.mean(datos_est.iloc[3,:]))
print(np.mean(datos_est.iloc[:,4]))
print(np.mean(datos_est.iloc[:,2:4], axis=1))

#%%

# Encuentra el máximo de un DataFrame
def maximo(DF):
  n = DF.shape[0]
  m = DF.shape[1]
  maxx = DF.iloc[0,0]
  for i in range(n):
    for j in range(m):
      if DF.iloc[i,j] > maxx:
        maxx = DF.iloc[i,j]
  return maxx

res = maximo(datos_est)
print(res)

#%%

# Ejemplo: Retornando una lista de valores
# La siguiente función recibe un DataFrame (DF) y retorna en un diccionario el valor mímimo, 
# el máximo, la cantidad de ceros y la cantidad de números pares que contiene el dataFrame:

def valores(DF):
  n = DF.shape[0]
  m = DF.shape[1]
  minx = DF.iloc[0,0]
  maxx = DF.iloc[0,0]
  total_ceros = 0
  total_pares = 0
  for i in range(n):
    for j in range(m):
      if DF.iloc[i,j] > maxx:
        maxx = DF.iloc[i,j]
      if DF.iloc[i,j] < minx:
        minx = DF.iloc[i,j]
      if DF.iloc[i,j] == 0:
        total_ceros = total_ceros+1
      if DF.iloc[i,j] % 2 == 0:
        total_pares = total_pares+1
  return {'Maximo' : maxx, 'Mimimo' : minx, 'Total_Ceros' : total_ceros, 'Pares' : total_pares}
  

res = valores(datos_est)
print(res)

#%%

# Ejemplo: La siguiente función recibe un DataFrame (DF) y un número de columna (nc) y 
# retorna en un diccionario el nombre de la variable correspondiente al número de columna, 
# la media, la mediana, la desviación estándar,la varianza, el máximo y el mínimo:

# nc = Número de columna iniciando en 0
def estadisticas(DF,nc):
  media = np.mean(DF.iloc[:,nc])
  mediana = np.median(DF.iloc[:,nc])
  deviacion = np.std(DF.iloc[:,nc])
  varianza = np.var(DF.iloc[:,nc])
  maximo = np.max(DF.iloc[:,nc])
  minimo = np.min(DF.iloc[:,nc])
  return {'Variable' : DF.columns.values[nc],
          'Media' : media,
          'Mediana' : mediana,
          'DesEst' : deviacion,
          'Varianza' : varianza,
          'Maximo' : maximo,
          'Minimo' : minimo}

res = estadisticas(datos_est,1)
print(res)

#%%

# Funciones con una cantidad indefinidad de parámetros
def cursos(*cursos_matriculados):
    print(cursos_matriculados)
        
cursos('español')
cursos('matemática', 'español', 'inglés')

# %%
