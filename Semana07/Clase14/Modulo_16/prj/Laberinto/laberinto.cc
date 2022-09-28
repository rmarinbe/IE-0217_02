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
#include <stack>
using namespace std;
#include "laberinto.h"

_cell::_cell(char Celda,int X,int Y): celda(Celda)
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
  x=X; y=Y;
  path=visited=false;
}//_________________________________________________________

_cell::operator const T_tipocelda&()
{
  return e_celda;
}//_________________________________________________________

_cell::operator const char&()
{
  return celda;
}//_________________________________________________________

_cell::operator bool&()
{
  return visited;
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
  int  x=0,y=0;
  while(true)
  {
    vector<_cell> fila;
    while(input.good())
    {
      input.get(car);
      if (car =='\n')
      {
        int size=fila.size();
        if (size !=0)
        {
          if (primera)
          {
            max_x=fila.size();
            primera=false;
          }
          if (max_x == size)
          {
            malla.push_back(fila);
            max_y++;
            x=0; y++;
          } else return false;
        }
        break;//returna a while(true) y recrea elemento
      }
      _cell celda(car,x++,y);
      if ((T_tipocelda)celda == error) return false;
      fila.push_back(celda);
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
  for (unsigned int j=0;j< malla.size();j++)
  {
    vector<_cell> linea=malla[j];
    for (unsigned int i=0;i<linea.size();i++)
      if ( (T_tipocelda)linea[i] == entrada)
      {
        x_in=i;y_in=j;
        return true;
      }
  }
  return false;
}//_______________________________________________________________________

bool _laberinto::left(void)
{
  if (current.x-1 == -1) return false;
  if (malla[current.y][current.x-1] == pared) return false;
  if (malla[current.y][current.x-1]) return false;
  current.x--;
  return true;
}//_______________________________________________________________________

bool _laberinto::up(void)
{
  if (current.y-1 == -1) return false;
  if (malla[current.y-1][current.x] == pared) return false;
  if (malla[current.y-1][current.x]) return false;
  current.y--;
  return true;
}//_______________________________________________________________________

bool _laberinto::right(void)
{
  if (current.x+1 == (int)malla[current.y].size()) return false;
  if (malla[current.y][current.x+1] == pared) return false;
  if (malla[current.y][current.x+1]) return false;
  current.x++;
  return true;
}//_______________________________________________________________________

bool _laberinto::down(void)
{
  if (current.y+1 == (int)malla.size()) return false;
  if (malla[current.y+1][current.x] == pared) return false;
  if (malla[current.y+1][current.x]) return false;
  current.y++;
  return true;
}//_______________________________________________________________________

bool _laberinto::resolver(void)
{
  //stack<T_posicion> stk;
  current.x=x_in;
  current.y=y_in;
  while(true)
  {
    if (malla[current.y][current.x]== salida) return true;
    bool &visited=malla[current.y][current.x];
    visited=true;
    malla[current.y][current.x].path=true;
    stk.push(current);
    if (right())  continue;
    if (up())     continue;
    if (left())   continue;
    if (down())   continue;
    //(bool)malla[current.y][current.x]=false;
    malla[current.y][current.x].path=false;
    stk.pop();
    if (stk.empty()) return false;
    current=stk.top();
    stk.pop();
  }
  return true;
}//_______________________________________________________________________

void _laberinto::ver_solucion(void)
{
  for (unsigned int i=0;i< malla.size();i++)
  {
    vector<_cell> linea=malla[i];
    for (unsigned int j=0;j<linea.size();j++)
    {
      char car = linea[j]== pasillo ? linea[j].path ? '@' :(char)linea[j]:
                 (char)linea[j];
      cout << car;
    }
    cout << endl;
  }
  getchar();
}//_______________________________________________________________________

void _laberinto::ver_coordenadas_solucion(void)
{
  while (!stk.empty())
  {
    T_posicion pos=stk.top();
    stk.pop();
    cout << "pos x= " <<pos.x << "  pos y= " << pos.y << endl;
  }
}//_______________________________________________________________________
