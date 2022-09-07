//===============================================
//Archivo: main_pila_vector.cpp
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmete para material didactico.
//==========n=====================================
#include <stdio.h>
#include <stdlib.h>
#include "pila_estatica.h"

void procese(void)
{
   _pila stack,stk;
   for (int i=0;i<20;i++)
     stack.push(i);
   stk=stack;
   printf("Pila creada y llena\n");
   for (int i=0;i<20;i++)
     printf("Desapilando stack:... %i Valor %i \n",i,stack.pop());

   for (int i=0;i<20;i++)
     printf("Desapilando stk:... %i Valor %i \n",i,stk.pop());
}//_____________________________________________________________

int main(void)
{
   procese();
}//_____________________________________________________________
