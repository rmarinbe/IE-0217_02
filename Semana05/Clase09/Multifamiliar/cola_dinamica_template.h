//===============================================
// Archivo: cola_dinamica_template.h
//===============================================
// Curso de Estructuras Abstractas y Algoritmos
// Profesor: Freddy Rojas.
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didáctico.
//===============================================
#ifndef COLA_DINAMICA_TEMPLATE_H_INCLUDED
#define COLA_DINAMICA_TEMPLATE_H_INCLUDED

template<typename T>
struct T_cola{
   T         dato;
   T_cola   *anterior;
};

template<typename T>
class _cola {
private:
    T_cola<T>  *inicio,*final,*index;
    int     contador;
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
_cola<T>::_cola(void)
{
  contador =0;
  inicio=final=index=NULL;
}//____________________________________

template<typename T>
_cola<T>::~_cola(void)
{
  while(extraiga());
}//_____________________________________

template<typename T>
bool _cola<T>::inserte(T info)
{
  T_cola<T> *ficha;
  ficha = new T_cola<T>;
  if (!ficha) return false;
  ficha->dato= info;
  if (contador==0)   //condiciones inciales
  {
    ficha->anterior=final;
    inicio=final=ficha;
    index=inicio;
  }else		//una condicion mas
  {
    ficha->anterior=final->anterior;
    final->anterior=ficha;
    final=ficha;
  }
  contador++;
  return true;
}//______________________________________

template<typename T>
bool _cola<T>::extraiga(T *info)
{
  T_cola<T> *temporal;
  if (!inicio) return false;
  if (info) *info=inicio->dato;
  temporal=inicio->anterior;
  delete inicio;
  inicio=temporal;
  if (!inicio) final=inicio;
  contador--;
  return true;
}//______________________________________

template<typename T>
bool _cola<T>::prev(T *info)
{
  if (!index->anterior) return false;
  index=index->anterior;
  if (info) *info=index->dato;
  return true;
}//________________________

template<typename T>
bool _cola<T>::gotop(T *info)
{
  if (!inicio) return false;
  index=inicio;
  if (info) *info=index->dato;
  return true;
}//________________________

template<typename T>
int _cola<T>::longitud_cola(void)
{
  return contador;
}//___________________________________
#endif
