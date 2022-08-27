//===============================================
//Archivo: main_while.cpp
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

int main(void)
{
  int row = 10, column;
  while (row >= 1)
  {
    column = 1;
    while (column <= 10)
    {
      //if implicito ?:
      //===============
      char v=row % 2 ? '<' : '>';
      cout << v;
      ++column;
    }
    --row;
    cout << endl;
  }

  int counter = 1;
  do {
    cout <<  counter << " ";
  } while (counter++ <= 10);
  cout << endl;
  return 0;
}

