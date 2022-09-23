//===============================================
//Archivo: main_ecuaciones3det_template_execp.cc
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
#include "../Utilitarios/_complex.h"
#include "determinantes3x3_template_excep.h"
#include "ecuaciones3incog_template_excep.h"

//MAIN()
//+++++++
int main(void)
{
  try
  {
    _ecuaciones3incog<double>   EcuLin1,EcuLin2;
    _ecuaciones3incog<_complex> EcuLin3;

    //ECUACION 1
    //===================================
    // X+Y+Z = 6
    EcuLin1[0][0]=1;
    EcuLin1[0][1]=1;
    EcuLin1[0][2]=1;
    EcuLin1[0][3]=6;

    // 2X-Y+Z = 3
    EcuLin1[1][0]= 2;
    EcuLin1[1][1]=-1;
    EcuLin1[1][2]= 1;
    EcuLin1[1][3]= 3;

    // X-Y+Z = 2
    EcuLin1[2][0]= 1;
    EcuLin1[2][1]=-1;
    EcuLin1[2][2]= 1;
    EcuLin1[2][3]= 2;

    if (EcuLin1.resolver())
    {
      cout<<"Las soluciones ecuación 1 son: "<< endl
          << "X= " << EcuLin1.valor(0) << endl
          << "Y= " << EcuLin1.valor(1) << endl
          << "Z= " << EcuLin1.valor(2) <<endl;
    }else cout << "Ecuaciones LD..." << endl;

    //ECUACION 2
    //===================================
    // X+Y+Z = 6
    EcuLin2[0][0]=1;
    EcuLin2[0][1]=1;
    EcuLin2[0][2]=1;
    EcuLin2[0][3]=6;

    // 2X+2Y+2Z = 12
    EcuLin2[1][0]= 2;
    EcuLin2[1][1]= 2;
    EcuLin2[1][2]= 2;
    EcuLin2[1][3]= 12;

    // X-Y+Z = 2
    EcuLin2[2][0]= 1;
    EcuLin2[2][1]=-1;
    EcuLin2[2][2]= 1;
    EcuLin2[2][3]= 2;

    if (EcuLin2.resolver())
    {
      cout<<"Las soluciones ecuación 2 son: "<< endl
          << "X= " << EcuLin2.valor(0) << endl
          << "Y= " << EcuLin2.valor(1) << endl
          << "Z= " << EcuLin2.valor(2) <<endl;
    }else cout << "Ecuaciones LD..." << endl;

    //ECUACION 3
    //===================================

    //1
    EcuLin3[0][0][REAL]       =1;
    EcuLin3[0][0][IMAGINARIO] =5;

    EcuLin3[0][1][REAL]       = 1;
    EcuLin3[0][1][IMAGINARIO] =-5;

    EcuLin3[0][2][REAL]       = 1;
    EcuLin3[0][2][IMAGINARIO] = 2;

    EcuLin3[0][3][REAL]       = 6;
    EcuLin3[0][3][IMAGINARIO] = 2;

    //2
    EcuLin3[1][0][REAL]       = 2;
    EcuLin3[1][0][IMAGINARIO] = 4;

    EcuLin3[1][1][REAL]       =-1;
    EcuLin3[1][1][IMAGINARIO] = 3;

    EcuLin3[1][2][REAL]       = 1;
    EcuLin3[1][2][IMAGINARIO] = 2;

    EcuLin3[1][3][REAL]       = 3;
    EcuLin3[1][3][IMAGINARIO] = 5;

    //3
    EcuLin3[2][0][REAL]       = 1;
    EcuLin3[2][0][IMAGINARIO] = 0;

    EcuLin3[2][1][REAL]       =-1;
    EcuLin3[2][1][IMAGINARIO] = 0;

    EcuLin3[2][2][REAL]       = 1;
    EcuLin3[2][2][IMAGINARIO] = 0;

    EcuLin3[2][3][REAL]       = 2;
    EcuLin3[2][3][IMAGINARIO] = 0;

    if (EcuLin3.resolver())
    {
      cout<<"Las soluciones son: "<< endl
          << "X= " << EcuLin3.valor(0) << endl
          << "Y= " << EcuLin3.valor(1) << endl
          << "Z= " << EcuLin3.valor(2) <<endl;
    }else cout << "Ecuaciones LD" << endl;
  }

  catch (_exception& e)
  {
     e.getMessage();
  }//+++++++++++++++++++++++++++++++

  bool salida=false;
  _determinante3x3<float> det;
  det[0][0]=1;
  det[0][1]=1;
  det[0][2]=1;
  det[0][3]=6;
  det[1][0]= 2;
  det[1][1]=-1;
  det[1][2]= 1;
  det[1][3]= 3;
  det[2][0]= 1;
  det[2][1]=-1;
  det[2][2]= 1;
  det[2][3]= 2;

  do{
    for (int i=0;i<3;i++)
    {
      for (int j=0;j<3;j++)
        cout << "det["<<i<<"]["<<j<<"]="<< det[i][j]<< "  ";
      cout << endl;
    }
    try{
      cout << "Observar dato para index "<< endl;
      int x,y;
      cin>> x >> y;
      cout << "Valor det("<< x <<"," << y << ")=" << det[x][y] << endl;
    }
    catch (_exception& e)
    {
      e.getMessage();
      continue;
    }//+++++++++++++++++++++++++++++++
  }while(!salida);
  return 0;
}//___________________________________________________________

