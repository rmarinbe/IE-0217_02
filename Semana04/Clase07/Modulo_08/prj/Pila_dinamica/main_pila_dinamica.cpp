//===============================================
//Archivo: main_pila_dinamica.cpp
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
#include "pila_dinamica.h"

int main(void)
{
  _pila   pila1;
  for(int i=0;i<20;i++)
    pila1.push(i);

  int i=0,j=-1;
  while(pila1.pop(&j)) printf("Extraccion %i es %i\n",i++,j);
}//____________________________________________________


