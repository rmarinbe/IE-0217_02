//===============================================
// Archivo: habitacional.cc
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
#define DEBUG
using namespace std;
#include "cola_dinamica_template.h"
#include "habitacional.h"
_piso::_piso(void)
{
  total_area=total_area_efectiva=0.0;
  total_apartamentos=0;
};//________________________________________


bool _piso::inserte_apartamento(float Ancho,float Largo)
{
  T_apartamento  apart;
  apart.ancho=Ancho;
  apart.largo=Largo;
  return apartamentos.inserte(apart);
};//________________________________________

void _piso::calcular_area(void)
{
  T_apartamento apart;
  total_area_efectiva=0.0;
  total_apartamentos=0;
  apartamentos.gotop(&apart);
  do{
    total_apartamentos++;
    total_area_efectiva+=apart.largo*apart.ancho;
  }while(apartamentos.prev(&apart));
  total_area=total_area_efectiva*1.35;
  #ifdef DEBUG
  cout << "Total de apartamentos " << total_apartamentos << endl;
  #endif
};//________________________________________

float _piso::area_total(void)
{
  return total_area;
};//________________________________________

float _piso::area_efectiva(void)
{
  return total_area_efectiva;
};//________________________________________

int _piso::numero_apartamentos(void)
{
  return total_apartamentos;
};//________________________________________

_edificio::_edificio(void)
{
  total_area_construccion=total_area_efectiva_construccion=
    total_area_terreno=total_area_vehiculos=0.0;
  total_apartamentos=0;
}//________________________________________

bool  _edificio::inserte_piso(T_pareja areas[],int size)
{
 _piso *piso_i=new _piso;
  for (int i=0;i<size;i++)
     if (!piso_i->inserte_apartamento(areas[i].ancho,areas[i].largo))
        return false;
  return pisos.inserte(piso_i);
}//________________________________________

void  _edificio::calcular_edificio(void)
{
  total_area_construccion=0.0;
  total_area_efectiva_construccion=0.0;
  total_area_terreno=0.0;
  total_area_vehiculos=0.0;
  total_apartamentos=0;
  int i=0;
  _piso *piso_i=NULL;
  pisos.gotop(&piso_i);
  do{
    piso_i->calcular_area();
    total_apartamentos+=piso_i->numero_apartamentos();
    float area_total_piso;
    total_area_efectiva_construccion+=piso_i->area_efectiva();
    area_total_piso=piso_i->area_total();
    total_area_construccion+=area_total_piso;
    if (area_total_piso > total_area_terreno) total_area_terreno=area_total_piso;
    #ifdef DEBUG
      cout << "Area efectiva del piso " << i << " es: " << piso_i->area_efectiva()
           << "\n area total piso asimetrica: " << piso_i->area_total() << endl;
    #endif
    i++;
  }while(pisos.prev(&piso_i));

  // Debe en forma correcta asumirse que el piso más grande en metros
  // cuadrados es el area real total de construccion x n pisos.
  total_area_vehiculos=total_apartamentos*METROS_PARQUEO;
  total_area_construccion=total_area_terreno*i;
  #ifdef DEBUG
    cout << "Area Total simétrica del edificio es: " <<  total_area_construccion
       << endl;
  #endif
  total_area_terreno+=total_area_vehiculos;
  #ifdef DEBUG
    cout << "Area Total simétrica del edificio + vehic es: " <<  total_area_terreno
       << endl;
  #endif
}//________________________________________

float _edificio::area_total_construccion(void)
{
  return total_area_construccion;
}//________________________________________

float _edificio::area_efectiva_construccion(void)
{
  return total_area_efectiva_construccion;
}//________________________________________

float _edificio::area_terreno(void)
{
  return total_area_terreno;
}//________________________________________

_habitacional::_habitacional(void)
{
  total_area_construccion=total_area_efectiva_construccion=
    total_area_terreno=total_area_vehiculos=0.0;
  total_apartamentos=0;
}//________________________________________

bool  _habitacional::inserte_edificio(_edificio *edif)
{
  return edificios.inserte(edif);
}//________________________________________

void  _habitacional::calcular_habitacional(void)
{
  total_area_construccion=0.0;
  total_area_efectiva_construccion=0.0;
  total_area_terreno=0.0;
  total_area_vehiculos=0.0;
  total_apartamentos=0;

  _edificio *edif_i=NULL;
  edificios.gotop(&edif_i);
  #ifdef DEBUG
  int i=0;
  #endif // DEBUG
  do
  {
    edif_i->calcular_edificio();

    total_area_construccion+=edif_i->area_total_construccion();
    total_area_efectiva_construccion+=edif_i->area_efectiva_construccion();
    total_area_terreno+=edif_i->area_terreno();
    #ifdef DEBUG
     cout  << "Edficio #" << ++i << " "
       << "\nArea construccion edificio: " <<  edif_i->area_total_construccion()
       << "\nArea Efectiva construccion: " <<  edif_i->area_efectiva_construccion()
       << "\nArea terreno edificio considerando vehiculos: " << edif_i->area_terreno()
       << endl << endl;
    #endif
  }while(edificios.prev(&edif_i));
  total_area_terreno*=1.15;
}//________________________________________

float _habitacional::area_total_construccion(void)
{
  return total_area_construccion;
}//________________________________________

float _habitacional::area_efectiva_construccion(void)
{
  return total_area_efectiva_construccion;
}//________________________________________

float _habitacional::area_terreno(void)
{
  return total_area_terreno;
}//________________________________________
