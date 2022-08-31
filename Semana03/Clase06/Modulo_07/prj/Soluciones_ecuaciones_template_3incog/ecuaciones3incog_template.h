//===============================================
//Archivo: ecuaciones3incog_template.h
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

//CLASS DEFINITION
//+++++++++++++++++
template<typename T> class _ecuacion_base
{
  private:
    T array[5];
  public:
    _ecuacion_base(T=T(0), T=T(0), T=T(0), T=T(0));
    T& operator[](int);
};//________________________________________________________________________

template<typename T> class _ecuaciones3incog
{
  private:
    _ecuacion_base<T> array[3];
    _determinante3x3<T> det[3], DetN;
    T soluciones[3];

  public:
    _ecuacion_base<T>& operator[](int);
    void setdeterminante();
    bool resolver(void);
    T valor(int a);
};//________________________________________________________________________

//CLASS IMPLEMENTATION
//+++++++++++++++++++++

//_ecuacion_base
//+++++++++++++++++++
template<typename T>
_ecuacion_base<T>::_ecuacion_base(T a, T b, T c, T d)
{
  array[1]=a;
  array[2]=b;
  array[3]=c;
  array[4]=d;
}//_________________________________________________________________

template<typename T>
T& _ecuacion_base<T>::operator[](int index)
{
   if(index>3) index=3;
   if(index<0) index=0;
   return array[index];
}//_________________________________________________________________

//_ecuaciones3incog
//+++++++++++++++++++
template<typename T>
_ecuacion_base<T>& _ecuaciones3incog<T>::operator[](int index)
{
   if(index>2) index=2;
   if(index<0) index=0;
   return array[index];
}//_________________________________________________________________

template<typename T>
void _ecuaciones3incog<T>::setdeterminante(void)
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

template<typename T>
bool _ecuaciones3incog<T>::resolver(void)
{
  bool solucion=false;

  setdeterminante();
  if(DetN.resolver()!=T(0))
  {
    solucion=true;
    for(int i=0; i<3; i++)
      soluciones[i]=det[i].resolver()/DetN.resolver();
  }
  else solucion=false;
  return solucion;
}//_________________________________________________________________

template<typename T>
T _ecuaciones3incog<T>::valor(int a)
{
   if(a>2) a=2;
   if(a<0) a=0;
   return soluciones[a];
}//_________________________________________________________________

#endif
