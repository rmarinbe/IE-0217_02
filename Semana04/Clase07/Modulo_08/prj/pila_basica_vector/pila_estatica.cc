//===============================================
// Archivo: pila_estatica.cc
//===============================================
// Curso de programacion en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include <stdlib.h>
#include <stdio.h>
#include "pila_estatica.h"

_pila::_pila(void)
{
   for(int i=0;i<MAXSTACKSIZE; i++)
     Pila[i]=0;
   Puntero=0;
}//_______________________________________________________

_pila::~_pila(void)
{
  printf("Pila fue liberada\n");
}//_______________________________________________________

bool _pila::push(int valor)
{
  if (Puntero>=MAXSTACKSIZE) return false;
  Pila[Puntero++]=valor;
  return true;
}//_______________________________________________________

int _pila::pop(void)
{
  if (Puntero==0) return -1;
  return Pila[--Puntero];
}//_______________________________________________________

