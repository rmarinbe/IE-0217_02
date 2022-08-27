//System Includes
//+++++++++++++++
//===============================================
//Archivo: for_anidados.cc
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

//User Includes
//+++++++++++++
#include "estructuras_de_control.h"

void ejecutar_lazo_for_anidados(void)
{
  int i=0,j=0,x=0, y=0;
  cout << "Ejemplo con for anidado" << endl;

  cout <<"Ingrese dos enteros entre 1-20: ";
  cin >> x >> y;

  for (int  i = 1; i <= y; i++)
  {
    for ( int j = 1; j <= x; j++)
      cout << "@";
    cout << endl;
  }//for int j
  cout << "El valor de i es " << i <<" y el de j es "<<j <<endl;
}//____________________________________________________________

