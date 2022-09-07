//===============================================
// Archivo: funciones_ref5.cpp
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================

//++++++++++++++++++++++++++++++++++++++++++++++
// Este código ilustra como crear un
// puntero referencial a cualquier funcion
// matemática f(x) mediante herencia de clases
// POLIMORFISMO
//++++++++++++++++++++++++++++++++++++++++++++++

#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;
#include "../Utilitarios/utilitarios.h"
#include "funciones_ref.h"
#include "clases_polimorficas.h"

//+++++++++++++++++
// Main_ref5()
//+++++++++++++++++
void main_ref5(void)
{
  cout << "Evaluacion Main_ref 5 " << endl;
  _sin_   f1x;
  _cos_   f2x;
  _tan_   f3x;
  _log_   f4x;
  _exp_   f5x;
  _cosh_  f6x;
  _sinh_  f7x;
  evaluar(f1x);
  evaluar(f2x);
  evaluar(f3x);
  evaluar(f4x);
  evaluar(f5x);
  evaluar(f6x);
  evaluar(f7x);
  end_function();
}//________________________________________________________________________
