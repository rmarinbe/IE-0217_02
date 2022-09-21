//===============================================
//Archivo: main_STL_vector.cc
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
#include <vector>
using namespace std;
#include "utilitarios.h"

void main_stl_matrix1(void)
{
   vector< vector<int> > vI2Matrix(3,vector<int>(2,0));

   vI2Matrix[0][0] = 0;
   vI2Matrix[0][1] = 1;
   vI2Matrix[1][0] = 10;
   vI2Matrix[1][1] = 11;
   vI2Matrix[2][0] = 20;
   vI2Matrix[2][1] = 21;

   cout << "Visualización de Matriz" << endl;

   int ii, jj;
   for(ii=0; ii < 3; ii++)
   {
      for(jj=0; jj < 2; jj++)
      {
         cout << "v[" <<ii <<"]["<<jj<<"]= "<<vI2Matrix[ii][jj] << endl;
      }
   }
   end_function();
}//______________________________________________________
