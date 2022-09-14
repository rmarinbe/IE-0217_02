//===============================================
// Archivo: cola_dinamica.h
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
#include "cola_dinamica.h"

_cola::_cola(void)
{
  contador =0;
  inicio=final=index=NULL;
}//____________________________________

_cola::~_cola(void)
{
  while(extraiga());
}//_____________________________________

bool _cola::inserte(int info)
{
  T_cola *ficha;
  ficha = new T_cola;
  if (!ficha) return false;
  ficha->dato= info;
  if (contador==0)   //condiciones inciales
  {
    ficha->proximo=final;
    inicio=final=ficha;
    index=inicio;
  }else		//una condicion mas
  {
    ficha->proximo=final->proximo;
    final->proximo=ficha;
    final=ficha;
  }
  contador++;
  return true;
}//______________________________________

bool _cola::extraiga(int *info)
{
  T_cola *temporal;
  if (!inicio) return false;
  if (info !=NULL ) *info=inicio->dato;
  temporal=inicio->proximo;
  delete inicio;
  inicio=temporal;
  index = inicio;
  if (!inicio) final=inicio;
  contador--;
  return true;
}//______________________________________

bool _cola::prev(int *info)
{
  if (!index->proximo) return false;
  index=index->proximo;
  *info=index->dato;
  return true;
}//________________________

bool _cola::gotop(int *info)
{
  if (!inicio) return false;
  index=inicio;
  *info=index->dato;
  return true;
}//________________________

int _cola::longitud_cola(void)
{
  return contador;
}//___________________________________
