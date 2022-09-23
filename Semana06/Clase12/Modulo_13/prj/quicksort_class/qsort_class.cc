//===============================================
//Archivo: quicksort_class.cc
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
//*****************
// class quicksort
// implementation
//*******************

void quicksort::_quicksort(int left, int right)
{
  int element = Vector[left];
  int left_in=left,right_in=right,reference;

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
  if (left  < reference) _quicksort(left,reference-1);
  if (right > reference) _quicksort(reference+1,right);
}//_________________________________________________________

void quicksort::sort(void)
{
  _quicksort(0,Size-1);
}//__________________________________________________________

quicksort::quicksort(int vector[],int size)
{
  Vector=vector;
  Size=size;
}//___________________________________________________________
