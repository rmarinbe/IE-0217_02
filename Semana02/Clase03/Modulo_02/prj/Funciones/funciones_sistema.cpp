//===============================================
//Archivo:funciones_sistema.cpp
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
/* Calculating compound interest */
#include <stdio.h>
#include <math.h>

double funcion_intereses(double Valor)
{
   int year;
   double amount, principal = Valor, rate = .05;

   printf("%4s%21s\n", "Año", "Cantidad en el depósito");

   for (year = 1; year <= 10; year++)
   {
      amount = principal * pow(1.0 + rate, year);
      printf("%i %f \n", year, amount);
   }
   return amount;
}//_________________________________________________________

