//===============================================
//Archivo: main_punteros_avanzados.cpp
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

struct S_estructura {
  int a, b;
} estructura, *e;

typedef struct S_datos{
  int a;
  float valor;
}T_datos;

typedef unsigned char byte;

typedef struct S_vector{
  byte    index;
  T_datos arreglo[MAX_DATA];
}T_vector;


void display_T_datos(T_datos *p)
{
  cout  << "Acceso a la estructura mediante puntero"
        << " parte a es " << p->a
        << " parte valor es " << p->valor << endl;
}//________________________________________________________

//MAIN()
//++++++++++
int main(void)
{
  T_datos simple = {10,20.7};
  T_datos *p=&simple;
  display_T_datos(p);

  T_datos grupo1[]={ {1,20},  {2,50.3},
                     {3,1.23},{4,3.23},
                     {4,9.27},{5,3.1415} };


  p=grupo1;
  for (unsigned int i=0; i<  sizeof(grupo1)/sizeof(T_datos)  ;i++)
    display_T_datos(p++);

  T_vector *q = new T_vector;
  e = new S_estructura;

  //Condición universal de error
  //=============================
  if (!e) exit(1);
  if (!q) exit(1);
  const unsigned int size = sizeof(q->arreglo)/sizeof(T_datos);
  for (unsigned int i=0; i < size; i++ )
  {
    q->index=i;
    q->arreglo[i].a=i*2;
    q->arreglo[i].valor=2.9;
  }
  delete q;
  delete e;
  return 0;
}//__________________________________________
