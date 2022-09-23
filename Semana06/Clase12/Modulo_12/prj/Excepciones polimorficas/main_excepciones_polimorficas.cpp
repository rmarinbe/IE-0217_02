//===============================================
// Archivo: main_excepciones_polimorficas.cpp
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
class _exception {
protected:
 const string msg;
public:
  _exception(string Msg=""): msg(Msg)
  {}//______________________________________________________________

  void virtual getMessage(void)
  {
    cout << "Undefined error handler by base exception class...!" << endl;
  }//______________________________________________________________
  virtual ~_exception(void)
  {}//______________________________________________________________
};//______________________________________________________________

class DivideByZero : public _exception {
private:
  int num;
  int denom;

public:
  DivideByZero(int n, int d) : _exception("Divide by zero"),num(n), denom(d)
  {}//______________________________________________________________

  ~DivideByZero()
  {}//______________________________________________________________

  void getMessage(void)
  {
    cout << msg << endl;
    cout << "Numerator:" << num << endl;
    cout << "Denominator: " << denom << endl;
  }//______________________________________________________________
};//______________________________________________________________


class StackException : public _exception{
public:
  StackException(string Msg):_exception(Msg)
  {}//______________________________________________________________

  ~StackException()
  {}//______________________________________________________________

  void getMessage(void)
  {
    cout << "Stack Exception: " << msg << endl;
  }//______________________________________________________________
};//______________________________________________________________

#define MAXSTACK 20
class CrudeStack
{
private:
  int data[MAXSTACK];
  int index;
public:
  CrudeStack() : index(0)
  {
  }//______________________________________________________________

  ~CrudeStack()
  {
  }//______________________________________________________________

  void push(int val)
  {
    if (index >= MAXSTACK)
    {
      StackException Overflow("Overflow");
      throw Overflow;
    }
    data[index++] = val;
  }//______________________________________________________________

  int pop(void)
  {
    if (index-1 < 0)
    {
      StackException Empty("Empty");
      throw Empty;
    }//______________________________________________________________

    int val = data[--index];
    return val;
  }//______________________________________________________________
};//_____________________________________________________

int divide(int num, int den)
{
  if (den == 0)
  {
    DivideByZero DbZ(num,den);
    throw DbZ;
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
    divide(num, den);

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
  catch (_exception& e)
  {
     e.getMessage();
  }//+++++++++++++++++++++++++++++++

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

