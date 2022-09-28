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
#include <algorithm>

using namespace std;

template<typename T>
void show(T i)
{
  cout << i << " " ;
}//________________________

int contenedor_set2(void)
{
  set<int> arbol;
  set<int>::iterator _begin,_end;

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

  for_each(arbol.begin(),arbol.end(),show<int>); cout << endl;

  getchar();
  return 0;
}//_______________________________________________________________
