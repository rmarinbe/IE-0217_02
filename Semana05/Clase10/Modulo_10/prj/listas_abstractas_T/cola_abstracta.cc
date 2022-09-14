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
#include "cola_abstracta.h"

_cola_base::_cola_base(int size) : _list(size)
{
  contador =0;
  inicio=final=index=NULL;
}//____________________________________

_cola_base::~_cola_base(void)
{
  while(extraiga());
}//_____________________________________

bool _cola_base::inserte(void *info)
{
  T_cola *ficha;
  ficha = new T_cola;
  if (!ficha) return false;
  ficha->dato= new byte[Size];
  if (!ficha->dato)
  {
     delete ficha;
     return false;
  }
  if (info) memcpy(ficha->dato, info, Size);
  if (contador==0)   //condiciones inciales
  {
     ficha->anterior=final;
     inicio=final=ficha;
     index=inicio;
  }else		//una condicion mas
  {
     ficha->anterior=final->anterior;
     final->anterior=ficha;
     final=ficha;
  }
  contador++;
  return true;
}//______________________________________

bool _cola_base::extraiga(void *info)
{
  T_cola *temporal;
  if (!inicio) return false;
  if (info) memcpy(info,inicio->dato,Size);
  delete [] (byte*)inicio->dato;
  temporal=inicio->anterior;
  delete inicio;
  inicio=temporal;
  if (!inicio) final=inicio;
  contador--;
  return true;
}//______________________________________

bool _cola_base::prev(void *info)
{
  if (!index->anterior) return false;
  index=index->anterior;
  if (info) memcpy(info,index->dato,Size);
  return true;
}//________________________

bool _cola_base::gotop(void *info)
{
  if (!inicio) return false;
  index=inicio;
  if(info) memcpy(info,index->dato,Size);
  return true;
}//________________________

const int _cola_base::longitud_cola(void)
{
  return Size;
}//___________________________________
