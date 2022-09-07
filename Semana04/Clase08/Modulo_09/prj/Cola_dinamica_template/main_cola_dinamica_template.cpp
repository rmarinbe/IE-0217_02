//===============================================
//Archivo: main_cola_dinamica_template.cpp
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
template<typename T>
void evaluar(_cola<T> &cola)
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
    cout << "Recorrido posición"<< i++ << " es " << j << endl;
  }while(cola.prev(&j));
  i=0;
  j=-1;

  //Vaciar la cola
  //================
  while(cola.extraiga(&j))
      cout << "Extracción posición"<< i++ << " es " << j << endl;
  end_function();
}

//Main()
//======
int main(void)
{
  _cola<int>   cola1;
  evaluar(cola1);

  _cola<float>   cola2;
  evaluar(cola2);

  _cola<_complex>   cola3;
  evaluar(cola3);
}//____________________________________________________


