//===============================================
//Archivo: main_ficheros_stl2.cc
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
#include <vector>
#include <stack>
using namespace std;
/*+++++++++++++
MAIN()
+++++++++++++++*/
#define MAXLINE 120
int main(void)
{
  string Filename="main_ficheros_stl2.cc";
  ifstream fin;
  fin.open( Filename.c_str() );
  cout << "Abriendo: "<< Filename.c_str() << endl;
  if( fin.fail() )
  {
    cout << "Archivo no encontrado..."<< endl;
     return 0;
  }
  char car;
  cout << "Leyendo... "<< endl;

  stack< vector<char> > matriz;
  vector<char> vect;
  while(fin.good())
  {
    fin.get(car);
    if (car =='\n')
    {
      matriz.push(vect);
      vect.clear();
    }
    else
      vect.push_back(car);
  }
  //int size=matriz.size();
  cout << "Pulsar tecla para ver contenidos en matriz..."<< matriz.size()<<endl;
  getchar();

//  for(int i=0;i< size;i++)
//  {
//    vector<char> &vect=matriz.top();
//    for (unsigned int j=0;j<vect.size();j++)
//      cout << vect[j];
//    cout << endl;
//    matriz.pop();
//  }
  while(!matriz.empty()) {
    vector<char> &vect=matriz.top();
    for (unsigned int j=0;j<vect.size();j++)
      cout << vect[j];
    cout << endl;
    matriz.pop();
  }
  fin.close();
}//___________________________________________________________________________





