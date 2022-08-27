//===============================================
//Archivo: main_friend_iostream.cpp
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
#include "complex.h"

int main(void)
{
  _complex a(2,2),b(3,3),c(0,0);

  c=a+b;
  cout << "Complex suma da " << c << endl;

  c=a-b;
  cout << "Complex resta da " << c << endl;

  c=a*b;
  cout << "Complex producto da " << c << endl;

  c=a/b;
  cout << "Complex división da " << c << endl;

  return 0;
}//_______________________________
