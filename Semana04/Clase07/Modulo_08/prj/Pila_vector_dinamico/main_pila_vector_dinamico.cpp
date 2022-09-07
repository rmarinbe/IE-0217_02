//===============================================
//Archivo: main_pila_vector_dinamico.cpp
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
#include "pila_vector_dinamico.h"

void procese(void)
{
   _pila stack(20);
   for (int i=0;i<20;i++)
     stack.push(i);
   _pila stk(stack);

   printf("Pila creada y llena\n");
   for (int i=0;i<20;i++)
     printf("Desapilando Copia:... %i Valor %i \n",i,stk.pop());

   for (int i=0;i<20;i++)
     stk.push(5);

   for (int i=0;i<20;i++)
     printf("Desapilando Original:... %i Valor %i,   %i \n",i,stack.pop(),stk.pop());
}//_____________________________________________________________

int main(void)
{
  procese();
  return 0;
}//_____________________________________________________
