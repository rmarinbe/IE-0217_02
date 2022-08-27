//===============================================
//Archivo: main_class_general.cpp
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;
#define MAXSIZE 20

class _def_object{
private:
  int  valor;
  char *msg;
  bool  selected;

protected:
  float y;

public:
  _def_object(int=0);
  ~_def_object(void);
  int get_value(void);
  void set_msg(const char*);
  const char *get_msg(void);
};//__________________________________________________________

_def_object::_def_object(int Valor):valor(Valor),selected(false)
{
  msg = new char [MAXSIZE];
  selected = msg != NULL;
  if (selected) sprintf(msg,"");
}//_________________________________

_def_object::~_def_object(void)
{
  if (selected) delete msg;
}//_________________________________

int _def_object::get_value(void)
{
  return valor;
}//_________________________________

void _def_object::set_msg(const char *txt)
{
  if (selected) strcpy(msg,txt);
}//_________________________________

const char *_def_object::get_msg(void)
{
  if (selected) return msg;
    else return NULL;
}//_________________________________

//Eval
//=====
int eval(void)
{
  _def_object objeto1,objeto2(30);
  _def_object *ptr;
  ptr = new _def_object;
  objeto1.set_msg("Texto cadena 1");
  objeto2.set_msg("Texto cadena 2");

  cout  << " objeto1.get_value() es " << objeto1.get_value()
        << " objeto1.msg= " << objeto1.get_msg() << endl;

  cout  << " objeto2.get_value() es " << objeto2.get_value()
        << " objeto2.msg= " << objeto2.get_msg() << endl;
  delete ptr;
  return 0;
}//___________________________________________________________________________

// MAIN()
//========
int main(void)
{
  eval();
  return 0;
}//___________________________________________________________________________
