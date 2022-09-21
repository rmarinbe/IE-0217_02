//===============================================
//Archivo: main_STL_stack.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include <stack>
#include <iostream>
using namespace std;

//+++++++++++++++
// main()
//+++++++++++++++
int main (void)
{
  stack<int> v;

  cout << "Ingresando datos en una pila:" << endl;
  for (int i = 0; i < 5; i++)
  {
    v.push(i);
    cout << i << " ";
  }
  cout << endl;

  cout << "Extrayendo valores de la pila: " ;
  while(!v.empty())
  {
    cout << v.top() << " ";
    v.pop();
  }
  cout << endl;

}//___________________________________________________________________________
