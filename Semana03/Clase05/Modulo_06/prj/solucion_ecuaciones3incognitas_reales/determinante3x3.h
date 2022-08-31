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
#define DETERMINANTE3x3_H_INCLUDED
#include <stdio.h>

class _base_determinante3x3{
private:
  double array[3];
public:
  double& operator[](int index);
};//_______________________________________________

class  _determinante3x3{
private:
  _base_determinante3x3 array[3];
public:
  _determinante3x3(double a=0,double b=0,double c=0,double=0,double=0,double=0,double=0,double=0,double=0);
  bool     set(int,int,double);
  double resolver(void);
  _base_determinante3x3& operator[](int index);
};//____________________________________________

#endif


