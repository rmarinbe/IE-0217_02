//===============================================
//Archivo: for.cc
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

#include "estructuras_de_control.h"

void ejecutar_lazo_for(void)
{
  int counter;
  cout << "Contando con for 1" << endl;

  for (counter = 0; counter <100; counter+=2)
    cout << counter << " ";
  cout << endl;

  cout << "Restando con for implicito" << endl;

  for (int i = 0,j=0; i <100; i++,j--)
    cout << i+j<< " ";
  cout << endl;

}

