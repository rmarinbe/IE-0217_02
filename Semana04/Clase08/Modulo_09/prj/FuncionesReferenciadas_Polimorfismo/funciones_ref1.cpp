//===============================================
// Archivo: funciones_ref1.cpp
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
// matemática f(x)
//++++++++++++++++++++++++++++++++++++++++++++++

#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;
#include "../Utilitarios/utilitarios.h"
#include "funciones_ref.h"


static double (*fx)(double )=NULL;
static double (*gx[])(double )={sin,cos,tan,log,exp,cosh,sinh,NULL};

//+++++++++++++++++
// Main_ref1()
//+++++++++++++++++
void main_ref1(void)
{
  cout << "Evaluacion Main_ref 1 " << endl;
  int i=0;
  while(gx[i]!= NULL)
  {
    fx=gx[i++];
    cout << "La funcion f(x)|x=2.5 es: " << fx(2.5) << endl;
  }

  end_function();
}//________________________________________________________________________
