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
#ifndef PILA_DINAMICA_TEMPLATE_H_INCLUDED
#define PILA_DINAMICA_TEMPLATE_H_INCLUDED
template <typename T>
struct T_pila{
  T  dato;
  T_pila *proximo;
};

template <typename T>
class _pila{
private:
  T_pila<T>  *array,*index;
  int         contador;
public:
  bool push(T);
  bool pop(T*);
  _pila(void);
  ~_pila(void);
};//____________________________

template <typename T>
_pila<T>::_pila(void)
{
   contador=0;
   array=index=NULL;
}//_________________________________________________

template <typename T>
_pila<T>::~_pila(void)
{
  T basura;
  while(pop(&basura));
}//____________________________________________________

template <typename T>
bool _pila<T>::push(T info)
{
  T_pila<T> *p_aux;

  //Algoritmo de la pila
  //++++++++++++++++++++
   p_aux  = new T_pila<T>;
   if (p_aux==NULL) return false;
   p_aux->proximo=array;
   array=p_aux;
   index =NULL;

  //Algoritmo de almacenamiento
  //++++++++++++++++++++++++++
   p_aux->dato =info;
   return true;
}//__________________________________________________

template <typename T>
bool _pila<T>::pop(T *info)
{
   T_pila<T> *p_aux;

   if (array==NULL) return false;
   //Algoritmo de almacenamiento
   //++++++++++++++++++++++++++
   *info=array->dato;
   //Algoritmo pila
   //++++++++++++++++++++++++++
   p_aux=array->proximo;
   delete array;
   array=p_aux;
   return true;
}//__________________________________________________
#endif


