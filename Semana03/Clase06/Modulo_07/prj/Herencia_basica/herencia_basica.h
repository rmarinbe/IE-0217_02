//===============================================
//Archivo: herencia_basica.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef HERENCIA_BASICA_H_INCLUDED
#define HERENCIA_BASICA_H_INCLUDED
class _base{
private:
  int variable_privada_base;
protected:
  int variable_protegida_base;
  _base(int,int);
public:
  _base(void);
  float variable_publica_base;
};//______________________________________

class _main : public _base {
private:
  int variable_privada_main;
protected:
  int variable_protegida_main;
public:
  float variable_publica_main;
  _main(void);
  _main(int,int);
};//______________________________________
#endif // HERENCIA_BASICA_H_INCLUDED
