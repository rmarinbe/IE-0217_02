//===============================================
// Archivo: cola_dinamica_template++.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef COLA_DINAMICA_TEMPLATE_PP_H_INCLUDED
#define COLA_DINAMICA_TEMPLATE_PP_H_INCLUDED

template<typename T>
class _cola :public _cola_base{
public:
        _cola(void);
        ~_cola(void);
   bool inserte(T);
   bool extraiga(T *x=NULL);
   int  longitud_cola(void);
   bool prev(T  *x=NULL);
   bool gotop(T *x=NULL);
};//____________________________

template<typename T>
_cola<T>::_cola(void) :_cola_base(sizeof(T))
{}//____________________________________

template<typename T>
_cola<T>::~_cola(void)
{
  while(_cola_base::extraiga());
}//_____________________________________

template<typename T>
bool _cola<T>::inserte(T info)
{
  return _cola_base::inserte(&info);
}//______________________________________

template<typename T>
bool _cola<T>::extraiga(T *info)
{
  return _cola_base::extraiga(info);
}//______________________________________

template<typename T>
bool _cola<T>::prev(T *info)
{
  return _cola_base::prev(info);
}//________________________

template<typename T>
bool _cola<T>::gotop(T *info)
{
  return _cola_base::gotop(info);
}//________________________

template<typename T>
int _cola<T>::longitud_cola(void)
{
  return _cola_base::longitud_cola();
}//___________________________________

#endif
