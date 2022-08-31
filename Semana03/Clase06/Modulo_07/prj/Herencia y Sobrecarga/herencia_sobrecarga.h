//===============================================
//Archivo: herencia_sobrecarga.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef HERENCIA_SOBRECARGA_H_INCLUDED
#define HERENCIA_SOBRECARGA_H_INCLUDED
class _base{
protected:
  int contador;
  _base(int);
public:
  void incrementar_contador(void);
  const int& get_cuenta();
};//______________________________________

class _base_main : public _base{
protected:
  int counter;
public:
  _base_main(int=0);
  void incrementar_contador(void);
  const int& get_cuenta(void);
};//______________________________________

class _main : public _base_main{
public:
  _main(int=0);
  int operator++(void);
  int operator++(int);
  const int& get_cuenta(void);
};//______________________________________
#endif // HERENCIA_SOBRECARGA_H_INCLUDED
