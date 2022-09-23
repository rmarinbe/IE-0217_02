//===============================================
// Archivo: throw2.cpp
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
}//________________________________________________


//  MAIN()
//=========
int main(void)
{
  try
  {
    PrintSequence(70);
  }
  catch(...)
  {
    cout << "Caught an exception " << endl;
    //throw;
  }
  cout << "Press any key to finish..." << endl;getchar();
return 0;
}//_________________________________________________________
