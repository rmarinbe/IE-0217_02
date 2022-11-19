'''
Created on Jan 29, 2021

@author: freddy
'''

# Clases base abstractas
import sys
from abc import  ABCMeta, abstractmethod

## Clase Abstracta, ABC Class
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

    

# Clase Compra
############################
class Compra(Base, BaseIO):
    def __init__(self) :
        self.__Codigo = 0
        self.__Descripcion = ""
        self.__MontoCompras = 0.0
        
    @property 
    def Codigo(self) :
        return(self.__Codigo)
        
    @Codigo.setter    
    def Codigo(self, codigo) :
        self.__Codigo = codigo 
    
    @property 
    def Descripcion(self) :
        return (self.__Descripcion)
        
    @Descripcion.setter    
    def Descripcion(self, descripcion) :
        self.__Descripcion = descripcion

    @property 
    def MontoCompras(self) :
        return(self.__MontoCompras)
        
    @MontoCompras.setter    
    def MontoCompras(self, monto_compras) :
        self.__MontoCompras = monto_compras
        
    def __str__(self):
        return ("Código de compra: %s\nDescripción de compra %s\nMontoCompra %.2f\n" 
                 % (self.__Codigo, self.__Descripcion, self.__MontoCompras) 
              )
         
    def Captura(self):
        self.__Codigo = int(self.Input("Código de compra: "))
        self.__Descripcion = self.Input("Descripción de compra: ")
        self.__MontoCompras = float(self.Input("MontoCompra: "))
       

# Clase Cliente
############################
class Cliente(Base, BaseIO):
    def __init__(self) :
        self.__NombreCliente = ""
        self.__DireccionCliente = ""
        self.__Compras = list()
        
    @property 
    def NombreCliente(self) :
        return(self.__NombreCliente)
        
    @NombreCliente.setter    
    def NombreCliente(self, nombre_cliente) :
        self.__NombreCliente = nombre_cliente 
 
    @property 
    def DireccionCliente(self) :
        return(self.__DireccionCliente)
        
    @DireccionCliente.setter    
    def DireccionCliente(self, direccion_cliente) :
        self.__DireccionCliente = direccion_cliente 
    
    def __str__(self):
        return ("Nombre del Cliente: %s\nDirección del Cliente: %s\n" 
                 % (self.__NombreCliente, self.__DireccionCliente) 
                )
         
    def Captura(self):
        self.__NombreCliente = self.Input("Nombre del Cliente: ")
        self.__DireccionCliente = self.Input("Dirección del Cliente: ")

       
# Clase Factura
############################
class Factura(Base, BaseIO) :

    def __init__(self) :
        self.__Codigo = 0
        self.__Cliente = Cliente()
        self.__Monto = 0.0
        self.__PorcentajeImpuesto = 0.0
        self.__Compras = list()

    # Método polimórfico para extender str y obtener _str_ de clases hijas        
    @abstractmethod
    def __extstr__(self):
        pass
   
    # Método polimórfico para extender Captura y obtener nuevas entradas de clases hijas        
    @abstractmethod
    def __extCaptura__(self):
        pass
   
    @abstractmethod
    def __AjustarMonto__(self):
        pass
    
    @property 
    def Codigo(self) :
        return(self.__Codigo)
        
    @Codigo.setter    
    def Codigo(self, codigo) :
        self.__Codigo = codigo
    
    @property 
    def Cliente(self) :
        return(self.__Cliente)

    @property 
    def Monto(self) :
        return(self.__Monto)
        
    @Monto.setter    
    def Monto(self, monto) :
        self.__Monto = monto

    @property 
    def PorcentajeImpuesto(self) :
        return(self.__PorcentajeImpuesto)
        
    @PorcentajeImpuesto.setter    
    def PorcentajeImpuesto(self, porcentaje_impuesto) :
        self.__PorcentajeImpuesto = porcentaje_impuesto
         
    def TotalPagar(self) :
        total = self.__Monto + self.__PorcentajeImpuesto * self.__Monto
        return (total)              
        
    def __str__(self):
        Resultado = "Código: %i\n" % (self.__Codigo)
        Resultado += self.__extstr__() + "\n"  # Obtiene atributos exdendidos según la clase hija
        Resultado += str(self.__Cliente)
        Resultado += ("Monto sin Impuesto %.2f\nImpuestos %.2f (%%)\nTotal a pagar %.2f\n" 
                     % (self.__Monto, self.__PorcentajeImpuesto * 100.0, self.TotalPagar()) 
                    )
        return Resultado
         
    def Captura(self):
        self.__Codigo = int(self.Input("Número de factura:"))
        self.__extCaptura__()  # Obtiene atributos exdendidos según la clase hija
        cliente = Cliente()
        cliente.Captura()
        self.__Cliente = cliente
        self.__Monto = 0.0
        self.__PorcentajeImpuesto = float(self.Input("Porcentaje de impuestos (%):")) / 100.0
        
    def AssignarListaCompras(self, listaCompras):
        self.__Compras = listaCompras
        self.__Monto = 0.0
        for i in range(len(listaCompras)):
            self.__Monto += listaCompras[i].MontoCompras
        self.__AjustarMonto__()


class FacturaCredito(Factura) :

        def __init__(self) :
            super().__init__()
            self.__Plazo = 0
            
        @property 
        def Plazo(self) :
            return(self.__Plazo)
            
        @Plazo.setter    
        def Plazo(self, plazo) :
            self.__Plazo = plazo

        def __extCaptura__(self):
            self.__Plazo = int(self.Input("Plazo de crédito de factura: "))
            
        def __extstr__(self):
            return "Plazo de crédito de factura: %i" % (self.__Plazo) 
        
        def __AjustarMonto__(self):
            self.Monto = self.Monto


class FacturaContado(Factura) :

        def __init__(self) :
            super().__init__()
            self.__PorcentajeDescuento = 0
            
        @property 
        def PorcentajeDescuento(self) :
            return(self.__PorcentajeDescuento)
            
        @PorcentajeDescuento.setter    
        def PorcentajeDescuento(self, porcentaje_descuento) :
            self.__PorcentajeDescuento = porcentaje_descuento

        def __extCaptura__(self):
            self.__PorcentajeDescuento = float(self.Input("Porcentaje de descuento: ")) / 100
            
        def __extstr__(self):
            return "Porcentaje de descuento:: %i" % (self.__PorcentajeDescuento * 100)
        
        def __AjustarMonto__(self):
            self.Monto = self.Monto - self.__PorcentajeDescuento * self.Monto


           
# #CONTENEDOR DE APPLLICACION
class AppFacturacion(BaseIO):

    def __init__(self):
        self.__facturas = list()
        
    def __menuCompras(self):
        print(" ==================================================== ")
        print(" [1] Insertar Compra")
        print(" [2] Ver Compras ")
        print(" [3] Borrar todas las compras")
        print(" [0] Salir y retornar lista de compras de factura")
        print(" ==================================================== ")
        return self.Input("> ")
    
    def __AgregarCompras(self, numero_factura):
        lista = list()
        respuesta = ""
        while respuesta != "0":
            respuesta = self.__menuCompras()
            if respuesta == "1":
                print("Agregando compra a factura número %s" % numero_factura)
                compra = Compra()
                compra.Captura()
                lista.append(compra)
                
            elif respuesta == "2":
                print("Mostrando todas las compras de factura número %s" % numero_factura)
                for i in range(len(lista)):
                    print(lista[i])
                self.Input("Digite cualquier tecla para continuar") 
            
            elif respuesta == "3":
                print("Se ha borrado la lista de pasajeros del local número %s" % numero_factura)
                lista.clear()
                self.Input("Digite cualquier tecla para continuar") 
                
        return lista
      
    def __menuPrincipal(self):
        print(" ==================================================== ")
        print(" [1] Insertar factura de Crédito")
        print(" [2] Insertar factura de Contado")
        print(" [3] Ver todas las facturas")
        print(" [4] Borrar lista completa de facturas")
        print(" [0] Salir")
        print(" ==================================================== ")
        return self.Input("> ")
    
    def __mostrarLista(self):
        for i in range(len(self.__facturas)):
            print(self.__facturas[i])
            
    def RUN(self):
        respuesta = ""
        while respuesta != "0":
            respuesta = self.__menuPrincipal()
            if respuesta == "1":
                print("Insertando factura de crédito")
                factura_credito = FacturaCredito()
                factura_credito.Captura()
                compras = self.__AgregarCompras(factura_credito.Codigo)
                factura_credito.AssignarListaCompras(compras)
                self.__facturas.append(factura_credito)
                
            elif respuesta == "2":
                print("Insertando factura de contado")
                factura_contado = FacturaContado()
                factura_contado.Captura()
                compras = self.__AgregarCompras(factura_contado.Codigo)
                factura_contado.AssignarListaCompras(compras)
                self.__facturas.append(factura_contado)
                
            elif respuesta == "3":
                print("Ver todas las facturas detallados")
                self.__mostrarLista()
                self.Input("Digite cualquier tecla para continuar")
                
            elif respuesta == "4":
                print("Borrando lista de todas las facturas")
                self.__facturas.clear()



print("\nEvaluación problema 1\n++++++++++++++++++\n")
def RUN() :
  TestingFacturacion = AppFacturacion()
  TestingFacturacion.RUN()



from contextlib import contextmanager
  
@contextmanager
def custom_redirection(fileobj_in,fileobj_out):
    old_in = sys.stdin
    old_out = sys.stdout
    sys.stdin = fileobj_in
    sys.stdout = fileobj_out
    try:
        yield fileobj_in
    finally:
        sys.stdin =  old_in
        sys.stdout = old_out
    
if __name__ == '__main__':
    with open('../Datos/python_outputEje1.txt', 'w',encoding = 'utf8') as outputs:
      with open('../Datos/EntradaEje1.txt', 'r',encoding = 'utf8') as inputs :
        with custom_redirection(inputs, outputs):
            print('Programa con I/O redirigido inicia...\n++++++++++++++++++++++++++++++++++++++++\n')
            RUN()
            print('Programa con I/O redirigido termina \n++++++++++++++++++++++++++++++++++++++++\n')
print('Este mensaje sale por stdout')
 

     
print("Archivo de entrada de datos...")
with open('../Datos/EntradaEje1.txt', 'r',encoding = 'utf8') as myfile:
  data = myfile.read()
  print(data)    
   

print("Archivo de salida de ejecución...")
with open('../Datos/python_outputEje1.txt', 'r',encoding = 'utf8') as myfile:
  data = myfile.read()
  print(data)    

