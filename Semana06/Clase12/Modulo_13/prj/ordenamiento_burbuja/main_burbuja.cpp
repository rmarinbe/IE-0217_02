//===============================================
//Archivo: main_burbuja.cc
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

// Declaration of swap function
template<typename T>
void Swap(T &x, T &y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}//______________________________________________________________


template<typename T,int N>
void sort_selection(T a[N])
{
  // Selection Sort
  for (int i = 0; i < (N - 1); i++)
  {
    int minIndex = i;
    // Find the index of the minimum element
    for (int j = i + 1; j < N; j++)
    {
      if (a[j] < a[minIndex])  minIndex = j;
    }
    // Swap if i-th element not already smallest
    if (minIndex > i) Swap<T>(a[i], a[minIndex]);
  }//for
}//______________________________________________________________

//+++++++++++++++++
// main()
//+++++++++++++++++
int main(void)
{
  const int N = 10;
  //Initial array
  //=============
  int a[N] = {52, 1, 12, 16, 99, 1002,2001, 0, 79, 99};
  cout << "Inicial"<< endl;
  for (int i = 0; i < N; i++) cout << i << " " << a[i] << endl;

  //Sort array
  //==========
  sort_selection<int,10>(a);

  // Print sorted results
  //=====================
  cout <<"Final"<< endl;
  for (int i = 0; i < N; i++) cout << i << " " << a[i] << endl;
  return 0;
}//_______________________________________________________________


