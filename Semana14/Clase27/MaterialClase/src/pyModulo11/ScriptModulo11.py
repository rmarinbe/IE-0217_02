'''
Created on Feb 8, 2021

@author: freddy
'''

## @knitr Item_A0
#%%

# Análisis Exploratorios Básico
# =============================

# Paso 1: Cargar la tabla de Datos
# Paquetes
import os
import pandas as pd
import numpy as np
import scipy.stats

import matplotlib.pyplot as plt

datos = pd.read_csv('../Datos/SAheart.csv',delimiter=';',decimal=".")
print(datos.head())
print(datos.shape)
print(datos.columns)

## @knitr Item_A1
#%%

# Paso 2: presentación de estadísticas básicas
print(datos.dropna().describe()) 
print(datos.mean(numeric_only=True))
print(datos.median(numeric_only=True))
print(datos.std(numeric_only=True))
print(datos.max(numeric_only=True))
# Los percentiles
print(datos.quantile(np.array([0,.25,.50,.75,1])))

## @knitr Item_A2
#%%
# Tabla cruzada

# En las variables no numéricas
# Contando
print(pd.crosstab(index=datos["chd"],columns="count"))
print(pd.crosstab(index=datos["famhist"],columns="count"))
# Otra forma
print(datos['chd'].value_counts())
print(datos["famhist"].value_counts())

famhist_chd = pd.crosstab(index=datos["famhist"], columns=datos["chd"])
print(famhist_chd)
famhist_chd.index = ["Absent","Present"]
print(famhist_chd)

# Contando
g_chd = pd.crosstab(index=datos["chd"],columns="count") 
print(g_chd )
print(g_chd['count'][0])
print(g_chd['count'][1])
g_famhist = pd.crosstab(index=datos["famhist"],columns="count") 
print(g_famhist)
print(g_famhist['count'][0])
print(g_famhist['count'][1])

## @knitr Item_A3
#%%
# Paso 3: Gráficos importantes
# Graficando

# Gráfico chd
alto = [g_chd['count'][0], g_chd['count'][1]]
barras = ('No', 'Sí')
y_pos = np.arange(len(barras))
null=plt.bar(y_pos, alto, color=['red','blue'])
null=plt.xticks(y_pos, barras)
plt.show()

# Gráfico famhist
alto = [g_famhist['count'][0], g_famhist['count'][1]]
barras = ('Absent ', 'Present')
y_pos = np.arange(len(barras))
null=plt.bar(y_pos, alto, color=['red','blue'])
null=plt.xticks(y_pos, barras)
plt.show()
plt.close()

# Gráfico chd
alto = [g_chd['count'][0], g_chd['count'][1]]
barras = ('No', 'Sí')
y_pos = np.arange(len(barras))
null=plt.bar(y_pos, alto, color=['red','blue'])
null=plt.xticks(y_pos, barras)
plt.show()
plt.close()

# Gráfico famhist
alto = [g_famhist['count'][0], g_famhist['count'][1]]
barras = ('Absent ', 'Present')
y_pos = np.arange(len(barras))
null=plt.bar(y_pos, alto, color=['red','blue'])
null=plt.xticks(y_pos, barras)
plt.show()
plt.close()

# Box Plots
print(datos.head())
boxplots = datos.boxplot(return_type='axes')
plt.show()
plt.close()


# Función de densidad
densidad = datos[datos.columns[:1]].plot(kind='density')
plt.show()
plt.close()

densidad = datos[datos.columns[:1]].plot(kind='density')
plt.show()
plt.close()

densidad = datos[datos.columns[8:9]].plot(kind='density')
plt.show()
plt.close()

densidad = datos['age'].plot(kind='density')
plt.show()
plt.close()

densidad = datos[datos.columns[:10]].plot(kind='density')
plt.show()
plt.close()

## @knitr Item_A3B
#%%
densidad = datos[datos.columns[:1]].plot(kind='hist')
plt.show()
plt.close()

densidad = datos[datos.columns[8:9]].plot(kind='hist')
plt.show()
plt.close()

densidad = datos['age'].plot(kind='hist')
plt.show()
plt.close()

densidad = datos[datos.columns[:10]].plot(kind='hist')
plt.show()
plt.close()

## @knitr Item_A4
#%%
# Test de Shapiro-Wilk
shapiro_resultados = scipy.stats.shapiro(datos['age'])
print(shapiro_resultados)
Test_Estadistico = shapiro_resultados[0]
print(Test_Estadistico)
p_value = shapiro_resultados[1]
print(p_value)
print(p_value < Test_Estadistico)
# Da True significa que los datos siguen la normal

# Test de Shapiro-Wilk
densidad = datos['obesity'].plot(kind='density')
plt.show()
plt.close()

shapiro_resultados = scipy.stats.shapiro(datos['obesity'])
print(shapiro_resultados)
Test_Estadistico = shapiro_resultados[0]
print(Test_Estadistico)
p_value = shapiro_resultados[1]
print(p_value)
print(p_value < Test_Estadistico)
# Da True significa que los datos siguen la normal

## @knitr Item_A4B
#%%

# Scatter Plot entre dos variables
colores = []
for i in datos['chd']:
    if i=='Si':
        colores.append('red')
    else:
        colores.append('blue')

# Orientado a objetos
datos.plot(kind='scatter', x='age', y='obesity', c=colores)
plt.show()
plt.close()

# Estilo funcional
plt.scatter(datos['age'], datos['obesity'],c=colores)
plt.xlabel('age')
plt.ylabel('obesity')
plt.show()
plt.close()


## @knitr Item_A5
#%%
# Gráfico de todas las variables 2 a 2
# El paquete Seaborn
import seaborn as sns

null=sns.pairplot(datos, hue='chd', height=2.5)
plt.show()
plt.close()

null=sns.pairplot(datos, hue='famhist', height=2.5)
plt.show()
plt.close()

## @knitr Item_A5B
#%%
# Es inteligente e ingnora las variables categóricas

corr = datos.corr()
corr
f, ax = plt.subplots(figsize=(10, 8))
sns.heatmap(corr, mask=np.zeros_like(corr, dtype=np.bool), cmap=sns.diverging_palette(220, 10, as_cmap=True),
            square=True, ax=ax)

plt.show()
plt.close()


# Conviertiendo una categoría en números
print(pd.value_counts(datos["chd"]))
# Equivalente
print(datos['chd'].value_counts())

# La siguiento función recodifica usando pandas
def recodificar(col, nuevo_codigo):
  col_cod = pd.Series(col, copy=True)
  for llave, valor in nuevo_codigo.items():
    col_cod.replace(llave, valor, inplace=True)
  return col_cod

datos["chd"] = recodificar(datos["chd"], {'No':0,'Si':1})
datos.head()

# Luego de recoficar
print(pd.value_counts(datos["chd"]))
# Equivalente
print(datos['chd'].value_counts())

# Conviertiendo un número en una categoría
datos["chd"] = recodificar(datos["chd"], {0:'No',1:'Si'})
datos.head()

##______________________ ACP_________________
## @knitr Item_B1
#%%
# ANÁLISIS EN COMPONENTES PRINCIPALES - ACP
# =========================================

from sklearn.decomposition import PCA

# Ejemplo 1
rng = np.random.RandomState(1)
X = np.dot(rng.rand(2, 2), rng.randn(2, 200)).T
print(X[1:20])
print(X.shape)
plt.scatter(X[:, 0], X[:, 1])
plt.axis('equal') # Misma Escala
plt.show()
plt.close()


pca = PCA(n_components=2) # Establece que va a calcular solo 2 componentes
pca.fit(X) # Ejecuta el ACP
print(pca.components_)
print(pca.explained_variance_)

def dibuja_vector(v0, v1, ax=None):
    ax = ax or plt.gca()
    tipo_flecha=dict(arrowstyle='->',
                    linewidth=2,
                    shrinkA=0, shrinkB=0)
    ax.annotate('', v1, v0, arrowprops=tipo_flecha)


# Plotea los datos y las 2 componentes
plt.scatter(X[:, 0], X[:, 1], alpha=0.2)
for length, vector in zip(pca.explained_variance_, pca.components_):
    v = vector * 3 * np.sqrt(length)
    dibuja_vector(pca.mean_, pca.mean_ + v)
plt.axis('equal')
plt.show()
plt.close()

## @knitr Item_B2
#%%
from sklearn.datasets import load_digits
digits = load_digits()
digits.data.shape

pca = PCA(2)  # Reduce las dimensiones a 2
componentes = pca.fit_transform(digits.data)
print(digits.data.shape)
print(componentes.shape)

plt.scatter(componentes[:, 0], componentes[:, 1],
            c=digits.target, edgecolor='none', alpha=0.5,
            cmap=plt.cm.get_cmap('nipy_spectral', 10))
plt.xlabel('componente 1')
plt.ylabel('componente 2')
plt.colorbar()
plt.show()
plt.close()

## @knitr Item_B3
#%%
print(os.getcwd())
datos = pd.read_csv('../Datos/EjemploEstudiantes.csv',delimiter=';',decimal=",",index_col=0)

print(datos)
print(datos.head())
print(datos.shape)

pca = PCA(n_components=2)
componentes = pca.fit_transform(datos)
print(componentes)
print(datos.shape)
print(componentes.shape)

plt.scatter(componentes[:, 0], componentes[:, 1])
plt.xlabel('componente 1')
plt.ylabel('componente 2')
plt.show()
plt.close()


## @knitr Item_B4
#%%
# ACP con el paquete "prince" 
import prince

# Ejemplo anterior ahora con prince.
print(datos)
print(datos.shape)

pca = prince.PCA(n_components=2,n_iter=3,rescale_with_mean=True,rescale_with_std=True,copy=True,check_input=True,engine='auto',random_state=42)
pca = pca.fit(datos)
pca.transform(datos)
ax = pca.plot_row_coordinates(datos,ax=None,figsize=(6, 6),x_component=0,y_component=1,labels=datos.index,ellipse_outline=False,ellipse_fill=False,show_points=False)
plt.show()
plt.close()

## @knitr Item_B5
#%%
# Ejemplo 4 (con prince)

from sklearn import datasets

X, y = datasets.load_iris(return_X_y=True)
X = pd.DataFrame(data=X, columns=['Sepal length', 'Sepal width', 'Petal length', 'Petal width'])
y = pd.Series(y).map({0: 'Setosa', 1: 'Versicolor', 2: 'Virginica'})
X.head()

pca = prince.PCA(n_components=2,n_iter=3,rescale_with_mean=True,rescale_with_std=True,copy=True,check_input=True,engine='auto',random_state=42)
pca = pca.fit(X)
pca.transform(X).head()
ax = pca.plot_row_coordinates(X,ax=None,figsize=(6, 6),x_component=0,y_component=1,labels=None,color_labels=y,ellipse_outline=False,ellipse_fill=True,show_points=True)
plt.show()
plt.close()
