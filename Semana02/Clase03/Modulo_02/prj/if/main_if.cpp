//===============================================
//Archivo: main_if.cpp
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
//System Includes
//+++++++++++++++
#include <iostream>
using namespace std;
int main(void)
{
  int a=0,b=0;
  float z=0;

  if (a==0)
  {
    b++;
    z=b+2.4;
  }
  else
  {
    a=2;
    z=5.2;
  }

  if (a==1)
  {
    if (b==2) a=20;
  }else a=10;

  if (a==1) cout << "a es 1" << endl;
    else if (a==2) cout << "a es 2" << endl;
      else if (a==3) cout << "a es 3" << endl;
        else cout << "a no es  1,2 o 3" << endl;

  switch(a)
  {
    case 1: cout << "a es 1" << endl;
            break;
    case 2: cout << "a es 2" << endl;
            return 1;
    case 3: cout << "a es 3" << endl;
            break;
    default:cout << "a no es  1,2 o 3" << endl;;
  }
  return 0;
}
