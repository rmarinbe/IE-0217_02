//===============================================
//Archivo:funciones_locales.cpp
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
/* A programmer-defined square function */
#include <stdio.h>

static double square(double);   /* function prototype */

double funcion_externa(double value)
{
   return square(value);
}

static double square(double y)
{
  return y * y;
}


