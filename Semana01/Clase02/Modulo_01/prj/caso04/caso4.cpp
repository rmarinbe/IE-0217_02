//===============================================
//Archivo: caso4.cpp
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#include <stdio.h>
#include <iostream>
#include "funciones.h"
using namespace std;
int variable_global=10;

extern float suma(float,float);

int main(void)
{
   int variable_global=30;
   cout << "La suma  de 20.3 y 40.2 da " << suma(20.3,40.2) << endl;
   variable_global++;
   getchar();
}//________________________________________
