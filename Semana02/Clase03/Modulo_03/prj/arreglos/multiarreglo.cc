//===============================================
//Archivo: multiarreglo.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
/* Initializing multidimensional arrays */
#include <stdio.h>

static void printArray(int [][3]);

void multi_array(void)
{
  int array1[2][3] = { {1, 2, 3}, {4, 5, 6} },
      array2[2][3] = { {1, 2, 3}, {4, 5} },
      array3[2][3] = { {1, 2}, {4} };

  printf("Valores en \"array1\" por fila :\n");
  printArray(array1);

  printf("Valores en \"array2\" por fila :\n");
  printArray(array2);

  printf("Valores en \"array3\" por fila :\n");
  printArray(array3);
}//___________________________________________________

static void printArray(int a[][3])
{
  int i, j;

  for (i = 0; i <= 1; i++)
  {
    for (j = 0; j <= 2; j++)
      printf("%d ", a[i][j]);;
    printf("\n");
  }
}//___________________________________________________

