//===============================================
//Archivo: main_operador_index.cpp
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
#define BASE_ARRAY 5
#define MAIN_ARRAY 7

//CLASS DEFINITION
//++++++++++++++++
class _base{
private:
  float array[BASE_ARRAY];
public:
  float& operator[](int index);
};//_______________________________________________

class  _main{
private:
  _base array[MAIN_ARRAY];
public:
  float resolver(void);
  _base& operator[](int index);
};//____________________________________________

//CLASS IMPLEMENTATION
//+++++++++++++++++++++
float &_base::operator[](int index)
{
  static float pad=0;
  if (index < 0) return pad;
  if (index >=BASE_ARRAY) return pad;
  return array[index];
}//________________________________________________

_base &_main::operator[](int index)
{
  static _base pad;
  if (index <  0) return pad;
  if (index >= MAIN_ARRAY) return pad;
  return array[index];
}//________________________________________________

float _main::resolver(void)
{
  float suma=0;
  for (int i=0;i<MAIN_ARRAY;i++)
    for (int j=0;j<BASE_ARRAY;j++)
    {
        float &ptr=array[i][j];
        ptr*=2;
        suma+=ptr;
    }
  cout << endl;
  return suma;
}//________________________________________________

//MAIN()
//======
int main(void)
{
  _main context;
  for (int i=0;i<MAIN_ARRAY;i++)
    for (int j=0;j<BASE_ARRAY;j++)
    context[i][j]= i*j;

  context.resolver();

  for (int i=0;i<MAIN_ARRAY;i++)
    for (int j=0;j<BASE_ARRAY;j++)
    cout << "Context["<<i<<"]["<<j<<"]="<< context[i][j] << endl;

  return 0;
}//____________________________________________________
