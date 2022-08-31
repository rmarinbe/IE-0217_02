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
#include "define.h"
#include "_complex.h"
#include "determinante3x3.h"
#include"ecuaciones3incog.h"

//_ecuacion_base
//+++++++++++++++++++
_ecuacion_base::_ecuacion_base(TYPE a, TYPE b, TYPE c, TYPE d)
{
  array[1]=a;
  array[2]=b;
  array[3]=c;
  array[4]=d;
}//_________________________________________________________________

TYPE& _ecuacion_base::operator[](int index)
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
  //sacando primera columna
  det[0][0][0]=array[0][3];  det[0][0][1]=array[0][1];  det[0][0][2]=array[0][2];
  det[0][1][0]=array[1][3];  det[0][1][1]=array[1][1];  det[0][1][2]=array[1][2];
  det[0][2][0]=array[2][3];  det[0][2][1]=array[2][1];  det[0][2][2]=array[2][2];

  //sacando segunda columna
  det[1][0][0]=array[0][0];  det[1][0][1]=array[0][3];  det[1][0][2]=array[0][2];
  det[1][1][0]=array[1][0];  det[1][1][1]=array[1][3];  det[1][1][2]=array[1][2];
  det[1][2][0]=array[2][0];  det[1][2][1]=array[2][3];  det[1][2][2]=array[2][2];

  //sacando tercera columna
  det[2][0][0]=array[0][0];  det[2][0][1]=array[0][1];  det[2][0][2]=array[0][3];
  det[2][1][0]=array[1][0];  det[2][1][1]=array[1][1];  det[2][1][2]=array[1][3];
  det[2][2][0]=array[2][0];  det[2][2][1]=array[2][1];  det[2][2][2]=array[2][3];

  //DetN
  DetN[0][0]=array[0][0];  DetN[0][1]=array[0][1];  DetN[0][2]=array[0][2];
  DetN[1][0]=array[1][0];  DetN[1][1]=array[1][1];  DetN[1][2]=array[1][2];
  DetN[2][0]=array[2][0];  DetN[2][1]=array[2][1];  DetN[2][2]=array[2][2];
}//_________________________________________________________________

bool _ecuaciones3incog::resolver(void)
{
  bool solucion=false;

  setdeterminante();
  if(DetN.resolver()!=TYPE(0))
  {
    solucion=true;
    for(int i=0; i<3; i++)
      soluciones[i]=det[i].resolver()/DetN.resolver();
  }
  else solucion=false;
  return solucion;
}//_________________________________________________________________

TYPE _ecuaciones3incog::valor(int a)
{
   if(a>2) a=2;
   if(a<0) a=0;
   return soluciones[a];
}//_________________________________________________________________
