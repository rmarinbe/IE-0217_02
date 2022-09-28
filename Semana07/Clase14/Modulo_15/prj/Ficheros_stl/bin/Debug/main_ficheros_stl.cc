//===============================================
//Archivo: main_ficheros_stl.cc
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================

using namespace std;

#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

/*+++++++++++++
MAIN()
+++++++++++++++*/
#define MAXLINE 120
int main(void)
{
  string Filename="main_ficheros_stl.cc";
  ifstream fin;
  fin.open( Filename.c_str() );
  cout << "Abriendo: "<< Filename.c_str() << endl;
  if( fin.fail() )
  {
    cout << "Archivo no encontrado..."<< endl;
     return false;
  }
  char car;
  cout << "Leyendo... "<< endl;

  vector< vector<char> > matriz;
  vector<char> vector;
  while(fin.good())
  {
    fin.get(car);
    if (car =='\n')
    {
      matriz.push_back(vector);
      vector.clear();
    }
    else
      vector.push_back(car);
  }
  cout << "Pulsar tecla para ver contenidos en matriz..."<< endl;
  getchar();
  for(unsigned int i=0;i< matriz.size();i++)
  {
    for (unsigned int j=0;j<matriz[i].size();j++)
      cout << matriz[i][j];
    cout << endl;
  }
  fin.close();
}//___________________________________________________________________________





