//===============================================
//Archivo: STL_vector3.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#define __MINMAX_DEFINED
#include <vector>
#include <iostream>

using namespace std;
#include "../Utilitarios/_complex.h"
#include "../Utilitarios/utilitarios.h"
//+++++++++++++++++++
// main_stl_vector3()
//+++++++++++++++++++
void main_stl_vector3 (void)
{
  vector<_complex> v(5);

  for (int i = 0; i < 5; i++)
  {
    v[i][0] = 2*i;
    v[i][1] = -3*i;
  }
  cout << "Se han escrito estos 5 valores a vector<_complex>: " << endl;

  for (int i = 0; i < 5; i++)
    cout << v[i] << " "; // print values to cout
  cout << endl;

  vector<_complex>::iterator first = v.begin();

  vector<_complex>::iterator last = v.end();
  cout << "Recorriendo el vector con iteradores:" << endl;

  while (first != last)
    cout << *first++ << " ";
  cout << endl;

  cout << "Insertando valores a vector: " << endl;
  for (int i = 0; i < 5; i++)
    v.push_back(_complex(i,i*2));

  for (int i = 0; i < 5; i++)
   cout << v[i] << " "; // print values to cout
  cout << endl;

  end_function();
}//_______________________________________________________________
