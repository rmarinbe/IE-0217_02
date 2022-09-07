//===============================================
// Archivo: funciones_ref2.cpp
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
// matemática f(x) mediante punteros a
// funciones.
//++++++++++++++++++++++++++++++++++++++++++++++

#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;
#include "../Utilitarios/utilitarios.h"
#include "funciones_ref.h"

//+++++++++++++++++++++++++
// definicion de clases
//+++++++++++++++++++++++++
class _funcion_v1{
private:
  double (*funcion_generica)(double);

public:
  _funcion_v1(double (*FX)(double))
  {
    funcion_generica=FX;
  }//+++++++++++++++++++++++++++
  double fx(double valor)
  {
    return (*funcion_generica)(valor);
  }//+++++++++++++++++++++++++++
};//_______________________________


static double (*gx[])(double)={sin,cos,tan,log,exp,cosh,sinh,NULL};

//+++++++++++++++++
// Main_ref2()
//+++++++++++++++++
void main_ref2(void)
{
  cout << "Evaluacion Main_ref 2 " << endl;
  int i=0;
  while(gx[i]!= NULL)
  {
    _funcion_v1 funcion_usuario(gx[i++]);
    cout << "La funcion f(x)|x=2.5 es: " << funcion_usuario.fx(2.5) << endl;
  }
  end_function();
}//________________________________________________________________________
