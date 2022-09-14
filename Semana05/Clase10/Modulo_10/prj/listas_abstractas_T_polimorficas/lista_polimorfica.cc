//===============================================
// Archivo: lista_polimorfica.h
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
#include "lista_polimorfica.h"

_list::_list(int size) : Size(size)
{}//____________________________________

_list::~_list(void)
{}//_____________________________________

_list& _list::operator =(_list &l)
{
  byte *eter;
  eter = new byte[Size];
  if (!eter) return *this;
  if (!l.gotop(eter))
  {
     delete eter;
     return *this;
  }
  do{
    inserte(eter);
  }while(l.prev(eter));
  delete eter;
  return *this;
}//_________________________________________
