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
{};//________________________________________

float _piso::area_total(void)
{
  return 0.0;
};//________________________________________

float _piso::area_efectiva(void)
{
  return 0.0;
};//________________________________________

int _piso::numero_apartamentos(void)
{
  return 0.0;
};//________________________________________

_edificio::_edificio(void)
{
  total_area_construccion=total_area_efectiva_construccion=
    total_area_terreno=total_area_vehiculos=0.0;
  total_apartamentos=0;
}//________________________________________

bool  _edificio::inserte_piso(T_pareja areas[],int size)
{
  return false;
}//________________________________________

void  _edificio::calcular_edificio(void)
{}//________________________________________

float _edificio::area_total_construccion(void)
{
  return 0.0;
}//________________________________________

float _edificio::area_efectiva_construccion(void)
{
  return 0.0;
}//________________________________________

float _edificio::area_terreno(void)
{
  return 0.0;
}//________________________________________

_habitacional::_habitacional(void)
{
  total_area_construccion=total_area_efectiva_construccion=
    total_area_terreno=total_area_vehiculos=0.0;
  total_apartamentos=0;
}//________________________________________

bool  _habitacional::inserte_edificio(_edificio *edif)
{
  return false;
}//________________________________________

void  _habitacional::calcular_habitacional(void)
{}//________________________________________

float _habitacional::area_total_construccion(void)
{
  return 0.0;
}//________________________________________

float _habitacional::area_efectiva_construccion(void)
{
  return 0.0;
}//________________________________________

float _habitacional::area_terreno(void)
{
  return 0.0;
}//________________________________________
