//===============================================
//Archivo: string1.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
//Operaciones con cadenas de caracteres
//======================================

#include <stdio.h>
#include "cadenas.h"
#include "../../utilitarios/utilitarios.h"

static void convertToUppercase(char *);
static int LongitudCadena(char cad[]);
void manipulacion_cadenas1(void)
{
  char string1[20], string2[] = "string literal";
  int i;

  printf("Ingrese una cadena de caracteres: ");
  scanf("%s", string1);
  printf("'string1' es: %s\n 'string2'es: %s\n"
         "'string1' separado con espacios es :\n",
          string1, string2);

  for (i = 0; string1[i] != '\0'; i++)
    printf("%c ", string1[i]);
  printf("\n");
  end_function();
}//_____________________________________________

//Manipulación básica de punteros implícitos en cadenas de caracteres
//===================================================================
void manipulacion_cadenas2(void)
{
  char string[] = "Curso de programación en C/C++";
  printf("La cadena antes de la conversión es: %s\n", string);
  convertToUppercase(string);
  printf("La cadena luego de convertirse es:  %s\n", string);
  end_function();
}//_________________________________________________________________


//Dualidad cadena vector de las cadenas de caracteres.
//===================================================================
void manipulacion_cadenas3(void)
{
  char Saludo[5];
  Saludo[0] = 'H';
  Saludo[1] = 'O';
  Saludo[2] = 'L';
  Saludo[3] = 'A';
  Saludo[4] = '\0';
  printf("Vector de caracteres como cadena es : %s y mide %i  \n",Saludo,
         LongitudCadena(Saludo));
  {
    char Cadena[20]="Esto es una prueba";
    printf("Vector asignado a string : \" %s \"y mide %i  \n",Cadena,
          LongitudCadena(Cadena));
  }
  {
    char Cadena[]="Esto es una prueba";
    printf("Vector asignado a string : \" %s \"y mide %i  \n",Cadena,
          LongitudCadena(Cadena));
  }
  end_function();
}

//Static utilities
//=================
void convertToUppercase(char *s)
{
  while (*s != '\0')
  {
    if (*s >= 'a' && *s <= 'z')
      *s = *s-'a'+ 'A';         /* conversión ASCII a uppercase letter */
    ++s;                        /* incremento a siguiente posición*/
  }
}//__________________________________________________________________

int LongitudCadena(char cad[])
{
  int l = 0;
  while(cad[l]) l++;
  return l;
}//_____________________________________________
