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
#define N 25
#define DEBUG
#include <iostream>
using namespace std;

// Declaration of swap function
void swap(int &x, int &y,int &cnt)
{
#ifdef DEBUG
   static int count=0;
#endif
    int temp;
    temp = x;
    x = y;
    y = temp;

#ifdef DEBUG
  ++count ;
  cnt++;
#endif
}//______________________________________________________________

void selection_sort(int a[N],int &total,int &cnt)
{
  // Selection Sort
  for (int i = 0; i < (N - 1); i++)
  {
    int minIndex = i;
    // Find the index of the minimum element
    for (int j = i + 1; j < N; j++)
    {
      total++;
      if (a[j] < a[minIndex])  minIndex = j;
    }
    // Swap if i-th element not already smallest
    if (minIndex > i) swap(a[i], a[minIndex],cnt);
  }//for
}//______________________________________________________________
//+++++++++++++++++
// main()
//+++++++++++++++++
int main()
{
  int total,excnt;
  int a[N];

  // Selection Sort
  total=excnt=0;
  for (int i=0;i< N;i++) a[i]=N-i;
  for (int i = 0; i < N; i++) cout << i << " " << a[i] << endl;
  selection_sort(a,total,excnt);
  printf("Loops: %i Exchanges: %i\n",total,excnt);
  getchar();

  total=excnt=0;
  for (int i=0;i< N;i++) a[i]=i; //Min Work
  for (int i = 0; i < N; i++) cout << i << " " << a[i] << endl;
  selection_sort(a,total,excnt);
  printf("Loops: %i Exchanges: %i\n",total,excnt);
  getchar();

  total=excnt=0;
  for (int i=0;i< N/2;i++) a[2*i]=i;
  for (int i = 0; i < N; i++) cout << i << " " << a[i] << endl;
  selection_sort(a,total,excnt);
  printf("Loops: %i Exchanges: %i\n",total,excnt);
  getchar();

  total=0;
  for (int i=0;i< N/2;i++) a[2*i+1]=N-i;
  for (int i = 0; i < N; i++) cout << i << " " << a[i] << endl;
  selection_sort(a,total,excnt);
  printf("Loops: %i Exchanges: %i\n",total,excnt);
  getchar();

  return 0;
}//_______________________________________________________________


