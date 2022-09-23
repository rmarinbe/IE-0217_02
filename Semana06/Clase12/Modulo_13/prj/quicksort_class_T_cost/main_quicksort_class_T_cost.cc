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
#define DEBUG

#include <cmath>
#include <stdio.h>
#include <iostream>

using namespace std;
int N;
//*****************
// class quicksort
//*****************
template <class T>
class quicksort {
 private:
#ifdef DEBUG
   int count,total;
#endif
   T    *Vector;
   int   Size;
   void _quicksort(int,int);
 public:
   quicksort(T [],int);
   void sort(void);
};//_______________________________________________________________

//*******************
// class qsort
//+++++++++++++++++
// implementation
//*******************
template <class T> void quicksort<T>::_quicksort(int left, int right)
{
  T element = Vector[left];
  int left_in=left,right_in=right,reference;

  while(left < right)
  {
     while ((Vector[right] >= element) && (left < right)) { right--;total++;}
     if (left != right)
     {
       Vector[left] = Vector[right];
       Vector[right] = element;
       left++;
#ifdef DEBUG
       count++;
#endif
     }

     while ((Vector[left] < element) && (left < right)) {left++; total++;}
     if (left != right)
     {
       Vector[right] = Vector[left];
       Vector[left] = element;
       right--;
#ifdef DEBUG
       count++;
#endif
     }
  }
  reference =left;
  left=left_in;
  right=right_in;
  if (left  < reference) _quicksort(left,reference-1);
  if (right > reference) _quicksort(reference+1,right);
}//_________________________________________________________


template <class T> void quicksort<T>::sort(void)
{
  _quicksort(0,Size-1);
#ifdef DEBUG
   cerr << "Debug::Total exchanges: " << count << " Total comparations: " <<total <<endl;
#endif
}//__________________________________________________________

template <class T> quicksort<T>::quicksort(T vector[],int size)
{
  Vector=vector;
  Size=size;
#ifdef DEBUG
  count=total=0;
#endif
}//___________________________________________________________


//+++++++++++++++++++++
// main() program
//+++++++++++++++++++++
int main(void)
{

  //Forma 1
  //=======
  {
    int   n=25,i;
    int *a;
    a= new int [n];
    for (int i=0;i< n;i++) a[i]=n-i;
    printf("Input table\n");
    for (i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    quicksort<int> qsrt(a,n);
    qsrt.sort();

    cout << "In sorted order: " << endl;
    for (i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    delete [] a;
    getchar();
  }

  //Forma 2
  //=======
  {
    int   n=25,i;
    int *a;
    a= new int [n];
    for (int i=0;i< n;i++) a[i]=i;
    printf("Input table\n");
    for (i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    quicksort<int> qsrt(a,n);
    qsrt.sort();

    cout << "In sorted order: " << endl;
    for (i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    delete [] a;
    getchar();
  }

  //Forma 3
  //=======
  {
    int   n=25,i;
    int *a;
    a= new int [n];
    for (int i=0;i< n/2;i++) a[2*i]=i;
    printf("Input table\n");
    for (i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    quicksort<int> qsrt(a,n);
    qsrt.sort();

    cout << "In sorted order: " << endl;
    for (i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    delete [] a;
    getchar();
  }

  //Forma 4
  //=======
  {
    int   n=25,i;
    int *a;
    a= new int [n];
    for (int i=0;i< n/2;i++) a[2*i+1]=n-i;
    printf("Input table\n");
    for (i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    quicksort<int> qsrt(a,n);
    qsrt.sort();

    cout << "In sorted order: " << endl;
    for (i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    delete [] a;
  }
  return 0;
}//________________________________________________________________
