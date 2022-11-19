'''
Created on Feb 8, 2021

@author: freddy
'''

#%%
import os
import pandas as pd
import matplotlib.pyplot as plt
from   sklearn.decomposition import PCA
from   sklearn.datasets import make_blobs
from   sklearn.cluster import KMeans
import numpy as np
from   math import pi

import mglearn

#%%

# Plotea un ejemplo de ejecución del algoritmo k-medias
mglearn.plots.plot_kmeans_algorithm()
plt.show()
plt.close()

# Plotea las fonteras de clases (diagrama de Voronoi)
mglearn.plots.plot_kmeans_boundaries()
plt.show()
plt.close()

#%%
# Un ejemplo con datos sinteticos

# Ejemplo 1. Datos simlados en 2 variables
#X, y = make_blobs(random_state=1)
#print(X[0:10]) # Datos
#print(y) # Cluster

from sklearn.datasets import make_blobs

blobs_num = 4

X, y = make_blobs(n_samples=200, centers=blobs_num, n_features=2,
                  random_state=21)
print(X.shape)

print(y)


#%%

# Construye un modelo k-medias
# Supongamos que no sabemos cuantos clusters hay

inercias = []
K = range(1,10)
for k in K:
    kmeanModel = KMeans(n_clusters=k)
    kmeanModel.fit(X)
    inercias.append(kmeanModel.inertia_)

plt.plot(K, inercias, 'bx-')
plt.xlabel('k')
plt.ylabel('inercias')
plt.title('Metodo de diagrama de codo para mostrar el k optimo')
plt.show()

# Observamos que el k optimo es = 4 cuando la inercia deja de cambiar
# significativamente

#%%
# k optimo es blobs_num como era de esperar
clusters_num = blobs_num
kmeans = KMeans(n_clusters=clusters_num)
kmeans.fit(X)

kmeans.inertia_

# Cluster al que pertenece al que asigna k-medias (dos formas de hacerlo)
print("Cluster al que pertenece cada individuo:\n{}".format(kmeans.labels_))
print(kmeans.predict(X))


# Plotea el resultado
# Es posible directamente porque solo hay dos variables
null=mglearn.discrete_scatter(X[:, 0], X[:, 1], kmeans.labels_, markers='o')
null=mglearn.discrete_scatter(  kmeans.cluster_centers_[:, 0], 
                           kmeans.cluster_centers_[:, 1], 
                           list(range(0,clusters_num)),
                           markers='^', markeredgewidth=2)
plt.show()
plt.close()

#%%

print(os.getcwd())
datos = pd.read_csv('../Datos/EjemploEstudiantes.csv',delimiter=';',decimal=",",index_col=0)
print(datos)
print(datos.head())
print(datos.shape)

#%%

# Ejecuta k-medias con 3 clusters
kmedias = KMeans(n_clusters=3)
kmedias.fit(datos)
print(kmedias.predict(datos))
centros = np.array(kmedias.cluster_centers_)
print(centros)

#%%

# Plotea Centro 1
c1 = centros[:1, :]
print(c1)

y=c1.tolist()[0]
print(y)

N = len(y)
print(N)

x = range(N)
print(x)

width = 1/1.5
colores_1 = ['#CF8EF8', '#523C81', '#D2D132', '#59C951', '#E5826C']
plt.bar(x, y, width, color=colores_1)
plt.xticks(range(datos.shape[1]), datos.columns)
plt.show()
plt.close()

#%%

# Plotea Centro 2
c2 = centros[1:2, :]
y=c2.tolist()[0]
N = len(y)
x = range(N)
width = 1/1.5
null=plt.bar(x, y, width, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)
plt.show()
plt.close()

# Plotea Centro 3
c3 = centros[2:3, :]
y=c3.tolist()[0]
N = len(y)
x = range(N)
width = 1/1.5
null=plt.bar(x, y, width, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)
plt.show()
plt.close()

#%%

# LOS TRES JUNTOS
colores_1 = ['#CF8EF8', '#523C81', '#D2D132', '#59C951', '#E5826C']
plt.figure(1,figsize=(18,8))
# Plotea Centro 1
plt.subplot(1, 3, 1)
y  = centros[:1, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)

# Plotea Centro 2
plt.subplot(1, 3, 2)
y= centros[1:2, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)

# Plotea Centro 3
plt.subplot(1, 3, 3)
y = centros[2:3, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)

#Todos juntos
plt.show()
plt.close()

#%%

# RADAR PLOT para interpretar
# ===========================

datos

#%%
centros
#%%
centros_trans = centros.T
centros_trans

#%%
V1 = centros_trans[:1,:]
print(V1)

V1=V1.tolist()[0]
print(V1)

V2 = centros_trans[1:2,:]
print(V2)

V2=V2.tolist()[0]
print(V2)

V3 = centros_trans[2:3,:]
print(V3)

V3=V3.tolist()[0]
print(V3)

V4 = centros_trans[3:4,:]
print(V4)

V4=V4.tolist()[0]
print(V4)

V5 = centros_trans[4:5,:]
print(V5)

V5=V5.tolist()[0]
print(V5)
#%%

# Datos para el Radar Plot
df = pd.DataFrame({
'grupo': ['Cluster-1','Cluster-2','Cluster-3'],
'Matematicas': V1,
'Ciencias': V2,
'Espanol': V3,
'Historia': V4,
'EdFisica': V5
})

df

#%%
#Otra forma de hacer lo mismo:
df = pd.DataFrame()
for i in range(datos.shape[1]):
    df = pd.concat([df,pd.DataFrame({datos.columns[i]:centros_trans[i,:].tolist()})],axis = 1)

df =  pd.concat([df,pd.DataFrame({'grupo': ['Cluster-1','Cluster-2','Cluster-3']})],axis = 1)

df

#%%
# Variables y Número de Variables
variables=list(df)[0:5]
print(variables)

N = len(variables)
print(N)

#%% 
# Ángulo de los ejes 
angulos = [n / float(N) * 2 * pi for n in range(N)]
angulos+= angulos[:1]

angulos

#%% 

# Inicializa el Radar
ax = plt.subplot(111, polar=True)
 
# En primer eje en la parte de arriba
ax.set_theta_offset(pi / 2)
ax.set_theta_direction(-1)
 
# Dibuja los ejes por variables + las etiquetas
null=plt.xticks(angulos[:-1], variables)
 
# Dibuja las etiquetas en Y
ax.set_rlabel_position(0)
null=plt.yticks([1,2,3,4,5,6,7,8,9,10], ["1","2","3","4","5","6","7","8","9","10"], color="grey", size=7)
plt.ylim(0,10)

# Plotea cada cluster (grupo) = una línea de datos
 
# Cluster 1
valores=df.loc[0].drop('grupo').values.tolist()

valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-1")
ax.fill(angulos, valores, 'b', alpha=0.1)
 
# Cluster 2
valores=df.loc[1].drop('grupo').values.tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-2")
ax.fill(angulos, valores, 'r', alpha=0.1)
 
# Cluster 3
valores=df.loc[2].drop('grupo').values.tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-3")
ax.fill(angulos, valores, 'b', alpha=0.1)
 
# Agrega la leyenda
plt.legend(loc='upper right', bbox_to_anchor=(0.1, 0.1))
plt.show()
plt.close()

#%%


# Los dibuja sobre el plano principal los clusters de k-medias
pca = PCA(n_components=2)
componentes = pca.fit_transform(datos)
componentes
print(datos.shape)
print(componentes.shape)
plt.scatter(componentes[:, 0], componentes[:, 1],c=kmedias.predict(datos))
plt.xlabel('componente 1')
plt.ylabel('componente 2')
plt.title('3 Cluster K-Medias')
plt.show()
plt.close()

#%%

# Ejemplo 3. Datos de Iris
iris = pd.read_csv('../Datos/iris.csv',delimiter=';',decimal=".")
print(iris)
iris.head()
iris.shape

# Ejecuta k-medias con 3 clusters
kmedias = KMeans(n_clusters=3)
iris_tempo=iris.iloc[:,:4]
iris_tempo
kmedias.fit(iris_tempo)
print(kmedias.predict(iris_tempo))
centros = np.array(kmedias.cluster_centers_)
print(centros) 

# Los dibuja sobre el plano principal
pca = PCA(n_components=2)
componentes = pca.fit_transform(iris_tempo)
print(componentes[0:20])

print(iris.shape)
print(componentes.shape)
# Gráfico
plt.scatter(componentes[:, 0], componentes[:, 1],c=kmedias.predict(iris_tempo))
plt.xlabel('componente 1')
plt.ylabel('componente 2')
plt.title('3 Cluster K-Medias')
plt.show()

#%%

# Graficos de barras de los clusters
colores_1 = ['#CF8EF8', '#523C81', '#D2D132', '#59C951', '#E5826C']
plt.figure(1,figsize=(18,8))
# Plotea Centro 1
plt.subplot(1, 3, 1)
y  = centros[:1, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(iris.shape[1]), iris.columns,rotation=45)
# Plotea Centro 2
plt.subplot(1, 3, 2)
y= centros[1:2, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(iris.shape[1]), iris.columns,rotation=45)
# Plotea Centro 3
plt.subplot(1, 3, 3)
y = centros[2:3, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(iris.shape[1]), iris.columns,rotation=45)
plt.show()
plt.close()

#%%
# RADAR PLOT para interpretar
# ===========================

df = pd.DataFrame()
for i in range(iris.shape[1]):
    df = pd.concat([df,pd.DataFrame({iris.columns[i]:centros_trans[i,:].tolist()})],axis = 1)

df =  pd.concat([df,pd.DataFrame({'grupo': ['Cluster-1','Cluster-2','Cluster-3']})],axis = 1)
print(df)

# Variables y Número de Variables
variables=list(df)[0:5]
variables
N = len(variables)
print(N)
 
# Ángulo de los ejes 
angulos = [n / float(N) * 2 * pi for n in range(N)]
angulos+= angulos[:1]
 
# Inicializa el Radar
ax = plt.subplot(111, polar=True)
 
# En primer eje en la parte de arriba
ax.set_theta_offset(pi / 2)
ax.set_theta_direction(-1)
 
# Dibuja los ejes por variables + las etiquetas
null=plt.xticks(angulos[:-1], variables,rotation=45)
 
# Dibuja las etiquetas en Y
ax.set_rlabel_position(0)
null=plt.yticks([1,2,3,4,5,6,7,8,9,10], ["1","2","3","4","5","6","7","8","9","10"], color="grey", size=7)
plt.ylim(0,10)
 
# Plotea cada cluster (grupo) = una línea de datos
 
# Cluster 1
valores=df.loc[0].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-1")
ax.fill(angulos, valores, 'b', alpha=0.1)
 
# Cluster 2
valores=df.loc[1].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-2")
ax.fill(angulos, valores, 'r', alpha=0.1)
 
# Cluster 3
valores=df.loc[2].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-3")
ax.fill(angulos, valores, 'b', alpha=0.1)
 
# Agrega la leyenda
plt.legend(loc='upper right', bbox_to_anchor=(0.1, 0.1))
plt.show()
plt.close()

#%% 

# Ejemplo 4. Ejemplo con datos Servicio al Cliente
print(os.getcwd())
datos = pd.read_csv('../Datos/EjemploClientesCorregidaEdad.csv',delimiter=';',decimal=",",index_col=0)
print(datos)
datos.head()
datos.shape
datos.dropna().describe()

#%%

# Ejecuta k-medias con 3 clusters
kmedias = KMeans(n_clusters=3)
kmedias.fit(datos)
print(kmedias.predict(datos))
centros = np.array(kmedias.cluster_centers_)
centros

# diagrama de codo
inercias = []
K = range(1,20)
for k in K:
    kmeanModel = KMeans(n_clusters=k)
    kmeanModel.fit(datos)
    inercias.append(kmeanModel.inertia_)

plt.plot(K, inercias, 'bx-')
plt.xlabel('k= numero de clusters')
plt.ylabel('inercias o suma de distancias cuadradas a centros de clusters')
plt.title('Metodo de diagrama de codo para mostrar el k optimo')
plt.show()


#%%
# En este caso no hay mucha claridad, K=3 o K=7 son buenas opciones

# LOS TRES JUNTOS
colores_1 = ['#C4F6C2','#03864B', '#AF960F','#F124A3','#FEF61E','#10855C',
             '#441308','#4C19BE','#E74D50','#45DC46','#AA27B6','#2B757E']

#plt.figure(1,figsize=(26,20))
# Plotea Centro 1
plt.subplot(3, 1, 1)
y  = centros[:1, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)
null =plt.tick_params(labelbottom=False)   
# Plotea Centro 2
plt.subplot(3, 1, 2)
y= centros[1:2, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)
null =plt.tick_params(labelbottom=False)
# Plotea Centro 3
plt.subplot(3, 1, 3)
y = centros[2:3, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns,rotation=30,fontsize=5)
plt.show()

#%%
# RADAR PLOT para interpretar
# ===========================

datos
centros
centros_trans = centros.T
centros_trans

df = pd.DataFrame()
for i in range(datos.shape[1]):
    df = pd.concat([df,pd.DataFrame({datos.columns[i]:centros_trans[i,:].tolist()})],axis = 1)

df =  pd.concat([df,pd.DataFrame({'grupo': ['Cluster-1','Cluster-2','Cluster-3']})],axis = 1)
print(df)

# Variables y Número de Variables
variables = list(df)[0:12]
variables
N = len(variables)
print(N)
 
# Ángulo de los ejes 
angulos = [n / float(N) * 2 * pi for n in range(N)]
angulos+= angulos[:1]
 
# Inicializa el Radar
ax = plt.subplot(111, polar=True)
 
# En primer eje en la parte de arriba
ax.set_theta_offset(pi / 2)
ax.set_theta_direction(-1)
 
# Dibuja los ejes por variables + las etiquetas
null=plt.xticks(angulos[:-1], variables)
 
# Dibuja las etiquetas en Y
ax.set_rlabel_position(0)
null=plt.yticks([1,2,3,4,5,6,7,8,9,10], ["1","2","3","4","5","6","7","8","9","10"], color="grey", size=7)
plt.ylim(0,10)
 
# Plotea cada cluster (grupo) = una línea de datos
 
# Cluster 1
valores=df.loc[0].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-1")
ax.fill(angulos, valores, 'b', alpha=0.1)
 
# Cluster 2
valores=df.loc[1].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-2")
ax.fill(angulos, valores, 'r', alpha=0.1)
 
# Cluster 3
valores=df.loc[2].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-3")
ax.fill(angulos, valores, 'b', alpha=0.1)
 
# Agrega la leyenda
plt.legend(loc='upper right', bbox_to_anchor=(0.1, 0.1))
plt.show()
plt.close()

#%%

# Los dibuja sobre el plano principal los clusters de k-medias
pca = PCA(n_components=2)
componentes = pca.fit_transform(datos)
componentes
print(datos.shape)
print(componentes.shape)
plt.scatter(componentes[:, 0], componentes[:, 1],c=kmedias.predict(datos))
plt.xlabel('componente 1')
plt.ylabel('componente 2')
plt.title('3 Cluster K-Medias')
plt.show()

#%%

## Clusterización Jerárquica

# Import the dendrogram function and the ward clustering function from SciPy
from scipy.cluster.hierarchy import dendrogram, ward, single, complete,average,linkage, fcluster
from scipy.spatial.distance import pdist

# f cluster para los centros

# Simulación del clustering jeráquico
mglearn.plots.plot_agglomerative()
plt.show()
plt.close()

#%%

# Ejemplo 1. Datos simulados con dos variables 
X, y = make_blobs(random_state=0, n_samples=20, n_features = 3)
X = pd.DataFrame(X).abs()
X.columns = ["X1","X2","X3"]
print(X)
print(y)

# Agregación de:
ward_res = ward(X)         #Ward
single_res = single(X)     #Salto mínimo
complete_res = complete(X) #Salto Máximo
average_res = average(X)   #Promedio

# Plotea el dendograma
plt.figure(figsize=(13,10))
null=dendrogram(average_res)
plt.show()
plt.close()

#%%

plt.figure(figsize=(13,10))
null=dendrogram(complete_res)
plt.show()
plt.close()


plt.figure(figsize=(13,10))
null=dendrogram(single_res)
plt.show()
plt.close()

plt.figure(figsize=(13,10))
d = dendrogram(ward_res)


#%%

# Agrega cortes con 2 y 3 clústeres
ax = plt.gca()
limites = ax.get_xbound()
ax.plot(limites, [15.5, 15.5], '--', c='k')
ax.plot(limites, [5, 5], '--', c='k')

ax.text(limites[1], 15.5, ' dos clústeres', va='center', fontdict={'size': 15})
ax.text(limites[1], 5, ' tres clústeres', va='center', fontdict={'size': 15})
plt.xlabel("Orden en el eje X")
plt.ylabel("Distancia o Agregación")
plt.show()
plt.close()

#%%

# Gráficos de barras : 
def centroide(num_cluster, datos, clusters):
  ind = clusters == num_cluster
  return(pd.DataFrame(datos[ind].mean()).T)

grupos = fcluster(linkage(pdist(X), method='ward'),3,'distance')
centros = np.array(pd.concat([centroide(1,X,grupos),centroide(2,X,grupos),centroide(3,X,grupos)]))


colores_1 = ['#CF8EF8', '#523C81', '#D2D132', '#59C951', '#E5826C']
plt.figure(1,figsize=(18,8))
# Plotea Centro 1
plt.subplot(1, 3, 1)
y  = centros[:1, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(X.shape[1]), X.columns)
# Plotea Centro 2
plt.subplot(1, 3, 2)
y= centros[1:2, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(X.shape[1]), X.columns)
# Plotea Centro 3
plt.subplot(1, 3, 3)
y= centros[2:3, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(X.shape[1]), X.columns)
plt.show()
plt.close()

#%%
# RADAR PLOT para interpretar
# ===========================
centros_trans = centros.T
centros_trans

df = pd.DataFrame()
for i in range(X.shape[1]):
    df = pd.concat([df,pd.DataFrame({X.columns[i]:centros_trans[i,:].tolist()})],axis = 1)

df =  pd.concat([df,pd.DataFrame({'grupo': ['Cluster-1','Cluster-2','Cluster-3']})],axis = 1)
print(df)

# Variables y Número de Variables
variables=list(df)[0:3]
variables
N = len(variables)
print(N)
 
# Ángulo de los ejes 
angulos = [n / float(N) * 2 * pi for n in range(N)]
angulos+= angulos[:1]
 
# Inicializa el Radar
ax = plt.subplot(111, polar=True)
 
# En primer eje en la parte de arriba
ax.set_theta_offset(pi / 2)
ax.set_theta_direction(-1)
 
# Dibuja los ejes por variables + las etiquetas
null=plt.xticks(angulos[:-1], variables)
 
# Dibuja las etiquetas en Y
ax.set_rlabel_position(0)
null=plt.yticks([1,2,3,4,5,6,7,8,9,10], ["1","2","3","4","5","6","7","8","9","10"], color="grey", size=7)
plt.ylim(0,10)
 
# Plotea cada cluster (grupo) = una línea de datos
 
# Cluster 1
valores=df.loc[0].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-1")
ax.fill(angulos, valores, 'b', alpha=0.1)
 
# Cluster 2
valores=df.loc[1].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-2")
ax.fill(angulos, valores, 'r', alpha=0.1)
 
# Cluster 3
valores=df.loc[2].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-3")
ax.fill(angulos, valores, 'b', alpha=0.1)
 
# Agrega la leyenda
plt.legend(loc='upper right', bbox_to_anchor=(0.1, 0.1))
plt.show()
plt.close()

#%%

# Ejemplo 2. Datos de Estudiantes

print(os.getcwd())
datos = pd.read_csv('../Datos/EjemploEstudiantes.csv',delimiter=';',decimal=",",index_col=0)
print(datos)
print(datos.head())
print(datos.shape)

# Agregación de:
ward_res = ward(datos)         #Ward
single_res = single(datos)     #Salto mínimo
complete_res = complete(datos) #Salto Máximo
average_res = average(datos)   #Promedio

# Plotea el dendograma
plt.figure(figsize=(13,10))

null=dendrogram(average_res,labels= datos.index.tolist())
plt.show()
plt.close()

plt.figure(figsize=(13,10))
null=dendrogram(complete_res,labels= datos.index.tolist())
plt.show()
plt.close()

plt.figure(figsize=(13,10))
null=dendrogram(single_res,labels= datos.index.tolist())
plt.show()
plt.close()

plt.figure(figsize=(13,10))
null=dendrogram(ward_res,labels= datos.index.tolist())

# Agrega cortes con 2 y 3 clústeres
ax = plt.gca()
limites = ax.get_xbound()
ax.plot(limites, [7.25, 7.25], '--', c='k')
ax.plot(limites, [4, 4], '--', c='k')

ax.text(limites[1], 7.25, ' dos clústeres', va='center', fontdict={'size': 15})
ax.text(limites[1], 4, ' tres clústeres', va='center', fontdict={'size': 15})
plt.xlabel("Orden en el eje X")
plt.ylabel("Distancia o Agregación")
plt.show()
plt.close()

#%%

# Gráficos de barras : 
grupos = fcluster(linkage(pdist(datos), method='ward'),3,'distance')
centros = np.array(pd.concat([centroide(1,datos,grupos),centroide(2,datos,grupos),centroide(3,datos,grupos)]))

colores_1 = ['#CF8EF8', '#523C81', '#D2D132', '#59C951', '#E5826C']
# Plotea Centro 1
plt.figure(1,figsize=(18,8))
plt.subplot(1, 3, 1)
y  = centros[:1,:].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)

# Plotea Centro 2
plt.subplot(1, 3, 2)
y= centros[1:2, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)

# Plotea Centro 3
plt.subplot(1, 3, 3)
y = centros[2:3, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)
plt.show()
plt.close()

#%%

# RADAR PLOT para interpretar
# ===========================
centros_trans = centros.T
centros_trans

df = pd.DataFrame()
for i in range(datos.shape[1]):
    df = pd.concat([df,pd.DataFrame({datos.columns[i]:centros_trans[i,:].tolist()})],axis = 1)

df =  pd.concat([df,pd.DataFrame({'grupo': ['Cluster-1','Cluster-2','Cluster-3']})],axis = 1)
print(df)

# Variables y Número de Variables
variables=list(df)[0:5]
variables
N = len(variables)
print(N)
 
# Ángulo de los ejes 
angulos = [n / float(N) * 2 * pi for n in range(N)]
angulos+= angulos[:1]
 
# Inicializa el Radar
ax = plt.subplot(111, polar=True)
 
# En primer eje en la parte de arriba
ax.set_theta_offset(pi / 2)
ax.set_theta_direction(-1)
 
# Dibuja los ejes por variables + las etiquetas
null=plt.xticks(angulos[:-1], variables)
 
# Dibuja las etiquetas en Y
ax.set_rlabel_position(0)
null=plt.yticks([1,2,3,4,5,6,7,8,9,10], ["1","2","3","4","5","6","7","8","9","10"], color="grey", size=7)
plt.ylim(0,10)
 
# Plotea cada cluster (grupo) = una línea de datos
 
# Cluster 1
valores=df.loc[0].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-1")
ax.fill(angulos, valores, 'b', alpha=0.1)
 
# Cluster 2
valores=df.loc[1].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-2")
ax.fill(angulos, valores, 'r', alpha=0.1)
 
# Cluster 3
valores=df.loc[2].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-3")
ax.fill(angulos, valores, 'b', alpha=0.1)
 
# Agrega la leyenda
plt.legend(loc='upper right', bbox_to_anchor=(0.1, 0.1))
plt.show()
plt.close()

#%%
##_______________________________________________________________________________________

# Ejemplo Iris

datos = pd.read_csv('../Datos/iris.csv',delimiter=';',decimal=".")
datos = datos.iloc[:,:4] #Elimina la variable categorica
print(datos)

print(datos.head())
print(datos.shape)
ward_res = ward(datos)         #Ward
single_res = single(datos)     #Salto mínimo
complete_res = complete(datos) #Salto Máximo
average_res = average(datos)   #Promedio

null=dendrogram(average_res,labels= datos.index.tolist(),color_threshold=1.9,leaf_rotation=90)
plt.show()
plt.close()

plt.figure(figsize=(13,10))
null=dendrogram(complete_res,labels= datos.index.tolist(),color_threshold=3.5,leaf_rotation=90)
plt.show()
plt.close()

plt.figure(figsize=(13,10))
null=dendrogram(single_res,labels= datos.index.tolist(),color_threshold=0.7,leaf_rotation=90)
plt.show()
plt.close()

#%%
## Agregando cortes en el dendograma
plt.figure(figsize=(13,10))
null=dendrogram(ward_res,labels= datos.index.tolist(),color_threshold=8,leaf_rotation=90)

ax = plt.gca()
limites = ax.get_xbound()
ax.plot(limites, [20, 20], '--', c='k')
ax.plot(limites, [8, 8], '--', c='k')

ax.text(limites[1], 20, ' dos clústeres', va='center', fontdict={'size': 15})
ax.text(limites[1], 8, ' tres clústeres', va='center', fontdict={'size': 15})
plt.xlabel("Orden en el eje X")
plt.ylabel("Distancia o Agregación")
plt.show()
plt.close()

#%%
grupos = fcluster(linkage(pdist(datos), method='ward'),3,criterion='maxclust')
print(grupos)
centros = np.array(pd.concat([centroide(1,datos,grupos),centroide(2,datos,grupos),centroide(3,datos,grupos)]))
print(centros)
colores_1 = ['#CF8EF8', '#523C81', '#D2D132', '#59C951', '#E5826C']
# Plotea Centro 1
plt.figure(1,figsize=(18,8))
plt.subplot(1, 3, 1)
y  = centros[:1,:].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)
# Plotea Centro 2
plt.subplot(1, 3, 2)
y= centros[1:2, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)
# Plotea Centro 3
plt.subplot(1, 3, 3)
y = centros[2:3, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)
plt.show()
plt.close()

#%%
##Radar Plot
centros_trans = centros.T
print(centros_trans)

df = pd.DataFrame()
for i in range(datos.shape[1]):
    df = pd.concat([df,pd.DataFrame({datos.columns[i]:centros_trans[i,:].tolist()})],axis = 1)
df =  pd.concat([df,pd.DataFrame({'grupo': ['Cluster-1','Cluster-2','Cluster-3']})],axis = 1)
print(df)

variables=list(df)[0:4]
print(variables)

N = len(variables)
print(N)

## Angulo de ejes
angulos = [n / float(N) * 2 * pi for n in range(N)]
angulos+= angulos[:1]
ax = plt.subplot(111, polar=True)
#Eeje a 90 grados
ax.set_theta_offset(pi / 2)
ax.set_theta_direction(-1)

null=plt.xticks(angulos[:-1], variables)
ax.set_rlabel_position(0)
null=plt.yticks([1,2,3,4,5,6,7,8,9,10], ["1","2","3","4","5","6","7","8","9","10"], color="grey", size=7)
plt.ylim(0,10)

#Graficando cada cluster (grupo) = una línea de datos
#Cluster 1
valores=df.loc[0].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-1")
ax.fill(angulos, valores, 'b', alpha=0.1)

#Cluster 2
valores=df.loc[1].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-2")
ax.fill(angulos, valores, 'r', alpha=0.1)

#Cluster 3
valores=df.loc[2].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-3")
ax.fill(angulos, valores, 'b', alpha=0.1)

#Plot
plt.legend(loc='upper right', bbox_to_anchor=(0.1, 0.1))
plt.show()
plt.close()

#%%
###_______________________________________________________________________

datos = pd.read_csv('../Datos/EjemploClientesCorregidaEdad.csv',delimiter=';',decimal=",",index_col=0)
print(datos)

print(datos.head())
print(datos.shape)
ward_res = ward(datos)         #Ward
single_res = single(datos)     #Salto mínimo
complete_res = complete(datos) #Salto Máximo
average_res = average(datos)   #Promedio

null=dendrogram(average_res,labels= datos.index.tolist(),color_threshold=9.8)
plt.show()
plt.close()

plt.figure(figsize=(13,10))
null=dendrogram(complete_res,labels= datos.index.tolist(),color_threshold=13)
plt.show()
plt.close()

plt.figure(figsize=(13,10))
null=dendrogram(single_res,labels= datos.index.tolist(),color_threshold=6.5)
plt.show()
plt.close()

#%%

## Con divisiones
plt.figure(figsize=(13,10))
null=dendrogram(ward_res,labels= datos.index.tolist(),color_threshold=15)
  
ax = plt.gca()
limites = ax.get_xbound()
ax.plot(limites, [20, 20], '--', c='k')
ax.plot(limites, [15, 15], '--', c='k')
ax.plot(limites, [12.5, 12.5], '--', c='k')

ax.text(limites[1], 20, ' dos clústeres', va='center', fontdict={'size': 15})
ax.text(limites[1], 15, ' tres clústeres', va='center', fontdict={'size': 15})
ax.text(limites[1], 12.5, ' cinco clústeres', va='center', fontdict={'size': 15})
plt.xlabel("Orden en el eje X")
plt.ylabel("Distancia o Agregación")
plt.show()
plt.close()

#%%

numero_clusters = 3
grupos = fcluster(linkage(pdist(datos), method='ward'),numero_clusters,criterion='maxclust')
print(grupos)

centro_lista = []
centros = np.array(pd.concat([centroide(i+1,datos,grupos) for i in range(numero_clusters)]))
print(centros)

colores_1 = ['#C4F6C2','#F3864B', '#AF960F','#F124A3','#FEF61E','#10855C',
             '#441308','#4C19BE','#E74D50','#45DC46','#AA27B6','#2B757E']
# Otra manera:
plt.figure(1,figsize=(25,20))
for i in range(numero_clusters):
    null=plt.subplot(numero_clusters, 1, i+1)
    min_limit = i
    max_limit = i+1
    y  = centros[min_limit:max_limit,:].tolist()[0]
    null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
    null=null=plt.xticks(range(datos.shape[1]), datos.columns,rotation=30,fontsize=10)
plt.show()
plt.close()

#%%

## RADAR PLOT
centros_trans = centros.T
print(centros_trans)

nombres =  ["Cluster-%i" % (i+1) for i in range(numero_clusters)]
print(nombres)

df = pd.DataFrame()
for i in range(datos.shape[1]):
    df = pd.concat([df,pd.DataFrame({datos.columns[i]:centros_trans[i,:].tolist()})],axis = 1)
df =  pd.concat([df,pd.DataFrame({'grupo': nombres})],axis = 1)
print(df)

max_limit = df.shape[1] -1
variables=list(df)[0:max_limit]
print(variables)

N = len(variables)
print(N)

angulos = [n / float(N) * 2 * pi for n in range(N)]
angulos+= angulos[:1]

ax = plt.subplot(111, polar=True)

ax.set_theta_offset(pi / 2)
ax.set_theta_direction(-1)

null=null=plt.xticks(angulos[:-1], variables)

ax.set_rlabel_position(0)
null=plt.yticks([1,2,3,4,5,6,7,8,9,10], ["1","2","3","4","5","6","7","8","9","10"], color="grey", size=7)
plt.ylim(0,10)

for i in range(numero_clusters):
  valores=df.loc[i].drop('grupo').values.flatten().tolist()
  valores += valores[:1]
  ax.plot(angulos, valores, linewidth=1, linestyle='solid', label=nombres[i])
  ax.fill(angulos, valores, 'b', alpha=0.1)

plt.legend(loc='upper right', bbox_to_anchor=(0.1, 0.1))
plt.show()
plt.close()
  


