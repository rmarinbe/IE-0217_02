//===============================================
// Archivo: throw3.cpp
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
void PrintSequence(int StopNum)
{
  int Num;
  Num = 1;
  while (true)
  {
    if (Num >= StopNum)
      throw Num;
    cout << Num << endl;
    Num++;
  }
}//________________________________________________________

//++++++++++++++++++
//   main()
//++++++++++++++++++
int main(void)
{
  try
  {
    PrintSequence(20);
  }//+++++++++++++++++

  catch(float FloatNum)
  {
    cout << "Caught an exception with float value: " << FloatNum << endl;
  }//+++++++++++++++++++

  catch(int IntNum)
  {
    cout << "Caught an exception with int value: " << IntNum << endl;
  }//+++++++++++++++++++

  catch(...)   // catch anything else
  {
    cout << "Caught an exception with type not int or float" << endl;
  }//++++++++++++++++++++

  cout << "Press any key to finish..." << endl;getchar();
}//_________________________________________________________

