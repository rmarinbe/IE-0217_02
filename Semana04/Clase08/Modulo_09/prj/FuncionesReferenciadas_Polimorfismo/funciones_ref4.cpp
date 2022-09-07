//===============================================
// Archivo: funciones_ref4.cpp
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
// SOBRECARGA
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
class _funcion_v3{
private:
public:
  double fx(double valor)
  {
    cout << "Funcion de usuario no definida...precaucion!!!"<< endl;
    return  0;
  }//+++++++++++++++++++++++++++
};//_______________________________

class _fsin: public _funcion_v3{
public:
  double fx(double valor)
  {
    return  sin(valor);
  }//+++++++++++++++++++++++++++
};//________________________________

class _fcos: public _funcion_v3{
public:
  double fx(double valor)
  {
    return  cos(valor);
  }//+++++++++++++++++++++++++++
};//________________________________

class _ftan: public _funcion_v3{
public:
  double fx(double valor)
  {
    return  tan(valor);
  }//+++++++++++++++++++++++++++
};//________________________________

class _flog: public _funcion_v3{
public:
  double fx(double valor)
  {
    return  log(valor);
  }//+++++++++++++++++++++++++++
};//________________________________

class _fexp: public _funcion_v3{
public:
  double fx(double valor)
  {
    return  exp(valor);
  }//+++++++++++++++++++++++++++
};//________________________________

class _fcosh: public _funcion_v3{
public:
  double fx(double valor)
  {
    return  cosh(valor);
  }//+++++++++++++++++++++++++++
};//________________________________

class _fsinh: public _funcion_v3{
public:
  double fx(double valor)
  {
    return  sinh(valor);
  }//+++++++++++++++++++++++++++
};//________________________________

class _ftanh: public _funcion_v3{
public:
};//________________________________

//+++++++++++++++++
// Main_ref4()
//+++++++++++++++++
void main_ref4(void)
{
  cout << "Evaluacion Main_ref 4 " << endl;
  _fsin   f1x;
  _fcos   f2x;
  _ftan   f3x;
  _flog   f4x;
  _fexp   f5x;
  _fcosh  f6x;
  _fsinh  f7x;
  _ftanh  f8x;
  cout << "La funcion f1(x)|x=2.5 es: " << f1x.fx(2.5) << endl;
  cout << "La funcion f2(x)|x=2.5 es: " << f2x.fx(2.5) << endl;
  cout << "La funcion f3(x)|x=2.5 es: " << f3x.fx(2.5) << endl;
  cout << "La funcion f4(x)|x=2.5 es: " << f4x.fx(2.5) << endl;
  cout << "La funcion f5(x)|x=2.5 es: " << f5x.fx(2.5) << endl;
  cout << "La funcion f6(x)|x=2.5 es: " << f6x.fx(2.5) << endl;
  cout << "La funcion f7(x)|x=2.5 es: " << f7x.fx(2.5) << endl;
  cout << "La funcion f8(x)|x=2.5 es: " << f8x.fx(2.5) << endl;
  end_function();
}//________________________________________________________________________
