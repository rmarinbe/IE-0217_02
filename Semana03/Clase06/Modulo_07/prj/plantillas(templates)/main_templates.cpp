//===============================================
//Archivo: main_templates.cpp
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

template <class T> T maxx(T x, T y)
{
  return (x > y) ? x : y;
};//_____________________________________________

template <class T, int nElementos>
class Tabla {
private:
  T *pT;

public:
  Tabla();
  ~Tabla();
  T& operator[](int indice) { return pT[indice]; }
};//________________________________________________

// Definición:
template <class T, int nElementos>
Tabla<T,nElementos>::Tabla()
{
  pT = new T[nElementos];
}//________________________________________________

template <class T, int nElementos>
Tabla<T, nElementos>::~Tabla()
{
  delete[] pT;
}//________________________________________________

#define MAXTABLE 32
int main(void)
{
  int a=2,b=10;
  int c= maxx<int>(a,b);

  cout << "El mayor de a y b "<< a << " "<< b << " es " << c << endl;

  Tabla<int,MAXTABLE>   TablaInt;     // Tabla de 32 enteros
  Tabla<float,12> TablaFloat;   // Tabla de 12 floats
  Tabla<bool,10>  TablaBool;    // Tabla de 10 bool

  for(int i = 0; i < MAXTABLE; i++)
    TablaInt[i] = MAXTABLE-i;
  return 0;
}//________________________________________________
