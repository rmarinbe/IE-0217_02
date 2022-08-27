//===============================================
//Archivo: main_t_complex.cpp
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

typedef struct S_complex {
  double real,imaginario;
  S_complex(double Real=0,double Imaginario=0):real(Real),imaginario(Imaginario)
  {};//_________________________________________________________________________

  ~S_complex(void)
  {
    cout << "Destructor !!!" << endl;
  };//_________________________________________________________________________

  S_complex operator +(S_complex otro)
  {
    S_complex resultado(real,imaginario);
    resultado.real+=otro.real;
    resultado.imaginario+=otro.imaginario;
    return resultado;
  }//___________________________________

  S_complex operator -(S_complex otro)
  {
    S_complex resultado(real,imaginario);
    resultado.real-=otro.real;
    resultado.imaginario-=otro.imaginario;
    return resultado;
  }//___________________________________
}T_complex;//_____________________________________________________

int main(void)
{
  T_complex a,b(90.2,3.2),c;
  a.real        = 10.2;
  a.imaginario  = 10.2;
  char signo=' ';

  c=a+b;
  signo = c.imaginario >=0 ? '+' :'-';
  cout << "Resultado de suma es " << c.real <<" "<< signo << c.imaginario << "j"<< endl;

  c=a-b;
  signo = c.imaginario <0 ? '+' :'-';
  cout << "Resultado de resta es " << c.real <<" "<< signo << c.imaginario << "j"<< endl;

  return 0;
}//___________________________________________________
