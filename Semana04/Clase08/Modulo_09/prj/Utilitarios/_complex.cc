//===============================================
//Archivo: complex.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================

#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
#include"../Utilitarios/_complex.h"

_complex::_complex(double re,double im)
{
  real=re;
  imaginario=im;
}//________________________________________________________

void _complex :: set(double in_real, double in_imag)
{
  real=in_real;
  imaginario=in_imag;
}//________________________________________________________


_complex _complex::operator+(_complex a)
{
  _complex temp;
  temp.real=real+a.real;
  temp.imaginario=imaginario+a.imaginario;
  return temp;
}//________________________________________________________

_complex _complex::operator-(_complex a)
{
  _complex temp;
  temp.real=real-a.real;
  temp.imaginario=imaginario-a.imaginario;
  return temp;
}//________________________________________________________

_complex _complex::operator*(_complex a)
{
  _complex temp;
  temp.real=real*a.real-imaginario*a.imaginario;
  temp.imaginario=real*a.imaginario+imaginario*a.real;
  return temp;
}//________________________________________________________

_complex _complex::operator/(_complex a)
{
  _complex temp;
  double div      =a.real*a.real+a.imaginario*a.imaginario;
  temp.real       =(real*a.real+imaginario*a.imaginario)/div;
  temp.imaginario =(imaginario*a.real-real*a.imaginario)/div;
  return temp;
}//________________________________________________________


_complex _complex::operator/=(_complex otro)
{
  *this=*this/otro;
  return *this;
}//________________________________________________________

_complex _complex::operator*=(_complex otro)
{
  *this=*this*otro;
  return *this;
}//________________________________________________________

_complex _complex::operator+=(_complex otro)
{
  *this=*this+otro;
  return *this;
}//________________________________________________________

_complex _complex::operator-()
{
  _complex temp;
  temp.real=-real;
  temp.imaginario=-imaginario;
  return temp;
}//________________________________________________________

bool _complex::operator==(_complex otro)
{
 return (otro.real == real)&&(otro.imaginario==imaginario);
}//________________________________________________________

bool _complex::operator!=(_complex a)
{
  if ((a.real != real) || (a.imaginario != imaginario))
   return true;
     else  return false;
}//________________________________________________________

double &_complex::operator[](int index)
{
  static double pad;
  switch (index) {
    case  0:return real;
    case  1:return imaginario;
    default: return pad;
  }
}//________________________________________________________

ostream& operator<<(ostream& ox, _complex salida)
{
  string x;
  x=salida.imaginario <0 ? "":"+";
  ox<< salida.real<< x <<salida.imaginario<<"j";
  return ox;
}//________________________________________________________

