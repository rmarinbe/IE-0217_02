//===============================================
//Archivo: main_estructuras_objeto.cpp
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

typedef struct S_objeto {
  int  valor;
  char *msg;
  bool  selected;

  S_objeto(int Valor=0):valor(Valor),selected(false)
  {
     msg = new char [MAXSIZE];
     selected = msg != NULL;
     if (selected) sprintf(msg,"");
  }//_________________________________

  int get_value(void)
  {
    return valor;
  }//_________________________________

  void set_msg(const char *txt)
  {
    if (selected) strcpy(msg,txt);
  }//_________________________________

}T_objeto;//__________________________________________________________________

int main(void)
{
  T_objeto objeto1,objeto2(30);
  objeto1.set_msg("Texto cadena 1");
  objeto2.set_msg("Texto cadena 2");

  cout  << "Objeto1.valor es " << objeto1.valor << " objeto1.get_value() es "
        << objeto1.get_value() << " objeto1.msg= " << objeto1.msg << endl;
  cout  << "Objeto2.valor es " << objeto2.valor << " objeto2.get_value() es "
        << objeto2.get_value() << " objeto2.msg= " << objeto2.msg << endl;
  return 0;
}//___________________________________________________________________________
