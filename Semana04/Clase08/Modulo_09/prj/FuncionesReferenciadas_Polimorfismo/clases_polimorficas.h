//===============================================
// Archivo: clases_polimorficas.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef CLASES_POLIMORFICAS_H_INCLUDED
#define CLASES_POLIMORFICAS_H_INCLUDED
class _funcion_base{
private:
public:
  double virtual fx(double valor);
  virtual ~_funcion_base(void);
};//_______________________________

class _sin_: public _funcion_base{
public:
  double fx(double valor);
};//________________________________

class _cos_: public _funcion_base{
public:
  double fx(double valor);
};//________________________________

class _tan_: public _funcion_base{
public:
  double fx(double valor);
};//________________________________

class _log_: public _funcion_base{
public:
  double fx(double valor);
};//________________________________

class _exp_: public _funcion_base{
public:
  double fx(double valor);
};//________________________________

class _cosh_: public _funcion_base{
public:
  double fx(double valor);
};//________________________________

class _sinh_: public _funcion_base{
public:
  double fx(double valor);
};//________________________________

void evaluar(_funcion_base &fx);
#endif // CLASES_POLIMORFICAS_H_INCLUDED
