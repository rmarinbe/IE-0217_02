//===============================================
// Archivo: clases_polimorficas.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;
#include "clases_polimorficas.h"

//====================
//class _funcion_base
//====================
double _funcion_base::fx(double valor)
{
  cout << "Funcion de usuario no definida...precaución!!!"<< endl;
  return  0;
}//______________________________________________________________

_funcion_base::~_funcion_base(void)
{}//_____________________________________________________________

//=================================
//clases heredadas con polimorfismo
//=================================
double _sin_::fx(double valor)
{
  return  sin(valor);
}//________________________________

double _cos_::fx(double valor)
{
  return  cos(valor);
}//________________________________

double _tan_::fx(double valor)
{
    return  tan(valor);
}//________________________________

double _log_::fx(double valor)
{
  return  log(valor);
}//________________________________

double _exp_::fx(double valor)
{
  return  exp(valor);
}//________________________________

double _cosh_::fx(double valor)
{
  return  cosh(valor);
}//________________________________

double _sinh_::fx(double valor)
{
  return  sinh(valor);
}//________________________________

void evaluar(_funcion_base &fx)
{
  cout << "La funcion f(x)|x=2.5 es: " << fx.fx(2.5) << endl;
}//____________________________________
