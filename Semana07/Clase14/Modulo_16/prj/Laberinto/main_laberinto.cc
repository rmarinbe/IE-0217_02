//===============================================
//Archivo: main_laberinto.cc
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
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;

#include "laberinto.h"

int main (void)
{
  _laberinto laberinto("laberinto_ref.txt");
  if (!laberinto.checkfile())
    cout << "Archivo no consistente con laberinto" << endl;
  laberinto.ver();
  if (laberinto.resolver())
  {
    laberinto.ver_solucion();
    laberinto.ver_coordenadas_solucion();
  }
}//_____________________________________________________________________





