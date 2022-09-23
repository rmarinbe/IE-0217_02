//===============================================
// Archivo: throw_multiclass.cpp
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
//+++++++++++++++++++
// Exception Class
//+++++++++++++++++++
class DivideByZero
{
private:
  int num;
  int denom;
  string message;

public:
  DivideByZero(int n, int d) : num(n), denom(d), message("Divide by zero")
  {}//____________________________________________________________________

  ~DivideByZero()
  {}//____________________________________________________________________

  void getMessage()
  {
     cout << message << endl;
     cout << "Numerator:" << num << endl;
     cout << "Denominator: " << denom << endl;
  }//____________________________________________________________________
};//____________________________________________________________________

class StackOverflowException {
public:
  StackOverflowException()
  {}//____________________________________________________________________

  ~StackOverflowException()
  {}//____________________________________________________________________

  void getMessage()
  {
    cout << "Exception: Stack Full" << endl;
  }//____________________________________________________________________
};//____________________________________________________________________

class StackEmptyException
{
public:
  StackEmptyException()
  {}//____________________________________________________________________

  ~StackEmptyException()
  {}//____________________________________________________________________

  void getMessage()
  {
     cout << "Exception: Stack Empty" << endl;
  }//____________________________________________________________________
};//____________________________________________________________________

#define MAXSTACK 20
class CrudeStack {
private:
  int data[MAXSTACK];
  int index;
public:
  CrudeStack() : index(-1)
  {
  }//______________________

  ~CrudeStack()
  {
  }//_______________________

  void push(int val)
  {
    index++;
    if (index >= MAXSTACK) throw StackOverflowException();
    data[index] = val;
  }//__________________________

  int pop(void)
  {
    if (index < 0) throw StackEmptyException();
    int val = data[index];
    index--;
    return val;
  }//____________________________
};//_____________________________________________________

int divide(int num, int den)
{
  if (den == 0)
  {
    throw DivideByZero(num,den);
  }
  return num/den;
}//__________________________________

int main(void)
{
  CrudeStack stack;
  int num;
  int den;
  int val;

  cout << "Enter num: ";
  cin >> num;
  cout << "Enter den: ";
  cin >> den;

  try
  {
    stack.push(num);
    stack.push(den);
    cout << "La división da: " << divide(num, den) << endl ;

    val = stack.pop();
    cout << "popped " << val << endl;
    val = stack.pop();
    cout << "popped " << val << endl;
    val = stack.pop();
    cout << "popped " << val << endl;
  }

  //++++++++++++++++++++++++++++++++
  // Exception Handler Zone
  //++++++++++++++++++++++++++++++++
  catch (StackOverflowException e)
  {
    e.getMessage();
  }//+++++++++++++++++++++++++++++++

  catch (StackEmptyException e)
  {
    e.getMessage();
  }//+++++++++++++++++++++++++++++++++

  catch (DivideByZero e)
  {
    e.getMessage();
  }//+++++++++++++++++++++++++++++++++

  catch (...)
  {
    cout << "An exception of unknown type occurred" << endl;
  }//++++++++++++++++++++++++++++++++++

  //++++++++++++++++
  // Normal Code
  //++++++++++++++++
  cout << "Goodbye" << endl;
  return 0;
}//______________________________________________
