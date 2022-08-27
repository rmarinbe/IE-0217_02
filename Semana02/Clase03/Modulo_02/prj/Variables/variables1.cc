//+++++++++++++++++++++++++++++
//Variables1.cc
//Curso C/C++ Basico-Avanzado.
//+++++++++++++++++++++++++++++
//Tipos, variables y alcance de
//variables.
//+++++++++++++++++++++++++++++++++
#include <stdio.h>


//===============================================
//Archivo:variables1.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================

enum dias_semana {lunes=0,martes,miercoles,jueves,viernes,sabado,domingo};
bool funcion_externa(void)
{
   int integer1=10,integer2=20;
   dias_semana tercero=miercoles;
   int sum;
   float flotante_numero1;
   double big_float=20e200;
   char   a='X';
   bool verdad=false;

   flotante_numero1=3.14;
   printf(" Dia de la semana es %i",tercero);
   printf(" Flotante núnero 1 es %f",flotante_numero1);
   printf(" Big Flotanet es %g",big_float);
   printf(" Caracter es %c y boolean es %i",a,verdad);
   printf("Ingrese primer entero (valor actual %d) \n",integer1);  /* prompt */
   scanf("%i", &integer1);  // El & delante del integer1 implica que scanf recibe una dirección y no un valor.
   printf("Ingrese segundo entero\n"); /* prompt */
   scanf("%d", &integer2);  // El & delante del integer2 implica que scanf recibe una dirección y no un valor.
   sum = integer1 + integer2;
   printf("Suma da %d\n", sum);
   return true;
}//_________________________________________________________________________________
