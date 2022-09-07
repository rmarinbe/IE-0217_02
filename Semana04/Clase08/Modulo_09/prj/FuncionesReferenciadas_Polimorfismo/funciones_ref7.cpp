//===============================================
// Archivo: funciones_ref7.cpp
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

static _funcion_base *gx[]={new _sin_ , new _cos_ , new _tan_ , new _log_ , new _exp_,
                     new _cosh_, new _sinh_, NULL};

//+++++++++++++++++
// Main()
//+++++++++++++++++
void main_ref7(void)
{
  cout << "Evaluacion Main_ref 7 " << endl;
  int i=0;
  while(gx[i]!= NULL)
    cout << "La funcion f(x)|x=2.5 es: " << (*gx[i++]).fx(2.5) << endl;
  end_function();
}//________________________________________________________________________
