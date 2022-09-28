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
#include <fstream>
#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;

#include "laberinto.h"

_cell::_cell(char Celda): celda(Celda)
{
  switch (Celda) {
    case '#':   e_celda=pared;       break;
    case ' ':   e_celda=pasillo;     break;
    case 'E':
    case 'e':   e_celda=entrada;     break;
    case 's':
    case 'S':   e_celda=salida;      break;
    default :   e_celda=error;       break;
  }
}//_________________________________________________________

_cell::operator const T_tipocelda&()
{
  return e_celda;
}//_________________________________________________________

_cell::operator const char&()
{
  return celda;
}//_________________________________________________________

_laberinto::_laberinto(const char *Filename):filename(Filename)
{
  max_x=max_y=0;
}//__________________________________________________________

_laberinto::~_laberinto(void)
{}//__________________________________________________________

bool _laberinto::checkfile(void)
{
  input.open( filename );
  if( input.fail() ) return false;

  char car;
  bool primera=true;

  while(true)
  {
    vector<_cell> elemento;
    while(input.good())
    {
      input.get(car);
      if (car =='\n')
      {
        int size=elemento.size();
        if (size !=0)
        {
          if (primera)
          {
            max_x=elemento.size();
            primera=false;
          }
          if (max_x == size)
          {
            malla.push_back(elemento);
            max_y++;
          } else return false;
        }
        break;//returna a while(true) y recrea elemento
      }
      _cell celda(car);
      if ((T_tipocelda)celda == error) return false;
      elemento.push_back(celda);
    }
    if (!input.good())break; //rompe el ciclo while(true);
  }
  return FindStart();
}//_________________________________________________________________________

void _laberinto::ver(void)
{
  for (unsigned int i=0;i< malla.size();i++)
  {
    vector<_cell> linea=malla[i];
    for (unsigned int j=0;j<linea.size();j++)
    {
      char car = (char)linea[j];
      cout << car;
    }
    cout << endl;
  }
  getchar();
}//________________________________________________________________________

bool _laberinto::FindStart(void)
{
  for (unsigned int i=0;i< malla.size();i++)
  {
    vector<_cell> linea=malla[i];
    for (unsigned int j=0;j<linea.size();j++)
      if ( (T_tipocelda)linea[j] == entrada)
      {
        x_in=j;y_in=i;
        return true;
      }
  }
  return false;
}//_______________________________________________________________________

bool _laberinto::resolver(void)
{
  cout << "Método a ser implementado..." << endl;
  return false;
}//_______________________________________________________________________

void _laberinto::ver_solucion(void)
{
  cout << "Método a ser implementado..." << endl;
}//_______________________________________________________________________






