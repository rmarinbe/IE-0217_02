//===============================================
//Archivo: main_ecuaciones3det.cc
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
using namespace std;
#include "determinante3x3.h"
#include"ecuaciones3incog.h"

//MAIN()
//+++++++
int main(void)
{
 {//Definicion IMPLICITA
  _ecuaciones3incog ECuLin;

  // X+Y+Z = 6
  ECuLin[0][0]= 1;
  ECuLin[0][1]= 1;
  ECuLin[0][2]= 1;
  ECuLin[0][3]= 6;

  // 2X-Y+Z = 3
  ECuLin[1][0]= 2;
  ECuLin[1][1]=-1;
  ECuLin[1][2]= 1;
  ECuLin[1][3]= 3;

  // X-Y+Z = 2
  ECuLin[2][0]= 1;
  ECuLin[2][1]=-1;
  ECuLin[2][2]= 1;
  ECuLin[2][3]= 2;

  if (ECuLin.resolver())
  {
    cout<<"Las soluciones son: "<< endl
        << "X= " << ECuLin.valor(0) << endl
        << "Y= " << ECuLin.valor(1) << endl
        << "Z= " << ECuLin.valor(2) <<endl;
  }else cout << "Ecuaciones LD" << endl;
 }{//Definicion IMPLICITA
  _ecuaciones3incog ECuLin;

  // X+Y+Z = 6
  ECuLin[0][0]=1;
  ECuLin[0][1]=1;
  ECuLin[0][2]=1;
  ECuLin[0][3]=6;

  // 2X+2Y+2Z = 12
  ECuLin[1][0]= 2;
  ECuLin[1][1]= 2;
  ECuLin[1][2]= 2;
  ECuLin[1][3]=12;

  // X-Y+Z = 2
  ECuLin[2][0]= 1;
  ECuLin[2][1]=-1;
  ECuLin[2][2]= 1;
  ECuLin[2][3]= 2;

  if (ECuLin.resolver())
  {
    cout<<"Las soluciones son: "<< endl
        << "X= " << ECuLin.valor(0) << endl
        << "Y= " << ECuLin.valor(1) << endl
        << "Z= " << ECuLin.valor(2) <<endl;
  }else cout << "Ecuaciones LD" << endl;
 }
 return 0;
}//___________________________________________________________
