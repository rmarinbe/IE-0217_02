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

#include "define.h"
#include "_complex.h"
#include "determinante3x3.h"

//class _base_determinante3x3
//======================
TYPE &_base_determinante3x3::operator[](int index)
{
     if (index <0) index=0;
     if (index >=3) index=2;
      return array[index];
}//________________________________________________

//class _determinante3x3
//======================
_determinante3x3::_determinante3x3(TYPE a,TYPE b,TYPE c,TYPE d,TYPE e,TYPE f,TYPE g,TYPE h,TYPE i)
{
   array[0][0]=TYPE(a);
   array[0][1]=TYPE(b);
   array[0][2]=TYPE(c);
   array[1][0]=TYPE(d);
   array[1][1]=TYPE(e);
   array[1][2]=TYPE(f);
   array[2][0]=TYPE(g);
   array[2][1]=TYPE(h);
   array[2][2]=TYPE(i);
}//______________________________________________

bool _determinante3x3::set(int x,int y,TYPE valor)
{
   if ( (x<0) || (x>=3) || (y<0) || (y>=3)) return false;
   array[x][y]=valor;
   return true;
}//______________________________________________

TYPE _determinante3x3::resolver(void)
{
   TYPE resultado;
   resultado= array[0][0]*array[1][1]*array[2][2]   +   array[1][0]*array[2][1]*array[0][2]   +   array[2][0]*array[0][1]*array[1][2]   -   array[2][0]*array[1][1]*array[0][2]   -   array[0][0]*array[2][1]*array[1][2]   -   array[1][0]*array[0][1]*array[2][2];
   return resultado;
}//______________________________________________

_base_determinante3x3& _determinante3x3::operator[](int index)
   {
     if (index <0) index=0;
     if (index >=3) index=2;
     return array[index];
}//_____________________________________________

