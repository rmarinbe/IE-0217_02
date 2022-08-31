//===============================================
//Archivo: herencia_sobrecarga.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include "herencia_sobrecarga.h"

//Class _base
//============
_base::_base(int Contador) :contador(Contador)
{}//______________________________________________________________

void _base::incrementar_contador(void)
{
  contador++;
}//______________________________________________________________

const int& _base::get_cuenta(void)
{
  return contador;
}//______________________________________

//Class _base_main
//================
_base_main::_base_main(int Contador) :_base(Contador),counter(Contador)
{}//______________________________________________________________

void _base_main::incrementar_contador(void)
{
  counter++;
}//______________________________________________________________

const int& _base_main::get_cuenta()
{
  return contador;
};//______________________________________

//Class _main
//================

_main::_main(int Counter) :_base_main(Counter)
{}//______________________________________________________________

int _main::operator++(void)
{
  return ++counter;
}//______________________________________________________________

int _main::operator++(int)
{
  return counter++;
}//_____________________________________________________________

const int& _main::get_cuenta(void)
{
  return counter;
}//______________________________________________________________

