//===============================================
//Archivo: herencia_multiple.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include "herencia_multiple.h"

//class _base_a
//==============
_base_a::_base_a(void)
{
  variable_privada_base=10;
  variable_protegida_base=30;
  variable_publica_base=10.77;
}//______________________________________________

_base_a::_base_a(int V_privada,int V_protegida)
{
  variable_privada_base=V_privada;
  variable_protegida_base=V_protegida;
  variable_publica_base=10.77;
}//______________________________________________

int _base_a::suma_interna(void)
{
  return variable_privada_base+variable_protegida_base;
}//______________________________________________

//class _base_b
//==============
_base_b::_base_b(void)
{
  variable_privada_base=100;
  variable_protegida_base=-3;
  variable_publica_base=314.77;
}//______________________________________________

_base_b::_base_b(int V_privada,int V_protegida)
{
  variable_privada_base=V_privada;
  variable_protegida_base=V_protegida;
  variable_publica_base=0.77;
}//______________________________________________

int _base_b::suma_interna(void)
{
  return variable_privada_base+variable_protegida_base;
}//______________________________________________

//class _main
//===========
_main::_main(void) :_base_b(10,10)
{
  variable_privada_main=770;
  variable_protegida_main=-90;
  variable_publica_main=9.3;
};//______________________________________

_main::_main(int V_privada,int V_protegida) :_base_a(V_privada,V_protegida)
{
  variable_privada_main=770;
  variable_protegida_main=-90;
  variable_publica_main=9.3;
};//______________________________________
