//===============================================
//Archivo: gauss.h
//===============================================
// Curso de programación en C/C++
// Profesor: Freddy Rojas.
// Material de curso licencia GPL version 2.0
//===============================================
// No se admiten responsabilidades por el
// uso del material que no sea el planteado
// inicialmente para material didactico.
//===============================================
#ifndef GAUSS_H_DEFINED
#define GAUSS_H_DEFINED

//CLASS DEFINITION
//=================
template<typename T,int N>
class _ecuacion_gauss_jordan_base{
private:
   T *array;
public:
   _ecuacion_gauss_jordan_base(void);
   T &operator [](int);
   int dimension(void);
   ~_ecuacion_gauss_jordan_base(void);
};//_______________________________________________

template<typename T,int N>
class _ecuaciones_gauss_jordan{
private:
   _ecuacion_gauss_jordan_base<T,N> *base;
   bool reordenar(void);
   void swap(T&,T&);
public:
   _ecuaciones_gauss_jordan(void);
   ~_ecuaciones_gauss_jordan(void);
   _ecuacion_gauss_jordan_base<T,N> &operator [](int);
   int dimension(void);
   int ecuaciones(void);
   bool resolve(void);
};//_______________________________________________

//CLASS IMPLEMENTATION
//=====================
//class _ecuacion_gauss_base
//+++++++++++++++++++++++++++
template<typename T,int N>
_ecuacion_gauss_jordan_base<T,N>::_ecuacion_gauss_jordan_base(void)
{
  array = new T [N+1];
  #ifdef DEBUG
  cout << "base gauss dimension es  " << N+1 << endl;
  #endif
}//__________________________________________________

template<typename T,int N>
_ecuacion_gauss_jordan_base<T,N>::~_ecuacion_gauss_jordan_base(void)
{
  if (array) delete [] array;
}//__________________________________________________

template<typename T,int N>
T & _ecuacion_gauss_jordan_base<T,N>::operator [](int index)
{
  static T Pad;
  if ( (index >= N+1)  || (index < 0) ) return Pad;
  return array[index];
}//___________________________________________________

template<typename T,int N>
int _ecuacion_gauss_jordan_base<T,N>::dimension(void)
{
  return N+1;
}//___________________________________________________

//class _ecuaciones_gauss_jordan
//+++++++++++++++++++++++++++++++
template<typename T,int N>
_ecuaciones_gauss_jordan<T,N>::_ecuaciones_gauss_jordan(void)
{
  base = new _ecuacion_gauss_jordan_base<T,N>[N];
  #ifdef DEBUG
  cout << "Base dimension es "<< base->dimension() << " N es "<< N << endl;
  #endif
}//___________________________________________________

template<typename T,int N>
_ecuaciones_gauss_jordan<T,N>::~_ecuaciones_gauss_jordan(void)
{
  if (base) delete []  base;
}//___________________________________________________

template<typename T,int N>
_ecuacion_gauss_jordan_base<T,N>& _ecuaciones_gauss_jordan<T,N>::operator [](int index)
{
  static _ecuacion_gauss_jordan_base<T,N> Pad;
  if ( (index >= N)  || (index < 0) ) return Pad;
  return base[index];
}//___________________________________________________

template<typename T,int N>
bool  _ecuaciones_gauss_jordan<T,N>::resolve(void)
{
  if (!reordenar()) return false;
  #ifdef DEBUG
    cout << "Inicial";
    x_view(*this);
  #endif

  //Punto 3.a
  //++++++++++
  for (int i=0;i< N;i++)
  {
   for (int k=0;k<N;k++)
   {
     //Punto 3.c
     //++++++++++
     if (i==k) continue;

     //Punto 3.b
     //++++++++++
     T div1=base[i][i];
     if (div1==0) return false;
     for(int j=0;j< base->dimension();j++)
     {
       base[i][j]/=div1;
     }//for j
     #ifdef DEBUG
       cout << "Normaliza ";
       x_view(*this);
     #endif

     //Punto 3.d
     //++++++++++
     T mul=base[k][i];
     if (mul != 0) for(int j=0;j<base->dimension();j++)
     {
       //Punto 3.d.1
       //+++++++++++
       base[i][j]*=-mul;
     }
     #ifdef DEBUG
       cout << "Ajusta ";
       x_view(*this);
     #endif

     if (mul != 0) for(int j=0;j<base->dimension();j++)
     {
       //Punto 3.d.2
       //+++++++++++
       base[k][j]+=base[i][j];
     }//for j

     #ifdef DEBUG
       cout << "Suma ";
       x_view(*this);
     #endif
   }//for k
   //Punto 3.f
   //++++++++++
   T div2=base[i][i];
   for(int j=0;j<base->dimension();j++)
   {
     base[i][j]/=div2;
   }//for j
   #ifdef DEBUG
     cout << "Renormaliza ";
     x_view(*this);
   #endif
  }//for i
  return true;
}//___________________________________________________


//++++++++++++++++++PRIVATE ++++++++++++
//_____________________ _________________
template<typename T,int N>
void _ecuaciones_gauss_jordan<T,N>::swap(T &a,T &b)
{
  T c;
  c=a;
  a=b;
  b=c;
}//___________________________________________________

template<typename T,int N>
bool _ecuaciones_gauss_jordan<T,N>::reordenar(void)
{
  // Intercambia las ecuaciones que una de sus columnas (i,i) sea cero
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  for (int i=0;i<N;i++)
  {
    if (base[i][i] != 0) continue;
    int ref = i+1 % N;  // Ecuacion para ordenar.
    for (int j=0;j< base->dimension();j++) swap(base[i][j],base[ref][j]);
  }

  //Verifica que todo sea consistente
  //+++++++++++++++++++++++++++++++++
  for (int i=0;i<N;i++)
  {
    if (base[i][i] == 0) return false;  //Hay menos variables que ecuaciones.
  }
  return true;
}//___________________________________________________
#endif

