//===============================================
//Archivo: exception_class.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef EXCEPTION_CLASS_H_INCLUDED
#define EXCEPTION_CLASS_H_INCLUDED
class _exception {
protected:
 const string msg;
public:
  _exception(string Msg="");
  void virtual getMessage(void);
  virtual ~_exception(void);
};//______________________________________________________________
#endif // EXCEPTION_CLASS_H_INCLUDED
