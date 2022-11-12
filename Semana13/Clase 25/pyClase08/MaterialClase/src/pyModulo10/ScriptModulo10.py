'''
Created on Feb 1, 2021

@author: freddy
'''


#%%
import numpy as np

M = np.random.random((3, 4))
print(M)

#%%

M.sum() # Es el llamado a un método de nunpy
M.min(axis=0) # Por columna
M.min(axis=1) # Por fila

#%%
datos = np.array([189, 170, 189, 163, 183, 171, 185, 168, 173, 183, 173, 173,  
                  175, 178, 183, 193, 178, 173, 174, 183, 183, 168, 170, 178,
                  182, 180, 183, 178, 182, 188, 175, 179, 183, 193, 182, 183,
                  177, 185, 188, 188, 182, 185])

print(datos)

print("Promedio:            ", datos.mean())
print("Desviación Estándar: ", datos.std())
print("Mínimo:              ", datos.min())
print("Máximo:              ", datos.max())
print("Percentile 25:       ", np.percentile(datos, 25))
print("Mediana :            ", np.median(datos))
print("Percentile 75:       ", np.percentile(datos, 75))


#%%

# Se genera una secuencia de 10 elementos de 0 a 9
x = np.arange(10)
print(x)

#%%
# Se construye un arreglo de valores predefinidos que se usan como index
i = np.array([2, 1, 8, 4])
print(i)

#modifica las posiciones de x[] en los valores indexados por i
x[i] = 99
print(x)

#%%

# Ordenando vectores con numpy
x = np.array([9, 1, -4, 23, 5])
np.sort(x)

# Usando el método 'sort'
x.sort()
print(x)

#%%
#Se construye x como un arreglo dado
x = np.array([9, 1, -4, 23, 5])
print(x)
#Se genera un vector de índices que corresponde a las posiciones ordenadas.
i = np.argsort(x)
print(i)
print(x[i])

#%%

# Se construye un generador de números aleatorios.
rand = np.random.RandomState(42)

# Se genera una matriz de 5x7 con números aleatorios enteros de 0 a 29
X = rand.randint(0, 30, (5, 7))
print(X, "\n")

# Usando los ejes por vertical (axis=0) o horizongal (axis=1)
print(np.sort(X, axis=0), "\n") # Ordena por columna
print(np.sort(X, axis=1), "\n") # Ordena por fila

#%%

# Manipulación de Datos en Pandas
# ===============================

import pandas as pd

# Series de Datos en Pandas

datos = pd.Series([0.25, 0.5, 0.75, 1.0])
print(datos)

print(datos.values)

print(datos.index)
#%%
datos = pd.Series([0.25, 0.5, 0.75, 1.0],index=['a', 'b', 'c', 'd'])
print(datos)
print(datos['b'])
print(datos[1]) # Es equivalente

#%%

# Series desde un diccionario de datos


poblacion = {'California': 38332521,
                   'Texas': 26448193,
                   'New York': 19651127,
                   'Florida': 19552860,
                   'Illinois': 12882135}
poblacion = pd.Series(poblacion)
print(poblacion)
print(poblacion['California'])
print(poblacion['California':'Florida'])

#%%
# DataFrames en Pandas

poblacion = {'California': 38332521,
                   'Texas': 26448193,
                   'New York': 19651127,
                   'Florida': 19552860,
                   'Illinois': 12882135}


area = {'California': 423967, 'Texas': 695662, 'New York': 141297,
             'Florida': 170312, 'Illinois': 149995}

estados = pd.DataFrame({'Poblacion': poblacion,'Area': area})
print(estados, "\n")
print(estados.index, "\n")   # Observe que son objetos
print(estados.columns, "\n")
print(estados['Area'], "\n")

#%%


# Otros ejemplos
datos = [{'a': i, 'b': 2 * i} for i in range(30)]
print(pd.DataFrame(datos))

print(pd.DataFrame(np.random.rand(3, 2),
             columns=['C1', 'C2'],
             index=['a', 'b', 'c']))


#%%
# Valores nulos en Python "NaN"
print(pd.DataFrame([{'a': 1, 'b': 2}, {'b': 3, 'c': 4}]))

#%%
# Índices explícitos e implícitos - Indexadores: loc, iloc, and ix

datos = pd.Series(['a', 'b', 'c'], index=[10, 30, 50])
# Los índices explícitos son 10, 30 y 50
# Los índices implícitos son 0, 1 y 2
print(datos)
print(datos[10]) # Índice explícito

#%%

print(datos[0:2]) # Índices implícitos, esto es extraño y confuso
print(datos[1:3]) # Índices implícitos, esto es extraño y confuso

#%%


# Lo anterior causa mucha confusión
# loc siempre se refiere al índice explícito
print(datos.loc[10], "\n")
print(datos.loc[10:30], "\n")
print(datos.loc[30:50], "\n")

print()

# iloc siempre se refiere al índice implícito
print(datos.iloc[1], "\n")
#print(datos.iloc[10]) # Da error
print(datos.iloc[0:2], "\n")
print(datos.iloc[1:3], "\n")

#%%

# Seleccionando datos en un DataFrame

poblacion = {'California': 38332521,
             'Texas': 26448193,
             'New York': 19651127,
             'Florida': 19552860,
             'Illinois': 12882135}

area = {'California': 423967, 'Texas': 695662, 'New York': 141297,
        'Florida': 170312, 'Illinois': 149995}

estados = pd.DataFrame({'Poblacion': poblacion,'Area': area})

print(estados['Poblacion'], "\n") #Dos formas de hacer lo mismo
print(estados.Poblacion, "\n")

#%%

# Agregando una variable
print(estados, "\n")

estados['Densidad'] = estados['Poblacion'] / estados['Area']
print(estados)

#%%

# Transponer el DataFrame
print("Trasponiendo la tabla")
ET = estados.T
ET

#%%

# Se puede usar iloc y loc en un DataFrame
print(estados)
print()
print(estados.iloc[:3, :2]) # Índices implícitos
print()
print(estados.loc[:'Illinois', :'Poblacion']) # Índices Explícitos

#%%

# Otros ejemplos
print(estados.loc[estados.Densidad > 100, ['Poblacion', 'Densidad']])
print()
print(estados['Florida':'Illinois'])
print()
print(estados[1:3])
print()
print(estados[estados.Densidad > 100])

#%%

# Modicando un dato
estados.iloc[0, 2] = 0
print(estados)

#%%

# Ejemplos

rng = np.random.RandomState(42)
serie = pd.Series(rng.randint(0, 10, 4))
serie

#%%

df = pd.DataFrame(rng.randint(0, 10, (3, 4)),columns=['A', 'B', 'C', 'D'])
df

#%%
# Aplica exponencial a la serie
np.exp(serie)

#%%
# Aplica seno al DataFrame
np.sin(df * np.pi / 4)

#%%

# Datos Ausentes en Pandas

# "None" es el indicador propio de Python para indicar datos ausentes,
# pero son funciona con datos que hereden de la clase "object"

valores1 = np.array([1, None, 3, 4])
valores1 # Observe que dtype=object

#%%
#valores1 = np.array([1, None, 3, 4],dtype=int) # Causa error el None
#valores1.sum() # causa error el None

# Uso del NaN (acronym for Not a Number)

valores2 = np.array([1, np.nan, 3, 24])
valores2

#%%
print(valores2.sum())  # No da error, da nan porque:
1 + np.nan # Da nan
print(valores2.dtype)  # Ahora es flotante
print(valores2.min())
print(valores2.max())

#%%
# Todo da nan, solución usar 
print(np.nansum(valores2))
print(np.nanmin(valores2))
print(np.nanmax(valores2))

#%%


datos = pd.Series([1, np.nan, 2, None, 90, -10, 76])
datos
#%%
datos.isnull() # Para detectarlos
#%%
# Eliminando valores nan, se debe eliminar toda la fila o toda la columna

df = pd.DataFrame([[1,      np.nan, 2],
                   [2,      3,      5],
                   [np.nan, 4,      6],
                   [-1, 94,      0]])
df

#%%
df.dropna() # Por defecto es por fila
#%%
df.dropna(axis='columns')
#%%
#%%
# Imputando datos

serie = pd.Series([1, np.nan, 2, None, 90, -10, 76], index=list('abcdefg'))
serie
#%%
serie.fillna(0) # Rellena (imputa el dato) con ceros
#%%
#%%
serie.fillna(method='ffill') # Rellena con el anterior
#%%
serie.fillna(method='bfill') # Rellena con el posterior
#%%
serie.fillna(np.mean(serie)) # Rellena con la media (1+2+90-10+76)/5=31.8
#%%
#%%
# Ejemplo con un data frame
df = pd.DataFrame([[1,      np.nan, 2],
                   [2,      3,      5],
                   [np.nan, 4,      6],
                   [-1, 94,      0]])
print(df)
#%%
df.fillna(0) # Rellena (imputa el dato) con ceros
#%%
print(df)
df.fillna(method='bfill',axis=1) # Rellena con en posterior de la fila
#%%
print(df)
df.fillna(method='bfill',axis=0) # Rellena con en posterior de la columna
#%%
print(df)
df.fillna(method='ffill',axis=1) # Rellena con en anterior de la fila
#%%
print(df)
df.fillna(method='ffill',axis=0) # Rellena con en anterior de la columna
#%%
print(df)
df.fillna(np.mean(df)) # Rellena con la media por columna

#%%

## Operaciones avanzadas sobre data frames

srs_a = pd.Series([10,30,60,80,90])
srs_b = pd.Series([22, 44, 55, 77, 101])
df = pd.DataFrame({'a': srs_a, 'b': srs_b})
print(df)

#%%
print(df.sum())

#%%

print(df.sum(axis=0))

#%%

print(df.sum(axis=1))

#%%
######################


# Combinando Sets de Datos: Concat y Append
# En numpy

x = [1, 2, 3]
y = [4, 5, 6]
z = [7, 8, 9]
print(np.concatenate([x, y, z]))

#%%

x = [[1, 2],[3, 4]]
y = [[-1, -2],[-3, -4]]
print(np.concatenate([x, y], axis=1))


#%%


serie1 = pd.Series(['A', 'B', 'C'], index=[1, 2, 3])
serie2 = pd.Series(['D', 'E', 'F'], index=[4, 5, 6])
pd.concat([serie1, serie2])

#%%

# Ejemplo DataFrame
# Por filas   
df1 = pd.DataFrame({'A': ['A0', 'A1', 'A2', 'A3'],
                    'B': ['B0', 'B1', 'B2', 'B3'],
                    'C': ['C0', 'C1', 'C2', 'C3'],
                    'D': ['D0', 'D1', 'D2', 'D3']},
                    index=[0, 1, 2, 3])
print(df1)

print()

df2 = pd.DataFrame({'A': ['A4', 'A5', 'A6', 'A7'],
                    'B': ['B4', 'B5', 'B6', 'B7'],
                    'C': ['C4', 'C5', 'C6', 'C7'],
                    'D': ['D4', 'D5', 'D6', 'D7']},                      
                    index=[4, 5, 6, 7])
print(df2)

print()

df3 = pd.DataFrame({'A': ['A8', 'A9', 'A10', 'A11'],
                    'B': ['B8', 'B9', 'B10', 'B11'],
                    'C': ['C8', 'C9', 'C10', 'C11'],
                    'D': ['D8', 'D9', 'D10', 'D11']},
                    index=[8, 9, 10, 11])
print(df3)

print()
resultado = pd.concat([df1, df2, df3])
print(resultado)

#%%
# Por columnas
df1 = pd.DataFrame({'A': ['A0', 'A1', 'A2', 'A3'],
                    'B': ['B0', 'B1', 'B2', 'B3'],
                    'C': ['C0', 'C1', 'C2', 'C3'],
                    'D': ['D0', 'D1', 'D2', 'D3']},
                    index=[0, 1, 2, 3])
print(df1)

df2 = pd.DataFrame({'E': ['A4', 'A5', 'A6', 'A7'],
                    'F': ['B4', 'B5', 'B6', 'B7'],
                    'G': ['C4', 'C5', 'C6', 'C7'],
                    'H': ['D4', 'D5', 'D6', 'D7']},                      
                    index=[0, 1, 2, 3])
print(df2)

df3 = pd.DataFrame({'I': ['A8', 'A9', 'A10', 'A11'],
                    'J': ['B8', 'B9', 'B10', 'B11'],
                    'K': ['C8', 'C9', 'C10', 'C11'],
                    'L': ['D8', 'D9', 'D10', 'D11']},
                    index=[0, 1, 2, 3])
print(df3)
print()
resultado = pd.concat([df1, df2, df3],axis=1)
print(resultado)

#%%

# Todas las columnas NO son iguales
# Ejemplo DataFrame
# Por filas   
df1 = pd.DataFrame({'A': ['A0', 'A1', 'A2', 'A3'],
                    'B': ['B0', 'B1', 'B2', 'B3'],
                    'C': ['C0', 'C1', 'C2', 'C3'],
                    'D': ['D0', 'D1', 'D2', 'D3']},
                    index=[0, 1, 2, 3])
print(df1)

df2 = pd.DataFrame({'C': ['A4', 'A5', 'A6', 'A7'],
                    'D': ['B4', 'B5', 'B6', 'B7'],
                    'E': ['C4', 'C5', 'C6', 'C7'],
                    'F': ['D4', 'D5', 'D6', 'D7']},                      
                    index=[4, 5, 6, 7])
print(df2)


resultado = pd.concat([df1, df2])
print(resultado)

#%%

# Usando Merge

df1 = pd.DataFrame({'employee': ['Bob', 'Jake', 'Lisa', 'Sue'],
                    'group': ['Accounting', 'Engineering', 'Engineering', 'HR']})
print(df1)
print()
df2 = pd.DataFrame({'employee': ['Lisa', 'Bob', 'Jake', 'Sue'],
                    'hire_date': [2004, 2008, 2012, 2014]})
print(df2)
print()

df3 = pd.merge(df1, df2)
print(df3)

#%%
df4 = pd.DataFrame({'group': ['Accounting', 'Engineering', 'HR'],
                    'supervisor': ['Carly', 'Guido', 'Steve']})
print(df4)
print()
print(pd.merge(df3, df4))

#%%
df5 = pd.DataFrame({'group': ['Accounting', 'Accounting',
                              'Engineering', 'Engineering', 'HR', 'HR'],
                    'skills': ['math', 'spreadsheets', 'coding', 'linux',
                               'spreadsheets', 'organization']})
print(df5)
print()
print(df1)
print()
print(pd.merge(df1, df5))


#%%
#funciones lambdas
x=(lambda x: x + 1)(2)

print("Función implícita 'lambda' da: "+str(x))

#%%

add_one = lambda x: x + 1



print(add_one(3))
print(add_one(10))

#%%


def Add_one(x):
    return x + 1

print(Add_one(15))
print(add_one(15))

#%%

# creating and initializing a list 
values= [['Rohan',455],['Elvish',250],['Deepak',495], 
         ['Soni',400],['Radhika',350],['Vansh',450]]  
  
# creating a pandas dataframe 
df = pd.DataFrame(values,columns=['Name','Total_Marks']) 

print(df)

#%%
# Applying lambda function to find  
# percentage of 'Total_Marks' column  
# using df.assign() 
df = df.assign(Percentage = lambda x: (x['Total_Marks'] /500 * 100)) 
  
# displaying the data frame 
print(df) 

#%%

# creating and initializing a nested list 
values_list = [[15, 2.5, 100], [20, 4.5, 50], [25, 5.2, 80], 
               [45, 5.8, 48], [40, 6.3, 70], [41, 6.4, 90], 
               [51, 2.3, 111]] 
  
# creating a pandas dataframe 
df = pd.DataFrame(values_list, columns=['Field_1', 'Field_2', 'Field_3']) 

print(df)
# Applying lambda function to find  
# the product of 3 columns using  
# df.assign() 
df = df.assign(Product=lambda x: (x['Field_1'] * x['Field_2'] * x['Field_3'])) 
  
# printing dataframe 
print(df)

#%%

# creating and initializing a nested list 
values_list = [[15, 2.5, 100], [20, 4.5, 50], [25, 5.2, 80], 
               [45, 5.8, 48], [40, 6.3, 70], [41, 6.4, 90],  
               [51, 2.3, 111]] 
  
# creating a pandas dataframe 
df = pd.DataFrame(values_list, columns=['Field_1', 'Field_2', 'Field_3'], 
                  index=['a', 'b', 'c', 'd', 'd', 'f', 'g']) 
  

print(df)  
# Apply function numpy.square() to square 
# the values of one row only i.e. row  
# with index name 'd' 
df1 = df.apply(lambda x: np.square(x) if x.name == 'd' else x) 
  
print(df1) 

df2 = df.apply(lambda x: np.square(x) if x.name == 'd' else x, axis=1) 
  
print(df2) 

 
#%%


data = pd.DataFrame(
    {'col1':[1,1,1,1,1,2,2,2,2,2],
    'col2':[1,2,3,4,5,6,7,8,9,0],
     'col3':[-1,-2,-3,-4,-5,-6,-7,-8,-9,0]
    }
)
print(data)


data1=data.groupby('col1').agg({'col2': 'max', 'col3': 'min'})
print(data1)
print("+++++")

data2=data.groupby('col1').agg({'col2': 'sum', 'col3': 'sum'})
print(data2)
print("+++++")

#%%

data3=data.groupby('col1').agg( col2=('col2',max), col3=('col3',min) ,col4=('col2',sum))
print(data3)
print("+++++")

data4=data.groupby('col1').agg( max_col2=('col2',max), min_col3=('col3',min) ,sum_col2=('col2',sum))
print(data4)
print("+++++")

#%%

data4=data.groupby('col1').filter(lambda x: sum(x['col2']) !=15)
print(data4)
print("+++++")

###########################################################
#%%

# Otro ejemplo con agrupamientos.
import seaborn as sns
planetas = sns.load_dataset('planets')
planetas.shape
planetas.head()
planetas
planetas.dropna().describe() # Como el str de R

# Ejemplo groupby
df = pd.DataFrame({'llave': ['A', 'B', 'C', 'A', 'B', 'C'],
                   'datos': range(6)}, columns=['llave', 'datos'])
df
df.groupby('llave').sum()

# Retomando el ejemplo de planetas
planetas.head()
planetas.groupby('method')['orbital_period'].median()
planetas.groupby('method')['orbital_period'].mean()
planetas.groupby('method')['orbital_period'].min()
planetas.groupby('method')['orbital_period'].max()
planetas.groupby('method')['orbital_period'].count()



df_user_table = pd.DataFrame(
    {
      'user_id' :[1,2,3,4,5],
      'like    ':['Paul','Ringo','John','George','Martin'],
    }  
  ) 


df_languages = pd.DataFrame(
    {
      'user_id' :[3,1,1,5,4,6],
      'like    ':['C++','Python','R','Pascal','Java',"Lisp"],
    }  
  ) 
print(df_user_table)
print("++++++++++++++++++++]n")

print(df_languages)
print("++++++++++++++++++++]n")



inner = pd.merge(df_user_table, df_languages, on='user_id', how='inner')
print(inner)
print("++++++++++++++++++++]n")



left = pd.merge(df_user_table, df_languages, on='user_id', how='left')
print(left)
print("++++++++++++++++++++]n")



right = pd.merge(df_user_table, df_languages, on='user_id', how='right')
print(right)
print("++++++++++++++++++++]n")



outer = pd.merge(df_user_table, df_languages, on='user_id', how='outer')
print(outer)
print("++++++++++++++++++++]n")

#Repitiendo un ejemplo anterior con diferentes índices
df1 = pd.DataFrame({'A': ['A0', 'A1', 'A2', 'A3'],
                    'B
                    : ['B0', 'B1', 'B2', 'B3'],
                    'C': ['C0', 'C1', 'C2', 'C3'],
                    'D': ['D0', 'D1', 'D2', 'D3']},
                    index=[0, 1, 2, 3])
print(df1)

df2 = pd.DataFrame({'C': ['A4', 'A5', 'A6', 'A7'],
                    'D': ['B4', 'B5', 'B6', 'B7'],
                    'E': ['C4', 'C5', 'C6', 'C7'],
                    'F': ['D4', 'D5', 'D6', 'D7']},                      
                    index=[4, 5, 6, 7])
print(df2)


resultado = pd.concat([df1, df2])
print(resultado)

resultado = pd.concat([df1, df2],join='inner')
print(resultado)

resultado = pd.concat([df1, df2],join='outer') # Por defecto es outer
print(resultado)




# Tablas Pivote

titanic = sns.load_dataset('titanic')
titanic.shape
titanic.head()

titanic.groupby('sex')[['survived']].mean()
titanic.groupby(['sex', 'class'])['survived'].aggregate('mean')
titanic.groupby(['sex', 'class'])['survived'].aggregate('mean').unstack()
titanic.groupby(['sex', 'class'])['survived'].aggregate('count').unstack() # Tabla cruzada



# Más fácil con una tabla pivote
titanic.pivot_table('survived', index='sex', columns='class')
titanic.pivot_table('survived', index='sex', columns='class',aggfunc='mean')
titanic.pivot_table('survived', index='sex', columns='class',aggfunc='count')

edad = pd.cut(titanic['age'], [0, 18, 80])
tabla_pivote=titanic.pivot_table('survived', ['sex', edad], 'class',aggfunc='count')

print(tabla_pivote)

# %%
