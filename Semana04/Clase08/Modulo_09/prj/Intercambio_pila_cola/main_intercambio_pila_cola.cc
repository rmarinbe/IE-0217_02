//===============================================
// Archivo: main_intercambio_pila_cola.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include <iostream>
using namespace std;
#include "../Utilitarios/utilitarios.h"
#include "../Utilitarios/_complex.h"
#include "cola_dinamica_template.h"
#include "pila_dinamica_template.h"
template<typename T>
void evaluar_y_copiar(_cola<T> &cola,_pila<T> &pila)
{
 //Llenar la cola
  //===============
  for(int i=0;i<20;i++)
    cola.inserte(i);
  int i=0;
  T   j=-1;

  //Recorrer la cola
  //================
  cola.gotop(&j);
  do{
    pila.push(j);
  }while(cola.prev(&j));
  i=0;
  j=-1;

  //Vaciar la cola
  //================
  while(cola.extraiga(&j))
      cout << "Cola::Extracción posición"<< i++ << " es " << j << endl;
  i=0;
  while(pila.pop(&j))
      cout << "Pila::Extracción posición"<< i++ << " es " << j << endl;
  end_function();
}

//Main()
//======
int main(void)
{
  _cola<int>   cola1;
  _pila<int>   pila1;
  evaluar_y_copiar(cola1,pila1);

  _cola<float>  cola2;
  _pila<float>  pila2;
  evaluar_y_copiar(cola2,pila2);

  _cola<_complex>   cola3;
  _pila<_complex>   pila3;
  evaluar_y_copiar(cola3,pila3);
}//____________________________________________________


