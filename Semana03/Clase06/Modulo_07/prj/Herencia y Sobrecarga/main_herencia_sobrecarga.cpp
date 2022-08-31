//===============================================
//Archivo: main_herencia_sobrecarga.cc
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
#include "herencia_sobrecarga.h"
int main(void)
{
  //Objeto de tipo _base_main
  //=========================
  {
    _base_main objeto(20);
    objeto.incrementar_contador();
    objeto.incrementar_contador();
    objeto.incrementar_contador();
    cout << "Valor del contador es :" << objeto.get_cuenta() << endl;

    _base &obj_padre=objeto;
    obj_padre.incrementar_contador();
    obj_padre.incrementar_contador();
    obj_padre.incrementar_contador();
    obj_padre.incrementar_contador();
    cout << "Valor del contador es :" << objeto.get_cuenta() << endl;
  }
  //Objeto de tipo _main
  //=====================
  {
    _main objeto(20);
    ++objeto;
    ++objeto;
    ++objeto;
    objeto++;
    cout << "Valor del contador es :" << objeto.get_cuenta() << endl;

    _base &obj_padre=objeto;
    obj_padre.incrementar_contador();
    obj_padre.incrementar_contador();
    obj_padre.incrementar_contador();
    obj_padre.incrementar_contador();
    cout << "Valor del contador es :" << objeto.get_cuenta() << endl;
  }
  return 0;
}//__________________________________________________________________
