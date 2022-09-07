//===============================================
//Archivo: pila_dinamica.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila_dinamica.h"
#define var
#define beginCode
#define endCode

#define FALSE 0
#define TRUE  !FALSE

//+++++++++++++++++++++++++
//    _pila  (generica)
//+++++++++++++++++++++++++
_pila::_pila(void)
{
   contador=0;
   array=index=NULL;
}//_________________________________________________

_pila::~_pila(void)
{
  int basura;
  while(pop(&basura));
}//____________________________________________________

bool _pila::push(int info)
{
  T_pila *p_aux;

  //Algoritmo de la pila
  //++++++++++++++++++++
   p_aux  = new T_pila;
   if (p_aux==NULL) return FALSE;
   p_aux->proximo=array;
   array=p_aux;
   index =NULL;

  //Algoritmo de almacenamiento
  //++++++++++++++++++++++++++
   p_aux->dato =info;
   return TRUE;
}//__________________________________________________

bool _pila::pop(int *info)
{
   T_pila *p_aux;

   if (array==NULL) return false;
   //Algoritmo de almacenamiento
   //++++++++++++++++++++++++++
   *info=array->dato;
   //Algoritmo pila
   //++++++++++++++++++++++++++
   p_aux=array->proximo;
   delete array;
   array=p_aux;
   return true;
}//__________________________________________________


