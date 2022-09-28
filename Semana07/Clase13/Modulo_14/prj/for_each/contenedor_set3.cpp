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

#include <set>
#include <list>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
typedef set<int, less<int> > integer_set;
typedef set<int, less<int> >::iterator integer_set_ptr;

void show_int (int i)
{
  cout << i << " " ;
}//__________________________________________

void display_collection (const integer_set &d, string title)
{
  cout << title << ": { ";
  for_each(d.begin(), d.end(), show_int);
  cout << "}" << endl;
}

void display_collection (const list<int> &d, string title)
{
  cout << title << ": [ ";
  for_each(d.begin(), d.end(), show_int);
  cout << "]" << endl;
}

void contenedor_set3(void)
{
  cout << "Demostración de SET" << endl;

  list<int> list1;
  integer_set set1;

  list1.push_back(89);
  list1.push_back(99);
  list1.push_back(89);
  list1.push_back(69);
  list1.push_back(59);
  list1.push_back(89);
  list1.push_back(89);
  list1.push_back(49);

  display_collection(list1, "List 2");
  list<int>::iterator lp;

  for (lp = list1.begin(); lp != list1.end(); lp++)
    set1.insert(*lp);

  display_collection(set1, "Set 1");

  cout << "Total de valores mayores a 50: ";
  integer_set_ptr begin=set1.begin(),end=set1.end();
  int count=0;
  while(begin!=end) if( *begin++ > 50 )count++;
  cout << count << endl;

  if (set1.find(89) != set1.end())
    cout << "89 está en el conjunto !!" << endl;
  else
    cout << "89 no está en el conjunto !!" << endl;

  // Uso del algoritmo generico de find
  if (find(set1.begin(), set1.end(), 123) != set1.end())
    cout << "123 está en el conjunto!!" << endl;
  else
    cout << "123 no está en el conjunto!!" << endl;

  set1.erase(89);
  cout << "Luego de borrar: ";
  if (set1.find(89) != set1.end())
    cout << "89 está en el conjunto!!" << endl;
  else
    cout << "89 no está en el conjunto!!" << endl;
  getchar();
}//_______________________________________________________________

