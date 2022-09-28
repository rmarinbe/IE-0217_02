//===============================================
//Archivo: contenedor_set1.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================

#include <iostream>
#include <set>
using namespace std;

static set<int> arbol;
static set<int>::iterator _begin,_end;
void contenedor_set1(void)
{
  arbol.insert(189);
  arbol.insert(99);
  arbol.insert(23);
  arbol.insert(41);
  arbol.insert(90);
  arbol.insert(71);
  arbol.insert(99);
  arbol.insert(70);

  cout << "Contenido del SET" <<endl;;
  _begin=arbol.begin();
  _end  =arbol.end();
  while(_begin!=_end)  cout << *_begin++ << " ";
  cout << endl;
  getchar();
}//_______________________________________________________________
