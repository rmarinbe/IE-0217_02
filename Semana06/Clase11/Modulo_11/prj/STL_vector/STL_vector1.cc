//===============================================
//Archivo: STL_vector1.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================

// use STL's generic min and max templates
#define __MINMAX_DEFINED
#include <vector>             // include STL vector implementation
#include <iostream>
using namespace std;
#include "../Utilitarios/utilitarios.h"
//++++++++++++++++++++
// main_stl_vector1()
//++++++++++++++++++++
void main_stl_vector1(void)
{
  vector<int> v(5);             // define a vector of int and
                                // reserve memory for five elements
  for (int i = 0; i < 5; i++)
    v[i] = 2*i;                 // store arbitrary values into v[0] to v[4]
  cout << "Se han escrito estos 5 valores a vector<int>:" << endl;

  for (int i = 0; i < 5; i++)
    cout << v[i] << " "; // print values to cout
  cout << endl;

  // of course you can also use iterators
  // define an iterator to the first vector element
  vector<int>::iterator first = v.begin();

  // define an iterator past the last vector element
  vector<int>::iterator last = v.end();
  cout << "Recorriendo el vector con iteradores:" << endl;

  while (first != last)
    cout << *first++ << " "; // first the iterator is dereferenced,
    // then it is incremented
  cout << endl;
 end_function();
}//___________________________________________________________________________
