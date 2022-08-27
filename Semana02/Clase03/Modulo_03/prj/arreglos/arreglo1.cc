//===============================================
//Archivo: arreglo1.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
/* initializing an array */
#include <stdio.h>
#include "arreglos.h"

#define MAXARRAY 15
#define SIZE 10

void arreglo_basico1(void)
{
  //Arreglo asignado programáticamente
  //==================================

  int n[MAXARRAY], i;
  for (i = 0; i < MAXARRAY; i++)
    n[i] = i*20;

  printf("%s%13s\n", "Elementos", "Valores");
  for(i = 0; i < MAXARRAY; i++)        /* print array */
    printf("%7d%13d\n", i, n[i]);
  end_function();
}//_________________________________________________________

void arreglo_basico2(void)
{
  //Arreglo asignado estáticamente
  //==================================
  int n[10] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};
  int i;

  printf("%s%13s\n", "Element", "Value");

  for(i = 0; i <= 9; i++)
    printf("%7d%13d\n", i, n[i]);

  end_function();
}//__________________________________________________________

void arreglo_basico3(void)
{
  //Arreglo manipulando caracteres uno a uno
  //=========================================

  int n[SIZE] = {19, 3, 15, 7, 11, 9, 13, 5, 17, 1};
  int i, j;

  printf("%s%13s%17s\n", "Element", "Value", "Histogram");

  for (i = 0; i <= SIZE - 1; i++)
  {
    printf("%7d%13d        ", i, n[i]);
    for(j = 1; j <= n[i]; j++)  printf("%c", '*');
    printf("\n");
  }
  end_function();
}//__________________________________________________________

//===========
// UTILITIES
//===========
void end_function(void)
{
  printf("Fin de función. Pulsar tecla para continuar..\n");
  getchar();
}//__________________________________________________________
