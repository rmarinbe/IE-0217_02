//===============================================
// Archivo: throw5.cpp
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
#include <string>
using namespace std;

class DivideByZero {
private:
  int num;
  int denom;
  string message;

public:
  DivideByZero(int n, int d) : num(n), denom(d), message("Divide by zero")
  {}//_______________________________________________________________________

  ~DivideByZero()
  {}//_______________________________________________________________________

  int getNumerator()
  {
    return num;
  }//_______________________________________________________________________

  int getDenominator()
  {
    return denom;
  }//_______________________________________________________________________

  string getMessage()
  {
    return message;
  }//_______________________________________________________________________

};//__________________________________________________________________________

//  MAIN()
//=========
int main(void)
{
  int x = 5;
  int y = 0;
  int result;

  try
  {
    if (y == 0)
    {
      throw DivideByZero(x, y);
    }
    result = x/y;
    printf("Resultado %i",result);
  }

  catch (DivideByZero e)
  {
    cout << e.getMessage() << endl;
    cout << "Numerator: " << e.getNumerator() << endl;
    cout << "Denominator: " << e.getDenominator() << endl;
  }

  cout << "Goodbye" << endl;
  return 0;
}//______________________________________________________________
