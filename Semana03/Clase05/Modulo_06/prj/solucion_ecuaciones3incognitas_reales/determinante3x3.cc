//===============================================
//Archivo: determinante3x3.cc
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
//class _base_determinante3x3
//============================
double &_base_determinante3x3::operator[](int index)
{
  if (index <0) index=0;
    if (index >=3) index=2;
      return array[index];
}//________________________________________________

//class _determinante3x3
//=========================
_determinante3x3::_determinante3x3(double a,double b,double c,double d,double e,double f,double g,double h,double i)
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

bool _determinante3x3::set(int x,int y,double valor)
{
   if ( (x<0) || (x>=3) || (y<0) || (y>=3)) return false;
   array[x][y]=valor;
   return true;
}//______________________________________________

double _determinante3x3::resolver(void)
{
   double resultado;
   resultado= array[0][0]*array[1][1]*array[2][2]   +   array[1][0]*array[2][1]*array[0][2]   +   array[2][0]*array[0][1]*array[1][2]   -   array[2][0]*array[1][1]*array[0][2]   -   array[0][0]*array[2][1]*array[1][2]   -   array[1][0]*array[0][1]*array[2][2];
   return resultado;
}//______________________________________________

_base_determinante3x3& _determinante3x3::operator[](int index)
{
     if (index <0) index=0;
     if (index >=3) index=2;
     return array[index];
}//_____________________________________________

