//===============================================
//Archivo: Teoria_conjuntos.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================

#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T> void show(T i)
{
  cout << i << " " ;
}//________________________________________

template <typename T>
set<T> operator +(const set<T>&A, const set<T>&B)
{
  set<T> C;
  typename set<T>::const_iterator begin=A.begin(),end=A.end();
  while(begin!=end) C.insert(*begin++);
  begin=B.begin(),end=B.end();
  while(begin!=end) C.insert(*begin++);
  return C;
}//_________________________________________

template <typename T>
set<T> operator *(const set<T>&A, const set<T>&B)
{
  set<T> C;
  typename set<T>::const_iterator begin_A=A.begin(),end_A=A.end();
  typename set<T>::const_iterator begin_B=B.begin(),end_B=B.end();
  while((begin_A !=end_A) && (begin_B !=end_B))
    if (*begin_A < *begin_B) begin_A++;
        else if (*begin_B < *begin_A ) begin_B++;
          else
          {
            //El elemento existe en ambos conjuntos
            //+++++++++++++++++++++++++++++++++++++
            C.insert(*begin_A);
            begin_A++;
            begin_B++;
          }
  return C;
}//_________________________________________

int main(void)
{
  set<int> A,B;
  for (int i=0;i<20;i++) A.insert(i);
  for (int i=10;i<30;i++)B.insert(i);
  set<int> Union=A+B;
  set<int> Interseccion=A*B;
  cout << "Conjunto A "<< endl;
  for_each(A.begin(),A.end(),show<int>);   cout << endl;

  cout << "Conjunto B "<< endl;
  for_each(B.begin(),B.end(),show<int>);   cout << endl;

  cout << "Conjunto A+B "<< endl;
  for_each(Union.begin(),Union.end(),show<int>);  cout << endl;

  cout << "Conjunto A*B "<< endl;
  for_each(Interseccion.begin(),Interseccion.end(),show<int>);  cout << endl;

  getchar();
  return 0;
}//___________________________________________________________
