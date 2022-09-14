//===============================================
//Archivo: pila_dinamica_template.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef PILA_DINAMICA_TEMPLATE_PP_H_INCLUDED
#define PILA_DINAMICA_TEMPLATE_PP_H_INCLUDED
template <typename T>
class _pila: public _pila_base{
public:
  bool push(T);
  bool pop(T*);
  _pila(void);
  ~_pila(void);
};//____________________________

template <typename T>
_pila<T>::_pila(void): _pila_base(sizeof(T))
{}//_________________________________________________

template <typename T>
_pila<T>::~_pila(void)
{
  while(extraiga());
}//____________________________________________________

template <typename T>
bool _pila<T>::push(T info)
{
  return _pila_base::inserte(&info);
}//__________________________________________________

template <typename T>
bool _pila<T>::pop(T *info)
{
  return _pila_base::extraiga(info);
}//__________________________________________________
#endif


