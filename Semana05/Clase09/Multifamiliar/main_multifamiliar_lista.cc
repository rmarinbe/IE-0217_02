//===============================================
// Archivo: main_multifamiliar_lista.cc
//===============================================
// Curso de Estructuras Abstractas y Algoritmos
// Profesor: Freddy Rojas.
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didáctico.
//===============================================
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
#include "cola_dinamica_template.h"
#include "habitacional.h"
typedef struct SS_pareja{
  float ancho,largo;
}TT_pareja;
//++++++++++++++++++++++
//  MAIN ()
//++++++++++++++++++++++
int main(void)
{
   _edificio edif1;
  T_pareja piso11[]={
                    {20,15},{20,15},{20,15},{20,15},{20,15},{20,15},
                    {20,15},{20,15},{20,15},{20,15},{20,15},{20,15}
                   };
  T_pareja piso12[]={
                    {20,15},{20,15},{20,15},{20,15},{20,15},{20,15},
                    {20,15},{20,15},{20,15},{20,15},{20,15},{20,15}
                   };

  T_pareja piso13[]={
                    {12,12},{12,12},{12,12},{12,12},{12,12},{12,12},
                    {12,12},{12,12},{12,12},{12,12},{12,12},{12,12}
                   };
  _edificio edif2;
  T_pareja piso21[]={
                    {20,15},{20,15},{20,15},{20,15},{20,15},{20,15},
                    {20,15},{20,15},{20,15},{20,15},{20,15},{20,15}
                   };
  T_pareja piso22[]={
                    {20,15},{20,15},{20,15},{20,15},{20,15},{20,15},
                    {20,15},{20,15},{20,15},{20,15},{20,15},{20,15}
                   };

  T_pareja piso23[]={
                    {12,12},{12,12},{12,12},{12,12},{12,12},{12,12},
                    {12,12},{12,12},{12,12},{12,12},{12,12},{12,12}
                   };

  _edificio edif3;
  T_pareja piso31[]={
                    {20,15},{20,15},{20,15},{20,15},{20,15},{20,15},
                    {20,15},{20,15},{20,15},{20,15},{20,15},{20,15}
                   };
  T_pareja piso32[]={
                    {20,15},{20,15},{20,15},{20,15},{20,15},{20,15},
                    {20,15},{20,15},{20,15},{20,15},{20,15},{20,15}
                   };

  T_pareja piso33[]={
                    {12,12},{12,12},{12,12},{12,12},{12,12},{12,12},
                    {12,12},{12,12},{12,12},{12,12},{12,12},{12,12}
                   };
  _habitacional complejo;

  int size11=sizeof(piso11)/sizeof(T_pareja);
  int size12=sizeof(piso12)/sizeof(T_pareja);
  int size13=sizeof(piso13)/sizeof(T_pareja);

  edif1.inserte_piso(piso11,size11);
  edif1.inserte_piso(piso12,size12);
  edif1.inserte_piso(piso13,size13);

  int size21=sizeof(piso21)/sizeof(T_pareja);
  int size22=sizeof(piso22)/sizeof(T_pareja);
  int size23=sizeof(piso23)/sizeof(T_pareja);

  edif2.inserte_piso(piso21,size21);
  edif2.inserte_piso(piso22,size22);
  edif2.inserte_piso(piso23,size23);

  int size31=sizeof(piso31)/sizeof(T_pareja);
  int size32=sizeof(piso32)/sizeof(T_pareja);
  int size33=sizeof(piso33)/sizeof(T_pareja);

  edif3.inserte_piso(piso31,size31);
  edif3.inserte_piso(piso32,size32);
  edif3.inserte_piso(piso33,size33);

  complejo.inserte_edificio(&edif1);
  complejo.inserte_edificio(&edif2);
  complejo.inserte_edificio(&edif3);

  complejo.calcular_habitacional();

  float total_area_construccion=complejo.area_total_construccion();
  float total_area_efectiva_construccion=complejo.area_efectiva_construccion();
  float total_area_terreno=complejo.area_terreno();

  cout << "\nArea construccion complejo: " <<  total_area_construccion
       << "\nArea Efectiva construccion: " <<  total_area_efectiva_construccion
       << "\nArea terreno complejo considerando vehiculos+zonas verdes: " << total_area_terreno;


  getchar();
  return 0;
}//____________________________________________________
