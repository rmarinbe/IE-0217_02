//===============================================
//Archivo: main_STL_list.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include <list>
#include <iostream>
using namespace std;

//+++++++++++++++
// main()
//+++++++++++++++
int main (void)
{
  list<int> v;

  cout << "Ingresando datos en una lista:" << endl;
  for (int i = 0; i < 5; i++)
  {
    v.push_back(2*i);
    v.push_front(i);
  }
  cout << "Recorriendo datos en una lista con iteradores:" << endl;

  list<int>::iterator first = v.begin();
  list<int>::iterator last  = v.end();
  while (first != last)
    cout << *first++ << " ";
  cout << endl;

  cout << "Extrayendo valores de la lista w en forma de cola: " ;
  list<int> w(v),x(v);
  while(!w.empty())
  {
    cout << w.front() << " ";
    w.pop_front();
  }
  cout << endl;

  cout << "Extrayendo valores de la lista x en forma de pila: " ;
  while(!x.empty())
  {
    cout << x.back() << " ";
    x.pop_back();
  }
  cout << endl;
}//___________________________________________________________________________
