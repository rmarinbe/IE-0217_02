//===============================================
//Archivo: main_flotante.cpp
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

int valor =10;
int main()
{
  double a = 12335545621232154.0E5;
  a = a + 1;
  a = a - 12335545621232154.0E5;
  cout << "El valor del float da: " << a << " y valor es " << valor << endl;
  return 0;
}
