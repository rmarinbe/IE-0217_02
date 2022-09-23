//===============================================
//Archivo: main_quicksort_class_T.cc
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

//+++++++++++++++++++++
// main() program
//+++++++++++++++++++++
//+++++++++++++++++++++
// main() program
//+++++++++++++++++++++
#include "quicksort_class_T.h"
int main(void)
{
  int *a;
  int   n,i;

  //Arreglo de enteros leido y ordenado.
  //===================================
  printf("Enter the amount of data to be ordered:");
  scanf("%d",&n);
  a= new int [n];
  printf("Enter %d integer numbers to be sorted: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  quicksort<int> qsrt(a,n);
  qsrt.sort();

  printf("In sorted order: ");
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
  delete [] a;

  //Arreglo de floats
  float *b= new float [n];
  printf("Enter %d float numbers to be sorted: ", n);
  for (i = 0; i < n; i++)
    scanf("%f", &b[i]);

  quicksort<float> qsrtf(b,n);
  qsrtf.sort();

  printf("In sorted order: ");
  for (i = 0; i < n; i++)
    printf("%f ", b[i]);
  printf("\n");
  delete [] b;

  return 0;
}//________________________________________________________________
