//===============================================
//Archivo: main_cola_dinamica.cpp
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
#include "cola_dinamica.h"

int main(void)
{
  _cola   cola1;

  //Llenar la cola
  //===============
  for(int i=0;i<20;i++)
    cola1.inserte(i);
  int i=0,j=-1;

  //Recorrer la cola
  //================
  if (cola1.gotop(&j)) do{
    printf("Recorrido posición %i es %i\n",i++,j);
  }while(cola1.prev(&j));
  i=0;
  j=-1;

  //Vaciar la cola
  //================
  while(cola1.extraiga(&j)) printf("Extraccion %i es %i\n",i++,j);
}//____________________________________________________


