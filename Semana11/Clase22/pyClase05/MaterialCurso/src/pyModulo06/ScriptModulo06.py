'''
Created on Jan 28, 2021

@author: freddy
'''



# Clase vacía
class punto:
    pass

p1 = punto()
p2 = punto()
p1.x = 5
p1.y = 4
p2.x = 3
p2.y = 6
print(p1.x, p1.y)
print(p2.x, p2.y)

# Método resetear traslada un punto al origen
class Punto_:
    def resetear(self):
        self.x = 0
        self.y = 0
        

p = Punto_()
p.x = 5
p.y = 4
print(p.x, p.y)       
p.resetear()
print(p.x, p.y)

import math

# Clase Punto
class Punto:
    def __init__(self, x = 0, y = 0): # Constructor
        self.x = x
        self.y = y     
         
    def cambiar(self, x, y):
        self.x = x
        self.y = y
        
    def inicializar(self):
        self.cambiar(0, 0)
        
    def calcular_distancia(self, otro_Punto):
        return math.sqrt(
                (self.x - otro_Punto.x)**2 +
                (self.y - otro_Punto.y)**2)


# ¿Cómo usarla?
Punto1 = Punto(2,3)
Punto2 = Punto(-2,9)
print(Punto1.x)
print(Punto1.y)
print(Punto2.x)
print(Punto2.y)

Punto1.inicializar()
Punto2.cambiar(5,0)
print(Punto1.x)
print(Punto1.y)
print(Punto2.x)
print(Punto2.y)
print(Punto2.calcular_distancia(Punto1))
Punto1.cambiar(3,4)
print(Punto1.calcular_distancia(Punto2))
print(Punto1.calcular_distancia(Punto1))

Punto3 = Punto() # Se invoca el constructor
print(Punto3.x)
print(Punto3.y)

# Ejemplo de conducta de clase
class Estado():
    def __init__(self, nombre, estado):
        self.nombre = nombre
        self.estado = estado 
               
    def activado(self):
        print(self.nombre.title() + " está ahora encendido.")
        self.estado=1
        
    def apagado(self):
        self.estado=0
        print(self.nombre.title() + " se apagado!")
        

control1 = Estado('Máquina1', 1)
control2 = Estado('Máquina2', 0)

print("El nombre en el control 1  es " + control1.nombre.title() + ".")
print("El estado en el control 2 es " + str(control2.estado) + " de operación.")
control1.activado()

print("El control2 está asociado a " + control2.nombre.title() + ".")
print("El control2 está en estado " + str(control2.estado) + " de operación.")



# HERENCIA EN PYTHON
# Clase Base
class Carro():
    def __init__(self, fabricante, modelo, anno):
        self.fabricante = fabricante
        self.modelo = modelo
        self.anno = anno
        self.kilometraje = 0     
          
    def obtener_nombre_completo(self):
        nombre_completo = self.fabricante + ' ' + str(self.anno) + ' ' + self.modelo
        return nombre_completo.title()   
      
    def lee_kilometraje(self):
        print("Este carro tiene " + str(self.kilometraje) + " kilometros recorridos.")     
         
    def modifica_kilometraje(self, kilometros):
        if kilometros >= self.kilometraje:
            self.kilometraje = kilometros
        else:
            print("Usted no puede modificar para atrás el kilometraje!")
            
    def incrementa_kilometraje(self, kilometros):
        self.kilometraje += kilometros

# Clase derivada o clase hija
class Carro_Electrivo(Carro):
    def __init__(self, fabricante, modelo, anno):
        super().__init__(fabricante, modelo, anno)
        self.capacidad_bateria = 70
        
    def describe_bateria(self):
        print("Este carro tiene una bateria de capacidad " + str(self.capacidad_bateria) + "-kWh.")
        
        
Tesla = Carro_Electrivo('tesla', 'modelo S', 2018)
print(Tesla.obtener_nombre_completo())
Tesla.describe_bateria()


# Relaciones de Componente-Compuesto
class Bateria():
    def __init__(self, capacidad = 70, marca = "LTH"):
        self.capacidad = capacidad
        self.marca = marca
        
    def describe(self):
        print("Este carro tiene una batería marca " + self.marca + " de capacidad " + str(self.capacidad) + "-kWh.")

mi_bateria = Bateria(90, "Hitachi")
mi_bateria.describe()

# Clase Base
class Carro1():
    def __init__(self, fabricante, modelo, anno):
        self.fabricante = fabricante
        self.modelo = modelo
        self.anno = anno
        self.kilometraje = 0     
          
    def obtener_nombre_completo(self):
        nombre_completo = self.fabricante + ' ' + str(self.anno) + ' ' + self.modelo
        return nombre_completo.title() 
        
    def lee_kilometraje(self):
        print("Este carro tiene " + str(self.kilometraje) + " kilometros recorridos.")    
          
    def modifica_kilometraje(self, kilometros):
        if kilometros >= self.kilometraje:
            self.kilometraje = kilometros
        else:
            print("Usted no puede modificar para atrás el kilometraje!")
            
    def incrementa_kilometraje(self, kilometros):
        self.kilometraje += kilometros

# Clase derivada o clase hija
class Carro_Electrico(Carro1):
    def __init__(self, fabricante, modelo, anno, capacidad_bateria, marca_bateria):
        super().__init__(fabricante, modelo, anno)
        self.bateria = Bateria(capacidad_bateria, marca_bateria)        
        
Tesla = Carro_Electrico('tesla', 'modelo S', 2018, 65, "Hitachi")
print(Tesla.obtener_nombre_completo())
Tesla.bateria.describe()

# Encapsulación en Python
# Atributos y Métodos privados

# Atributo dato público
class Prueba1:
        def __init__(self):
            self.dato = 1
 
tempo = Prueba1()
tempo.dato


# Un atributo privado solo puede ser usado por los métodos de la propia clase
# Se deben usar dos guiones bajos al inicio del nombre del atributo
class Prueba2(object):
        def __init__(self):
            self.__dato = 1
            
        def obtener_dato(self):
            return self.__dato
 
tempo = Prueba2()
tempo.obtener_dato()
# La siguiente línea no puede usarse ya que sigue dando error de acceso a partes atributos privados
###   tempo.__dato 



# Métodos GETTERS AND SETTERS (Obtener y Modificar)
class Prueba3(object):
        def __init__(self):
            self.__dato = 1
            
        def obtener_dato(self):
            return self.__dato
          
        def modificar_dato(self,nuevo_dato):
            self.__dato = nuevo_dato
        
tempo = Prueba3()
print(tempo.obtener_dato())
tempo.modificar_dato(-3)
print(tempo.obtener_dato())


class Prueba4(object):
        def __init__(self):
            self.__dato = 1
            
        def obtener_dato(self):
            print("Pasó por obtener")
            return self.__dato
          
        def modificar_dato(self,nuevo_dato):
            print("Pasó por modificar")
            self.__dato = nuevo_dato
            
        dato = property(obtener_dato,modificar_dato)
            
tempo = Prueba4()
tempo.obtener_dato()
tempo.modificar_dato(-3)
tempo.obtener_dato()

print("Ahora por decorador")
tempo.dato=10
print(tempo.dato)

# La instrucción "dato = property(obtener_dato,modificar_dato)" hace que Python
# conozca que los métodos obtener_dato() y modificar_dato() son los
# get y set del atributo "dato".

# Todavía mejor como sigue:

class Prueba5(object):
        def __init__(self):
            self.__dato = 1
            
        @property
        def dato(self):
            print("Pasó por obtener")
            return self.__dato
          
        @dato.setter
        def dato(self, nuevo_dato):
            print("Pasó por modificar")
            if nuevo_dato > 100:
                raise ValueError("El dato debe ser menor o igual a 100")
            self.__dato = nuevo_dato
 
tempo = Prueba5()
print(tempo.dato)

tempo.dato = 3
print(tempo.dato)
## tempo.dato = 200 # Da error controlado

# MÉTODOS PRIVADOS
# Los métodos pueden hacerse privados de la misma manera, 
# nombrándolos con dos guiones bajos principales y sin guiones bajos posteriores.
# Un método privado se puede usar solamente dentro de otro método de la misma clase.

class Prueba6():
    def __init__(self, nombre):
        self.__hola = "Hola"
        self.nombre = nombre
        
    def __decir_hola(self):
        print(self.__hola)
        
    def decir_hola(self):
        print(self.nombre + ' ' + "te dice" )
        self.__decir_hola()
 
tempo = Prueba6("Luis")
##tempo.__decir_hola() # Da error pues es un método privado
tempo.decir_hola()

# Más sobre el uso de Python @property

# Clase para covertir Celsius a  farenheit
class Celsius:
    def __init__(self, temperatura = 0):
        self.temperatura = temperatura
        
    def convierte_farenheit(self):
        return (self.temperatura * 1.8) + 32

instancia = Celsius()
# set temperatura
instancia.temperatura = 37
# get temperatura
instancia.temperatura
# Convierte la temperatura
instancia.convierte_farenheit()

# Métodos Get (Obtener) y Set (Modificar) al estilo C++ o Java
class Celsius1:
    def __init__(self, temperatura = 0):
        self.modificar_temperatura(temperatura)
        
    def convierte_farenheit(self):
        return (self.obtener_temperatura() * 1.8) + 32
      
    def obtener_temperatura(self):
        return self._temperatura
      
    def modificar_temperatura(self, nuevo_valor):
        if nuevo_valor < -273:
            raise ValueError("Una temperatura por debajo de -273 no es posible")
        self._temperatura = nuevo_valor

##  c = Celsius1(-277)  # Da el error controlado
c = Celsius1(37)
c.obtener_temperatura()
c.modificar_temperatura(10)
c.obtener_temperatura()


# Versión Usando property al verdadero estilo Python
class Celsius2:
    def __init__(self, temperatura = 0):
        self.__temperatura = temperatura
        
    def convierte_farenheit(self):
        return (self.temperatura * 1.8) + 32
      
    def obtener_temperatura(self):
        print("Obteniendo el valor")
        return self.__temperatura
      
    def modificar_temperatura(self, nuevo_valor):
        if nuevo_valor < -273:
            raise ValueError("Una temperatura por debajo de -273 no es posible")
        print("Modificando el valor")
        self.__temperatura = nuevo_valor
        
    temperatura = property(obtener_temperatura,modificar_temperatura)
    

c = Celsius2()
c.temperatura
c.temperatura = 39
c.convierte_farenheit()

# Una forma más transparente de hacer lo anterior y que permite usar el mismo 
# nombre en el método que el del atributo es la siguiente:

class Celsius3:
    def __init__(self, temperatura = 0):
        self.__temperatura = temperatura
        
    def convierte_farenheit(self):
        return (self.temperatura * 1.8) + 32
      
    @property
    def temperatura(self):
        print("Obteniendo el valor")
        return self.__temperatura
      
    @temperatura.setter
    def temperatura(self, nuevo_valor):
        if nuevo_valor < -273:
            raise ValueError("Una temperatura por debajo de -273 no es posible")
        print("Retornando el valor")
        self.__temperatura = nuevo_valor

c = Celsius3()
c.temperatura
c.temperatura = 37
c.temperatura
c.convierte_farenheit()




# EJEMPLO: Mi propio Data Frame usando Componente-Compuesto 

import pandas as pd
import numpy as np

class mi_DF():
    def __init__(self, DF = pd.DataFrame()):
        self.__num_filas = DF.shape[0]
        self.__num_columnas = DF.shape[1]
        self.__DF = DF
        
    @property
    def num_filas(self):
        return self.__num_filas
      
    @property
    def num_columnas(self):
        return self.__num_columnas
      
    @property
    def DF(self):
        return self.__DF  
      
    def maxximo(self):
        maxx = self.DF.iloc[0,0]
        for i in range(self.num_filas):
            for j in range(self.num_columnas):
                if self.DF.iloc[i,j] > maxx:
                    maxx = self.DF.iloc[i,j]
        return maxx
      
    def valores(self):
        minx = self.DF.iloc[0,0]
        maxx = self.DF.iloc[0,0]
        total_ceros = 0
        total_pares = 0
        for i in range(self.num_filas):
            for j in range(self.num_columnas):
                if self.DF.iloc[i,j] > maxx:
                    maxx = self.DF.iloc[i,j]
                if self.DF.iloc[i,j] < minx:
                    minx = self.DF.iloc[i,j]
                if self.DF.iloc[i,j] == 0:
                    total_ceros = total_ceros+1
                if self.DF.iloc[i,j] % 2 == 0:
                    total_pares = total_pares+1
        return {'maxximo' : maxx, 'minximo' : minx, 'Total_Ceros' : total_ceros, 'Pares' : total_pares}
      
    def estadisticas(self,nc):
        media = np.mean(self.DF.iloc[:,nc])
        mediana = np.median(self.DF.iloc[:,nc])
        deviacion = np.std(self.DF.iloc[:,nc])
        varianza = np.var(self.DF.iloc[:,nc])
        maxximo = np.max(self.DF.iloc[:,nc])
        minximo = np.min(self.DF.iloc[:,nc])
        return {'Variable' : self.DF.columns.values[nc],
                'Media' : media,
                'Mediana' : mediana,
                'DesEst' : deviacion,
                'Varianza' : varianza,
                'maxximo' : maxximo,
                'minximo' : minximo}
      

datos = mi_DF(pd.DataFrame([[4,1,-3],[2,4.4,0],[-5,9,198],[2,4,-5]]))
print(datos.num_filas)
print(datos.num_columnas)
print(datos.DF)
print(datos.maxximo())
print(datos.valores())
print(datos.estadisticas(1))

# Leyendo un archivo CSV
datos_est = pd.read_csv('../Datos/EjemploEstudiantes.csv',delimiter=';',decimal=",",index_col=0)
datos = mi_DF(datos_est)
print(datos.num_filas)
print(datos.num_columnas)
print(datos.DF)
print(datos.maxximo())
print(datos.valores())





import math
from math import sqrt

class Complex(object):
    def __init__(self, real, imag=0.0):
        self.real = real
        self.imag = imag
        # Formats our results
        print(self.real + self.imag)

    def __add__(self, other):
        print('\nSum:')
        return Complex(self.real + other.real, self.imag + other.imag)

    def __sub__(self, other):
        print('\nDifference:')
        return Complex(self.real - other.real, self.imag - other.imag)
    
    def __mul__(self, other):
        print('\nProduct:')
        return Complex((self.real * other.real) - (self.imag * other.imag),
            (self.imag * other.real) + (self.real * other.imag))

    def __truediv__(self, other):
        print('\nQuotient:')
        r = (other.real**2 + other.imag**2)
        return Complex((self.real*other.real - self.imag*other.imag)/r,
            (self.imag*other.real + self.real*other.imag)/r)

    def __abs__(self):
        print('\nAbsolute Value:')
        new = (self.real**2 + (self.imag**2)*-1)
        return Complex(sqrt(new.real))


i = Complex(2, 10j)
k = Complex(3, 5j)

print(i + k)
print(i - k)
print(i * k)
print(i / k)
print(abs(i))
print(abs(k))
