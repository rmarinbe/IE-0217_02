//===============================================
//Archivo: main_STL_queue.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include <queue>
#include <iostream>
using namespace std;

//+++++++++++++++
// main()
//+++++++++++++++
int main (void)
{
  queue<int> v;

  cout << "Ingresando datos en una pila:" << endl;
  for (int i = 0; i < 5; i++)
  {
    v.push(i);
    cout << i << " ";
  }
  cout << endl;

  cout << "Extrayendo valores de la cola copia: " ;
  queue<int> w(v);
  while(!w.empty())
  {
    cout << w.front() << " ";
    w.pop();
  }
  cout << endl;

  cout << "Extrayendo valores de la cola original: " ;
  while(!v.empty())
  {
    cout << v.back() << " ";
    v.pop();
  }
  cout << endl;
}//___________________________________________________________________________
