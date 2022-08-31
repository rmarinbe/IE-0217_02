//===============================================
//Archivo: main_herencia_multiple.cpp
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
#include "herencia_multiple.h"

//Definición de Clases
//=====================
using namespace std;

//MAIN
//=====
int main(void)
{
  _main objeto_heredado1,objeto_heredado2(20,90);
  cout << objeto_heredado1._base_a::variable_publica_base << endl;
  cout << objeto_heredado2.variable_publica_main << endl;
  cout << objeto_heredado1._base_a::suma_interna() << endl;
  return 0;
}//___________________________________________________

