//===============================================
// Archivo: throw4.cpp
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
#include <string>
using namespace std;

// MAIN()
//========
int main(void)
{
  int x = 5;
  int y = 0;
  int result;
  try
  {
    if (y == 0)
    {
      string s = "Divide by zero";
      throw s;
    }
    result = x/y;
    printf("Resultado %i",result);
  }
  catch (string e)
  {
    cout << e << endl;
  }
  cout << "Goodbye" << endl;
  return 0;
}//________________________________________________
