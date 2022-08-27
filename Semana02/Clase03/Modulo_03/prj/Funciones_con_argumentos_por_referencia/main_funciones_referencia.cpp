//===============================================
//Archivo: main_funciones_referencia.cpp
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

#define MAX_DATA 20
//#define FALLA

typedef struct S_int{
  int *valor;
}T_int;

typedef unsigned char byte;

void maximo(int a,int b,int *c)
{
  *c = a>b ? a : b;
}//__________________________________________________

void asigne_int(int *d)
{
   d = new int;
  *d = 10;
  cout << "Valor local es "<< *d << endl;
}//__________________________________________________

void asigne_int_ref(int **d)
{
  *d  = new int;
  **d = 10;
  cout << "Valor local es "<< **d << endl;
}//__________________________________________________

void asigne_struct(T_int *d)
{
  d->valor  = new int;
  *d->valor  = 10;
  cout << "Valor local es "<< *d->valor << endl;
}//__________________________________________________


//MAIN()
//++++++++++
int main(void)
{
  int a=50,b=30,c,*d,*e;
  T_int entero;

  maximo(a,b,&c);
  cout << "El máximo entre a(" << a << ") y b("<< b<<") es "<< c << endl;

  e = d = new int;
  *e=20;
  cout << "El valor del contenido de d es " << *d << endl;

  asigne_int(d);
  cout << "El valor del contenido de d es " << *d << endl;

  #ifndef FALLA
  asigne_int_ref(&d);
  #endif
  cout << "El valor del contenido de d es " << *d << endl;

  asigne_struct(&entero);
  cout << "El valor del contenido de entero es " << *entero.valor << endl;

  delete e;
  delete d;
  delete entero.valor;
  return 0;
}//______________________________________________________________________________

