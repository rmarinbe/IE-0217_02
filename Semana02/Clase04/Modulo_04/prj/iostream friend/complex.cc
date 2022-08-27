//===============================================
//Archivo: complex.cc
// Fuente de referencia básico
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
#include"complex.h"

_complex::_complex(double re,double im)
{
  real=re;
  imaginario=im;
};//__________________________________________________

_complex _complex::operator+(_complex a)
{
  _complex temp;
  temp.real=real+a.real;
  temp.imaginario=imaginario+a.imaginario;
  return temp;
}//__________________________________________________

_complex _complex::operator-(_complex a)
{
  _complex temp;
  temp.real=real-a.real;
  temp.imaginario=imaginario-a.imaginario;
  return temp;
}//__________________________________________________

_complex _complex::operator*(_complex a)
{
  _complex temp;
  temp.real=real*a.real-imaginario*a.imaginario;
  temp.imaginario=real*a.imaginario+imaginario*a.real;
  return temp;
}//__________________________________________________

_complex _complex::operator/(_complex a)
{
  _complex temp;
  temp.real=(real*a.real-imaginario*a.imaginario)/(a.real*a.real+a.imaginario*a.imaginario);
  temp.imaginario=(real*a.imaginario+imaginario*a.real)/(a.real*a.real+a.imaginario*a.imaginario);
  return temp;
}//__________________________________________________

ostream& operator<<(ostream& ox, _complex salida)
{
  string x;
  x=salida.imaginario <0 ? "":"+";
  ox<< salida.real<< x <<salida.imaginario<<"j";
  return ox;
}//__________________________________________________

