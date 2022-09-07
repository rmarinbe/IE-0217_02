//===============================================
// Archivo: funciones_ref3.cpp
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
// matemática f(x) punteros a funciones en
// Clase BASE-
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
class _funcion_v2{
private:
  double (*funcion_generica)(double);

public:
  _funcion_v2(double (*FX)(double))
  {
    funcion_generica=FX;
  }//+++++++++++++++++++++++++++

  double fx(double valor)
  {
    return (*funcion_generica)(valor);
  }//+++++++++++++++++++++++++++
};//_______________________________

class fsin: public _funcion_v2{
public:
  fsin() : _funcion_v2(sin) {}
};//________________________________

class fcos: public _funcion_v2{
public:
  fcos() : _funcion_v2(cos) {}
};//________________________________

class ftan: public _funcion_v2{
public:
  ftan() : _funcion_v2(tan) {}
};//________________________________

class flog: public _funcion_v2{
public:
  flog() : _funcion_v2(log) {}
};//________________________________

class fexp: public _funcion_v2{
public:
  fexp() : _funcion_v2(exp) {}
};//________________________________

class fcosh: public _funcion_v2{
public:
  fcosh() : _funcion_v2(cosh) {}
};//________________________________

class fsinh: public _funcion_v2{
public:
  fsinh() : _funcion_v2(sinh) {}
};//________________________________

//+++++++++++++++++
// Main_ref3()
//+++++++++++++++++
void main_ref3(void)
{
  cout << "Evaluacion Main_ref 3 " << endl;
  fsin   f1x;
  fcos   f2x;
  ftan   f3x;
  flog   f4x;
  fexp   f5x;
  fcosh  f6x;
  fsinh  f7x;
  cout << "La funcion f1(x)|x=2.5 es: " << f1x.fx(2.5) << endl;
  cout << "La funcion f2(x)|x=2.5 es: " << f2x.fx(2.5) << endl;
  cout << "La funcion f3(x)|x=2.5 es: " << f3x.fx(2.5) << endl;
  cout << "La funcion f4(x)|x=2.5 es: " << f4x.fx(2.5) << endl;
  cout << "La funcion f5(x)|x=2.5 es: " << f5x.fx(2.5) << endl;
  cout << "La funcion f6(x)|x=2.5 es: " << f6x.fx(2.5) << endl;
  cout << "La funcion f7(x)|x=2.5 es: " << f7x.fx(2.5) << endl;
  end_function();
}//________________________________________________________________________
