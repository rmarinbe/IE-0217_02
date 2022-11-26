'''
Created on Feb 11, 2021

@author: freddy
'''

## @knitr Eval1_py
#%%
import pandas as pd 
import numpy as np
from   math import pi
import matplotlib.pyplot as plt
from   sklearn.decomposition import PCA
from   sklearn.cluster import KMeans

from scipy.cluster.hierarchy import dendrogram, ward, single, complete,average,linkage, fcluster
from scipy.spatial.distance import pdist

## @knitr Plot
#%%
def Plot():
    plt.show()
    plt.close()
    
## @knitr Eval1a
#%%
def centroide(num_cluster, datos, clusters):
  ind = clusters == num_cluster
  return(pd.DataFrame(datos[ind].mean()).T) 

datos = pd.read_csv('../Datos/titanic.csv',delimiter=',',decimal=".",index_col =0)
datos=datos.dropna()
print(datos.head(10))

## @knitr Eval1b
#%%
print("Análsis de archivo")
print("+++++++++++++++++++++")
print(datos.dtypes)

#Nombres de variables
NombreTodasVar=datos.columns.values.tolist()
print("Nombre de todas las variables \n%s" % NombreTodasVar)

#Convertir a categóricas las tipo 'object'
lista_categoricas=['Ticket','Cabin','Survived', 'Pclass', 'Sex']
for nombre in lista_categoricas:
    datos[nombre]=datos[nombre].astype('category')

Survived=datos['Survived']    
#Borrar variables ID y no trascendentales
lista_borrar=[ 'Name', 'Ticket','Cabin','Survived', 'Pclass', 'Sex','Embarked']
datos=datos.drop(lista_borrar,axis=1)

#Todas las variables ajustadas.
NombreTodasVar= datos.columns.values.tolist()
print("Nombre de todas las variables sin ID's \n%s" % NombreTodasVar)

df_numericas = datos.select_dtypes(include=['float64','int64'])
NombresNumericas=df_numericas.columns.values.tolist()
print("Nombre de variables numéricas \n%s" % NombresNumericas)

## @knitr Eval1c
#%%
### CLUSTERING JERARQUICO
single_res = single(datos)          #Salto mínimo
complete_res = complete(datos)      #Salto Máximo
average_res = average(datos)        #Promedio
ward_res = ward(datos)              #Ward

## Dendogramas
null=dendrogram(single_res,color_threshold=3,labels= datos.index.tolist())
ax = plt.gca()
limites = ax.get_xbound()
ax.plot(limites, [200, 200], '--', c='k')
ax.text(limites[1], 200, ' dos clústeres', va='center', fontdict={'size': 8})
ax.plot(limites, [40, 40], '--', c='k')
ax.text(limites[1], 40, ' tres clústeres', va='center', fontdict={'size': 8})
plt.xlabel("Orden en el eje X")
plt.ylabel("Distancia o Agregación")
Plot()

null=dendrogram(complete_res,color_threshold=3,labels= datos.index.tolist())
ax = plt.gca()
limites = ax.get_xbound()
ax.plot(limites, [400, 400], '--', c='k')
ax.text(limites[1], 400, ' dos clústeres', va='center', fontdict={'size': 8})
ax.plot(limites, [200, 200], '--', c='k')
ax.text(limites[1], 200, ' tres clústeres', va='center', fontdict={'size': 8})
plt.xlabel("Orden en el eje X")
plt.ylabel("Distancia o Agregación")
Plot()

null=dendrogram(average_res,color_threshold=3,labels= datos.index.tolist())
ax = plt.gca()
limites = ax.get_xbound()
ax.plot(limites, [300, 300], '--', c='k')
ax.text(limites[1], 300, ' dos clústeres', va='center', fontdict={'size': 8})
ax.plot(limites, [100, 100], '--', c='k')
ax.text(limites[1], 100, ' tres clústeres', va='center', fontdict={'size': 8})
plt.xlabel("Orden en el eje X")
plt.ylabel("Distancia o Agregación")
Plot()

null=dendrogram(ward_res,color_threshold=2,labels= datos.index.tolist())
ax = plt.gca()
limites = ax.get_xbound()
ax.plot(limites, [800, 800], '--', c='k')
ax.text(limites[1], 800, ' dos clústeres', va='center', fontdict={'size': 8})
ax.plot(limites, [640, 640], '--', c='k')
ax.text(limites[1], 640, ' tres clústeres', va='center', fontdict={'size': 8})
plt.xlabel("Orden en el eje X")
plt.ylabel("Distancia o Agregación")
Plot()

## @knitr Eval1d
#%%
#BAR plot 
grupos = fcluster(linkage(pdist(datos), method='ward'),2,criterion='maxclust')
print(grupos)
centros = np.array(   pd.concat([centroide(1,datos,grupos),
                                 centroide(2,datos,grupos) ])  )
print(centros)
colores_1 = ['#CF8EF8', '#523C81', '#D2D132', '#59C951', '#E5826C']

# Plotea Centro 1
plt.subplot(1, 2, 1)
y  = centros[:1, :].tolist()[0]
plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)

# Plotea Centro 2
plt.subplot(1, 2, 2)
y= centros[1:2, :].tolist()[0]
plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)
Plot()

## @knitr Eval1e
#%%
#Radar plot
centros_trans = centros.T
df = pd.DataFrame()
for i in range(datos.shape[1]):
    df = pd.concat([df,pd.DataFrame({datos.columns[i]:centros_trans[i,:].tolist()})],
                   axis = 1)
df =  pd.concat([df,pd.DataFrame(  {'grupo': ['Cluster-1','Cluster-2'] } )],
                axis = 1)
print(df)
maximo=df.max(axis=1).max()
variables=list(df)[0:datos.shape[1]]
print(variables)
N = len(variables)
angulos = [n / float(N) * 2 * pi for n in range(N)]
angulos+= angulos[:1]

#Generación de Radar
ax = plt.subplot(111, polar=True)
ax.set_theta_offset(pi / 2)
ax.set_theta_direction(-1)
null=plt.xticks(angulos[:-1], variables)
ax.set_rlabel_position(0)
lista=np.arange(1,11)*int(maximo/10)
lista_p=lista.astype(str)
null=plt.yticks(lista, lista_p, color="grey", size=7)
plt.ylim(0,maximo)

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

plt.legend(loc='upper right', bbox_to_anchor=(0.1, 0.1))

Plot()

## @knitr Eval1f
#%%
#PCA 2 componentes todos
pca = PCA(n_components=2)
componentes = pca.fit_transform(datos)
#print(componentes)
print(datos.shape)
print(componentes.shape)

plt.scatter(componentes[:, 0], componentes[:, 1],c=grupos)
plt.xlabel('componente 1')
plt.ylabel('componente 2')
plt.title('2 Cluster K-Medias basada en grupos HClustering')
Plot()

#PCA 2 componentes Survived
print("Survived")
print(Survived)
plt.scatter(componentes[:, 0], componentes[:, 1],c=Survived)
plt.xlabel('componente 1')
plt.ylabel('componente 2')
plt.title('2 Cluster K-Medias basados en "Survived" ')
Plot()

## @knitr Eval1g
#%%

#K medias
kmedias = KMeans(n_clusters=2)
kmedias.fit(datos)
print(kmedias.predict(datos))
centros = np.array(kmedias.cluster_centers_)
print(centros) 

#Bar plot
colores_1 = ['#CF8EF8', '#523C81', '#D2D132', '#59C951', '#E5826C']
#plt.figure(1,figsize=(25,15))

# Plotea Centro 1
plt.subplot(1, 2, 1)
y  = centros[:1, :].tolist()[0]
plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)

# Plotea Centro 2
plt.subplot(1, 2, 2)
y= centros[1:2, :].tolist()[0]
plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns)

Plot()

## @knitr Eval1h
#%%

#Radar plot
centros_trans = centros.T
df = pd.DataFrame()
for i in range(datos.shape[1]):
    df = pd.concat([df,pd.DataFrame({datos.columns[i]:centros_trans[i,:].tolist()})],
                   axis = 1)
df =  pd.concat([df,pd.DataFrame(  {'grupo': ['Cluster-1','Cluster-2'] } )],
                axis = 1)
print(df)

maximo=df.max(axis=1).max()
variables=list(df)[0:datos.shape[1]]

print(variables)
N = len(variables)
angulos = [n / float(N) * 2 * pi for n in range(N)]
angulos+= angulos[:1]

#Generación de Radar
ax = plt.subplot(111, polar=True)
ax.set_theta_offset(pi / 2)
ax.set_theta_direction(-1)
null=plt.xticks(angulos[:-1], variables)
ax.set_rlabel_position(0)
lista=np.arange(1,11)*int(maximo/10)
lista_p=lista.astype(str)
null=plt.yticks(lista, lista_p, color="grey", size=7)
plt.ylim(0,maximo)

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

plt.legend(loc='upper right', bbox_to_anchor=(0.1, 0.1))

Plot()

## @knitr Eval1i
#%%
#PCA 2 componentes

pca = PCA(n_components=2)
componentes = pca.fit_transform(datos)
#print(componentes)
print(datos.shape)
print(componentes.shape)
plt.scatter(componentes[:, 0], componentes[:, 1],c=kmedias.predict(datos))
plt.xlabel('componente 1')
plt.ylabel('componente 2')
plt.title('2 Cluster K-Medias')
Plot()

#PCA 2 componentes Survived
plt.scatter(componentes[:, 0], componentes[:, 1],c=Survived)
plt.xlabel('componente 1')
plt.ylabel('componente 2')
plt.title('2 Cluster K-Medias basados en "Survived" ')
Plot()

## @knitr Eval1j
#%%
#Codo de Jambú
print("Codo de Jambú inercia interclases")
Nc = range(1, 50)
kmediasList = [KMeans(n_clusters=i) for i in Nc]
varianza = [kmediasList[i].fit(datos).score(datos) 
            for i in range(len(kmediasList))]
plt.plot(Nc,varianza,'o-')
plt.xlabel('Número de clústeres')
plt.ylabel('Varianza explicada por cada cluster (Inercia Interclases)')
plt.title('Codo de Jambu inercia interclase')
Plot()

print("Codo de Jambú inercia intraclases")
Nc = range(1, 50)
kmediasList = [KMeans(n_clusters=i) for i in Nc]
varianza = [kmediasList[i].fit(datos).inertia_ 
            for i in range(len(kmediasList))]
plt.plot(Nc,varianza,'o-')
plt.xlabel('Número de clústeres')
plt.ylabel('Varianza explicada por cada cluster (Inercia Intraclases)')
plt.title('Codo de Jambu inercia intraclases')
plt.show()
