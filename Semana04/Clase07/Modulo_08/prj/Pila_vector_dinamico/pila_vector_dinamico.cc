//===============================================
//Archivo: pila_vector_dinamico.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================

#include <stdlib.h>
#include <stdio.h>
#include "pila_vector_dinamico.h"

_pila::_pila(int size) :Maxsize(size)
{
   Pila = new int[Maxsize];
   if (!Pila) return;
   printf("Longitud de pila es %i\n",Maxsize);
   for(int i=0;i<Maxsize; i++)
     Pila[i]=0;
   Puntero=0;
}//_______________________________________________________

_pila::_pila(_pila &original) :Maxsize(original.Maxsize)
{
   Pila = new int[Maxsize];
   if (!Pila) return;
   printf("Longitud de pila origen es %i\n",Maxsize);
   for(int i=0;i<Maxsize; i++)
     Pila[i]=original.Pila[i];
   Puntero=original.Puntero;
}//_______________________________________________________

_pila::~_pila(void)
{
  if (Pila) delete [] Pila;
  printf("Pila fue liberada\n");
}//_______________________________________________________

bool _pila::push(int valor)
{
  if (Puntero>=Maxsize) return false;
  Pila[Puntero++]=valor;
  return true;
}//_______________________________________________________

int _pila::pop(void)
{
  if (Puntero==0) return -1;
  return Pila[--Puntero];
}//_______________________________________________________

