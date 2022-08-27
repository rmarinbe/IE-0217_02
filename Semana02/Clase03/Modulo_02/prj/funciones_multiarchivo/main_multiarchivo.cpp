//===============================================
//Archivo:main_multiarchivo.cpp
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
#include "multiarchivo.h"

int main()
{
  int valor=0;
  cout << "Llamado a función en archivos múltiples, valor =" << funcion_publica(valor,10) << endl;
  cout << "Primer contacto con fallos por excepción. División por cero "<< funcion_division(valor,0) << endl;
  cout << "Esta línea no se ejecutará." << endl;
  return 0;
}//_______________________________________________________________________
