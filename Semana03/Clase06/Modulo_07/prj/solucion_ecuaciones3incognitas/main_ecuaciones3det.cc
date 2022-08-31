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
#include "define.h"
#include "_complex.h"
#include "determinante3x3.h"
#include"ecuaciones3incog.h"

//MAIN()
//+++++++
#if (_COMPLEX_==true)
int main(void)
{
 {//Definicion IMPLICITA
  _ecuaciones3incog ECuLin;

  // X+Y+Z = 6
  ECuLin[0][0]=TYPE(1);
  ECuLin[0][1]=TYPE(1);
  ECuLin[0][2]=TYPE(1);
  ECuLin[0][3]=TYPE(6);

  // 2X-Y+Z = 3
  ECuLin[1][0]=TYPE(2);
  ECuLin[1][1]=TYPE(-1);
  ECuLin[1][2]=TYPE(1);
  ECuLin[1][3]=TYPE(3);

  // X-Y+Z = 2
  ECuLin[2][0]=TYPE(1);
  ECuLin[2][1]=TYPE(-1);
  ECuLin[2][2]=TYPE(1);
  ECuLin[2][3]=TYPE(2);

  if (ECuLin.resolver())
  {
    cout<<"Las soluciones son: "<< endl
        << "X= " << ECuLin.valor(0) << endl
        << "Y= " << ECuLin.valor(1) << endl
        << "Z= " << ECuLin.valor(2) <<endl;
  }else cout << "Ecuaciones LD" << endl;
 }
 {//Definicion IMPLICITA
  _ecuaciones3incog ECuLin;

  // X+Y+Z = 6
  ECuLin[0][0]=TYPE(1);
  ECuLin[0][1]=TYPE(1);
  ECuLin[0][2]=TYPE(1);
  ECuLin[0][3]=TYPE(6);

  // 2X+2Y+2Z = 12
  ECuLin[1][0]=TYPE(2);
  ECuLin[1][1]=TYPE(2);
  ECuLin[1][2]=TYPE(2);
  ECuLin[1][3]=TYPE(12);

  // X-Y+Z = 2
  ECuLin[2][0]=TYPE(1);
  ECuLin[2][1]=TYPE(-1);
  ECuLin[2][2]=TYPE(1);
  ECuLin[2][3]=TYPE(2);

  if (ECuLin.resolver())
  {
    cout<<"Las soluciones son: "<< endl
        << "X= " << ECuLin.valor(0) << endl
        << "Y= " << ECuLin.valor(1) << endl
        << "Z= " << ECuLin.valor(2) <<endl;
  }else cout << "Ecuaciones LD" << endl;
 }
 {//Definicion IMPLICITA
  _ecuaciones3incog ECuLin;


  ECuLin[0][0]=TYPE(1,5);
  ECuLin[0][1]=TYPE(1,-5);
  ECuLin[0][2]=TYPE(1,2);
  ECuLin[0][3]=TYPE(6,2);


  ECuLin[1][0]=TYPE(2,4);
  ECuLin[1][1]=TYPE(-1,3);
  ECuLin[1][2]=TYPE(1,2);
  ECuLin[1][3]=TYPE(3,5);


  ECuLin[2][0]=TYPE(1,0);
  ECuLin[2][1]=TYPE(-1,0);
  ECuLin[2][2]=TYPE(1,0);
  ECuLin[2][3]=TYPE(2,0);

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
//============================================================
#else
int main(void)
{
 {//Definicion IMPLICITA
  _ecuaciones3incog ECuLin;

  // X+Y+Z = 6
  ECuLin[0][0]=TYPE(1);
  ECuLin[0][1]=TYPE(1);
  ECuLin[0][2]=TYPE(1);
  ECuLin[0][3]=TYPE(6);

  // 2X-Y+Z = 3
  ECuLin[1][0]=TYPE(2);
  ECuLin[1][1]=TYPE(-1);
  ECuLin[1][2]=TYPE(1);
  ECuLin[1][3]=TYPE(3);

  // X-Y+Z = 2
  ECuLin[2][0]=TYPE(1);
  ECuLin[2][1]=TYPE(-1);
  ECuLin[2][2]=TYPE(1);
  ECuLin[2][3]=TYPE(2);

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
  ECuLin[0][0]=TYPE(1);
  ECuLin[0][1]=TYPE(1);
  ECuLin[0][2]=TYPE(1);
  ECuLin[0][3]=TYPE(6);

  // 2X+2Y+2Z = 12
  ECuLin[1][0]=TYPE(2);
  ECuLin[1][1]=TYPE(2);
  ECuLin[1][2]=TYPE(2);
  ECuLin[1][3]=TYPE(12);

  // X-Y+Z = 2
  ECuLin[2][0]=TYPE(1);
  ECuLin[2][1]=TYPE(-1);
  ECuLin[2][2]=TYPE(1);
  ECuLin[2][3]=TYPE(2);

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
#endif
