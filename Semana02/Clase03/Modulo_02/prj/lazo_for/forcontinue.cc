//===============================================
//Archivo: forcontinue.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
//System Includes
//+++++++++++++++
#include <iostream>
using namespace std;

//User Includes
//+++++++++++++
#include "estructuras_de_control.h"

void ejecutar_lazo_continue(void)
{
  int x;
  for (x = 1; x <= 10; x++)
  {
    if (x <= 5) continue;  /* no imprime cuando x <= 5 */
    cout << x << " ";
   }
   cout << endl;
   cout << "Success" << endl;
}

