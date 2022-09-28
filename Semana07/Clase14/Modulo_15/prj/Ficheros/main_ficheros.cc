//===============================================
//Archivo: main_ficheros.cc
//===============================================
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
using namespace std;
/*+++++++++++++
MAIN()
+++++++++++++++*/
#define MAXLINE 120
int main(void)
{
  string Filename="main_ficheros.cc";
  char   Line[MAXLINE];
  ifstream fin;
  fin.open( Filename.c_str() );
  cout << "Abriendo: "<< Filename.c_str() << endl;
  if( fin.fail() )
  {
    cout << "Archivo no encontrado..."<< endl;
     return 0;
  }
  cout << "Escribiendo... "<< endl;

  Filename="Archivo_cc.txt";
  ofstream fout(Filename.c_str());
  fout << "Salida de información en archivo texto utilizando ostream..."<< endl;

  while(!fin.eof())
  {
      fin.getline(Line,MAXLINE,'\n');
      cout << Line << endl;
      fout << Line << endl;
      if (!fin.good() && !fin.eof()){
        cout << "Máximo de línea alcanzado y condición de error interna en fin" << endl;
        break;
      }
  }
  fout.close();
  fin.close();
}//___________________________________________________________________________





