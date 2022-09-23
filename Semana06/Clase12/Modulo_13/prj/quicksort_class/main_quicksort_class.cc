//===============================================
//Archivo: main_quicksort_class.cc
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
#define N 10
#include "quicksort_class.h"
//*************
// Main()
//*************
int main(void)
{
  int a[N], i;
  printf("Enter %d numbers to be sorted: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  quicksort qsrt(a,N);
  qsrt.sort();

  printf("In sorted order: ");
  for (i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}//________________________________________________________________
