//===============================================
//Archivo: exception_class.cc
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
#include "exception_class.h"
_exception::_exception(string Msg): msg(Msg)
{
}//______________________________________________________________

void _exception::getMessage(void)
{
    cout << "Undefined error handler by base exception class...!" << endl;
}//______________________________________________________________

_exception::~_exception(void)
{
}//______________________________________________________________
