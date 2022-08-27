//===============================================
//Archivo: externo.cpp
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
extern int dato_main;
extern int dato_publico;

//Habilitar la siguiente linea provoca un error en el linker ¿Porqué?
//#define COMPLETO
bool funcion_general(void)
{
  cout << "El valor del dato publico es accesible en " << dato_publico << endl;
  #ifdef COMPLETO
  cout << "El valor del dato main es inaccesible en " << dato_main << endl;
  #endif
  return true;
}

void funcion_reiterativa_1(void)
{
  int cuenta=10;
  cout << "El valor del dato local cuenta es " << ++cuenta << endl;
  return;
}

void funcion_reiterativa_2(void)
{
  static int cuenta=10;
  cout << "El valor del dato local cuenta es " << ++cuenta << endl;
}

