//===============================================
//Archivo: ecuaciones3incog.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include <iostream>
using namespace std;
#include "determinante3x3.h"
#include"ecuaciones3incog.h"

//_ecuacion_base
//+++++++++++++++++++
_ecuacion_base::_ecuacion_base(double a, double b, double c, double d)
{
}//_________________________________________________________________

double& _ecuacion_base::operator[](int index)
{
   if(index>3) index=3;
   if(index<0) index=0;
   return array[index];
}//_________________________________________________________________

//_ecuaciones3incog
//+++++++++++++++++++
_ecuacion_base& _ecuaciones3incog::operator[](int index)
{
   if(index>2) index=2;
   if(index<0) index=0;
   return array[index];
}//_________________________________________________________________

void _ecuaciones3incog::setdeterminante(void)
{
}//_________________________________________________________________

bool _ecuaciones3incog::resolver(void)
{
  return true;
}//_________________________________________________________________

double _ecuaciones3incog::valor(int a)
{
  return double(0);
}//_________________________________________________________________
