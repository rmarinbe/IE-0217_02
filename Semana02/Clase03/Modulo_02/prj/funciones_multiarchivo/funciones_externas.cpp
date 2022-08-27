//===============================================
//Archivo: funciones_externas.cpp
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
#include "multiarchivo.h"

//===================
// Funciones locales
//===================

// Funciones únicamente accesible desde este archivo
//++++++++++++++++++++++++++++++++++++++++++++++++++++

static int funcion_operacional(int a,int b)
{
  int c,d=10;
  c=a;
  a++;
  c--;
  d=b--+c;
  a+=a;
  b+=c;
  d/=4;
  return a+b+c-d;
}//_________________________________________________

//==================
//Funciones publicas
//==================

//Funciones declaradas en multiarchivo.h
//++++++++++++++++++++++++++++++++++++++++
int funcion_publica(int a,int b)
{
  return funcion_operacional(a,b);
}//______________________________________________

int funcion_suma(int a,int b)
{
  return a+b;
}//______________________________________________

int funcion_resta(int a,int b)
{
  return a-b;
}//______________________________________________

int funcion_multiplicacion(int a,int b)
{
  return a*b;
}//______________________________________________

int funcion_resto(int a,int b)
{
  return a%b;
}//______________________________________________

int funcion_division(int a,int b)
{
  if (b==0) throw(0);
  return a/b;
}//______________________________________________
