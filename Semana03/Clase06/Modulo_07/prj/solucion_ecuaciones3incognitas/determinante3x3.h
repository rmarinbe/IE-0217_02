//===============================================
//Archivo: determinante3x3.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef DETERMINANTE3x3_H_INCLUDED
#define UTILITARIOS_H_INCLUDED
#include <stdio.h>

class _base_determinante3x3{
private:
  TYPE array[3];
public:
  TYPE& operator[](int index);
};//_______________________________________________

class  _determinante3x3{
private:
  _base_determinante3x3 array[3];
public:
  _determinante3x3(TYPE a=0,TYPE b=0,TYPE c=0,TYPE=0,TYPE=0,TYPE=0,TYPE=0,TYPE=0,TYPE=0);
  bool     set(int,int,TYPE);
  TYPE resolver(void);
  _base_determinante3x3& operator[](int index);
};//____________________________________________

#endif


