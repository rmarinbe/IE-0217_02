//===============================================
//Archivo: main_estructuras.cpp
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
#include "../../utilitarios/utilitarios.h"

struct S_estr1 {
  int   a;
  char  b;
  float c;
}R,S,T;

struct S_tarjeta {
   int valor;
   int tiempo;
};

typedef struct S_tarjeta T_tarjeta;

typedef union U_number {
   int x;
   float y;
}T_number;

int main(void)
{
  struct S_estr1 inicio;
  void estructuras_uniones(void);
  void estructuras_bits(void);
  int  s;
  inicio.a=10;
  inicio.b='z';
  inicio.c=10.3445;
  R=inicio;
  s=10;
  inicio.a=inicio.a+s;
  cout << inicio.a << endl;

  //Definición de nuevos tipos.
  //===========================
  T_tarjeta visa;
  visa.valor  =10000;
  visa.tiempo = 10;

  cout << "Partes de tarjeta "<< visa.valor <<" "<< visa.tiempo<< endl;

  T_number dual;
  dual.x=10;
  cout << "dual.x "<< dual.x << "visto como float es dual.y " << dual.y << endl;
  dual.y=3.1415;
  cout << "dual.y "<< dual.y << "visto como int es dual.x " << dual.x << endl;
  end_function();
  estructuras_uniones();
  estructuras_bits();
  return 0;
}//______________________________________________________________________________
