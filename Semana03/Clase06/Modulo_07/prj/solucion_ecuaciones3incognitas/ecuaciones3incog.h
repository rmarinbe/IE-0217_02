//===============================================
//Archivo: ecuaciones3incog.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef ECUACIONES3INCOG_H_INCLUDED
#define ECUACIONES3INCOG_H_INCLUDED

#include<iostream>
using namespace std;
class _ecuacion_base
{
  private:
    TYPE array[4];
  public:
    _ecuacion_base(TYPE=TYPE(0), TYPE=TYPE(0), TYPE=TYPE(0), TYPE=TYPE(0));
    TYPE& operator[](int);
};//________________________________________________________________________

class _ecuaciones3incog
{
  private:
    _ecuacion_base array[3];
    _determinante3x3 det[3], DetN;
    TYPE soluciones[3];

  public:
    _ecuacion_base& operator[](int);
    void setdeterminante();
    bool resolver(void);
    TYPE valor(int a);
};//________________________________________________________________________


#endif
