'''
Created on Jan 29, 2021 

@author: freddy
'''

# Clases base abstractas
import sys
from abc import  ABCMeta, abstractmethod

# Clase Abstracta, ABC Class
class Base(metaclass=ABCMeta):
    @abstractmethod
    def __str__(self):
        pass    

    @abstractmethod
    def Captura(self):
        pass


class BaseIO(object):
    def Input(self, info=""):
        return input(info)


       
class BaseIO(object):
    def Input(self, info=""):
        print(info)
        result = sys.stdin.readline().strip()
        print(result)
        return result


from dateutil import parser

class Pasajero(Base, BaseIO): 
    def __init__(self):
        self.__Codigo = 0
        self.__Nombre = ""
        self.__PrecioTiquete = 0.0
        self.__PorcentajeImpuesto = 0.0

    def __str__(self):
        return ("Código: %i\nPasajero %s\nPrecio tiquete %.2f\nImpuestos %.2f (%%)\nTotal a pagar %.2f\n" 
                 % (self.__Codigo, self.__Nombre, self.__PrecioTiquete,
                 self.__PorcentajeImpuesto * 100, self.TotalPagar()) 
                )

    def Captura(self):
        self.__Nombre = self.Input("Nombre del Pasajero:")
        self.__Codigo = int(self.Input("Código de pasajero:"))
        self.__PrecioTiquete = float(self.Input("Precio del tiquete a pagar ($):"))
        self.__PorcentajeImpuesto = float(self.Input("Porcentaje de impuestos (%):")) / 100.0
        
    @property
    def Codigo(self):
        return self.__Codigo
    
    @Codigo.setter
    def Codigo(self, Codigo):
        self.__Codigo = Codigo
        
    @property
    def Nombre(self):
        return (self.__Nombre)
            
    @property
    def PrecioTiquete(self):
        return self.__PrecioTiquete
    
    @PrecioTiquete.setter
    def PrecioTiquete(self, precioTiquete):
        self.__PrecioTiqueteo = precioTiquete
 
    @property
    def PorcentajeImpuesto(self):
        return self.__PorcentajeImpuesto
    
    @PorcentajeImpuesto.setter
    def PorcentajeImpuesto(self, porcentajeImpuesto):
        self.__PorcentajeImpuesto = porcentajeImpuesto      
        
    def TotalPagar(self):
        return (self.__PrecioTiquete + self.__PorcentajeImpuesto * 
                self.__PrecioTiquete)


# Clase heredada de pasajeros
############################
class PasajeroFrecuente(Pasajero):
    def TotalPagar(self):
        super().__init__()
        return super().TotalPagar() * 0.8
     

# Clases Vuelo
#################
class Vuelo(Base, BaseIO) :
    def __init__(self):
        self.__Numero = 0
        self.__HoraSalida = parser.parse("Apr 2 2018 12:00AM")
        self.__HoraLlegada = parser.parse("Apr 2 2018 12:00AM")
        self.__lista = list()

    # Método polimórfico para extender str y obtener _str_ de clases hijas        
    @abstractmethod
    def __extstr__(self):
      pass
   
    # Método polimórfico para extender Captura y obtener nuevas entradas de clases hijas        
    @abstractmethod
    def __extCaptura__(self):
      pass
     
    @property
    def NumeroVuelo(self) :
      return self.__Numero
    
    @NumeroVuelo.setter
    def NumeroVuelo(self, numero) :
      self.__Numero = numero
      
    @property
    def HoraSalida(self) :
      return self.__Hora_salida
    
    @HoraSalida.setter
    def HoraSalida(self, horaSalida) :
      self.__HoraSalida = horaSalida 

    @property
    def HoraLlegada(self) :
      return self.__Hora_llegada
    
    @HoraLlegada.setter
    def Hora_llegada(self, horaLlegada) :
      self.__HoraLlegada = horaLlegada      
  
    def __str__(self):
        hora1 = str(self.__HoraSalida)
        hora2 = str(self.__HoraLlegada)
        DatosVuelo = ("Número Vuelo: %s\nHora Salida %s\nHora Llegada %s\n" 
                 % (self.__Numero, hora1, hora2))
        DatosVuelo += "Venta total del vuelo =%.2f\n" % (self.TotalVendido())
        DatosVuelo += self.__extstr__() + "\n"  # Obtiene atributos exdendidos según la clase hija
        for p in self.__lista: 
            DatosVuelo += str(p)   
        return(DatosVuelo)

    def Captura(self):
        self.__Numero = self.Input("Número de Vuelo:")
        self.__HoraSalida = parser.parse(self.Input("Fecha y hora Salida  (Apr 2 2018 12:00AM): "))
        self.__HoraLlegada = parser.parse(self.Input("Fecha y hora llegada (Apr 2 2018 12:00AM): "))
        self.__extCaptura__()

    def AssignarListaPasajeros(self, lista):
        self.__lista = lista
    
    def TotalVendido(self):
        total = 0.0
        for p in self.__lista: 
            total += p.TotalPagar()
        return total

        
# Clase heredada VueloLocal
############################
class VueloLocal(Vuelo) :
    def __init__(self):
        super().__init__()
        self.__Numero_minimo_pasajeros = 10
        
    def __extCaptura__(self):
        self.__Numero_minimo_pasajeros = int(self.Input("Numero mínimo de pasajeros: "))
        
    def __extstr__(self):
        return "Número mínimo de pasajeros: %i" % (self.__Numero_minimo_pasajeros)

        
# Clase heredada  VueloInternacional
#####################################
class VueloInternacional(Vuelo):
    def __init__(self):
        super().__init__()
        self.__PaisDestino = ""

    def __extCaptura__(self):
        self.__PaisDestino = self.Input("País destino: ")
        
    def __extstr__(self):
        return "País destino: %s" % (self.__PaisDestino)

 
# Clases VueloCarga
####################    
class VueloCarga(Vuelo):
    def __init__(self):
        super().__init__()
        self.__PesoMaximo_carga = 500.0

    def __extCaptura__(self):
        self.__PesoMaximo_carga = float(self.Input("Peso de carga máximo: "))

    def __extstr__(self):
        return "Peso máximo: %f" % (self.__PesoMaximo_carga)  


# #CONTENEDOR DE APPLLICACION
class AppVuelos(BaseIO):
    def __init__(self):
        self.__lista = list()
        
    def __menuPasajeros(self):
        print(" ==================================================== ")
        print(" [1] Insertar Pasajero frecuente")
        print(" [2] Insertar Pasajero no frecuente")
        print(" [3] Ver Pasajeros en vuelo")
        print(" [4] Borrar lista completa de pasajeros")
        print(" [0] Salir y retornar lista")
        print(" ==================================================== ")
        return self.Input("> ")
    
    def __EnlistarPasajeros(self, Vuelo):
        lista = list()
        respuesta = ""
        while respuesta != "0":
            respuesta = self.__menuPasajeros()
            if respuesta == "1":
                print("Asigando pasajero frecuente a vuelo local número %s" % Vuelo)
                pasajero = PasajeroFrecuente()
                pasajero.Captura()
                lista.append(pasajero)
                
            elif respuesta == "2":
                print("Asigando pasajero NO frecuente a vuelo local número %s" % Vuelo)
                pasajero = Pasajero()
                pasajero.Captura()
                lista.append(pasajero)
                
            elif respuesta == "3":
                print("Mostrando lista de pasajeros a vuelo local número %s" % Vuelo)
                for i in range(len(lista)):
                    print(lista[i])
                self.Input("Digite cualquier tecla para continuar") 
            
            elif respuesta == "4":
                print("Se ha borrado la lista de pasajeros del local número %s" % Vuelo)
                lista.clear()
                self.Input("Digite cualquier tecla para continuar") 
        return lista
      
    def __menuPrincipal(self):
        print(" ==================================================== ")
        print(" [1] Insertar vuelo local (con pasajeros)")
        print(" [2] Insertar vuelo internacional (con pasajeros)")
        print(" [3] Insertar vuelo carga")
        print(" [4] Ver vuelos")
        print(" [5] Borrar lista completa de vuelos")
        print(" [0] Salir")
        print(" ==================================================== ")
        return self.Input("> ")
    
    def __mostrarLista(self):
        for i in range(len(self.__lista)):
            print(self.__lista[i])
      
    def RUN(self):
        respuesta = ""
        while respuesta != "0":
            respuesta = self.__menuPrincipal()
            if respuesta == "1":
                print("Asingando vuelo local")
                vuelo_local = VueloLocal()
                vuelo_local.Captura()
                pasajeros = self.__EnlistarPasajeros(vuelo_local.NumeroVuelo)
                vuelo_local.AssignarListaPasajeros(pasajeros)
                self.__lista.append(vuelo_local)
                
            elif respuesta == "2":
                print("Asingando vuelo internacional")
                vuelo_internacional = VueloInternacional()
                vuelo_internacional.Captura()
                pasajeros = self.__EnlistarPasajeros(vuelo_internacional.NumeroVuelo)
                vuelo_internacional.AssignarListaPasajeros(pasajeros)
                self.__lista.append(vuelo_internacional)
                
            elif respuesta == "3":
                print("Asingando vuelo de carga")
                vuelo_carga = VueloCarga()
                vuelo_carga.Captura()
                self.__lista.append(vuelo_carga)
                
            elif respuesta == "4":
                print("Ver todos los vuelos detallados")
                self.__mostrarLista()
                self.Input("Digite cualquier tecla para continuar")
                
            elif respuesta == "5":
                print("Borrando lista de los vuelos")
                self.__lista.clear()




print("\nEvaluacón problema 2\n++++++++++++++++++\n")

def RUN() :
  TestingVuelos = AppVuelos()
  TestingVuelos.RUN()

from contextlib import contextmanager
@contextmanager
def custom_redirection(fileobj_in, fileobj_out):
    old_in = sys.stdin
    old_out = sys.stdout
    sys.stdin = fileobj_in
    sys.stdout = fileobj_out
    try:
        yield fileobj_in
    finally:
        sys.stdin = old_in
        sys.stdout = old_out
 
    
if __name__ == '__main__':
    with open('../Datos/python_outputEje2.txt', 'w',encoding = 'utf8') as outputs:
      with open('../Datos/EntradaEje2.txt', 'r',encoding = 'utf8') as inputs :
        with custom_redirection(inputs, outputs):
            print('Programa con I/O redirigido inicia...\n++++++++++++++++++++++++++++++++++++++++\n')
            RUN()
            print('Programa con I/O redirigido termina \n++++++++++++++++++++++++++++++++++++++++\n')
    print('Este mensaje sale por stdout')
 

print('++++ RESULTADO +++++')
with open('../Datos/EntradaEje2.txt', 'r',encoding = 'utf8') as myfile:
  data = myfile.read()
print(data)
         

print('++++ RESULTADO +++++')
with open('../Datos/python_outputEje2.txt', 'r',encoding = 'utf8') as myfile:
  data = myfile.read()
print(data)
