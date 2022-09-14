//===============================================
// Archivo: main_listas_abstractas_T_polimorficas.cc
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

#include "../Utilitarios/utilitarios.h"
#include "../Utilitarios/_complex.h"
#include "lista_polimorfica.h"
#include "pila_abstracta.h"
#include "pila_dinamica_template++.h"
#include "cola_abstracta.h"
#include "cola_dinamica_template++.h"

int main(void)
{
  _cola<int> cola;
  _pila<int> pila;
  int valor=10;

  for (int i=0;i<10;i++) pila.push(i*valor+7);
  _list &p=pila;
  _list &q=cola;
  q=p;

  cola.gotop(&valor);
  do{
    printf("Revision de cola entera es %i\n",valor);
  } while(cola.prev(&valor));

  while(pila.pop(&valor)) printf("Extraccion de pila es %i\n",valor);
  printf("Pulse cualquier tecla para continuar...\n");
  getchar();

  float dato=10.2;
  _pila<float> pila1;
  _cola<float> cola1;
  for (int i=0;i<10;i++)
    cola1.inserte(i*dato+7);
  cola1.gotop(&dato);
  do{
    printf("Revision de cola float es %f\n",dato);
  } while(cola1.prev(&dato));

  _list &r=pila1;
  _list &s=cola1;
  r=s;
  while(pila1.pop(&dato)) printf("Extraccion de pila es %f\n",dato);
}//____________________________________________________


