//===============================================
//Archivo: herencia_basica.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include "herencia_basica.h"

//class _base
//===========
_base::_base(void)
{
  variable_privada_base=10;
  variable_protegida_base=30;
  variable_publica_base=10.77;
}//______________________________________________

_base::_base(int V_privada,int V_protegida)
{
  variable_privada_base=V_privada;
  variable_protegida_base=V_protegida;
  variable_publica_base=10.77;
}//______________________________________________

//class _main
//===========
_main::_main(void)
{
  variable_privada_main=770;
  variable_protegida_main=-90;
};//______________________________________

_main::_main(int V_privada,int V_protegida) :_base(V_privada,V_protegida)
{
  variable_privada_main=770;
  variable_protegida_main=-90;
};//______________________________________
