//===============================================
//Archivo: main_quicksort.cc
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
//*****************
// quicksort
//*****************
void quicksort(int Vector[],int left, int right)
{
  int element = Vector[left];
  int left_in=left,right_in=right,reference;
  printf("tick...\n");
  while(left < right)
  {
    while ((Vector[right] >= element) && (left < right)) right--;
    if (left != right)
    {
      Vector[left] = Vector[right];
      Vector[right] = element;
      left++;
    }

    while ((Vector[left] < element) && (left < right)) left++;
    if (left != right)
    {
      Vector[right] = Vector[left];
      Vector[left] = element;
      right--;
    }
  }
  reference =left;
  left=left_in;
  right=right_in;
  if (left  < reference) quicksort(Vector,left,reference-1);
  if (right > reference) quicksort(Vector,reference+1,right);
}//_________________________________________________________

//*************
// Main()
//*************
int main(void)
{
  int a[N], i;

  printf("Enter %d numbers to be sorted: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  quicksort(a, 0, N - 1);

  printf("In sorted order: ");
  for (i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}//________________________________________________________________
