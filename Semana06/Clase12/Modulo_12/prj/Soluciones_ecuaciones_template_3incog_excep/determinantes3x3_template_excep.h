//===============================================
//Archivo: determinante3x3_template_excep.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef DETERMINANTE3x3_TEMPLATE_EXCEP_H_INCLUDED
#define DETERMINANTE3x3_TEMPLATE_EXCEP_H_INCLUDED
#include <stdio.h>
#include "exception_class.h"
#include "range_check_error.h"

//CLASS DEFINITION
//+++++++++++++++++
template<typename T> class _base_determinante3x3{
private:
  T array[3];
public:
  T& operator[](int index);
};//_______________________________________________

template<typename T> class  _determinante3x3{
private:
  _base_determinante3x3<T> array[3];
public:
  _determinante3x3(T=0,T=0,T=0,T=0,T=0,T=0,T=0,T=0,T=0);
  bool     set(int,int,T);
  T resolver(void);
  _base_determinante3x3<T>& operator[](int index);
};//____________________________________________

//CLASS IMPLEMENTATION
//+++++++++++++++++++++

//class _base_determinante3x3
//===========================
template <typename T> T& _base_determinante3x3<T>::operator[](int index)
{
  if (index <0) index=0;
  if (index >=3) index=2;
  return array[index];
}//________________________________________________

//class _determinante3x3
//======================
template<typename T> _determinante3x3<T>::_determinante3x3(T a,T b,T c,T d,T e,T f,T g,T h,T i)
{
  array[0][0]=a;
  array[0][1]=b;
  array[0][2]=c;
  array[1][0]=d;
  array[1][1]=e;
  array[1][2]=f;
  array[2][0]=g;
  array[2][1]=h;
  array[2][2]=i;
}//______________________________________________

template<typename T> bool _determinante3x3<T>::set(int x,int y,T valor)
{
  if ( (x<0) || (x>=3) || (y<0) || (y>=3))
  {
    _range_check_error fault;
    throw fault;
  }
  array[x][y]=valor;
  return true;
}//______________________________________________

template<typename T> T _determinante3x3<T>::resolver(void)
{
  T resultado;
  resultado= array[0][0]*array[1][1]*array[2][2]   +   array[1][0]*array[2][1]*array[0][2]   +   array[2][0]*array[0][1]*array[1][2]   -   array[2][0]*array[1][1]*array[0][2]   -   array[0][0]*array[2][1]*array[1][2]   -   array[1][0]*array[0][1]*array[2][2];
  return resultado;
}//______________________________________________

template<typename T> _base_determinante3x3<T>& _determinante3x3<T>::operator[](int index)
{
  if ((index <0)||(index >=3))
  {
    _range_check_error fault;
    throw fault;
  }
  return array[index];
}//_____________________________________________

#endif


