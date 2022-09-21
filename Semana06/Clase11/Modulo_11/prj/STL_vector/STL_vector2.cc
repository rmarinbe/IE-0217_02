//===============================================
//Archivo: STL_vector2.cc
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
#include "../Utilitarios/utilitarios.h"
//+++++++++++++++++++
// main_stl_vector2()
//+++++++++++++++++++
void main_stl_vector2 (void)
{
  vector<int> seq_numeros;
  int         input;
  cout << "Ingrese números simples (1 digito) separados con espacios y cualquier letra para terminar" << endl;
  while (cin >> input)
  {
    if ((input < 0) ||( input > 9)) break;
    seq_numeros.push_back (input);
  }//while

  vector<int> seq_derivada(seq_numeros);
  vector<int>::iterator first  = seq_derivada.begin();
  vector<int>::iterator last   = seq_derivada.end();

  //Efecto Pila
  while (first != last)
  {
    cout << "Valor: "<< *--last <<endl;
  }//while
  end_function();
}//_______________________________________________________________
