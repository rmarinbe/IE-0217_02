//===============================================
//Archivo: puntero1.cc
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
#include "punteros.h"
#include "../../utilitarios/utilitarios.h"
#define MAXINT 20

void manipulacion_punteros(void)
{
  int a;
  int *p=&a;
  a=10;
  printf("El puntero p tiene el valor de %i \n",*p);
  end_function();
}//_______________________________________________________________

void puntero_a_cadena(void)
{
  char *msg="Una prueba con cadenas \n";
  char*p=msg;
  printf("El puntero p tiene la cadena de caracteres: %s \n",p);
  end_function();
}//_______________________________________________________________

void puntero_a_vector(void)
{
  int a[MAXINT]={2,4,8,14,30,8,90,80,77,3};
  int *p=a;
  for (int i=0;i<MAXINT;i++) printf("A[%i] es: %i \n",i,*p++);
  end_function();
}//______________________________________________________________

