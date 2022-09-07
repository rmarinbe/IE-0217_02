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
#include <iostream>
using namespace std;

#include "pila_dinamica_template.h"
#include "../utilitarios/_complex.h"

int main(void)
{
  _pila<int>   pila1;
  for(int i=0;i<20;i++)
    pila1.push(i);

  int i=0,j=-1;
  while(pila1.pop(&j)) printf("Extraccion %i es %i\n",i++,j);

  _pila<float>   pila2;

  for(int i=0;i<20;i++)
    pila2.push(i);

  i=0;
  float valor=0;
  while(pila2.pop(&valor)) printf("Extraccion %i es %f\n",i++,valor);

  _pila<_complex>   pila3;

  for(int i=0;i<20;i++)
    pila3.push(i);

  i=0;
  _complex value;
  while(pila3.pop(&value)) cout << "Extraccion " << i++<< " es " << value << endl;
}//____________________________________________________
