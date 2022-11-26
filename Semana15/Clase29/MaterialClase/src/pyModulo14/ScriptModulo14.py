'''
Created on Feb 11, 2021

@author: freddy
'''


#%%
import pandas as pd 
import numpy as np
from   math import pi
import matplotlib.pyplot as plt
from   sklearn.cluster import KMeans

from scipy.cluster.hierarchy import dendrogram, ward, single, complete,average,linkage, fcluster
from scipy.spatial.distance import pdist


#%%
def Plot():
    plt.show()
    plt.close()
    
def centroide(num_cluster, datos, clusters):
  ind = clusters == num_cluster
  return(pd.DataFrame(datos[ind].mean()).T) 
  

#%% 
#Importing the library
from sklearn import preprocessing

datos = pd.read_csv('../Datos/ConsumoEuropa.csv',delimiter=';',decimal=',',index_col =0)
datos=datos.dropna()
print(datos)

#Esto se puede descomentar luego para ver la diferencias de
#cuando se escalan los datos:

#datos_values = datos.values
#scaler = preprocessing.MinMaxScaler()
#x_scaled = scaler.fit_transform(datos_values)
#datos_scaled = pd.DataFrame(x_scaled,columns=datos.columns, index=datos.index)

#datos = datos_scaled

#datos_scaled
#%%
print("Análsis de archivo")
print("+++++++++++++++++++++")
print(datos.dtypes)

#Nombres de variables
NombreTodasVar=datos.columns.values.tolist()
print("Nombre de todas las variables \n%s" % NombreTodasVar)
 
df_numericas = datos.select_dtypes(include=['float64','int64'])
NombresNumericas=df_numericas.columns.values.tolist()
print("Nombre de variables numéricas \n%s" % NombresNumericas)
 
#%%
### CLUSTERING JERARQUICO
single_res = single(datos)          #Salto mínimo
complete_res = complete(datos)      #Salto Máximo
average_res = average(datos)        #Promedio
ward_res = ward(datos)              #Ward
 
## Dendogramas
null=dendrogram(single_res,color_threshold=3,labels= datos.index.tolist(),leaf_rotation=30,leaf_font_size=5)
ax = plt.gca()
limites = ax.get_xbound()

ax.plot(limites, [11.2, 11.2], '--', c='k')
ax.text(limites[1], 11.2, ' dos clústeres', va='center', fontdict={'size': 8})

ax.plot(limites, [10.5, 10.5], '--', c='k')
ax.text(limites[1], 10.5, ' tres clústeres', va='center', fontdict={'size': 8})

ax.plot(limites, [10.1, 10.1], '--', c='k')
ax.text(limites[1], 10.1, ' cuatro clústeres', va='center', fontdict={'size': 8})

plt.ylabel("Distancia o Agregación")
Plot()
 
#%%
null=dendrogram(complete_res,color_threshold=3,labels= datos.index.tolist(),leaf_rotation=30,leaf_font_size=5)
ax = plt.gca()
limites = ax.get_xbound()

ax.plot(limites, [35, 35], '--', c='k')
ax.text(limites[1], 35, ' dos clústeres', va='center', fontdict={'size': 8})

ax.plot(limites, [27,27], '--', c='k')
ax.text(limites[1], 27, ' tres clústeres', va='center', fontdict={'size': 8})

ax.plot(limites, [22, 22], '--', c='k')
ax.text(limites[1], 22, ' cuatro clústeres', va='center', fontdict={'size': 8})
Plot()

#%%
null=dendrogram(average_res,color_threshold=3,labels= datos.index.tolist(),leaf_rotation=30,leaf_font_size=5)
ax = plt.gca()
limites = ax.get_xbound()

ax.plot(limites, [22, 22], '--', c='k')
ax.text(limites[1], 22, ' dos clústeres', va='center', fontdict={'size': 8})

ax.plot(limites, [19,19], '--', c='k')
ax.text(limites[1], 19, ' tres clústeres', va='center', fontdict={'size': 8})

ax.plot(limites, [17, 17], '--', c='k')
ax.text(limites[1], 17, ' cuatro clústeres', va='center', fontdict={'size': 8})
Plot()

#%%
null=dendrogram(ward_res,color_threshold=3,labels= datos.index.tolist(),leaf_rotation=30,leaf_font_size=5)
ax = plt.gca()
limites = ax.get_xbound()

ax.plot(limites, [60, 60], '--', c='k')
ax.text(limites[1], 60, ' dos clústeres', va='center', fontdict={'size': 8})

ax.plot(limites, [40,40], '--', c='k')
ax.text(limites[1], 40, ' tres clústeres', va='center', fontdict={'size': 8})

ax.plot(limites, [30, 30], '--', c='k')
ax.text(limites[1], 30, ' cuatro clústeres', va='center', fontdict={'size': 8}) 
Plot()

#%% 
#BAR plot 
grupos = fcluster(linkage(pdist(datos), method='ward'),3,criterion='maxclust')
print(grupos)
centros = np.array(   pd.concat([centroide(1,datos,grupos),
                                 centroide(2,datos,grupos),
                                 centroide(3,datos,grupos) ])  )
print(centros)
colores_1 = ['#CF8EF8', '#523C81', '#D2D132', '#59C951', '#E5826C']
 
# Plotea Centro 1
plt.subplot(1, 3, 1)
y  = centros[:1, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns,rotation=45,fontsize=5)
 
# Plotea Centro 2
plt.subplot(1, 3, 2)
y= centros[1:2, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns,rotation=45,fontsize=5)

# Plotea Centro 3
plt.subplot(1, 3, 3)
y= centros[2:3, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns,rotation=45,fontsize=5)
Plot()

#%%
#Radar plot
centros_trans = centros.T
df = pd.DataFrame()
for i in range(datos.shape[1]):
    df = pd.concat([df,pd.DataFrame({datos.columns[i]:centros_trans[i,:].tolist()})],
                   axis = 1)
df =  pd.concat([df,pd.DataFrame(  {'grupo': ['Cluster-1','Cluster-2','Cluster-3'] } )],
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
 
#Cluster 3
valores=df.loc[2].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-3")
ax.fill(angulos, valores, 'r', alpha=0.1)
 
plt.legend(loc='upper right', bbox_to_anchor=(0.1, 0.1))
 
Plot()
 
#%%
#K medias
kmedias = KMeans(n_clusters=3)
kmedias.fit(datos)
print(kmedias.predict(datos))
centros = np.array(kmedias.cluster_centers_)
print(centros) 
 
#%%
#Bar plot
colores_1 = ['#CF8EF8', '#523C81', '#D2D132', '#59C951', '#E5826C']
#plt.figure(1,figsize=(25,15))
 
# Plotea Centro 1
plt.subplot(1, 3, 1)
y  = centros[:1, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns,rotation=45,fontsize=5)
 
# Plotea Centro 2
plt.subplot(1, 3, 2)
y= centros[1:2, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns,rotation=45,fontsize=5)
 
# Plotea Centro 3
plt.subplot(1, 3, 3)
y= centros[2:3, :].tolist()[0]
null=plt.bar(range(len(y)), y, 1/1.5, color=colores_1)
null=plt.xticks(range(datos.shape[1]), datos.columns,rotation=45,fontsize=5)

Plot()
 
#%%
#Radar plot
centros_trans = centros.T
df = pd.DataFrame()
for i in range(datos.shape[1]):
    df = pd.concat([df,pd.DataFrame({datos.columns[i]:centros_trans[i,:].tolist()})],
                   axis = 1)
df =  pd.concat([df,pd.DataFrame(  {'grupo': ['Cluster-1','Cluster-2','Cluster-3'] } )],
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
 
#Cluster 3
valores=df.loc[2].drop('grupo').values.flatten().tolist()
valores += valores[:1]
ax.plot(angulos, valores, linewidth=1, linestyle='solid', label="Cluster-3")
ax.fill(angulos, valores, 'r', alpha=0.1)
 
plt.legend(loc='upper right', bbox_to_anchor=(0.1, 0.1))
 
Plot()
 
#%%

#Codo de Jambú
print("Codo de Jambú inercia interclases")
Nc = range(1, 10)
kmediasList = [KMeans(n_clusters=i) for i in Nc]
varianza = [kmediasList[i].fit(datos).score(datos) 
            for i in range(len(kmediasList))]
plt.plot(Nc,varianza,'o-')
plt.xlabel('Número de clústeres')
plt.ylabel('Varianza explicada por cada cluster (Inercia Interclases)')
plt.title('Codo de Jambu inercia interclase')
Plot()
 
print("Codo de Jambú inercia intraclases")
Nc = range(1, 10)
kmediasList = [KMeans(n_clusters=i) for i in Nc]
varianza = [kmediasList[i].fit(datos).inertia_ 
            for i in range(len(kmediasList))]
plt.plot(Nc,varianza,'o-')
plt.xlabel('Número de clústeres')
plt.ylabel('Varianza explicada por cada cluster (Inercia Intraclases)')
plt.title('Codo de Jambu inercia intraclases')
Plot()

