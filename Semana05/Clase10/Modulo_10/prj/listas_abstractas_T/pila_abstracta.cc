//===============================================
// Archivo: cola_abstracta.cc
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
#include <string.h>
using namespace std;
#include "lista.h"
#include "pila_abstracta.h"

//+++++++++++++++++++++++++
//    _pila  (generica)
//+++++++++++++++++++++++++
_pila_base::_pila_base(int size): _list(size)
{
  Pila=Aux=NULL;
}//_________________________________________________

_pila_base::~_pila_base(void)
{
  void *basura;
  basura = new byte[Size];
  if (!basura) return;
  while(extraiga(basura));
}//____________________________________________________

bool _pila_base::inserte(void *info)
{
  T_pila *p_aux;

  //Algoritmo de la pila
  //++++++++++++++++++++
   p_aux  = new T_pila;
   if (p_aux==NULL) return false;
   p_aux->anterior=Pila;
   Pila=p_aux;

  //Algoritmo de almacenamiento
  //++++++++++++++++++++++++++

   Pila->dato = new byte[Size];
   //if (!p_aux->dato)
   memcpy(Pila->dato, info, Size);
   return true;
}//__________________________________________________

bool _pila_base::extraiga(void *info)
{
  T_pila *p_aux;

  if (Pila==NULL) return false;
  //Algoritmo de almacenamiento
  //++++++++++++++++++++++++++
  memcpy(info,Pila->dato,Size);
  delete [] (byte*)Pila->dato;

  //Algoritmo pila
  //++++++++++++++++++++++++++
  p_aux=Pila->anterior;
  delete Pila;
  Pila=p_aux;
  return true;
}//__________________________________________________

bool _pila_base::gotop(void *info)
{
  if (Pila==NULL) return false;
  Aux=Pila;
  memcpy(info,Aux->dato,Size);
  Aux=Aux->anterior;
  return true;
}//_______________________________________________________

bool _pila_base::prev(void *info)
{
  if (Aux==NULL) return false;
  //Algoritmo de almacenamiento
  //++++++++++++++++++++++++++
  memcpy(info,Aux->dato,Size);

  //Algoritmo pila
  //++++++++++++++++++++++++++
  Aux=Aux->anterior;
  return true;
}//__________________________________________________

