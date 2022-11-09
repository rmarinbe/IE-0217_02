'''
Created on Jan 29, 2021

@author: freddy
'''

#%%
class SuenaAudio:
    def __init__(self, nombre_archivo):
        if not nombre_archivo.endswith(self.ext):  # El atributo no existe en la clase SuenaAudio, pero forma parte el objeto self ya que por herencia es accesible (debe ser publico)
            raise Exception("formato invalido")
        self.nombre_archivo = nombre_archivo

class SuenaMP3(SuenaAudio):
    ext = "mp3"
    def suena(self):
        print("Sonando {} como un mp3".format(self.nombre_archivo))

class SuenaWav(SuenaAudio):
    ext = "wav"
    def suena(self):
        print("Sonando {} como un wav".format(self.nombre_archivo))

class SuenaOgg(SuenaAudio):
    ext = "ogg"
    def suena(self):
        print("Sonando {} como un ogg".format(self.nombre_archivo))
        
   
ogg = SuenaOgg("archivo.ogg")
ogg.suena()

mp3 = SuenaMP3("archivo.mp3")
mp3.suena()

no_mp3 = SuenaMP3("archivo.ogg")

#%%
# Ejemplo Herencia Múltiple - Versión 1
class ClaseBase:
    num_llamados_base = 0
    def metodo_ejemplo(self):
        print("Llamando metodo_ejemplo en clase Base")
        self.num_llamados_base += 1

class SubclaseIzquierda(ClaseBase):
    num_llamados_izquierda = 0
    def metodo_ejemplo(self):
        ClaseBase.metodo_ejemplo(self)
        print("Llamando metodo_ejemplo en SubclaseIzquierda desde SubclaseFinal")
        self.num_llamados_izquierda += 1

class SubclaseDerecha(ClaseBase):
    num_llamados_derecha = 0
    def metodo_ejemplo(self):
        ClaseBase.metodo_ejemplo(self)
        print("Llamando metodo_ejemplo en SubclaseDerecha desde SubclaseFinal")
        self.num_llamados_derecha += 1
        
class SubclaseFinal(SubclaseIzquierda, SubclaseDerecha):
    num_llamados_final = 0
    def metodo_ejemplo(self):
        SubclaseIzquierda.metodo_ejemplo(self)
        SubclaseDerecha.metodo_ejemplo(self)
        print("Llamando metodo_ejemplo desde SubclaseFinal")
        self.num_llamados_final += 1  
        
s = SubclaseFinal()
s.metodo_ejemplo()
print(s.num_llamados_final,s.num_llamados_izquierda,s.num_llamados_derecha,s.num_llamados_base)

#%%


# Ejemplo Herencia Múltiple - Versión 2 

class ClaseBase:
    num_llamados_base = 0
    def metodo_ejemplo(self):
        print("Llamando metodo_ejemplo en Base Class")
        self.num_llamados_base += 1

class SubclaseIzquierda(ClaseBase):
    num_llamados_izquierda = 0
    def metodo_ejemplo(self):
        super().metodo_ejemplo()
        print("Llamando metodo_ejemplo en Left SubclaseFinal")
        self.num_llamados_izquierda += 1

class SubclaseDerecha(ClaseBase):
    num_llamados_derecha = 0
    def metodo_ejemplo(self):
        super().metodo_ejemplo()
        print("Llamando metodo_ejemplo en Right SubclaseFinal")
        self.num_llamados_derecha += 1
        
class SubclaseFinal(SubclaseIzquierda, SubclaseDerecha):
    num_llamados_final = 0
    def metodo_ejemplo(self):
        super().metodo_ejemplo()
        print("Llamando metodo_ejemplo en SubclaseFinal")
        self.num_llamados_final += 1  
        
s = SubclaseFinal()
s.metodo_ejemplo()
print(s.num_llamados_final,s.num_llamados_izquierda,s.num_llamados_derecha,s.num_llamados_base)

#%%


import os
from abc import  ABCMeta, abstractmethod
# Clase Abstracta, ABC Class
class Base(metaclass = ABCMeta):    
    @abstractmethod
    def __str__(self):
        pass    
    @abstractmethod
    def Captura(self):
        pass
      


class Libro(Base):
    def __init__(self,nombre = "",anio = 0):
        self.__nombre = nombre
        self.__anio = anio  
    @property
    def nombre(self):
        return self.__nombre
    @property
    def anio(self):
        return self.__anio 
    @nombre.setter
    def nombre(self, nuevo_nombre):
        self.__nombre = nuevo_nombre     
    @anio.setter
    def anio(self, nuevo_anio):
        self.__anio = nuevo_anio 
    # Los siguientes métodos usan los set y get NO los atributos       
    def __str__(self):
        return "Nombre del Libro: %s\nAño: %i" % (self.nombre, self.anio)
    def Captura(self):
        self.nombre = input("Nombre del Libro:")
        self.anio = int(input("Año del Libro:"))
  
  
class Persona(Base):
    def __init__(self,nombre = "", edad = 0):
        self.__nombre = nombre
        self.__edad = edad
    @property
    def nombre(self):
        return self.__nombre
    @property
    def edad(self):
        return self.__edad  
    @nombre.setter
    def nombre(self, nuevo_nombre):
        self.__nombre = nuevo_nombre     
    @edad.setter
    def edad(self, nueva_edad):
        self.__edad = nueva_edad  
    # Los siguientes métodos usan los set y get NO los atributos    
    def __str__(self):
        return "Persona:%s\nEdad:%i" % (self.nombre,self.edad)
    def Captura(self):
        self.nombre = input("Digite el nombre: ")
        self.edad = int(input("Digite la edad:"))


        
class Asistente(Persona):
  def __init__(self,nombre="",edad=0,prom=0,cur="",hA=0,carr=""):
      Persona.__init__(self,nombre,edad)
      self.__promPonderado = prom
      self.__curso = cur
      self.__horasAs = hA
      self.__carrera = carr;
  @property
  def promPonderado(self):
      return self.__promPonderado
  @property
  def curso(self):
      return self.__curso 
  @property
  def horasAs(self):
      return self.__horasAs
  @property
  def carrera(self):
      return self.__carrera  
  @promPonderado.setter
  def promPonderado(self, nuevo_promPonderado):
      self.__promPonderado = nuevo_promPonderado    
  @curso.setter
  def curso(self, nuevo_curso):
      self.__curso = nuevo_curso     
  @horasAs.setter
  def horasAs(self, nueva_horasAs):
      self.__horasAs = nueva_horasAs    
  @carrera.setter
  def carrera(self, nueva_carrera):
      self.__carrera = nueva_carrera  
  # Los siguientes métodos usan los set y get NO los atributos        
  def __str__(self):
      s ="Asistente:%s\nEdad:%i\nCarrera:%s\nHoras Asignadas:%i\nCurso:%s\nPromedio Ponderado:%s"
      return s % (self.nombre,self.edad, self.carrera, self.horasAs,self.curso,self.promPonderado)
  def Captura(self):
      Persona.Captura(self)
      self.carrera = input("Digite la carrera: ")
      self.horasAs = int(input("Digite las horas asistente:"))
      self.curso = input("Digite el curso asignado:")
      self.promPonderado = int(input("Digite el promedio ponderado:"))



class Estudiante(Persona):
    def __init__(self,nombre="",edad=0,examen1=0,examen2=0):
        Persona.__init__(self,nombre,edad)
        self.__examen1 = examen1
        self.__examen2 = examen2
        self.__numeroLibros = 0
        self.__libros = []
    @property
    def examen1(self):
        return self.__examen1
    @property
    def examen2(self):
        return self.__examen2 
    @property
    def numeroLibros(self):
        return self.__numeroLibros
    @property
    def libros(self):
        return self.__libros  
    @examen1.setter
    def examen1(self, nuevo_examen1):
        self.__examen1 = nuevo_examen1    
    @examen2.setter
    def examen2(self, nuevo_examen2):
        self.__examen2 = nuevo_examen2     
    @numeroLibros.setter
    def numeroLibros(self, nuevo_numeroLibros):
        self.__numeroLibros = nuevo_numeroLibros    
    @libros.setter
    def libros(self, nuevos_libros):
        self.__libros = nuevos_libros 
    # Los siguientes métodos usan los set y get NO los atributos     
    def calculaPromedio(self):
        return (self.examen1+self.examen2)/2    
    def __str__(self):
        s ="Estudiante:%s\nPromedio:%i\n=====Libros====="
        for i in range(self.numeroLibros):
            s = s +"\n"+ str(self.libros[i])
        s = s + "\n================"
        return s % (self.nombre,self.calculaPromedio())
    def Captura(self):
        Persona.Captura(self)
        self.examen1 = int(input("Nota Examen 1:"))
        self.examen2 = int(input("Nota Examen 2:"))
        self.numeroLibros = int(input("Numero de libros del estudiante:"))
        for i in range(self.numeroLibros):
            lib = Libro()
            lib.Captura()
            self.libros.append(lib)



class EstCompu(Estudiante):
    def __init__(self,nombre="",edad=0,examen1=0,examen2=0,examen3=0):
        Estudiante.__init__(self,nombre,edad,examen1,examen2)
        self.__examen3 = examen3
    @property
    def examen3(self):
        return self.__examen3        
    @examen3.setter
    def examen3(self, nuevo_examen3):
        self.__examen3 = nuevo_examen3  
    # Los siguientes métodos usan los set y get NO los atributos         
    def calculaPromedio(self):
        return (self.examen1+self.examen2+self.examen3)/3
    def __str__(self):
        s ="Estudiante:%s\nPromedio:%i\n=====Libros====="
        for i in range(self.numeroLibros):
            s = s +"\n"+ str(self.libros[i])
        s = s + "\n================"
        return s % (self.nombre,self.calculaPromedio())
    def Captura(self):
        Persona.Captura(self)
        self.examen1 = int(input("Nota Examen 1:"))
        self.examen2 = int(input("Nota Examen 2:"))
        self.examen3 = int(input("Nota Examen 3:"))
        self.numeroLibros = int(input("Numero de libros del estudiante:"))
        for i in range(self.numeroLibros):
            lib = Libro()
            lib.Captura()
            self.libros.append(lib)



class Lectura:
    def LeeDatosPersona(self):
        persona = Persona()
        os.system('cls') #os.system('cls') #en windows
        persona.Captura()
        return persona
    def LeeDatosEstudiante(self):
        estudiante = Estudiante()
        os.system('cls') #os.system('cls') #en windows
        estudiante.Captura()
        return estudiante
    def LeeDatosEstCompu(self):
        estudianteC = EstCompu()
        os.system('cls') #os.system('cls') #en windows
        estudianteC.Captura()
        return estudianteC
    def LeeDatosAsistente(self):
        asistente = Asistente()
        os.system('cls') #os.system('cls') #en windows
        asistente.Captura()
        return asistente



class App:
    def __init__(self):
        self.__lista = list()
        self.__lec = Lectura()
    def __menu(self):
        ##print("\n"*50)
        #os.system('clear') #os.system('cls') #en windows
        print(" ==================================================== ")
        print(" [1] Insertar Persona ")
        print(" [2] Insertar Asistente")
        print(" [3] Insertar Estudiante")
        print(" [4] Insertar Estudiante de Computacion")
        print(" [5] Ver la Lista Polimorfica" )
        print(" [6] Borrar la Lista Polimorfica")
        print(" [7] Salir")
        print(" ==================================================== ")
        return input("> ")
    def __mostrarLista(self):
        ##print("\n"*50)
        #os.system('Clear') #os.system('cls') #en windows
        for i in range(len(self.__lista)):
            print(self.__lista[i])
            print(15 * "*" + "\n")
    def principal(self):
        respuesta = ""
        while respuesta != "7":
            respuesta = self.__menu()
            if respuesta == "1":
                self.__lista.append(self.__lec.LeeDatosPersona())
            elif respuesta == "2":
                self.__lista.append(self.__lec.LeeDatosAsistente())
            elif respuesta == "3":
                self.__lista.append(self.__lec.LeeDatosEstudiante())
            if respuesta == "4":
                self.__lista.append(self.__lec.LeeDatosEstCompu())
            elif respuesta == "5":
                self.__mostrarLista()
                input("Digite cualquier tecla para continuar")
            elif respuesta == "6":
                self.__lista.clear()



def RUN() :
  prueba = App()
  prueba.principal()

RUN()


#%%
  
import sys
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
  with open('../Datos/python_output.txt', 'w') as outputs:
    with open('../Datos/Entrada.txt', 'r') as inputs :
      with custom_redirection(inputs,outputs):
        print('Programa con I/O redirigido incia...\n++++++++++++++++++++++++++++++++++++++++\n')
        RUN()
        print('Programa con I/O redirigido termina \n++++++++++++++++++++++++++++++++++++++++\n')
  print('Este mensaje sale por stdout')
 
#%%

  
    
with open('../Datos/Entrada.txt', 'r') as myfile:
    data=myfile.read()
print(data)
 


with open('../Datos/python_output.txt', 'r') as myfile:
    data=myfile.read()
print(data)


#%%

class Mine(metaclass=ABCMeta):
    def __init_(self):
      self.__settings=0
      
    def _get_stuff(self):
        return self._get_stuff_impl()

    @abstractmethod
    def _get_stuff_impl(self):
        raise NotImplementedError()

    def _set_stuff(self, value):
        return self._set_stuff_impl(value)

    @abstractmethod
    def _set_stuff_impl(self, value):
        raise NotImplementedError()

    settings = property(_get_stuff, _set_stuff)

    def do_stuff_with_settings(self):
        return self.__settings



class Child(Mine):
    def _get_stuff_impl(self):
        return self.__settings
      
    def _set_stuff_impl(self,data):
        self.__settings=data
#    settings = property(_get_stuff, _set_stuff)



print("\nEvaluando")
x=Child()
x.settings=2000
print(x.settings)

#%%

class Base(metaclass = ABCMeta):    
    def __str__(self):
      return self.Print()  
        
    @abstractmethod
    def Print(self):
      pass
    
    @abstractmethod
    def Captura(self):
        pass
      



class Libro(Base):
    def __init__(self,nombre = "",anio = 0):
        self.__nombre = nombre
        self.__anio = anio  
        
    @property
    def nombre(self):
        return self.__nombre
      
    @property
    def anio(self):
        return self.__anio 
      
    @nombre.setter
    def nombre(self, nuevo_nombre):
        self.__nombre = nuevo_nombre  
           
    @anio.setter
    def anio(self, nuevo_anio):
        self.__anio = nuevo_anio 
        
    # Los siguientes métodos usan los set y get NO los atributos       
    def Print(self):
        return "Nombre del Libro: %s\nAño: %i" % (self.nombre, self.anio)
      
    def Captura(self):
        self.nombre = input("Nombre del Libro:")
        self.anio = int(input("Año del Libro:"))
        
        


class Persona(Base):
    def __init__(self,nombre = "", edad = 0):
        self.__nombre = nombre
        self.__edad = edad
        
    @property
    def nombre(self):
        return self.__nombre
      
    @property
    def edad(self):
        return self.__edad  
      
    @nombre.setter
    def nombre(self, nuevo_nombre):
        self.__nombre = nuevo_nombre   
          
    @edad.setter
    def edad(self, nueva_edad):
        self.__edad = nueva_edad
          
    # Los siguientes métodos usan los set y get NO los atributos    
    def Print(self):
        return "Persona:%s\nEdad:%i" % (self.nombre,self.edad)
      
    def Captura(self):
        self.nombre = input("Digite el nombre: ")
        self.edad = int(input("Digite la edad:"))


       
class Asistente(Persona):
  def __init__(self,nombre="",edad=0,prom=0,cur="",hA=0,carr=""):
      Persona.__init__(self,nombre,edad)
      self.__promPonderado = prom
      self.__curso = cur
      self.__horasAs = hA
      self.__carrera = carr;
      
  @property
  def promPonderado(self):
      return self.__promPonderado
    
  @property
  def curso(self):
      return self.__curso 
    
  @property
  def horasAs(self):
      return self.__horasAs
    
  @property
  def carrera(self):
      return self.__carrera  
    
  @promPonderado.setter
  def promPonderado(self, nuevo_promPonderado):
      self.__promPonderado = nuevo_promPonderado  
        
  @curso.setter
  def curso(self, nuevo_curso):
      self.__curso = nuevo_curso     
      
  @horasAs.setter
  def horasAs(self, nueva_horasAs):
      self.__horasAs = nueva_horasAs  
        
  @carrera.setter
  def carrera(self, nueva_carrera):
      self.__carrera = nueva_carrera  
      
  # Los siguientes métodos usan los set y get NO los atributos        
  def Print(self):
      s ="Asistente:%s\nEdad:%i\nCarrera:%s\nHoras Asignadas:%i\nCurso:%s\nPromedio Ponderado:%s"
      return s % (self.nombre,self.edad, self.carrera, self.horasAs,self.curso,self.promPonderado)
    
  def Captura(self):
      Persona.Captura(self)
      self.carrera = input("Digite la carrera: ")
      self.horasAs = int(input("Digite las horas asistente:"))
      self.curso = input("Digite el curso asignado:")
      self.promPonderado = int(input("Digite el promedio ponderado:"))



class Estudiante(Persona):
    def __init__(self,nombre="",edad=0,examen1=0,examen2=0):
        Persona.__init__(self,nombre,edad)
        self.__examen1 = examen1
        self.__examen2 = examen2
        self.__numeroLibros = 0
        self.__libros = []
        
    @property
    def examen1(self):
        return self.__examen1
      
    @property
    def examen2(self):
        return self.__examen2 
      
    @property
    def numeroLibros(self):
        return self.__numeroLibros
      
    @property
    def libros(self):
        return self.__libros  
      
    @examen1.setter
    def examen1(self, nuevo_examen1):
        self.__examen1 = nuevo_examen1    
        
    @examen2.setter
    def examen2(self, nuevo_examen2):
        self.__examen2 = nuevo_examen2     
        
    @numeroLibros.setter
    def numeroLibros(self, nuevo_numeroLibros):
        self.__numeroLibros = nuevo_numeroLibros   
         
    @libros.setter
    def libros(self, nuevos_libros):
        self.__libros = nuevos_libros 
        
    # Los siguientes métodos usan los set y get NO los atributos     
    def calculaPromedio(self):
        return (self.examen1+self.examen2)/2    
      
    def Print(self):
        s ="Estudiante:%s\nPromedio:%i\n=====Libros====="
        for i in range(self.numeroLibros):
            s = s +"\n"+ str(self.libros[i])
        s = s + "\n================"
        return s % (self.nombre,self.calculaPromedio())
      
    def Captura(self):
        Persona.Captura(self)
        self.examen1 = int(input("Nota Examen 1:"))
        self.examen2 = int(input("Nota Examen 2:"))
        self.numeroLibros = int(input("Numero de libros del estudiante:"))
        for i in range(self.numeroLibros):
            lib = Libro()
            lib.Captura()
            self.libros.append(lib)



class EstCompu(Estudiante):
    def __init__(self,nombre="",edad=0,examen1=0,examen2=0,examen3=0):
        Estudiante.__init__(self,nombre,edad,examen1,examen2)
        self.__examen3 = examen3
        
    @property
    def examen3(self):
        return self.__examen3        
      
    @examen3.setter
    def examen3(self, nuevo_examen3):
        self.__examen3 = nuevo_examen3  
        
    # Los siguientes métodos usan los set y get NO los atributos         
    def calculaPromedio(self):
        return (self.examen1+self.examen2+self.examen3)/3
      
    def Print(self):
        s ="Estudiante:%s\nPromedio:%i\n=====Libros====="
        for i in range(self.numeroLibros):
            s = s +"\n"+ str(self.libros[i])
        s = s + "\n================"
        return s % (self.nombre,self.calculaPromedio())
      
    def Captura(self):
        Persona.Captura(self)
        self.examen1 = int(input("Nota Examen 1:"))
        self.examen2 = int(input("Nota Examen 2:"))
        self.examen3 = int(input("Nota Examen 3:"))
        self.numeroLibros = int(input("Numero de libros del estudiante:"))
        for i in range(self.numeroLibros):
            lib = Libro()
            lib.Captura()
            self.libros.append(lib)



class Lectura:
    def LeeDatosPersona(self):
        persona = Persona()
        os.system('clear') #os.system('cls') #en windows
        persona.Captura()
        return persona
      
    def LeeDatosEstudiante(self):
        estudiante = Estudiante()
        os.system('clear') #os.system('cls') #en windows
        estudiante.Captura()
        return estudiante
      
    def LeeDatosEstCompu(self):
        estudianteC = EstCompu()
        os.system('clear') #os.system('cls') #en windows
        estudianteC.Captura()
        return estudianteC
      
    def LeeDatosAsistente(self):
        asistente = Asistente()
        os.system('clear') #os.system('cls') #en windows
        asistente.Captura()
        return asistente



class App:
    def __init__(self):
        self.__lista = list()
        self.__lec = Lectura()
         
    def __menu(self):
        ##print("\n"*50)
        #os.system('clear') #os.system('cls') #en windows
        print(" ==================================================== ")
        print(" [1] Insertar Persona ")
        print(" [2] Insertar Asistente")
        print(" [3] Insertar Estudiante")
        print(" [4] Insertar Estudiante de Computacion")
        print(" [5] Ver la Lista Polimorfica" )
        print(" [6] Borrar la Lista Polimorfica")
        print(" [7] Salir")
        print(" ==================================================== ")
        opcion=input("> ")
        print(" Opcion-> "+opcion)
        return opcion
       
    def __mostrarLista(self):
        ##print("\n"*50)
        #os.system('Clear') #os.system('cls') #en windows
        for i in range(len(self.__lista)):
            element=self.__lista[i]
            print(element)
            print(15 * "*" + "\n")
             
    def principal(self):
        respuesta = ""
        while respuesta != "7":
            respuesta = self.__menu()
            if respuesta == "1":
              self.__lista.append(self.__lec.LeeDatosPersona())
            elif respuesta == "2":
              self.__lista.append(self.__lec.LeeDatosAsistente())
            elif respuesta == "3":
              self.__lista.append(self.__lec.LeeDatosEstudiante())
            if respuesta == "4":
              self.__lista.append(self.__lec.LeeDatosEstCompu())
            elif respuesta == "5":
              self.__mostrarLista()
              input("Digite cualquier tecla para continuar")
            elif respuesta == "6":
              self.__lista.clear()


def RUN() :
  prueba = App()
  prueba.principal()
  
print("Finaliza SCRIPT")

#%%

class base():        
  def __init__(self):
    self.__atributo=10
    self._atributo=20
    self.atributo=30
    
  def get_atributo_privado(self):
    return (self.__atributo) 
   
  def get_atributo_protegido(self):
    return (self._atributo)  
   
  def get_atributo_publico(self):
    return (self.atributo)
   
  def AccesoAbierto(self):
    return self.get_atributo_privado()
   
class heredada(base):
  otro =100    
  def __init__(self):
    super().__init__()
    #self.__otro=1000 
    self.__atributo=70
    self.atributo =100
     
  def get_atributo_privado(self):
    return super().get_atributo_privado()
    #return (self.__otro) 
   
  def __str__(self):
    return("Este objeto vale "+str(self.__atributo))
 
 
y=base()
print(y.AccesoAbierto())
 
x=heredada()
print(x)

print(x.AccesoAbierto())
print(x.get_atributo_publico())







# %%
